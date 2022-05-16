//
// Created by lihp on 2022/5/11.
//

#include "lobby.h"
#include "serverApp.h"
/**/
lobby::lobby()
{
    //创建两个座子
    tabeinfo t1;
    t1.table_player[0]=nullptr;
    t1.table_player[1]=nullptr;
    t1.table_player[2]=nullptr;
    t1.table_player[3]=nullptr;
    t1.isReady = 0;
    tableinfo.insert(std::make_pair(1,t1));
    tableinfo.insert(std::make_pair(2,t1));
}
std::shared_ptr<player> lobby::addaplayer(std::shared_ptr<PB::Client_Server::Login> t)
{
    // 创建玩家  把玩家放在大厅中

    int a =serverApp::Rand(1,5);
    /*生成一个随机数*/
    /* 12 0000 2334*/
    if(playerInfo.size()>1000)
    {
        std::cout<<"too many player in lobby"<<std::endl;

        return nullptr;
    }
    int  token=0;
    for(int i=0;i<20;i++)
    {
        int a=serverApp::Rand(10,50)*10000000+serverApp::Rand(0,99)*10000+serverApp::Rand(0,999);
        if(playerInfo.find(a)==playerInfo.end())
        {
           // std::cout<<token<<std::endl;
            token=a;
            std::cout<<token<<std::endl;
            break;;
        }
    }
    if(token==0)
    {
        std::cout<<"can not get token of player"<<std::endl;
        return nullptr;
    }
    auto play_t =std::make_shared<player>();
    play_t->unmae=t->uname();
    play_t->pwd=t->pwd();
    play_t->token =token;
    play_t->money =2222;
    char xxs[100];
    sprintf(xxs,"%d",token);
    play_t->tokenStr=xxs;
    play_t->lobby_ptr=shared_from_this();

    playerInfo.insert(std::make_pair(token,play_t));
    return play_t;
}

int lobby::delaplayer(std::shared_ptr<PB::Client_Server::Logout> t)
{
    int token=t->token();
    auto  xxpter=playerInfo.find(token);
    if(xxpter==playerInfo.end())
    {
        std::cout<<"can not findplayer by token"<<std::endl;
       return  -1;
    }
    //接触绑定   不然以后可以有循环应用关系 导致内存泄漏
    xxpter->second->con_ptr= nullptr;
    xxpter->second->lobby_ptr= nullptr;
    playerInfo.erase(xxpter);
    return  0;
}

int lobby::sitDown(std::shared_ptr<PB::Client_Server::SitDown> t)
{
    int token=t->token();
    auto  xxpter=playerInfo.find(token);

    if(xxpter==playerInfo.end())
    {
        std::cout<<"can not findplayer by token"<<std::endl;
        return  -1;
    }
    //接触绑定   不然以后可以有循环应用关系 导致内存泄漏
    int  ta=t->tableid();
    int  tb=t->tablesit();

    auto tabe=tableinfo.find(ta);
    if(tabe==tableinfo.end())
    {
        std::cout<<"can not tabe"<<std::endl;
        return  -2;
    }
    if(tb>3||tb<0)
    {
        std::cout<<"tb error"<<std::endl;
        return  -3;
    }
    auto setx =tabe->second.table_player[tb];
    if(setx!= nullptr)
    {
        std::cout<<"setx have player"<<std::endl;
        return  -4;
    }
    tabe->second.table_player[tb]=xxpter->second;

    return  0;
}

int lobby::Ready(std::shared_ptr<PB::Client_Server::Ready> t)
{
    int token=t->token();
    auto  xxpter=playerInfo.find(token);

    if(xxpter==playerInfo.end())
    {
        std::cout<<"can not findplayer by token"<<std::endl;
        return  -1;
    }
    //接触绑定   不然以后可以有循环应用关系 导致内存泄漏
    int  ta=t->tableid();
    int  tb=t->tablesit();

    auto tabe=tableinfo.find(ta);
    if(tabe==tableinfo.end())
    {
        std::cout<<"can not tabe"<<std::endl;
        return  -2;
    }
    if(tb>3||tb<0)
    {
        std::cout<<"tb error"<<std::endl;
        return  -3;
    }
    auto setx =tabe->second.table_player[tb];
   // std::cout<<setx->tokenStr<<std::endl;
   // std::cout<<xxpter->second->tokenStr<<std::endl;
    if(setx->token != xxpter->second->token)
    {
        std::cout<<" player is not equit by table"<<std::endl;
        return  -4;
    }

    xxpter->second->isReady =1;
    doReady(ta);
    return  0;
}

void lobby::doReady(int ta)
{
    auto tabe=tableinfo.find(ta);
    if(tabe==tableinfo.end())
    {
        std::cout<<"can not tabe"<<std::endl;
        return  ;
    }
    int CoutX=0;
    for(int i=0;i<4;i++)
    {
        if(tabe->second.table_player[i] != nullptr&& tabe->second.table_player[i]->isReady ==0)
            return;
        if(tabe->second.table_player[i] != nullptr&& tabe->second.table_player[i]->isReady ==1)
            CoutX++;

    }
    if(CoutX>=2)
        tabe->second.isReady =1;
    //座子准备好了
    //启动定时器 20秒后  开始 创建玩家服务？
    std::cout<<"doReady XXXXX"<<std::endl;
}