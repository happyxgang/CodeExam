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

#include "test_int_parser.h"
#include "test_user_data_parser.h"
//#include "test_array_parser.h"
//#include "test_analyzer.h"
//#include "test_utility.h"

using std::cout;
using std::endl;
using std::vector;
using codemaster::IntElement;
using codemaster::Pattern;
using codemaster::DataStream;
using namespace codemaster;
//bool test_data_stream(){
//	std::string file = "D://test_data_stream.txt";
//	DataStream ds(file);
//	std::vector<std::string> items; 
//	ds.next_line(items);
//	assert(items.size() == 2);
//	cout << "test data stream passed" << endl;
//	return true;
//}
//bool test_int_parser(){
//	std::string file = "D://test_data_stream.txt";
//	Pattern p;
//	IntElement* ele_int1 = new IntElement();
//	IntElement* ele_int2 = new IntElement();
//	
//	p.append(ele_int1);
//	p.append(ele_int2);
//	
//	Analyzer analyzer(p, file);
//	int skip_num = 0;
//	RowData rd = analyzer.next_row(skip_num);
//	
//	Data d;
//	if (rd.get(1, d)){
//		cout << *(int*)*d << endl;
//	}
//	if (rd.get(0, d)){
//		cout << *(int*)*d << endl;
//	}
//	return true;
//}
//bool test_data(){
//	Data d;
//	int* p = new int(127);
//	d.set_data((void*)p);
//	int *p2 = (int*)*d;
//	cout << *p2 << endl;
//	return 0;
//}
//SharedPtr<void*> test_make_shared(void* p){
//	SharedPtr<void*> shared_ptr;
//	shared_ptr.set_val(p);
//	return shared_ptr;
//}
//bool test_shared_ptr(){
//	int* a = new int(32);
//	SharedPtr<void*> p = test_make_shared((void*)a);
//	cout << *((int*)*p) << endl;
//	return true;
//}
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