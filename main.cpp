#include <iostream>
#include <string>
#include "int_element.h"
#include "pattern.h"
using std::cout;
using std::endl;

using codemaster::IntElement;
using codemaster::Pattern;

int main(){
	Pattern pattern;

	IntElement ele_int;

	// template vs parameter
	//ArrayElement<IntElement> ele_arr;

	//UseDataElement ele_usr(func);

	pattern.append(ele_int);
	pattern.append(ele_int);

	//pattern.set(2, ele_arr);
	
	std::string file = "/home/kevin/data";

	// why use pattern like this;
	Analyzer analyzer(pattern, file);
	
	//Analyzer::iterator itr_start = analyzer.start();
	//Analyzer::iterator itr_end = analyzer.end();

	//while (itr_start != itr_end){
	//	RowElements rwo = *itr_start;
	//	
	//}


	// num_skip == 0 means normal end
	// num_skip == 1 means normal next row
	// num_skip  > 1 means skip num_skip row get a right output
	// num_skip < 0 means skip num_skip row and reach the end with out a right output
	int num_skip = 1;

	while (num_skip != 0) {
		RowElements row = analyzer.next_row(num_skip);

		if (num_skip > 0){
			cout << "parse " << num_skip << "lines" << endl;
			cout << (int) row.get_value(1) << endl;
			cout << (int) row.get_value(2) << endl;
		} else if (num_skip < 0){
			cout << "skip " << -num_skip << "lines" << endl;
			cout << "reach end" << endl;
		} else {// num_skip == 0
			cout << "ends successful" << endl;
		}
	}
	return 0;
}