#include "string_parser.h"

#include <ctype.h> 
#include <string>
#include "utility.h"
using std::string;
namespace codemaster{

Data StringParser::convert(string data_str){
	// simple convert using atoi 
	Data data(DATA_STRING);
	string* str = new string();
	*str = data_str;
	data.set_data((void*)str);
	return data;
}

}