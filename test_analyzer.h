#ifndef TEST_ANALYZER_H
#define TEST_ANALYZER_H
#include <gtest/gtest.h>

#include <string>
#include <iostream>

#include "analyzer.h"
#include "int_element.h"
#include "pattern.h"

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
	IntElement* ele1 = new IntElement();
	IntElement* ele2 = new IntElement();
	
	p.append(ele1);
	p.append(ele2);
	string file_path = "test_analyzer_int_int.txt";
	Analyzer analyzer(p, file_path);
	int skip_num;
	RowData rd = analyzer.next_row(skip_num);
	Data d;
	if (rd.get(0, d)){
		int val0 = *(int*)*d;
		ASSERT_EQ(val0, 111);
	}
	if (rd.get(1, d)){
		int val1 = *(int*)*d;
		ASSERT_EQ(val1, 222);
	}
}
#endif