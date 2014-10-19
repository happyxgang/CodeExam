#include "data_stream.h"

#include <iostream>
#include <sstream>

#include "utility.h"
using std::string;
using std::vector;
using std::ifstream;

namespace codemaster{

void DataStream::set_file(string filename){
	this->_file.open(filename);
	if (this->_file.fail()){
		// TODO: handle error properly
		std::cout << "set file failed" << std:: endl;
		exit(1);
	}
}
void DataStream::set_delimeter(char ch){
	this->_delimeter = ch;
}
//DataStream DataStream::create(string filename){
//	return create(filename, DataStream::_default_delimeter);
//}
//
//// TODO: ensure return by value will not decrease function effiency use another method
//DataStream DataStream::create(string filename, char ch){
//	DataStream data_stream;
//	data_stream.set_file(filename);
//	data_stream.set_delimeter(ch);
//	return data_stream;
//}
char DataStream::_default_delimeter = '\t';
//vector<string> DataStream::split(string line, char delim){
//	vector<string> items;
//	string item;
//	std::istringstream ss(line);
//	while (std::getline(ss, item, delim)) {
//		items.push_back(item);
//	}
//	return items;
//}

bool DataStream::next_line(vector<string>& items){
	string line;
	if (std::getline(this->_file, line)) {
		items = split(line, this->_delimeter);
	} else {
		return false;
	}
	return true;
}

}