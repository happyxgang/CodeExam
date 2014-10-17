#include <sstream>
#include "data_stream.h"
using std::string;
using std::vector;
using std::ifstream;

namespace codemaster{

void DataStream::set_file(string filename){
	this->_file = ifstream(filename);
}
void DataStream::set_delimeter(char ch){
	this->_delimeter = ch;
}
DataStream DataStream::create(string filename){
	return create(filename, '\t');
}

// TODO: ensure return by value will not decrease function effiency use another method
DataStream DataStream::create(string filename, char ch){
	DataStream data_stream;
	data_stream.set_file(filename);
	data_stream.set_delimeter(ch);
	return data_stream;
}
void DataStream::split(string line, vector<string>& items){
		string item;
		std::stringstream ss(line);
		while (std::getline(ss, item, this->_delimeter)){
			items.push_back(item);
		}
}
int DataStream::next_line(vector<string>& items){
	string line;
	if (std::getline(this->_file, line)){
		split(line, items);
	}
	return 0;
}
}