#include <string>
#include <vector>
namespace codemaster{
typedef unsigned int uint32;
typedef unsigned long uint64;

std::vector<std::string> split(std::string, char delim);

std::string trim(const std::string& str);

bool is_int(std::string str);
bool is_uint(std::string str);
bool is_uint32(std::string str);
bool is_uint64(std::string str);
bool is_float(std::string str);
int to_int(std::string str);
uint32 to_uint32(std::string str);
uint64 to_uint64(std::string str);
float to_float(std::string str);
}