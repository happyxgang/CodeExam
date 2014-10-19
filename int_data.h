#ifndef INT_DATA_H
#define INT_DATA_H
#include "data.h"
namespace codemaster{

// TODO: change it to template to avoid type explosion
class IntData:public Data{
public:
	IntData():Data(DATA_INT){}
	void set_val(int val){ _val = val; }
private:
	int _val;
};

}
#endif