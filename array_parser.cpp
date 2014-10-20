#include "array_parser.h"

#include <algorithm>
#include "utility.h"
using std::string;
using std::vector;
namespace codemaster{
bool ArrayParser::validate(string data_str){

	// find size delimter pos
	int size_pos_end = data_str.find(':');

	// check size delimeter
	if (size_pos_end == string::npos){
		return false;
	}

	// get size string
	string str_size = data_str.substr(0, size_pos_end);

	// size must be size_t type
	if (!is_uint(str_size)) {
		return false;
	}
	
	int size = atoi(str_size.c_str());
	
	string str_items = data_str.substr(size_pos_end + 1);
	vector<string> items = split(str_items, ',');
	
	if (items.size() != size){
		return false;
	}
	
	for (size_t i = 0; i < items.size(); i++) {
		if (!_parser->validate(items[i])){
			return false;
		}
	}
	return true;
}
Data ArrayParser::convert(std::string data_str){

	int size_pos_end = data_str.find(':');
	string str_size = data_str.substr(0, size_pos_end);
	int size = atoi(str_size.c_str());

	string str_items = data_str.substr(size_pos_end + 1);
	vector<string> items = split(str_items, ',');
	
	for (size_t i = 0; i < items.size(); i++) {
		_array->push_back(_parser->convert(items[i]));
	}

	Data data;
	data.set_data((void*)_array);
	return data;
}
}