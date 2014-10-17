#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "element.h"
namespace codemaster{

class Parser{
public:
	Parser(){
	}
	virtual ~Parser();
	virtual bool validate(std::string data_str);
	virtual Element convert(std::string data_str);
	virtual bool parse(std::string data_str, Element& val);
private:
};

}
#endif