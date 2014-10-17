#ifndef DATASTREAM_H
#define DATASTREAM_H
#include <fstream>
#include <string>
#include <vector>
namespace codemaster{
class DataStream{
public:
	~DataStream(){}
	int next_line(std::vector<std::string>& items);
	static DataStream create(std::string filename);
	static DataStream create(std::string filename, char seperator);
private:
	DataStream(){}
	void set_file(std::string file);
	void set_delimeter(char c);
	void split(std::string, std::vector<std::string>& items);

	std::ifstream _file;
	char _delimeter;
};
}
#endif