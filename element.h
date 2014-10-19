#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>

#include "parser.h"
namespace codemaster{
// TODO: if it is more proper to use template to replace inheritance and how
class Element{
public:
	Element(Parser* parser) :_parser(parser){}
	virtual ~Element(){ std::cout << "deconstructor in Element" << std::endl; delete _parser; }

	// convert from str to proper data using _parser
	bool convert(std::string str, Data& data);
private:
	Parser* _parser;
};

}
#endif