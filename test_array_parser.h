#ifndef TEST_ARRAY_PARSER_H
#define TEST_ARRAY_PARSER_H
#include <vector>

#include <gtest/gtest.h>

#include "array_parser.h"
#include "data.h"
#include "int_parser.h"
using std::vector;
using namespace codemaster;
class test_array_parser :public ::testing::Test{
public:
	test_array_parser() :parser(new IntParser()){}
	ArrayParser parser;
};

TEST_F(test_array_parser, int_array_validate){
	ASSERT_TRUE(parser.validate("3:1,2,3"));
	ASSERT_FALSE(parser.validate("2:1,2,3"));
	ASSERT_FALSE(parser.validate("4:1,2,3"));
	ASSERT_FALSE(parser.validate("3,1,2,3"));
	ASSERT_FALSE(parser.validate("3:1:2,3"));
	ASSERT_FALSE(parser.validate("3:1,,3"));
}
TEST_F(test_array_parser, int_array_convert) {
	Data d = parser.convert("3:1,2,3");
	vector<Data> array = *(vector<Data>*)*d;
	Data d0 = array[0];
	Data d1 = array[1];
	Data d2 = array[2];
	int val0 = *(int*)*d0;
	int val1 = *(int*)*d1;
	int val2 = *(int*)*d2;
	ASSERT_EQ(val0, 1);
	ASSERT_EQ(val1, 2);
	ASSERT_EQ(val2, 3);
}
#endif