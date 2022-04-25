//
// Created by lihp on 2022/4/21.
//

#include "connClient.h"

connClient::connClient() {
     recvData=new char[1024*200+10];
     //建议一个包不能超过1024 char大小 大概就能缓存200个包
     // +10 就是怕异常移除  其实不写也没问题
    recvlen=0;
     recvend=1024*200;
}

connClient::~connClient() {
    std::cout << "~connClient()" << std::endl;
    delete [] recvData;
}

void connClient::callbackRead() {
    std::cout << " connClient:callbackRead" << std::endl;
    int n = 0;
    //char line[9999];

    if ((n = read(lihp_fd, recvData+recvlen, recvend-recvlen)) <= 0) {
        // 读取错误
        // 不一定是读取错误 一般这个 就是对方关闭了连接
        //告诉epoll 我已经鸡都鸡了  你们就不要绑定我  我是智能指针 应该会掉自己的析构函数
        ((serverApp *) this->serverptr)->delConnHandlebyId(epollpos);
        lihp_fd = -1;// 写个-1  让它失效
    } else {
        recvlen+=n;
       // std::cout << "lihpClient [" << line << "]" << std::endl;
        //*   规范 包结构数据   每个有效包 必须是 前4个字节是 长度  后面对应是数据 (以后后面的部分可以是各种序列化的数据) *//
        //处理数据
        DealData();
    }
}
void connClient::DealData()
{
    //如果一次性来多个包

    char * nowRead=recvData;
    char * readEnd=recvData+recvlen;
    int nowReadLen=0;
    while (readEnd-nowRead>=8) //必须要有8个字符 让 它可以读包头
    {
        int dataLen = *(int *) nowRead;  //数据长度
        int datatype = *(int *) (nowRead+4);//数据类型  //比如char*    protobuf  或者以后自己写的序列化？？

        if(readEnd-nowRead>=dataLen+8) //如果数据完整 才操作 如果不完整 可能要读下一个包了
        {
            // nowRead+8 ~ nowRead+dataLen 就是正常包的数据
            // 操作 转换成base64 打印一下？

            // 操作完成 后 就men

        } else{
            break; //数据不够了
        }
        nowRead+=dataLen+8;//这个+8 和设计包有关   dataLen只是数据长度 不包括包头长度 如果设计含包头长度 就不要+8
    }
    memmove(recvData,nowRead,readEnd-nowRead);
    recvlen -= readEnd-nowRead;

}
//从char* 中读取数据

void connClient::callbackWrite() {


    /**
      * 如何实现 用回调 来写write
      1 想要发送数据的时候 往容器添加数据 如果有数据 就把epoll状态  添加写事件
      2 进入写状态  进入回调 callbackWrite
      3 由于是非阻塞函数  write函数一定是 马上返回  写失败返回<=0?
      不断的写 如果容器为空和 写失败 马上
      直接调用 write  如果失败 就不要write了 分析error  如果是网络不可写  就epll 添加写事件
      等回调写实现  再调用write 函数  还需要自己一个boll 变量标记可写不可写
     * */

}

void connClient::Write()
{
    std::cout << "Write" << std::endl;
    //
    write(lihp_fd,"hello",6);
}