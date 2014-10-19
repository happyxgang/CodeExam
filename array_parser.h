#ifndef ARRAY_PARSER_H
#define ARRAY_PARSER_H
#include <string>
#include <vector>

#include "data.h"
#include "parser.h"
namespace codemaster{
class ArrayParser:public Parser{
public:
	ArrayParser(Parser* parser):_parser(parser),_array(new std::vector<Data>()){}
	bool validate(std::string data_str);
	Data convert(std::string data_str);
	~ArrayParser(){}
private:
	Parser* _parser;
	std::vector<Data>* _array;
};

}
#endif