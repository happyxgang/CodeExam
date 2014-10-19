#include "pattern.h"
namespace codemaster{
Pattern::~Pattern(){
	for (size_t i = 0; i < _ele_list.size(); i++){
		delete _ele_list[i];
	}
}
}