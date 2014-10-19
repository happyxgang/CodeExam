#include "int_parser.h"

#include <ctype.h> 
#include <string>
#include "utility.h"
using std::string;
namespace codemaster{
// WARNING:	1.only works for positive number without pre or post spaces
//						2.limit not checked, string can exceed the int size
// TODO: make it more universal
bool IntParser::validate(std::string data_str){
	return is_int(data_str);
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