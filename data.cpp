#include "data.h"

#include <memory>

namespace codemaster{
Data::~Data(){
	//switch (_type) {
	//case DATA_INIT:{
	//	// init state do nothing
	//	break;
	//}
	//case DATA_INT:
	//case DATA_UINT32:
	//case DATA_UINT64:
	//case DATA_FLOAT:
	//case DATA_STRING:
	//case DATA_USRDATA:{
	//	delete _data;
	//	break;
	//}
	//case DATA_ARRAY:{
	//	delete[] _data;
	//	break;
	//}
	//default:{
	//	break;
	//}
	//}//ends for switch
}

// this is a swap operation
// TODO: to avoid swap method
// possible solution: use shared_ptr 
Data::Data(const Data& data){
	this->_data = data._data;
	this->_type = data._type;
}
Data& Data::operator=(Data& data){
	if (this == &data){
		return *this;
	}
	this->_data = data._data;
	this->_type = data._type;

	return *this;
}
}