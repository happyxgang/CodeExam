#include "parser.h"
namespace codemaster{
bool Parser::parse(Element& val){
	if (validate(_data_str)){
		val = convert(_data_str);
		return true;
	} else{
		return false;
	}
}
}