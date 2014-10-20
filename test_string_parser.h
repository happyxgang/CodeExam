#ifndef TEST_STRING_PARSER_H
#define TEST_STRING_PARSER_H

#include <string>

#include <gtest/gtest.h>

#include "string_parser.h"

using std::string;
using namespace codemaster;

class test_string_parser :public ::testing::Test{
public:

	StringParser parser;
};
TEST_F(test_string_parser, validate){
	EXPECT_TRUE(parser.validate("string"));
}
TEST_F(test_string_parser, convert){
	string data_str = "abc";
	Data d = parser.convert(data_str);
	string str = *(string*)*d;
	ASSERT_EQ(str, data_str);
}
#endif