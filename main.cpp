#include <assert.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "analyzer.h"
#include "data_stream.h"
#include "int_element.h"
#include "pattern.h"

using std::cout;
using std::endl;

using codemaster::IntElement;
using codemaster::Pattern;
using codemaster::DataStream;
using namespace codemaster;
void test_main(){
	//Pattern pattern;

	//IntElement ele_int;

	//// template vs parameter
	////ArrayElement<IntElement> ele_arr;

	////UseDataElement ele_usr(func);

	//pattern.append(ele_int);
	//pattern.append(ele_int);

	////pattern.set(2, ele_arr);

	//std::string file = "/home/kevin/data";

	//// why use pattern like this;
	//Analyzer analyzer(pattern, file);

	////Analyzer::iterator itr_start = analyzer.start();
	////Analyzer::iterator itr_end = analyzer.end();

	////while (itr_start != itr_end){
	////	RowElements rwo = *itr_start;
	////	
	////}


	//// num_skip == 0 means normal end
	//// num_skip == 1 means normal next row
	//// num_skip  > 1 means skip num_skip row get a right output
	//// num_skip < 0 means skip num_skip row and reach the end with out a right output
	//int num_skip = 1;

	//while (num_skip != 0) {
	//	RowElements row = analyzer.next_row(num_skip);

	//	if (num_skip > 0){
	//		cout << "parse " << num_skip << "lines" << endl;
	//		cout << (int)row.get_value(1) << endl;
	//		cout << (int)row.get_value(2) << endl;
	//	}
	//	else if (num_skip < 0){
	//		cout << "skip " << -num_skip << "lines" << endl;
	//		cout << "reach end" << endl;
	//	}
	//	else {// num_skip == 0
	//		cout << "ends successful" << endl;
	//	}
	//}
}
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
	//std::string file = "D://test_data_stream.txt";
	//Pattern p;
	//IntElement* ele_int1 = new IntElement();
	//IntElement* ele_int2 = new IntElement();
	//
	//p.append(ele_int1);
	//p.append(ele_int2);
	//
	//Analyzer analyzer(p, file);
	//int skip_num = 0;
	//RowData rd = analyzer.next_row(skip_num);
	//
	//Data d;
	//int ret = rd.get(1, d);
	//cout << (int)*d << endl;
	return true;
}
bool test_data(){
	Data d;
	int* p = new int(127);
	d.set_data((void*)p);
	int * p2 = (int*)*d;
	cout << p2 << endl;
	return 0;
}
bool test_shared_ptr(){
	int* a = new int(32);
	SharedPtr<void*> p;
	p.set_val((void*)a);
	SharedPtr<void*> p2=p;
	cout << *((int*)*p2) << endl;
	cout << *((int*)*p) << endl;
	return true;
}
int main(){
	//test_data_stream();
	//test_data();
	test_shared_ptr();
	getchar();
	return 0;
}