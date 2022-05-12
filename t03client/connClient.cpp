//
// Created by lihp on 2022/4/21.
//

#include "connClient.h"
#include "pbhead.h"
#include <google/protobuf/stubs/status.h>
#include <google/protobuf/util/json_util.h>

connClient::connClient() {
    recvData=new char[1024*200+10];
    //建议一个包不能超过1024 char大小 大概就能缓存200个包
    // +10 就是怕异常移除  其实不写也没问题
    recvlen=0;
    recvend=1024*200;
}

connClient::~connClient() {
    delete [] recvData;
    std::cout << "~connClient()" << std::endl;
}


//connect or accept
void connClient::callbackRead() {
    std::cout << " connClient:callbackRead" <<
              std::endl;
    int n = 0;
    char line[9999];

        std::cout <<  recvData+recvlen<<"::"<<recvend-recvlen<<
                  std::endl;
        if ((n = read(lihp_fd, recvData+recvlen, recvend-recvlen)) <= 0) {
            // 读取错误
            // 不一定是读取错误 一般这个 就是对方关闭了连接
            //告诉epoll 我已经鸡都鸡了  你们就不要绑定我  我是智能指针 应该会掉自己的析构函数
            std::cout << " 2" <<
                      std::endl;
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


            switch (datatype) {
                case PB::Client_Server::Login::Id: {
                    auto msg = std::make_shared<PB::Client_Server::Login>();
                    if (!msg->ParseFromArray(nowRead + 8, dataLen)) {
                        std::string temp;
                        google::protobuf::util::MessageToJsonString(*msg, &temp);
                        std::cout << temp.c_str() <<
                                  std::endl;
                    }
                    //PB::Client_Server::Login t=
                }
                    break;
            }
            // 操作完成 后 就men

        } else{
            break; //数据不够了
        }
        nowRead+=dataLen+8;//这个+8 和设计包有关   dataLen只是数据长度 不包括包头长度 如果设计含包头长度 就不要+8
    }
    memmove(recvData,nowRead,readEnd-nowRead);
    recvlen -= readEnd-nowRead;

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

void connClient::connWrite(int id,std::shared_ptr<google::protobuf::Message> msg)
{
  //  std::string buff{};
   // msg->SerializeToString(&buff);
    int pbLen = msg->ByteSizeLong();
    char * tt =new char[pbLen+8];
    msg->SerializeToArray(tt+8, pbLen);
    (*(int*)(tt))=pbLen;
    (*(int*)(tt+4))=id;
   // int a=buff.size();
    std::cout<<pbLen<< std::endl;
    write(lihp_fd,tt,pbLen+8);



        std::string temp;
        google::protobuf::util::MessageToJsonString(*msg, &temp);
        std::cout<<temp.c_str();

    for(int xx=0;xx<pbLen+8;xx++)
    {
        int xx3=*(tt+xx);
        std::cout <<"--" <<xx3<< std::endl;
    }
   // PB::Client_Server::Login t;
   // t.uname()
    auto  ss=std::make_shared<PB::Client_Server::Login>();
    ss->ParseFromArray(tt+8, pbLen);
    std::cout<<ss->uname()<<std::endl;

}
