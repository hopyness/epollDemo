//
// Created by lihp on 2022/5/11.
//

#ifndef EPOLLDEMO_GAMESERVER_H
#define EPOLLDEMO_GAMESERVER_H
#include <vector>
#include <set>
#include <map>
#include <memory>
struct tabeinfo;
class  lobby;
class timer;
class gameserver {
public:
    gameserver();
    ~gameserver();
    //初始化
    void init();
    //结束操作
    void gameoverDeal();

    //准备释放对象了
    void befordel();
    //定时函数
    void timefun1();
    void timefun2();
public:
    std::shared_ptr<tabeinfo> taneinfo;
    /*
     创建游戏服  创建一个游戏服务器  gs
     绑定  gs 与 大厅关系  是大厅的哪座的
     绑定 gs 座子的关系

     初始化 游戏信息 如 30分钟座子 还是 1小时座子
     玩家信息初始化 如  玩家钱-400  带入初始值=400
     //第一次 做 就是直接给不用旋转  在游戏中 推送三次 每次输赢结果  就直接结束  到 gs 析构 玩家重新回到座子上 进入非准备状态
     */
    int  alltime;
    std::shared_ptr<lobby> sp_b;
    void* serverptr;
    std::shared_ptr<timer> time1;
    std::shared_ptr<timer> time2;
    int gamewin;
    int tableid;

};


#endif //EPOLLDEMO_GAMESERVER_H
