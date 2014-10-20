#ifndef FLOAT_PARSER_H
#define FLOAT_PARSER_H
#include <string>
#include "parser.h"

namespace codemaster{

class FloatParser:public Parser{
public:
	bool validate(std::string data_str);
	Data convert(std::string data_str);
	~FloatParser(){}
private:

};

}
#endif
