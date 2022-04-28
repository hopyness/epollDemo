//
// Created by lihp on 2022/4/21.
//

#include "serverApp.h"
#include <iostream>
//构造函数
serverApp::serverApp() {
    isrun= false;
}
void serverApp::init() {
    m_lihpHandles.fill(nullptr);
    epoll_fd=epoll_create1(0);
    isrun=true;
}
void serverApp::run() {

    while (isrun) {

        int   nfds=epoll_wait(epoll_fd,m_events.data(),maxFiles,500);
        for(int i=0;i<nfds;++i) //处理所发生的所有事件
        {
            int  tt=m_events[i].data.u32;

            //m_lihpHandles[tt];//就是这个去处理消息

            //data.u32 在添加创建的epoll_event时候    查看m_lihpHandles 那个是空 就用他的数组序号复制  实现 id和指针对应
            if(m_events[i].events & EPOLLIN)
            {
                m_lihpHandles[tt]->callbackRead();//读信号 回调读函数
            }
            if(m_events[i].events & EPOLLOUT)
            {
                m_lihpHandles[tt]->callbackWrite();//写信号 回调写函数
            }

        }
    }
   // std::cout<<"isedn"<<std::endl;

}
//这个没有
void serverApp::endclear() {

}

bool serverApp::addConnHandle(std::shared_ptr<connHandle> shared_handle)
{
    int i=0;
    for(;i<maxFiles;i++)
    {
        if(m_lihpHandles[i]== nullptr)
        {
            m_lihpHandles[i] =shared_handle;
            // 这两个 先保留 好像没乱用
            shared_handle->epollpos =i;
            shared_handle->serverptr =this;
            struct epoll_event ev2;
            // data 的对象 居然是和联合体 不是结构体
            // ev2.data.ptr = 0;
            //ev2.data.fd = tt->lihp_fd;
            ev2.data.u32 = i;
            // Edge_triggered(边缘触发)     只有从不可 到可以 才触发
            // Level_triggered(水平触发)    只要是可以 就一直触发
            // EPOLLET  EPOLLLT  默认是LT  可以不写  也没有 EPOLLLT的宏
            ev2.events = EPOLLIN;  //只写输入  输出信号 必须 自己想写的时候在加
            epoll_ctl(epoll_fd, EPOLL_CTL_ADD, shared_handle->lihp_fd, &ev2);
            std::cout<<"shared_handle->lihp_fd"<<std::endl;
            return true;
        }
    }
    // 打印错误日志 epoll管理的文件描述符太多了
    return false;
}
bool serverApp::delConnHandlebyId(int id)
{
    //寻找到 对应的 Handle 在移除
    std::shared_ptr<connHandle> delHandle=  m_lihpHandles[id];
    //接触绑定
    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, delHandle->lihp_fd, nullptr);
    //清除容器的数据
    m_lihpHandles[id] = nullptr;
    std::cout<<"delConnHandlebyId"<<delHandle.use_count()<<std::endl;
    return true; //如果 找不到 对应的handle  应该就return FALSE
}
