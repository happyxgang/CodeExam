#include "row_data.h"
namespace codemaster{
RowData::RowData(){

}
RowData::RowData(const RowData& row_data){
		
}
RowData::~RowData(){
}
int RowData::get(int num, Data& data){
	if (num > this->_content.size()){
		return -1;
	}
	data = this->_content[num];
	return 0;
}
}