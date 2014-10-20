#include "float_parser.h"

#include <ctype.h> 
#include <string>
#include "data.h"
#include "utility.h"
using std::string;
namespace codemaster{
// WARNING:	1.only works for positive number without pre or post spaces
//						2.limit not checked, string can exceed the int size
// TODO: make it more universal
bool FloatParser::validate(std::string data_str){
	return is_float(data_str);
}

Data FloatParser::convert(string data_str){
	// simple convert using atoi 
	Data data(DATA_FLOAT);
	float* val = new float();
	*val = to_float(data_str);
	data.set_data((void*)val);
	return data;
}
}