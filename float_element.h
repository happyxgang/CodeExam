#ifndef FLOAT_ELEMENT_H
#define FLOAT_ELEMENT_H
#include <iostream>
#include "element.h"
#include "float_parser.h"
namespace codemaster{
class FloatElement : public Element{
public:
	// TODO: parser can be replace by global single instance
	FloatElement():Element(new FloatParser()){}
	~FloatElement(){}
private:
};
}
#endif
