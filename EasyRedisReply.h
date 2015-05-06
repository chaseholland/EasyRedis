//
// Created by chase on 4/28/15.
//

#ifndef EASYREDISREPLY_H
#define EASYREDISREPLY_H

#include <hiredis/hiredis.h>
#include <string>


namespace easyredis
{
    class EasyRedisReply {
    private:
        redisReply* m_reply;
    public:
        EasyRedisReply(redisReply* reply);
        ~EasyRedisReply();

        //
        /// \brief getter for raw redis reply from hiredis
        //
        const redisReply* raw_redis_reply();

        //
        /// \brief Converts redis reply to a string
        /// \return Returns an empty string "" if there was an error, else a string represention of the response.
        /// \note REDIS_REPLY_ARRAY is not currently supported and will return an empty string. Use raw_redis_reply() for now.
        //
        const std::string as_string();

        //
        /// \brief
        //
        const double as_double();
    };
}


#endif //EASYREDISREPLY_H
