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
#include <map>
#include "gameserver.h"
#include "player.h"
#include "pbhead.h"
//保存玩家 用玩家id  不需要用玩家指针？？
class timer;
class gameserver;
struct tabeinfo
{
    std::array< std::shared_ptr<player>, 4> table_player;

    int isReady =0;
    std::shared_ptr<timer> timers;
    std::shared_ptr<gameserver> gsX;
};
class lobby  :public std::enable_shared_from_this<lobby>{
public://方法
    lobby();

    ~lobby()
    {}
    //addaplayer 添加一个玩家
    //delaplayer  移除一个玩家
    //stargameserver( teebid)
    //
    std::shared_ptr<player> addaplayer(std::shared_ptr<PB::Client_Server::Login> t);
    int delaplayer(std::shared_ptr<PB::Client_Server::Logout> t);

    int sitDown(std::shared_ptr<PB::Client_Server::SitDown> t);
    int Ready(std::shared_ptr<PB::Client_Server::Ready> t);

    void doReady(int ta);
    void addSerevr(int ta);
    void delecXX(int ta);

public: //变量

    // 0  父类指针
    void* serverptr;
    //1 玩家信息
    std::map<int , std::shared_ptr<player> > playerInfo;
    //进大厅玩家可以不在座子上  key 值 保存玩家的 token
    //1 座子信息
    // 改成指针     可以把指针 传递给 游戏服
    std::map<int , std::shared_ptr<tabeinfo> > tableinfo;
    //?? 座子状态？？
};


#endif //EPOLLDEMO_LOBBY_H
