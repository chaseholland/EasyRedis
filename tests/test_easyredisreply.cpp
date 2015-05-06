//
// Created by chase on 5/5/15.
//

#include "gtest/gtest.h"
#include "../EasyRedis.h"
#include "test_easyredis_fixture.h"

using namespace easyredis;

TEST_F(EasyRedisTest, TestReplyStringString)
{
    EasyRedis easyRedis = EasyRedis("localhost", 6379);
    easyRedis.run_command("SET %s %s", test_key_set.c_str(), test_value.c_str());

    EasyRedisReply reply = easyRedis.run_command("GET %s", test_key_set.c_str());
    ASSERT_EQ(strcmp(reply.raw_redis_reply()->str, reply.as_string().c_str()), 0);
}

TEST_F(EasyRedisTest, TestReplyStringNumber)
{
    const double test_number = 1.0;
    EasyRedis easyRedis = EasyRedis("localhost", 6379);
    easyRedis.run_command("SET %s %f", test_key_set.c_str(), test_number);

    EasyRedisReply reply = easyRedis.run_command("GET %s", test_key_set.c_str());
    ASSERT_DOUBLE_EQ(std::stof(reply.raw_redis_reply()->str), std::stof(reply.as_string()));
}

TEST_F(EasyRedisTest, TestReplyNumber)