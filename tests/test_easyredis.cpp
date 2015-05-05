//
// Created by chase on 5/4/15.
//

#include "test_easyredis.h"
#include "gtest/gtest.h"
#include "../EasyRedis.h"

TEST (EasyRedisTest, TestContextCreation)
{
    EasyRedis easyRedis = EasyRedis("localhost", 6379);
    EXPECT_TRUE(easyRedis.raw_redis_context() != NULL);
    ASSERT_EQ(easyRedis.raw_redis_context()->err, 0);
}

TEST (EasyRedisTest, TestCommand)
{
    EasyRedis easyRedis = EasyRedis("localhost", 6379);
}