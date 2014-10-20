#ifndef TEST_INT_PARSER_H
#define TEST_INT_PARSER_H
#include <gtest/gtest.h>
#include "int_parser.h"
using namespace codemaster;
class test_int_parser :public ::testing::Test{
public:
	virtual void SetUp(){

	}
	IntParser parser;
};
TEST_F(test_int_parser, validate){
	ASSERT_TRUE(parser.validate("123"));
	ASSERT_TRUE(parser.validate("-123"));
	ASSERT_TRUE(parser.validate("+123"));
}
TEST_F(test_int_parser, convert){

}
#endif