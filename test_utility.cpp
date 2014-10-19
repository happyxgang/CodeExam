#include "gtest/gtest.h"
#include "utility.h"
using namespace codemaster;
class test_utility:public::testing::Test{
public:
	virtual void SetUp(){
		
	}

};
TEST_F(test_utility, test_is_int){
	ASSERT_TRUE(is_int("123"));
	ASSERT_TRUE(is_int("+123"));
	ASSERT_TRUE(is_int("-123"));
	ASSERT_FALSE(is_int("a1213"));
	ASSERT_FALSE(is_int("12.13"));
	ASSERT_FALSE(is_int("5555555555555555555555"));
	ASSERT_FALSE(is_int("-5555555555555555555555"));
}
TEST_F(test_utility, test_is_float){
	ASSERT_TRUE(is_float("123"));
	ASSERT_TRUE(is_float("123.0"));
	ASSERT_TRUE(is_float("123."));
	ASSERT_FALSE(is_float("a123"));
}