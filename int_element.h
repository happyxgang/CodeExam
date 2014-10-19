#ifndef INT_ELEMENT_H
#define INT_ELEMENT_H
#include "element.h"
#include "int_parser.h"
namespace codemaster{
class IntElement:public Element{
public:
	// TODO: parser can be replace by global single instance
	IntElement() :Element(new IntParser()){}
	//TODO:check the right format: if there's a space between right parenthese and right brace;
private:
};
}
#endif
