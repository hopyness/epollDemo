//
// Created by lihp on 2022/4/21.
//

#include "connCmd.h"
#include "serverApp.h"
#include "connClient.h"
#include "connServer.h"
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


    /**
     * 支持的有 命令
       给对应客户端发送一条消息 --   send id 1234
       给所有客户端发送一条消息 --   sendall  1234
       （延迟发送）                sendaftter  1min  1234
       关闭某个客服端              killone id
       关闭所有客户端             killoneclient
       关闭 服务listen           killsrever
       退出                     quit
     * */

    if (strncmp(x, "send", 4) == 0) {
        //给所有客户端发送一条消息 --   sendall  1234
        serverApp* p_app =((serverApp*)this->serverptr);
            p_app->m_lihpHandles;

        int i=0;
        for(;i<maxFiles;i++)
        {
            if( p_app->m_lihpHandles[i]!= nullptr) {
               auto  ss =std::dynamic_pointer_cast<connClient>((p_app->m_lihpHandles[i]));//
               if(ss) //只处理 是客户端的
               {
                   ss->Write();
                  // std::cout<<"ok"<<std::endl;
               }
            }

            }
    }
    if (strncmp(x, "close", 5) == 0) {
        //关闭所有客户端
        serverApp* p_app =((serverApp*)this->serverptr);
        p_app->m_lihpHandles;

        int i=0;
        for(;i<maxFiles;i++)
        {
            if( p_app->m_lihpHandles[i]!= nullptr) {
                auto  ss =std::dynamic_pointer_cast<connClient>((p_app->m_lihpHandles[i]));//
                if(ss) //只处理 是客户端的
                {
                    //ss->Write();
                    close(ss->lihp_fd);
                    p_app->delConnHandlebyId(ss->epollpos);
                    ss->lihp_fd = -1;// 写个-1  让它失效
                    // std::cout<<"ok"<<std::endl;
                }
            }

        }
    }
    if (strncmp(x, "kill", 4) == 0) {
        //关闭listen 服务  关闭  关闭listen 后已经连接的端口 已经连接的端口 有啥反应？
        /* netstat -anp |grep 端口 确实没有看见了 listen状态的端口 但是已经连接的还能正常操作*/
        serverApp* p_app =((serverApp*)this->serverptr);
        p_app->m_lihpHandles;

        int i=0;
        for(;i<maxFiles;i++)
        {
            if( p_app->m_lihpHandles[i]!= nullptr) {
                auto  ss =std::dynamic_pointer_cast<connServer>((p_app->m_lihpHandles[i]));//
                if(ss) //只处理 是客户端的
                {
                    //ss->Write();
                    close(ss->lihp_fd);
                    p_app->delConnHandlebyId(ss->epollpos);
                    ss->lihp_fd = -1;// 写个-1  让它失效
                    // std::cout<<"ok"<<std::endl;
                }
            }

        }
    }

    if (strncmp(x, "quit", 4) == 0) {
        //   退出                     quit
        serverApp* p_app =((serverApp*)this->serverptr);
        p_app->stop();
    }
    //妈耶 一遍输出 一遍打印   命令不好执行
    //添加定时器
    if (strncmp(x, "addtime", 7) == 0) {
        //   关闭定时器
        serverApp* p_app =((serverApp*)this->serverptr);
        auto tt=std::make_shared<timer>(0, 10, 3000, []() { std::cout << "hahhahaha" << std::endl; });
        p_app->m_timerList.push_back(tt);

    }
    //添加关闭所有定时器
    if (strncmp(x, "stoptime", 8) == 0) {
        //   关闭定时器
        serverApp* p_app =((serverApp*)this->serverptr);
        for(auto t:p_app->m_timerList)
        {
            t->stop();
        }
    }

}