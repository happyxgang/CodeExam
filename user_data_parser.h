#ifndef USER_DATA_PARSER_H
#define USER_DATA_PARSER_H
#include <string>

#include "parser.h"

namespace codemaster{
typedef void*(*ParserFunc)(std::string);
class UserDataParser : public Parser{
public:
	UserDataParser(ParserFunc parser_func) : _parser_func(parser_func){}
	Data convert(std::string data_str);
private:
	ParserFunc _parser_func;
};

}
#endif