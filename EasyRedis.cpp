//
// Created by chase on 4/28/15.
//

#include <stdexcept>
#include "EasyRedis.h"


EasyRedis::EasyRedis(std::string host, int port)
{
    this->m_context = redisConnect(host.c_str(), port);
    m_host = host;
    m_port = port;
}

EasyRedis::~EasyRedis()
{
    redisFree(m_context);
    m_context = NULL;
}

EasyRedisReply EasyRedis::run_command(const char* command, ...)
{
    va_list arglist;
    va_start(arglist, command);
    EasyRedisReply reply = EasyRedisReply((redisReply*)redisvCommand(m_context, command, arglist));
    va_end(arglist);

    return reply;
}

