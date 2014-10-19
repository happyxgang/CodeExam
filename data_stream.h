#ifndef DATASTREAM_H
#define DATASTREAM_H
#include <fstream>
#include <string>
#include <vector>

namespace codemaster{

#define    DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&);                \
	TypeName& operator=(const TypeName&)

class DataStream{
public:
	DataStream(std::string filename ):_file(filename), _delimeter(_default_delimeter){}
	~DataStream(){}

	bool next_line(std::vector<std::string>& items);
private:
	void set_file(std::string file);
	void set_delimeter(char c);
	void split(std::string, std::vector<std::string>& items);

	std::ifstream _file;
	char _delimeter;
	static char _default_delimeter;
};

}
#endif