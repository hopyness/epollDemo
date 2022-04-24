//
// Created by lihp on 2022/4/21.
//

#include "connClient.h"

connClient::connClient() {

}

connClient::~connClient() {
    std::cout << "~connClient()" << std::endl;
}


//connect or accept
void connClient::callbackRead() {
    std::cout << " connClient:callbackRead" <<
              std::endl;
    int n = 0;
    char line[9999];
    if ((
                n = read(lihp_fd, line, 9999)
        ) <= 0) {
        // 读取错误
        // 不一定是读取错误 一般这个 就是对方关闭了连接
        //告诉epoll 我已经鸡都鸡了  你们就不要绑定我  我是智能指针 应该会掉自己的析构函数
        ((serverApp *) this->serverptr)->
                delConnHandlebyId(epollpos);
        lihp_fd = -1;// 写个-1  让它失效
    } else {
        std::cout << "lihpClient [" << line << "]" <<
                  std::endl;
    };
}

void connClient::callbackWrite() {

}

void connClient::connetfd(std::string ipstr, int prot) {

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons((uint16_t) prot);
    if (!inet_pton(AF_INET, ipstr.c_str(), &addr.sin_addr)) {
        //  std::cout<<"inet_pton error"<<std::endl;
    }
    auto &&fd2 = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    // 设置一些 tcp 参数( 可选 )
    int on = 1;
    setsockopt(fd2, IPPROTO_TCP, TCP_NODELAY, (const char *) &on, sizeof(on));
    lihp_fd = fd2;

    if (connect(fd2, (sockaddr *) &addr, sizeof(addr)) == -1)
        return;

}
