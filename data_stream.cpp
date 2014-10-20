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
		exit(1);
	}
}
void DataStream::set_delimeter(char ch){
	this->_delimeter = ch;
}
char DataStream::_default_delimeter = '\t';

bool DataStream::next_line(vector<string>& items){
	string line;
	if (std::getline(this->_file, line)) {
		items = split(line, this->_delimeter);

		for (size_t index = 0; index < items.size(); index++){
			items[index] = trim(items[index]);
		}
	} else {
		return false;
	}
	return true;
}

}