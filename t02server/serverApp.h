//
// Created by lihp on 2022/4/21.
//

#ifndef ALL_SERVERAPP_H
#define ALL_SERVERAPP_H


#include "connHandle.h"
#include "timer.h"
#include <sys/epoll.h>
#include <memory>
#include <list>
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
private:
    int epoll_fd; //epoll的文件句柄
    bool isrun; //运行状态

    std::array<epoll_event, maxFiles> m_events;
    // std::array<std::shared_ptr<connHandle>, maxFiles> m_lihpHandles;
};


#endif //ALL_SERVERAPP_H
