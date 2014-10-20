#ifndef TEST_UTILITY_H
#define TEST_UTILITY_H

#include <string>

#include <gtest/gtest.h>
#include "utility.h"
#include <math.h>

using std::string;
using namespace codemaster;
class test_utility:public::testing::Test{
public:
	virtual void SetUp(){
		
	}
};

TEST_F(test_utility, trim){
	string left = "   123";
	string both = "  123   ";
	string right = "123   ";
	string target = "123";

	EXPECT_EQ(target, trim(left));
	EXPECT_EQ(target, trim(both));
	EXPECT_EQ(target, trim(right));
}
TEST_F(test_utility, is_int){
	EXPECT_TRUE(is_int("123"));
	EXPECT_TRUE(is_int("+123"));
	EXPECT_TRUE(is_int("-123"));
	EXPECT_FALSE(is_int("a1213"));
	EXPECT_FALSE(is_int("12.13"));
}

TEST_F(test_utility, to_int){
	EXPECT_EQ(123, to_int("123"));
	EXPECT_EQ(123, to_int("+123"));
	EXPECT_EQ(-123, to_int("-123"));
	EXPECT_EQ(123, to_int("123"));
}

TEST_F(test_utility, is_uint32){
	EXPECT_TRUE(is_uint32("123"));
	EXPECT_TRUE(is_uint32("+123"));
	EXPECT_FALSE(is_uint32("-123"));
}
TEST_F(test_utility, to_uint32){
	EXPECT_EQ(123, to_uint32("123"));
}

TEST_F(test_utility, is_uint64){

	EXPECT_TRUE(is_uint64("123"));
	EXPECT_TRUE(is_uint64("+123"));
	EXPECT_FALSE(is_uint64("-123"));
}
TEST_F(test_utility, to_uint64){
	EXPECT_EQ(123, to_uint64("123"));
}


TEST_F(test_utility, is_float){
	EXPECT_TRUE(is_float("123"));
	EXPECT_TRUE(is_float("123.0"));
	EXPECT_TRUE(is_float("123."));
	EXPECT_TRUE(is_float("0.123"));
	EXPECT_TRUE(is_float(".123"));
	EXPECT_FALSE(is_float("a123"));
	EXPECT_FALSE(is_float("."));
}
TEST_F(test_utility, to_float){
	EXPECT_TRUE(std::abs(to_float("123.123") - 123.123) < 0.01);
	EXPECT_TRUE(std::abs(to_float(".123") - 0.123) < 0.01);
	EXPECT_TRUE(std::abs(to_float("123.") - 123) < 0.01);
	EXPECT_TRUE(std::abs(to_float("123123") - 123123) < 0.01);
}
#endif