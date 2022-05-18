//
// Created by lihp on 2022/5/11.
//

#include "gameserver.h"
#include "lobby.h"
#include "timer.h"
gameserver::gameserver() {

}
gameserver::~gameserver(){
    std::cout<<"~gameserver()"<<std::endl;
}
//初始化
void gameserver::init(){
    //每个玩家 钱-400  当前 筹码=400；
    for(auto tt:taneinfo->table_player)
    {
        if(tt!= nullptr)
        {
            tt->money-=400;
            tt->moneybet =400;
        }
    }
    // 当前房间是一共就三盘
    alltime=3;
    //定时器 写成一次
    auto tt3=std::make_shared<timer>(2, 0, 10000, [this]() { this->timefun1() ;});

    serverApp* p_app =((serverApp*)this->serverptr);
    p_app->m_timerList.push_back(tt3);
    time1=tt3;
}

//定时器函数1
void gameserver::timefun1(){
     //模拟 一盘结束
    int allbet=0;
    int allplaynum=0;
    for(auto tt:taneinfo->table_player)
    {
        if(tt!= nullptr)  //以后要加玩家状态  玩家是否可进行游戏(如没有钱)
        {
           int  a=serverApp::Rand(50,100);
            tt->moneybet -= a;
            allbet+=a;
            allplaynum++;
        }
    }
    int  xxwin=allbet*95/100;  //我们抽水 5% 不足够1元 也要扣1元
    gamewin+=allbet-xxwin;//记录一下 我们服务器的赢钱？
    int xxWinnum=serverApp::Rand(1,allplaynum);//随便找个玩家 把奖池给他
    for(auto tt:taneinfo->table_player)
    {
        if(tt!= nullptr)
        {
            xxWinnum--;
            if(xxWinnum==0)
            {
                tt->moneybet+=xxwin;
            }
        }
    }
    //打印
    for(auto tt:taneinfo->table_player)
    {
        if(tt!= nullptr)
        {
           std::cout<<tt->unmae.c_str()<<":"<<tt->moneybet<<std::endl;
        }
    }
    //给客户端推送一下
    alltime--;
    if(alltime)
    {//还有几次游戏
        auto tt3=std::make_shared<timer>(2, 0, 10000, [this]() { this->timefun1() ;});


    serverApp* p_app =((serverApp*)this->serverptr);
    p_app->m_timerList.push_back(tt3);
    time1=tt3;
    } else
    {

        time1= nullptr;//其实用time1 也可以 但是一个定时器 和一个回调函数对应
        //播放结束动画  慢慢的 这个对象也要解散了
        gameoverDeal();
    }

}
//结束操作
void gameserver::gameoverDeal(){
    //1   把玩家上的带入筹码 换到玩家上
    std::cout<<"gameoverDeal()"<<tableid<<std::endl;
    for(auto tt:taneinfo->table_player)
    {
        if(tt!= nullptr)  //以后要加玩家状态  玩家是否可进行游戏(如没有钱)
        {
            tt->money += tt->moneybet;
            tt->moneybet=0;
        }
    }
    //通知大厅 这个gs  可以释放了
    //打印
    for(auto tt:taneinfo->table_player)
    {
        if(tt!= nullptr)
        {
            std::cout<<tt->unmae.c_str()<<":"<<tt->money<<std::endl;
        }
    }
    sp_b->delecXX(tableid);
}

//准备释放对象了
void gameserver::befordel(){

}