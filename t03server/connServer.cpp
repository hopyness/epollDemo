//
// Created by lihp on 2022/4/21.
//

#include "connServer.h"

#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <iostream>
#include <memory>

#include "connClient.h"

connServer::connServer() {
    lihp_fd = -1;
}

void connServer::callbackRead() {
    //回调读事件  connServer的事件  就要有人要来连接了 你去监听

    struct sockaddr_in clientaddr;
    bzero(&clientaddr, sizeof(clientaddr));
    socklen_t len = sizeof(clientaddr);
    int  connfd = accept(lihp_fd,(sockaddr *)&clientaddr, &len);

    if(connfd<0){

        std::cout<<"accept erro"<<std::endl;
    }
    char *str = inet_ntoa(clientaddr.sin_addr);
    std::cout<<str<<":"<<clientaddr.sin_port<<std::endl;

//    PB::Client_Server::Login t1;
//    t1.set_uname("hello");
//    t1.set_pwd("word");
//    std::string buff{};
//    t1.SerializeToString(&buff);
//    int  s=buff.length()+8;
//    int t2=PB::Client_Server::Login::Id;
//    write(connfd,&s,4);
//    write(connfd,&t2,4);
//    write(connfd,buff.c_str(),s-8);
//    pbData t;

    //
    auto xx21=std::make_shared<connClient>();

    xx21->lihp_fd =connfd;
    xx21->m_oppositeIP=str;
    xx21->m_oppositePort=clientaddr.sin_port;
    ((serverApp*)this->serverptr)->addConnHandle(xx21);
}

void connServer::callbackWrite() {
    //永远不可能有写事件发送；

}

void connServer::creatFd(int const &port) {


    //1 创建   sockaddr

    int sockType = SOCK_STREAM;
    char const *const &hostName = nullptr;
    char portStr[20];
    snprintf(portStr, sizeof(portStr), "%d", port);

    addrinfo hints;
    // memset
    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = 2;                                            // ipv4 / 6
    hints.ai_socktype = sockType;                                           // SOCK_STREAM / SOCK_DGRAM
    hints.ai_flags = AI_PASSIVE;                                            // all interfaces

    addrinfo *ai_, *ai;
    if (getaddrinfo(hostName, portStr, &hints, &ai_)) return;
    //使用这个 可以支持  ipv4 /  ipv6 反正也看不懂  但是记得成功后记得调用 freeaddrinfo 释放
    //其次最重要的是可以     兼容这个 bind 的二三个参数 ai_addr   getaddrinfo函数可以系统获取   ipv4 /  ipv6的二三个参数还不一样
    int fd  ;
    for (ai = ai_; ai != nullptr; ai = ai->ai_next) {

        fd = socket(ai->ai_family, ai->ai_socktype | SOCK_NONBLOCK, ai->ai_protocol);
        if (fd == -1) continue;

        int enable = 1;
        /*
         * SO_REUSEPORT是端口重用，SO_REUSEADDR是地址重用  也看懂不啥
         * 反正 就是这个东西 不加 关闭后马上重启 tcp状态是time_wait状态的 马上重启就不能listen
        */
        if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
            close(fd);
            continue;
        }

        if (setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(int)) < 0) {
            close(fd);
            continue;
        }
        if (!bind(fd, ai->ai_addr, ai->ai_addrlen)) break;                  // success
        close(fd);
    }
    freeaddrinfo(ai_);
    //创建完了 就开始监听
    if (-1 == listen(fd, SOMAXCONN)) return;
    lihp_fd = fd;
}