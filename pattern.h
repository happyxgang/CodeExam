#ifndef PATTERN_H
#define PATTERN_H
#include <vector>
#include "element.h"
#include "shared_ptr.h"
namespace codemaster{
class Pattern{
public:
	typedef std::vector<Element*>::iterator iterator;
	// typedef std::vector<Element*>::const_iterator const_iterator;

	// TODO: try to eliminate order dependency
	void append(Element* ele){
		_ele_list.push_back(ele);
	}
	iterator begin(){
		return _ele_list.begin();
	}
	iterator end(){
		return _ele_list.end();
	}
	int size() const{
		return _ele_list.size();
	}
	~Pattern();
private:
	std::vector<Element*> _ele_list;
};
}
#endif