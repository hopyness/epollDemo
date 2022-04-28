//
// Created by lihp on 2022/4/21.
//

#include "connCmd.h"

connCmd::connCmd() {
    lihp_fd = STDIN_FILENO;
}

connCmd::~connCmd() {
    std::cout << "~connCmd()" << std::endl;
}

void connCmd::callbackRead() {
    std::cout << "epoll_wait222" << std::endl;
    int n = 0;
    char line[9999];
    if ((n = read(lihp_fd, line, 9999)) < 0) {
        // 读取错误
    } else {
        CMDdo(line);
    };
}

void connCmd::callbackWrite() {

}


void connCmd::CMDdo(const char *x) {
    std::cout << "CMDdo [" << x << "]" << std::endl;

    if (strncmp(x, "quit", 4) == 0) {
        std::cout << "CMDdo  quit" << std::endl;
    }
    /** 客户端
     * 支持的有 命令
       给对应服务器发送一条消息 --   send id 1234

       （延迟发送）                sendaftter  1min  1234
       关闭某个客服端              killone id
       new一个新的客户端再连接      addconnetnew
       关闭某个客户端              killclientbyid
       关闭所有客户端              killallclien
       关闭 服务listen            killsrever
       退出                     quit
     * */

}