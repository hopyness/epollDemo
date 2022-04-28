//
// Created by lihp on 2022/4/21.
//

#ifndef ALL_CONNSERVER_H
#define ALL_CONNSERVER_H
#include "connHandle.h"

class connServer : public connHandle{
public:
    connServer();

    void callbackRead() override;
    void callbackWrite()override;
    void creatFd(int const & port);
};


#endif //ALL_CONNSERVER_H
