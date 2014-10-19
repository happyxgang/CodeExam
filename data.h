#ifndef DATA_H
#define DATA_H
#include <memory>
#include "shared_ptr.h"
namespace codemaster{
enum DataType 
{
	DATA_INIT,//Invalid init data type
	DATA_INT,
	DATA_FLOAT,
	DATA_STRING,
	DATA_ARRAY,
	DATA_UINT32,
	DATA_UINT64,
	DATA_USRDATA
};

class Data{
public:
	Data():_type(DATA_INIT){}
	Data(DataType type) :_data(NULL), _type(type){}
	// this is a move operation
	Data(const Data& data);
	Data& operator=(Data& d);
	~Data();

	SharedPtr<void*> data(){ return _data; }
	void set_data(void* data){ SharedPtr<void*> ptr(data); }
private:
	SharedPtr<void*> _data;
	DataType _type;
};
}
#endif