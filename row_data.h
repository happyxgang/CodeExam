#ifndef ROW_DATA_H
#define ROW_DATA_H
#include <vector>
#include "data.h"
namespace codemaster{
class RowData{
public:
	RowData();
	~RowData();
	RowData(const RowData& row_data);

	void push_back(Data data){ _content.push_back(data); }
	int get(int num, Data& data);
	void clear(){ _content.clear(); }
	std::vector<Data> content();
private:
	std::vector<Data> _content;
};
}
#endif