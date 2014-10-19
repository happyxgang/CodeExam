#include "row_data.h"
namespace codemaster{
RowData::RowData(){

}
RowData::RowData(const RowData& row_data){
	this->_content = row_data._content;
}
RowData::~RowData(){
}
int RowData::get(size_t num, Data& data){
	if (num > this->_content.size()){
		return -1;
	}
	data = this->_content[num];
	return 0;
}
}