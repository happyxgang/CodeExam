#include "uint32_parser.h"

#include <ctype.h> 
#include <string>
#include "utility.h"
using std::string;
namespace codemaster{
	// WARNING:	1.only works for positive number without pre or post spaces
	//						2.limit not checked, string can exceed the int size
	// TODO: make it more universal
	bool UInt32Parser::validate(std::string data_str){
		return is_uint32(data_str);
	}

	Data UInt32Parser::convert(string data_str){
		// simple convert using atoi 
		Data data(DATA_UINT32);
		uint32* val = new uint32;
		*val = to_uint32(data_str);
		data.set_data((void*)val);
		return data;
	}
}