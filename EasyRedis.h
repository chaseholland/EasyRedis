//
// Created by chase on 4/28/15.
//

#ifndef EASYREDIS_H
#define EASYREDIS_H

#include <string>
#include <hiredis/hiredis.h>
#include "EasyRedisReply.h"

class EasyRedis
{
    private:
        std::string m_host;
        int m_port;
        redisContext* m_context;
    public:
        EasyRedis(std::string host, int port);
        ~EasyRedis();
        EasyRedisReply run_command(const char* command, ...);
        const redisContext* raw_redis_context();
};


#endif //EASYREDIS_H
