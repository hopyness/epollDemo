//
// Created by lihp on 2022/4/21.
//

#include "connCmd.h"
#include "serverApp.h"
#include "connClient.h"
#include "pbhead.h"
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
   // std::cout << "CMDdo [" << x << "]" << std::endl;

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
     //初始化  让cmd 找到 conclient 句柄  以后方便发送数据
    if (strncmp(x, "init", 4) == 0) {
        //给所有客户端发送一条消息 --   sendall  1234
        serverApp* p_app =((serverApp*)this->serverptr);
        p_app->m_lihpHandles;

        int i=0;
        for(;i<maxFiles;i++)
        {
            if( p_app->m_lihpHandles[i]!= nullptr) {

                std::cout << (p_app->m_lihpHandles[i])->lihp_fd << std::endl;
                auto  ss =std::dynamic_pointer_cast<connClient>((p_app->m_lihpHandles[i]));//
                if(ss) //只处理 是客户端的
                {
                    connClientX =ss;
                    std::cout << connClientX->lihp_fd << std::endl;
                    break;
                }
            }

        }
    }
    //登录
    if (strncmp(x, "login1", 6) == 0) {
        //给所有客户端发送一条消息 --   sendall  1234

       auto  ss=std::make_shared<PB::Client_Server::Login>();
        ss->set_uname("111");
        ss->set_pwd("123");

        connClientX->connWrite(PB::Client_Server::Login::Id,ss);
    }

    //登录
    if (strncmp(x, "login2", 6) == 0) {
        //给所有客户端发送一条消息 --   sendall  1234

        auto  ss=std::make_shared<PB::Client_Server::Login>();
        ss->set_uname("222");
        ss->set_pwd("123");

        connClientX->connWrite(PB::Client_Server::Login::Id,ss);
    }

    if (strncmp(x, "logout", 6) == 0) {
        //给所有客户端发送一条消息 --   sendall  1234
        std::cout << "CMDdo logout" << std::endl;

        auto  ss=std::make_shared<PB::Client_Server::Logout>();
        //connClientX->m_player->token
        ss->set_token(connClientX->m_player->token);

        connClientX->connWrite(PB::Client_Server::Logout::Id,ss);
    }
    if (strncmp(x, "sd11", 4 ) == 0) {
        //坐下

        auto  ss=std::make_shared<PB::Client_Server::SitDown>();
        //connClientX->m_player->token
        ss->set_token(connClientX->m_player->token);
        ss->set_tableid(1);
        ss->set_tablesit(1);
        connClientX->m_player->tableid=1;
        connClientX->m_player->tablesit=1;
        connClientX->connWrite(PB::Client_Server::SitDown::Id,ss);
    }
    if (strncmp(x, "sd12", 4) == 0) {

        auto  ss=std::make_shared<PB::Client_Server::SitDown>();
        //connClientX->m_player->token
        ss->set_token(connClientX->m_player->token);
        ss->set_tableid(1);
        ss->set_tablesit(2);
        connClientX->m_player->tableid=1;
        connClientX->m_player->tablesit=2;
        connClientX->connWrite(PB::Client_Server::SitDown::Id,ss);
    }
    if (strncmp(x, "ready", 5) == 0) {

        auto  ss=std::make_shared<PB::Client_Server::Ready>();
        //connClientX->m_player->token
        ss->set_token(connClientX->m_player->token);
        ss->set_tableid(1);
        ss->set_tablesit(2);

        ss->set_tableid( connClientX->m_player->tableid);
        ss->set_tablesit( connClientX->m_player->tablesit);
        connClientX->connWrite(PB::Client_Server::Ready::Id,ss);
    }

}