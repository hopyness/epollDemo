
#include <iostream>
#include <sys/socket.h>
#include <sys/epoll.h>
//epoll_create
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

using namespace std;
#define MAXLINE 5
#define OPEN_MAX 100
#define LISTENQ 20
#define SERV_PORT 5000
#define INFTIM 1000

#include "serverApp.h"
#include "connClient.h"
#include "connCmd.h"
int main(int argc, char *argv[]) {

    //创建App
    serverApp app;
    app.init();

    //添加一个 监听cmd输入的
    auto xx=std::make_shared<connCmd>();
    app.addConnHandle(xx);
    // struct  St  qq{4,5};
    //添加监听serever 服务
    auto xx2 = std::make_shared<connClient>();
    xx2->connetfd("127.0.0.1",6688);
    app.addConnHandle(xx2);
    app.run();
    return 0;
}
