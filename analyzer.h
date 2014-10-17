#ifndef ANALYZER_H
#define ANALYZER_H
#include <fstream>
#include <iostream>
#include <string>
#include "data_stream.h"
#include "pattern.h"
namespace codemaster{
class RowElements;
class Analyzer{
public:
	Analyzer(const Pattern& p, std::string file_name);
	~Analyzer();
	RowElements next_row(int& skip_num);
private:
	Pattern _pattern;
	DataStream data_stream;
};
}
#endif