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
	return is_int(data_str);
}

bool is_float(string data_str){
	return 0.0;
}

}