#include "row_data.h"
namespace codemaster{
RowData::RowData(){

}
RowData::RowData(const RowData& row_data){
	this->_content = row_data._content;
}
RowData::~RowData(){
}

// index starts from 0 to _content.size() - 1
bool RowData::get(size_t index, Data& data){
	if (index >= this->_content.size()){
		return false;
	}
	data = this->_content[index];
	return true;
}
}