//
// Created by lihp on 2022/5/11.
//

#ifndef EPOLLDEMO_PLAYER_H
#define EPOLLDEMO_PLAYER_H

#include <iostream>
#include <string>
#include <memory>
#include "connClient.h"
#include "lobby.h"
class player {

public:
    //方法
    player()
    {
        isReady=0;
    }
    ~player()
    {
        std::cout<<" ~player()"<<unmae.c_str()<<std::endl;
    }
public:
    //成员变量
    //1 玩家属性
    std::string unmae;
    std::string pwd;
    int64_t  money;

    int  moneybet;
    int token;
    std::string tokenStr;
    //2 和其他对象的绑定
    std::shared_ptr<connClient>  con_ptr;
    std::shared_ptr<lobby>  lobby_ptr;
    int isReady;

};


#endif //EPOLLDEMO_PLAYER_H
