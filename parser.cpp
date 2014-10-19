#include "parser.h"

#include <string>
namespace codemaster{
bool Parser::parse(std::string data_str, Data& val){
	if (validate(data_str)){
		val = convert(data_str);
		return true;
	} else{
		return false;
	}
}

bool Parser::validate(std::string data_str){
	return true;
}
Data Parser::convert(std::string data_str){
	return Data();
}

}