#ifndef ARRAY_ELEMENT_H
#define ARRAY_ELEMENT_H

#include "array_element.h"
#include "array_parser.h"
#include "element.h"

namespace codemaster{

class ArrayElement:public Element{
public:
	ArrayElement(Parser* parser) : Element(new ArrayParser(parser)){}
	~ArrayElement(){}
private:
};

}
#endif