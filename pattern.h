#ifndef PATTERN_H
#define PATTERN_H
#include <vector>
#include "element.h"
namespace codemaster{
class Pattern{
public:
	typedef std::vector<Element>::iterator iterator;

	void append(Element ele){
		ele_list.push_back(ele);
	}
	iterator begin(){
		return ele_list.begin();
	}
	iterator end(){
		return ele_list.end();
	}
private:
	std::vector<Element> ele_list;
};
}
#endif