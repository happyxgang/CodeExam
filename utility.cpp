#include "utility.h"

#include <sstream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::istringstream;

namespace codemaster{
template<typename T>
void str_to_number(string num_str, T& val){
	string::iterator itr = num_str.begin();
	bool minus = false;
	if (num_str[0] == '-'){
		minus = true;
		itr++;
	} else if (num_str[0] == '+'){
		itr++;
	}
	val = 0;
	while (itr != num_str.end()){
		val = val * 10 + (*itr - '0');
		itr++;
	}
}
vector<string> split(string line, char delim){
	vector<string> items;
	string item;
	istringstream ss(line);
	while (std::getline(ss, item, delim)) {
		items.push_back(item);
	}
	return items;
}
int to_int(string data_str){
	return atoi(data_str.c_str());
}
uint32 to_uint32(string data_str){
	uint32 val;
	str_to_number(data_str, val);
	return val;
}
uint64 to_uint64(string data_str){
	uint64 val;
	str_to_number(data_str, val);
	return val;
}

// TODO: need to be improved
bool is_int(string data_str){

	// empty string
	if (data_str.size() == 0){
		return false;
	}

	string::const_iterator itr = data_str.begin();
	bool minus = false;
	if (*itr == '-')
	{
		minus = true;
		itr++;
	} else if (*itr == '+'){
		itr++;
	}
	while (itr != data_str.end() && isdigit(*itr)){
		++itr;
	}
	// not empty and all chars are digit 
	return !data_str.empty() && itr == data_str.end();
}

// TODO: need to be improved
bool is_uint(string data_str){
	string::iterator itr = data_str.begin();
	if (*itr == '+'){
		itr++;
	}
	int num_count = 0;
	while (itr != data_str.end() && isdigit(*itr)){
		itr++;
		num_count++;
	}
	return num_count && itr == data_str.end();
}
bool is_uint32(string data_str){
	return is_uint(data_str);
}
bool is_uint64(string data_str){
	return is_uint(data_str);
}
bool is_float(string data_str){
	if (is_int(data_str)){
		return true;
	}

	int point_pos = data_str.find('.');

	// if not int, must have a '.' 
	if (point_pos == string::npos) {
		return false;
	}
	
	if (point_pos == 0){//.bbb
		return is_int(data_str.substr(1));
	} else if (point_pos == data_str.size() - 1){ // .aaa
		return is_int(data_str.substr(0, data_str.size() - 1));
	} else { // aaa.bbb format
		return is_int(data_str.substr(0, point_pos)) && is_int(data_str.substr(point_pos + 1));
	}
}

}