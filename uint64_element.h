#ifndef UINT64_ELEMENT_H
#define UINT64_ELEMENT_H
#include <iostream>
#include "element.h"
#include "uint64_parser.h"
namespace codemaster{
class UInt64Element : public Element{
public:
	// TODO: parser can be replace by global single instance
	UInt64Element() : Element(new UInt64Parser()){}
	~UInt64Element(){}
private:
};
}
#endif