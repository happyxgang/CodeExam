#include "user_data_parser.h"
namespace codemaster{
Data UserDataParser::convert(std::string data_str){
	void* data_ptr = _parser_func(data_str);
	Data d;
	d.set_data(data_ptr);
	return d;
}
}