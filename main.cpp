#include <assert.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "array_parser.h"
#include "analyzer.h"
#include "data_stream.h"
#include "int_element.h"
#include "int_parser.h"
#include "pattern.h"

using std::cout;
using std::endl;
using std::vector;
using codemaster::IntElement;
using codemaster::Pattern;
using codemaster::DataStream;
using namespace codemaster;
bool test_data_stream(){
	std::string file = "D://test_data_stream.txt";
	DataStream ds(file);
	std::vector<std::string> items; 
	ds.next_line(items);
	assert(items.size() == 2);
	cout << "test data stream passed" << endl;
	return true;
}
bool test_int_parser(){
	std::string file = "D://test_data_stream.txt";
	Pattern p;
	IntElement* ele_int1 = new IntElement();
	IntElement* ele_int2 = new IntElement();
	
	p.append(ele_int1);
	p.append(ele_int2);
	
	Analyzer analyzer(p, file);
	int skip_num = 0;
	RowData rd = analyzer.next_row(skip_num);
	
	Data d;
	if (rd.get(1, d)){
		cout << *(int*)*d << endl;
	}
	if (rd.get(0, d)){
		cout << *(int*)*d << endl;
	}
	return true;
}
bool test_data(){
	Data d;
	int* p = new int(127);
	d.set_data((void*)p);
	int *p2 = (int*)*d;
	cout << *p2 << endl;
	return 0;
}
SharedPtr<void*> test_make_shared(void* p){
	SharedPtr<void*> shared_ptr;
	shared_ptr.set_val(p);
	return shared_ptr;
}
bool test_shared_ptr(){
	int* a = new int(32);
	SharedPtr<void*> p = test_make_shared((void*)a);
	cout << *((int*)*p) << endl;
	return true;
}
class test_array :public ::testing::Test{
public:
	test_array() :array_parser(new IntParser()){}
	virtual void SetUp(){
		bool valid = array_parser.parse("3:1,2,3", d);
	}
	ArrayParser array_parser;
	Data d;
};
TEST_F(test_array, array_int){
	vector<Data> val = *((vector<Data>*)*d);
	ASSERT_EQ(val.size(), 3);
	int val1 = *((int*)*val[0]);
	ASSERT_EQ(val1, 1);

	int val2 = *((int*)*val[1]);
	ASSERT_EQ(val2, 2);

	int val3 = *((int*)*val[2]);
	ASSERT_EQ(val3, 3);
}
TEST(utility_test,convert_test ){
}

TEST(utility_test,is_test){
	
}
int main(int argc, char* argv[]){
	
	//test_data_stream();
	//test_data();
	//test_shared_ptr();
	//test_int_parser();

	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
	getchar();
	return 0;
}