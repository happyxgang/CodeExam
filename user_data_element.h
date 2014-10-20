#ifndef USER_DATA_H
#define USER_DATA_H
#include <string>
#include "element.h"
#include "user_data_parser.h"
namespace codemaster{
class UserDataElement :public Element{
public:
	UserDataElement():Element(new UserDataParser(ParserFunc func)){}
	~UserDataElement(){}
private:
};

}
#endif