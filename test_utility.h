#ifndef TEST_UTILITY_H
#define TEST_UTILITY_H

#include <gtest/gtest.h>
#include "utility.h"

using namespace codemaster;
class test_utility:public::testing::Test{
public:
	virtual void SetUp(){
		
	}
};
TEST_F(test_utility, test_is_int){
	EXPECT_TRUE(is_int("123"));
	EXPECT_TRUE(is_int("+123"));
	EXPECT_TRUE(is_int("-123"));
	EXPECT_FALSE(is_int("a1213"));
	EXPECT_FALSE(is_int("12.13"));
	//TODO: overflo detection
	//EXPECT_FALSE(is_int("5555555555555555555555"));
	//EXPECT_FALSE(is_int("-5555555555555555555555"));
}
TEST_F(test_utility, test_is_float){
	EXPECT_TRUE(is_float("123"));
	EXPECT_TRUE(is_float("123.0"));
	EXPECT_TRUE(is_float("123."));
	EXPECT_TRUE(is_float("0.123"));
	EXPECT_TRUE(is_float(".123"));
	EXPECT_FALSE(is_float("a123"));
	EXPECT_FALSE(is_float("."));
}
TEST_F(test_utility, test_is_uint32){
	EXPECT_TRUE(is_uint32("123"));
	EXPECT_TRUE(is_uint32("+123"));
	EXPECT_FALSE(is_uint32("-123"));
}
TEST_F(test_utility, test_is_uint64){

	EXPECT_TRUE(is_uint64("123"));
	EXPECT_TRUE(is_uint64("+123"));
	EXPECT_FALSE(is_uint64("-123"));
}
TEST_F(test_utility, test_to_int){
	EXPECT_EQ(123, to_int("123"));
	EXPECT_EQ(123, to_int("+123"));
	EXPECT_EQ(-123, to_int("-123"));
	EXPECT_EQ(123, to_int("123"));
}
TEST_F(test_utility, test_to_uint32){
	EXPECT_EQ(123, to_uint32("123"));
}
TEST_F(test_utility, test_to_uint64){
	EXPECT_EQ(123, to_uint64("123"));
}
#endif