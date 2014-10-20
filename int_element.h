#ifndef INT_ELEMENT_H
#define INT_ELEMENT_H
#include <iostream>
#include "element.h"
#include "int_parser.h"
namespace codemaster{
class IntElement : public Element{
public:
	// TODO: parser can be replace by global single instance
	IntElement() :Element(new IntParser()){}
	~IntElement(){}
private:
};
}
#endif
