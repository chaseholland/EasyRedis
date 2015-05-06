//
// Created by chase on 5/4/15.
//

#include "gtest/gtest.h"
#include "../EasyRedis.h"
#include "test_easyredis_fixture.h"

using namespace easyredis;

TEST_F (EasyRedisTest, TestContextCreation)
{
    EasyRedis easyRedis = EasyRedis("localhost", 6379);
    EXPECT_TRUE(easyRedis.raw_redis_context() != NULL);
    ASSERT_EQ(easyRedis.raw_redis_context()->err, 0);
}

TEST_F (EasyRedisTest, TestContextCreationFailure)
{
    EasyRedis easyRedis = EasyRedis("localhost", 6378);
    EXPECT_TRUE(easyRedis.raw_redis_context() != NULL);
    ASSERT_EQ(easyRedis.raw_redis_context()->err, 1);
}

TEST_F (EasyRedisTest, TestRunCommandReply)
{
    EasyRedis easyRedis = EasyRedis("localhost", 6379);
    EasyRedisReply setReply = easyRedis.run_command("SET %s %s", test_key_set.c_str(), test_value.c_str());
    EasyRedisReply getReply = easyRedis.run_command("GET %s", test_key_set.c_str());

    ASSERT_NE(setReply.raw_redis_reply()->type, REDIS_REPLY_ERROR);
    ASSERT_EQ(strcmp(test_value.c_str(), getReply.raw_redis_reply()->str), 0);
}

TEST_F (EasyRedisTest, TestRunCommandNoReply)
{
    EasyRedis easyRedis = EasyRedis("localhost", 6379);
    EasyRedisReply setReply = easyRedis.run_command("SET %s %s", test_key_set.c_str(), test_value.c_str());
    EasyRedisReply getReply = easyRedis.run_command("GET %s", test_key_not_set.c_str());


    ASSERT_NE(setReply.raw_redis_reply()->type, REDIS_REPLY_ERROR);
    ASSERT_EQ(getReply.raw_redis_reply()->type, REDIS_REPLY_NIL);
}