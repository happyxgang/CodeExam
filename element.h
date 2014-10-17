#ifndef ELEMENT_H
#define ELEMENT_H
#include "parser.h"
namespace codemaster{
enum ElementType
{
	ELE_INT,
	ELE_FLOAT,
	ELE_STRING,
	ELE_ARRAY,
	ELE_UINT32,
	ELE_UINT64,
	ELE_USRDATA
};
class Element{
public:
	explicit Element(ElementType type, Parser parser) :_type(type),_parser(parser){}
	virtual ~Element(){}
private:
	ElementType _type;
	Parser _parser;
};

}
#endif