#ifndef TEST_USER_DATA_PARSER_H
#define TEST_USER_DATA_PARSER_H
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "user_data_parser.h"
#include "utility.h"

using std::string;
using std::vector;
using namespace codemaster;

struct Point {
	int x;
	int y;
};

void* user_parser_func(std::string data_str){
	vector<string> items = split(data_str, ',');

	Point* p = new Point();
	p->x = to_int(items[0]);
	p->y = to_int(items[1]);

	return (void*)p;
}

class test_user_data_parser :public::testing::Test{
public:
	test_user_data_parser() : user_data_parser(user_parser_func){}
	UserDataParser user_data_parser;
};

TEST_F(test_user_data_parser, point){
	Data d;
	ASSERT_TRUE(user_data_parser.parse("1,2", d));
	Point* point_ptr = (Point*)*d;

	ASSERT_EQ(point_ptr->x, 1);
	ASSERT_EQ(point_ptr->y, 2);

}
#endif