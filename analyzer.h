#ifndef ANALYZER_H
#define ANALYZER_H

#include <fstream>
#include <iostream>
#include <string>

#include "data_stream.h"
#include "pattern.h"
#include "row_data.h"

namespace codemaster{
class RowElements;
class Analyzer{
public:
	Analyzer(const Pattern& p, std::string file_name) : _pattern(p), _data_stream(file_name){};
	~Analyzer(){};

	RowData next_row(int& skip_num);
private:
	// use proper parser in pattern to parse every element in items and store in row_data
	bool convert(Pattern& pattern, std::vector<std::string>& items, RowData& row_data);
	Pattern _pattern;
	DataStream _data_stream;
};
}
#endif