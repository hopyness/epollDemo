//
// Created by lihp on 2022/4/28.
//

#ifndef EPOLLDEMO_PBDATA_H
#define EPOLLDEMO_PBDATA_H
#include "pbhead.h"

class pbData {
public:
    int len;
    int type;

    std::shared_ptr<google::protobuf::Message> tpd;
    char* senddata;
    char * getData()
    {
        std::string buff{};
        tpd->SerializeToString(&buff);
        int xx=buff.length();

        return  senddata;
    };
};


#endif //EPOLLDEMO_PBDATA_H
