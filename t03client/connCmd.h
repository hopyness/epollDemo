//
// Created by lihp on 2022/4/21.
//

#ifndef ALL_CONNCMD_H
#define ALL_CONNCMD_H

#include <iostream>
#include <unistd.h>
#include <string>
#include <string.h>

#include "connHandle.h"
#include "connClient.h"
class connCmd : public connHandle{
public:
    connCmd();

    ~connCmd();

    void callbackRead() override;

    void callbackWrite()override;

private:
    void CMDdo(const  char * x);
    std::shared_ptr<connClient> connClientX;
};



#endif //ALL_CONNCMD_H
