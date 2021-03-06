//
// Created by lihp on 2022/4/21.
//

#include "connClient.h"
#include "lobby.h"
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
        std::cout << n << std::endl;
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
    std::cout << " DealData" << std::endl;
    char * nowRead=recvData;
    char * readEnd=recvData+recvlen;
    int nowReadLen=0;
    while (readEnd-nowRead>=8) //必须要有8个字符 让 它可以读包头
    {
        int dataLen = *(int *) nowRead;  //数据长度
        int datatype = *(int *) (nowRead+4);//数据类型  //比如char*    protobuf  或者以后自己写的序列化？？
        std::cout << " datatype"<<datatype << std::endl;
        if(readEnd-nowRead>=dataLen+8) //如果数据完整 才操作 如果不完整 可能要读下一个包了
        {
            // nowRead+8 ~ nowRead+dataLen 就是正常包的数据
            // 操作 转换成base64 打印一下？
            switch (datatype) {
                case PB::Client_Server::Login::Id:
                {

                    auto msg =  std::make_shared<PB::Client_Server::Login>();
                    for(int xx=0;xx<dataLen+8;xx++)
                    {
                        int xx3=*(nowRead+xx);
                        std::cout <<"--" <<xx3<< std::endl;
                    }
                    if (!msg->ParseFromArray(nowRead+8, dataLen))
                    {
                        std::cout <<"reeor" << std::endl;
                    } else{
                        //登录包
                        //告诉大厅 有个 玩家登录
                        auto lp=((serverApp *) this->serverptr)->sp_lobby->addaplayer(msg );
                        if(lp)
                        {
                            //添加成功 玩家类和 tcp 实现绑定
                            std::cout <<"ok" << std::endl;
                            //std::cout <<"No" << std::endl;
                            lp->con_ptr = shared_from_this();
                            //回包
                            auto  ss=std::make_shared<PB::Server_Client::LoginRet>();
                           // ss->set_uname("123");
                            //ss->set_pwd("123");

                            ss->set_type(1);
                            ss->set_usename(lp->unmae);
                            ss->set_token(lp->tokenStr);
                            ss->set_tokenint(lp->token);
                            ss->set_money(lp->money);
                            connWrite(PB::Server_Client::LoginRet::Id,ss);

                        }
                        else{
                            //进不了大厅？ //密码错误 大厅添加不起玩家？
                            std::cout <<"No" << std::endl;
                        }
                        //std::cout <<"reeor" << std::endl;
                        std::cout <<"44" << std::endl;
                        std::string temp;
                        google::protobuf::util::MessageToJsonString(*msg, &temp);
                        std::cout<<temp.c_str()<<"-123"<< std::endl;

                        std::string buff{};
                        msg->SerializeToString(&buff);
                    }
                        //PB::Client_Server::Login t=
                }
                    break;
                case PB::Client_Server::Logout::Id:
                {
                    std::cout <<"Logout" << std::endl;
                    auto msg =  std::make_shared<PB::Client_Server::Logout>();

                    if (!msg->ParseFromArray(nowRead+8, dataLen))
                    {
                        std::cout <<"reeor" << std::endl;
                    } else{

                        int token=msg->token();
                        // 大厅 移除玩家
                        auto lp=((serverApp *) this->serverptr)->sp_lobby->delaplayer(msg );
                        std::cout <<"LogoutRet" <<lp<< std::endl;

                    }
                }
                    break;

                case PB::Client_Server::SitDown::Id:
                {
                    std::cout <<"SitDown" << std::endl;
                    auto msg =  std::make_shared<PB::Client_Server::SitDown>();

                    if (!msg->ParseFromArray(nowRead+8, dataLen))
                    {
                        std::cout <<"reeor" << std::endl;
                    } else{

                        int token=msg->token();
                        // 大厅 移除玩家
                        auto lp=((serverApp *) this->serverptr)->sp_lobby->sitDown(msg );
                        std::cout <<"SitDown" <<lp<< std::endl;

                    }
                }
                    break;
                case PB::Client_Server::Ready::Id:
                {
                    std::cout <<"Logout" << std::endl;
                    auto msg =  std::make_shared<PB::Client_Server::Ready>();

                    if (!msg->ParseFromArray(nowRead+8, dataLen))
                    {
                        std::cout <<"reeor" << std::endl;
                    } else{

                        int token=msg->token();
                        // 大厅 移除玩家
                        auto lp=((serverApp *) this->serverptr)->sp_lobby->Ready(msg );
                        std::cout <<"LogoutRet" <<lp<< std::endl;

                    }
                }
                    break;
            }
            // 操作完成 后 就men

        } else{
            break; //数据不够了
        }
        nowRead+=dataLen+8;//这个+8 和设计包有关   dataLen只是数据长度 不包括包头长度 如果设计含包头长度 就不要+8
    }
    std::cout << " memmove"<<nowRead<<readEnd-nowRead << std::endl;
    memmove(recvData,nowRead,readEnd-nowRead);
    recvlen += recvData-nowRead;

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

void connClient::connWrite(int id,std::shared_ptr<google::protobuf::Message> msg)
{
    //  std::string buff{};
    // msg->SerializeToString(&buff);
    std::cout << "Write"<<id << std::endl;
    int pbLen = msg->ByteSizeLong();
    char * tt =new char[pbLen+8];
    msg->SerializeToArray(tt+8, pbLen);
    (*(int*)(tt))=pbLen;
    (*(int*)(tt+4))=id;
    // int a=buff.size();
    std::cout<<pbLen<< std::endl;
    write(lihp_fd,tt,pbLen+8);

}