//
// Created by chase on 5/5/15.
//

#pragma once

#ifndef EASYREDIS_TEST_EASYREDIS_FIXTURE_H
#define EASYREDIS_TEST_EASYREDIS_FIXTURE_H

#include "gtest/gtest.h"
#include "../EasyRedis.h"

const std::string test_key_base = "EASYREDISTEST_";
const std::string test_key_set = test_key_base + "A";
const std::string test_value = test_key_base + "B";
const std::string test_key_not_set = test_key_base + "C";

class EasyRedisTest: public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        ;
    }
    virtual ~EasyRedisTest()
    {
        EasyRedis easyRedis = EasyRedis("localhost", 6379);
        easyRedis.run_command("DEL %s", test_key_set.c_str());
    }
};

#endif //EASYREDIS_TEST_EASYREDIS_FIXTURE_H
