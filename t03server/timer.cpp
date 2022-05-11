//
// Created by lihp on 2022/4/26.
//

#include "timer.h"
timer::timer(int64_t lastTime, int cycleNumber, int64_t cycletime, std::function<void()> _callback) {
std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();  //系统运行了的时间
lastTimepos = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() + lastTime;

this->cycleNumber = cycleNumber;
this->cycletime = cycletime;
this->_callback = _callback;
isRun = true;
std::cout << "timer" << std::endl;
}

timer::~timer() {
    std::cout << " ~timer" << std::endl;
}

void timer::stop() {
    isRun = false;
}

void timer::timeOut() {
    if(!isRun) return;
    std::cout << "timeOut" <<cycleNumber<< std::endl;
    _callback();//如果多线程 这个建议放到多线程里面去
    if (cycleNumber == 0) {
        isRun = false;
    }
    //设置下一次定时的变量
    if (isRun && cycleNumber != 0) {


        std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();
        int64_t nowpos = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

        while (nowpos > lastTimepos)
            //本来 2分钟执行一次的 如果 这次执行的时间点 就过了很长时间 （如10分钟） 那么下一次
            // 不可能是当前时间以前的时间了  缺的几次  不补
        {
            lastTimepos += cycletime;
        }
        if (cycleNumber > 0)cycleNumber--;
    }
}