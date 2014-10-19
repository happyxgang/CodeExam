#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "data.h"
namespace codemaster{

class Parser{
public:
	Parser(){
	}
	virtual ~Parser(){};

	virtual bool validate(std::string data_str);
	virtual Data convert(std::string data_str);
	bool parse(std::string data_str, Data& val);
private:
};

}
#endif