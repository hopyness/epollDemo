//
// Created by lihp on 2022/5/11.
//

#ifndef EPOLLDEMO_PLAYER_H
#define EPOLLDEMO_PLAYER_H

#include <iostream>
#include <string>
#include <memory>

class player {

public:
    //方法
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
    int token;
    std::string tokenStr;
    int tableid;
    int  tablesit;

};


#endif //EPOLLDEMO_PLAYER_H
