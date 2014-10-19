#include <ctype.h> 
#include <string>
#include "int_parser.h"

using std::string;
namespace codemaster{
// WARNING:	1.only works for positive number without pre or post spaces
//						2.limit not checked, string can exceed the int size
// TODO: make it more universal
bool IntParser::validate(std::string data_str){
	string::const_iterator it = data_str.begin();
	while (it != data_str.end() && isdigit(*it)){
		++it;
	}
	// not empty and all chars are digit 
	return !data_str.empty() && it == data_str.end();
}

Data IntParser::convert(string data_str){
	// simple convert using atoi 
	Data data(DATA_INT);
	int* val = new int;
	*val = atoi(data_str.c_str());
	data.set_data((void*)val);
	return data;
}
}