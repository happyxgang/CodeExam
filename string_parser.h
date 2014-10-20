#ifndef STRING_PARSER_H
#define STRING_PARSER_H
#include <string>
#include "parser.h"
namespace codemaster{

class StringParser : public Parser{
public:
	Data convert(std::string data_str);
	~StringParser(){}
private:

};

}
#endif