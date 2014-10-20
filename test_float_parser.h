#ifndef TEST_FLOAT_PARSER_H
#define TEST_FLOAT_PARSER_H
#include <math.h>
#include <gtest/gtest.h>
#include "float_parser.h"
using namespace codemaster;
class test_float_parser :public ::testing::Test{
public:
	virtual void SetUp(){

	}
	FloatParser parser;
};
TEST_F(test_float_parser, validate){
	ASSERT_TRUE(parser.validate("123"));
	ASSERT_TRUE(parser.validate("123."));
	ASSERT_TRUE(parser.validate("123.123"));
	ASSERT_TRUE(parser.validate(".123"));
}
TEST_F(test_float_parser, convert){
	Data d = parser.convert("123.123");
	float f = *(float*)*d;
	ASSERT_TRUE(std::abs(f - 123.123) < 0.01);
}
#endif