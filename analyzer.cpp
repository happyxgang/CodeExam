#include <fstream>
#include <string>
#include "analyzer.h"
#include "data_stream.h"
using std::ifstream;
using std::string;
using std::vector;
using std::string;
namespace codemaster{
// get next row data
// skip_num:
//			== 1: normal
//			== 0: the file end
//			> 1 : skip line number and return a valid row data
//			< 0 : skip line number and reach the file ends;
RowData Analyzer::next_row(int& skip_num){
	int processed_line_num = 0;
	bool valid_line = false;

	// WARNING: no deal with bad line format
	// TODO: add bad line format process
	RowData row_data;
	do{
		vector<string> items;
		if (_data_stream.next_line(items)) {
			valid_line = convert(_pattern, items, row_data);
			processed_line_num++;
		} else {
			// revert the sign when reach the end of file
			processed_line_num = -processed_line_num;
			break;
		}
	} while (!valid_line);

	skip_num = processed_line_num;

	return row_data;
}
bool Analyzer::convert(Pattern& pattern, vector<string>& items, RowData& row_data){

	// pattern and item size must match
	if (pattern.size() != items.size()) {
		return false;
	}
		
	Pattern::iterator itr_pattern = pattern.begin();
	vector<string>::iterator itr_items = items.begin();

	// process every element using proper element parser
	// return true only if all items are proper handled
	while (itr_pattern != pattern.end()) {
		Element* ele = *itr_pattern++;
		string str = *itr_items;

		Data data;

		if (ele->convert(str, data)) {
			row_data.push_back(data);
		} else {
			row_data.clear();
			return false;
		}
	}
	return true;
}
}