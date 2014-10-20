#ifndef TEST_ANALYZER_H
#define TEST_ANALYZER_H
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>

#include "analyzer.h"
#include "array_element.h"
#include "float_parser.h"
#include "int_element.h"
#include "pattern.h"
#include "string_element.h"
#include "string_parser.h"
#include "uint32_element.h"
#include "uint64_element.h"
#include "user_data_element.h"
#include "user_data_parser.h"
#include "utility.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;
using namespace codemaster;

class test_analyzer :public ::testing::Test{
public:
	void SetUp(){

	}
};
TEST_F(test_analyzer, int_int){
	Pattern p;
	Element* ele1 = new IntElement();
	Element* ele2 = new IntElement();
	
	p.append(ele1);
	p.append(ele2);

	string file_path = "test_22.txt";
	Analyzer analyzer(p, file_path);

	int skip_num;
	RowData rd = analyzer.next_row(skip_num);
	ASSERT_EQ(1, skip_num);

	Data d;
	ASSERT_TRUE(rd.get(0, d));
	int val0 = *(int*)*d;
	ASSERT_EQ(111,val0);

	ASSERT_TRUE(rd.get(1, d));
	int val1 = *(int*)*d;
	ASSERT_EQ(222, val1);
}

TEST_F(test_analyzer, string_int){
	Pattern p;
	Element* ele1 = new StringElement();
	Element* ele2 = new IntElement();
	
	p.append(ele1);
	p.append(ele2);

	string file_path = "test_22.txt";
	Analyzer analyzer(p, file_path);

	int skip_num;
	RowData rd = analyzer.next_row(skip_num);
	ASSERT_EQ(1, skip_num);
	Data d;

	ASSERT_TRUE(rd.get(0, d));
	string val0 = *(string*)*d;
	string target = "111";
	ASSERT_EQ(target, val0);

	ASSERT_TRUE(rd.get(1, d));
	int val1 = *(int*)*d;
	ASSERT_EQ(222, val1);
}

struct Point{
	uint32 x;
	uint64 y;
};
void* point_parser_func(string data_str){
	Point* ptr = new Point();
	vector<string> items = split(data_str, ',');

	ptr->x = to_uint32(items[0]);
	ptr->y = to_uint64(items[1]);

	return (void*)ptr;
}
TEST_F(test_analyzer, uint_userdata){
	Pattern pattern;
	Element* ele1 = new UInt32Element();
	Element* ele2 = new UserDataElement(point_parser_func);

	pattern.append(ele1);
	pattern.append(ele2);

	string file_path = "test_int_point.txt";
	Analyzer analyzer(pattern, file_path);

	int skip_num;
	RowData rd = analyzer.next_row(skip_num);
	ASSERT_EQ(1, skip_num);
	Data d;

	ASSERT_TRUE(rd.get(0, d));
	int val0 = *(int*)*d;
	ASSERT_EQ(111, val0);

	ASSERT_TRUE(rd.get(1, d));
	Point p = *(Point*)*d;
	ASSERT_EQ(100, p.x);
	ASSERT_EQ(200, p.y);

}
TEST_F(test_analyzer, float_array_int){
	Pattern p;
	Element* ele1 = new ArrayElement(new FloatParser());
	Element* ele2 = new IntElement();

	p.append(ele1);
	p.append(ele2);

	string file_path = "test_float_array_int.txt";
	Analyzer analyzer(p, file_path);
	
	int skip_num;
	RowData rd = analyzer.next_row(skip_num);
	ASSERT_EQ(1, skip_num);
	Data d;

	ASSERT_TRUE(rd.get(0, d));
	vector<Data> array = *(vector<Data>*)*d;
	ASSERT_EQ(3, array.size());
	float f1 = *(float*)*array[0];
	float f2 = *(float*)*array[1];
	float f3 = *(float*)*array[2];
	ASSERT_TRUE(std::abs(123.123-f1) < 0.001);
	ASSERT_TRUE(std::abs(0.01 - f2) < 0.001);
	ASSERT_TRUE(std::abs(111 - f3) < 0.001);

	ASSERT_TRUE(rd.get(1, d));
	int val1 = *(int*)*d;
	ASSERT_EQ(222, val1);
}
#endif