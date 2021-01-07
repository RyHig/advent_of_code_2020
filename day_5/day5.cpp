#include "function.hpp"

int main() {
	vector<string> strs = open_and_read_file("input");
	int upper_bound = binary_highest_id(strs);
	int lower_bound = binary_lowest_id(strs);
	cout << where_is_my_seat(strs, lower_bound, upper_bound) << endl;

	return 0;
}

