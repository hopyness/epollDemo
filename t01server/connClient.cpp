//
// Created by lihp on 2022/4/21.
//

#include "connClient.h"

connClient::connClient() {

}

connClient::~connClient() {
    std::cout << "~connClient()" << std::endl;
}

void connClient::callbackRead() {
    std::cout << " connClient:callbackRead" << std::endl;
    int n = 0;
    char line[9999];
    if ((n = read(lihp_fd, line, 9999)) <= 0) {
        // 读取错误
        // 不一定是读取错误 一般这个 就是对方关闭了连接
        //告诉epoll 我已经鸡都鸡了  你们就不要绑定我  我是智能指针 应该会掉自己的析构函数
        ((serverApp *) this->serverptr)->delConnHandlebyId(epollpos);
        lihp_fd = -1;// 写个-1  让它失效
    } else {
        std::cout << "lihpClient [" << line << "]" << std::endl;
    };
}

void connClient::callbackWrite() {

    /**
     * 如何实现 用回调 来写write
      1 想要发送数据的时候 往容器添加数据 如果有数据 就把epoll状态  添加写事件
      2 进入写状态  进入回调 callbackWrite 
      3 由于是非阻塞函数  write函数一定是 马上返回  写失败返回<=0?
      不断的写 如果容器为空和 写失败 马上
     * */
}
void connClient::Write()
{
    std::cout << "Write" << std::endl;
    write(lihp_fd,"hello",6);
}