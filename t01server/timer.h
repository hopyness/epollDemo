//
// Created by lihp on 2022/4/26.
//

#ifndef EPOLLDEMO_TIMER_H
#define EPOLLDEMO_TIMER_H

#include <chrono>
#include <atomic>
#include <functional>
#include <iostream>

class timer {
    //定时器对象 需要 时间  循环周期  卧槽 时间 和 次数单词一样了
public:
    std::function<void()> _callback; //回调函数 只能是无参数 且无 返回的函数  写lambda 注意这一点就好了
    int64_t lastTimepos; //下一个执行的时间  毫秒

    int cycleNumber;//循环次数 // -1 无限循环  0 不循环  正数 循环这么多次后结束


    int64_t cycletime;  //间隔的时间 毫秒
    bool isRun;// 是否运行 如果不运行  在其他地方就可能被销毁 外接可以强制停止它
    //方法
    //构造函数
    timer(int64_t lastTime, int cycleNumber, int64_t cycletime, std::function<void()> _callback);

    ~timer();

    void stop() ;

    void timeOut() ;

};


#endif //EPOLLDEMO_TIMER_H
