//
// Created by lihp on 2022/4/21.
//

#ifndef ALL_CONNHANDLE_H
#define ALL_CONNHANDLE_H


class connHandle {

public: // 先全公有 后面改
    // 1 文件描述符
    int lihp_fd;
    // epollpos 的位置 和 父类指针 有绑定关系 实现双向绑定
    int epollpos;
    // 2  父类指针
    void* serverptr;
public:
    //  读回调函数 虚函数 子类要重写
    virtual  void callbackRead()
    {

    };
    virtual  void callbackWrite()
    {

    };

};


#endif //ALL_CONNHANDLE_H
