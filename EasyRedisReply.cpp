//
// Created by chase on 4/28/15.
//

#include "EasyRedisReply.h"

EasyRedisReply::EasyRedisReply(redisReply* reply)
{
    m_reply = reply;
}

EasyRedisReply::~EasyRedisReply()
{
    freeReplyObject(m_reply);
    m_reply = NULL;
}

const redisReply* EasyRedisReply::raw_redis_reply()
{
    return m_reply;
}