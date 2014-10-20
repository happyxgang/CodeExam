#ifndef UINT32_ELEMENT_H
#define UINT32_ELEMENT_H
#include <iostream>
#include "element.h"
#include "uint32_parser.h"
namespace codemaster{
	class UInt32Element : public Element{
	public:
		// TODO: parser can be replace by global single instance
		UInt32Element() :Element(new UInt32Parser()){}
		~UInt32Element(){}
	private:
	};
}
#endif