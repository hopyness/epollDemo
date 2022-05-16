//
// Created by lihp on 2022/4/21.
//

#ifndef ALL_SERVERAPP_H
#define ALL_SERVERAPP_H
#include <sys/epoll.h>
#include <memory>
#include <list>
#include <random>

#include "connHandle.h"
#include "timer.h"

//#include "lobby.h"
class  lobby;
//最多添加的文件句柄 也是epoll add的最大值
constexpr int maxFiles=10000;
//APP 绑定 epoll  run 运行 就是 死循环调用epollwait
class serverApp {
public:
    serverApp();
    // 初始化
    void init();
    //运行
    void run();
    void stop()
    {
        isrun= false;
    }
    //结束后释放
    void endclear();
    //添加
    bool addConnHandle(std::shared_ptr<connHandle> shared_handle);
    //移除
    bool delConnHandlebyId(int id);
    //改成公有方便其他访问
    std::array<std::shared_ptr<connHandle>, maxFiles> m_lihpHandles;
    //定时器函数？
    std::list<std::shared_ptr<timer>>m_timerList;

    std::shared_ptr<lobby> sp_lobby;
private:

    int epoll_fd; //epoll的文件句柄
    bool isrun; //运行状态

    std::array<epoll_event, maxFiles> m_events;
    // std::array<std::shared_ptr<connHandle>, maxFiles> m_lihpHandles;

    //一些静态函数
public:
    static  int Rand(int a,int b)
    {
        return  std::uniform_int_distribution<int>(a, b)(e1);
    }
    static std::default_random_engine e1;

};

#endif //ALL_SERVERAPP_H
