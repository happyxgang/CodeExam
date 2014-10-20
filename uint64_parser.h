#ifndef UINT64_PARSER_H
#define UINT64_PARSER_H
#include "parser.h"
#include "data.h"
namespace codemaster{

class UInt64Parser : public Parser{
public:
	bool validate(std::string data_str);
	Data convert(std::string data_str);
	~UInt64Parser(){}
private:

};

}
#endif