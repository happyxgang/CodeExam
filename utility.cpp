#include "utility.h"

#include <sstream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::istringstream;

namespace codemaster{

vector<string> split(string line, char delim){
	vector<string> items;
	string item;
	istringstream ss(line);
	while (std::getline(ss, item, delim)) {
		items.push_back(item);
	}
	return items;
}

// TODO: need to be improved
bool is_int(string data_str){
	string::const_iterator it = data_str.begin();
	while (it != data_str.end() && isdigit(*it)){
		++it;
	}
	// not empty and all chars are digit 
	return !data_str.empty() && it == data_str.end();
}

// TODO: need to be improved
bool is_uint(string data_str){
	return is_int(data_str);
}

bool is_float(string data_str){
	return 0.0;
}

}