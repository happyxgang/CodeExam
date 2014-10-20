#ifndef UINT32_PARSER_H
#define UINT32_PARSER_H
#include <string>
#include "parser.h"
namespace codemaster{
class UInt32Parser : public Parser{
public:
	bool validate(std::string data_str);
	Data convert(std::string data_str);
	~UInt32Parser(){}
private:

};

}
#endif