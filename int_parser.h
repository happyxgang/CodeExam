#ifndef INT_PARSER_H
#define INT_PARSER_H
#include <string>
#include "parser.h"

namespace codemaster{

class IntParser:public Parser{
public:
	bool validate(std::string data_str);
	Data convert(std::string data_str);
	~IntParser(){}
private:

};

}
#endif