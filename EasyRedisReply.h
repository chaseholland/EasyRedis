//
// Created by chase on 4/28/15.
//

#ifndef EASYREDISREPLY_H
#define EASYREDISREPLY_H

#include <hiredis/hiredis.h>
#include <string>


class EasyRedisReply {
    private:
        redisReply* m_reply;
    public:
        EasyRedisReply(redisReply* reply);
        ~EasyRedisReply();
        const redisReply* raw_redis_reply();
};


#endif //EASYREDISREPLY_H
