//
// Created by lihp on 2022/4/21.
//

#ifndef ALL_CONNCLIENT_H
#define ALL_CONNCLIENT_H
#include "connHandle.h"
#include <iostream>
#include <unistd.h>
#include <string>
#include <string.h>
#include "serverApp.h"
#include "pbhead.h"
class connClient : public std::enable_shared_from_this<connClient> ,public connHandle{
public:
    connClient();

    ~connClient();
    char *  recvData; //缓存 收到的数据
    int recvlen,recvend;
    // 记录 一下 连接信息 连接的谁
    std::string m_oppositeIP;
    int m_oppositePort;

    //connect or accept
    void callbackRead() override;

    void callbackWrite()override;
    void Write();
    void DealData();
    void connWrite(int id, std::shared_ptr<google::protobuf::Message>   msg);
};


#endif //ALL_CONNCLIENT_H
