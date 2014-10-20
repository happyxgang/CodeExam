#ifndef STRING_ELEMENT_H
#define STRING_ELEMENT_H
#include <iostream>
#include "element.h"
#include "string_parser.h"
namespace codemaster{
class StringElement : public Element{
public:
	// TODO: parser can be replace by global single instance
	StringElement() :Element(new StringParser()){}
	~StringElement(){}
private:
};
}
#endif
