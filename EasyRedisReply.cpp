//
// Created by chase on 4/28/15.
//

#include "EasyRedisReply.h"
namespace easyredis {

    EasyRedisReply::EasyRedisReply(redisReply *reply)
    {
        m_reply = reply;
    }

    EasyRedisReply::~EasyRedisReply()
    {
        if (m_reply)
            freeReplyObject(m_reply);
        m_reply = NULL;
    }

    const redisReply *EasyRedisReply::raw_redis_reply()
    {
        return m_reply;
    }

    const std::string EasyRedisReply::as_string()
    {
        switch (m_reply->type) {
            case REDIS_REPLY_NIL:
                return "";
            case REDIS_REPLY_ERROR:
                return std::string(m_reply->str);
            case REDIS_REPLY_STRING:
                return std::string(m_reply->str);
            case REDIS_REPLY_INTEGER:
                return std::to_string(m_reply->integer);
            case REDIS_REPLY_ARRAY:
                return "";
        }
        return "";
    }

    const double EasyRedisReply::as_double()
    {
        switch (m_reply->type) {
            case REDIS_REPLY_NIL:
                return 0;
            case REDIS_REPLY_ERROR:
                return 0;
            case REDIS_REPLY_STRING:
                return std::stod(m_reply->str);
            case REDIS_REPLY_INTEGER:
                return m_reply->integer;
            case REDIS_REPLY_ARRAY:
                return 0;
        }
        return 0;
    }
}