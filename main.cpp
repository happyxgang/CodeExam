#include <assert.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "array_parser.h"
#include "analyzer.h"
#include "data_stream.h"
#include "int_element.h"
#include "int_parser.h"
#include "pattern.h"

#include "test_int_parser.h"
#include "test_user_data_parser.h"
#include "test_string_parser.h"
#include "test_float_parser.h"
//#include "test_array_parser.h"
//#include "test_analyzer.h"
//#include "test_utility.h"

using std::cout;
using std::endl;
using std::vector;
using codemaster::IntElement;
using codemaster::Pattern;
using codemaster::DataStream;
using namespace codemaster;

int main(int argc, char* argv[]){

	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
	getchar();
	return 0;
}