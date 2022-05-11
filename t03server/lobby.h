//
// Created by lihp on 2022/5/11.
//

#ifndef EPOLLDEMO_LOBBY_H
#define EPOLLDEMO_LOBBY_H

/* 游戏启动 就创建一个单列大厅
  有玩家登录  大厅就new 一个玩家
  一个座子 开始游戏 就new gameserver
 成员变量 有 玩家列表
 游戏服列表
  座子信息
  如果推送座子信息 就是
    {1:[0:无人 1:a,2:b,]}
    {1:[0:无人 1:a,2:b,]}
 * */
#include <vector>
#include <set>
#include "gameserver.h"
#include "player.h"
//保存玩家 用玩家id  不需要用玩家指针？？
struct tabeinfo
{
    std::shared_ptr<player> p_A= nullptr;
    std::shared_ptr<player> p_B= nullptr;
    std::shared_ptr<player> p_C= nullptr;
    std::shared_ptr<player> p_D= nullptr;

};
class lobby {
public://方法
    lobby()
    {}
    ~lobby()
    {}
    //addaplayer 添加一个玩家
    //delaplayer  移除一个玩家
    //stargameserver( teebid)
    //

public: //变量
    //1 玩家信息
    std::set<int , std::shared_ptr<player> > playerSet;
    //1 座子信息
    std::set<int , tabeinfo > tableinfo;
    //?? 座子状态？？
};


#endif //EPOLLDEMO_LOBBY_H
