#include "element.h"
using std::string;
namespace codemaster{

bool Element::convert(string str, Data& data){
	bool is_valid =_parser->parse(str, data);
	return is_valid;
}

}