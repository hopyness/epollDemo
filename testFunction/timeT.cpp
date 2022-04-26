//
// Created by lihp on 2022/4/26.
//

#include <chrono>
#include <iomanip>
#include <thread>
#include <iostream>
#include <unistd.h>
void testtime1()
{
    //steady_clock
    std::chrono::time_point<std::chrono::steady_clock> now1=std::chrono::steady_clock::now();  //系统运行了的时间

    std::chrono::milliseconds t(1000*5);
    int64_t  xxx=std::chrono::duration_cast<std::chrono::milliseconds>(now1.time_since_epoch()).count()+1000*5;

    usleep(4520);
    std::chrono::time_point<std::chrono::steady_clock> now2=std::chrono::steady_clock::now();
    int64_t  xxx2=std::chrono::duration_cast<std::chrono::milliseconds>(now2.time_since_epoch()).count();
    if(xxx2-xxx>=0)
    {
        std::cout<<"do 111"<<std::endl;
    } else
    {
        std::cout<<"no do 111"<<std::endl;
    }
    usleep(4520);
    std::chrono::time_point<std::chrono::steady_clock> now3=std::chrono::steady_clock::now();
    int64_t  xxx3=std::chrono::duration_cast<std::chrono::milliseconds>(now3.time_since_epoch()).count();
    if(xxx3-xxx>=0)
    {
        std::cout<<"do 222"<<std::endl;
    } else
    {
        std::cout<<"no do 222"<<std::endl;
    }
   /* std::chrono::nanoseconds
    std::chrono::microseconds
    std::chrono::milliseconds
    std::chrono::seconds
    std::chrono::minutes
    std::chrono::hours*/



}