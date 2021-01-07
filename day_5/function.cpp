#include "function.hpp"

vector<string> open_and_read_file(string file_name) {
	ifstream file;
	vector<string> strs;

	file.open(file_name);
	if(!file) {
		cout << "input file not found in directory." << endl;
	}
	else {
		string read_in;

		while(getline(file, read_in)) {
			strs.push_back(read_in);
		}
	}
	return strs;
}

int highest_seat_id(vector<string> strs) {

	int largest_id = -1;
	
	for(int i = 0; i < strs.size(); i++) { 
		int current_id = 0;
		int row_l_bound = 0;
		int row_h_bound = 127;
		int column_l_bound = 0;
		int column_h_bound = 7;
		int truncate_col = 0;
		int truncate_row = 1;
		for(int j = 0; j < 6; j++) {
			if(strs[i][j] == 'F') {
				row_h_bound = (row_l_bound + row_h_bound) / 2 + truncate_col;
			}
			else if(strs[i][j] == 'B') {
				row_l_bound = (row_l_bound + row_h_bound) / 2 + truncate_col;
			}
			if(truncate_col) {
				truncate_col = 0;
			}
			else {
				truncate_col = 1;
			}
		}
		for(int k = 7; k < 9; k++) {
			if(strs[i][k] == 'R') {
				column_l_bound = (column_l_bound + column_h_bound) / 2 + truncate_row;
			}
			else if(strs[i][k] == 'L') {
				column_h_bound = (column_l_bound + column_h_bound) / 2 + truncate_row;
			}
			if(truncate_row) {
				truncate_row = 0;
			}
			else {
				truncate_row = 1;
			}
		}
		if(strs[i][6] == 'F') {
			current_id = 8 * row_l_bound;
		}
		else {
			current_id = 8 * row_h_bound;
		}
		if(strs[i][9] == 'L') {
			current_id = current_id + column_l_bound;

		}
		else {
			current_id = current_id + column_h_bound;
		}
		if(current_id > largest_id) {
			cout << "column: " << column_l_bound << " " << column_h_bound << endl;
			cout << "row: " << row_l_bound << " " << row_h_bound << endl;
			cout << current_id << " is higher than " << largest_id << endl;
			largest_id = current_id;
		}
	}

	return largest_id;
}

int test_one(string str) {
	int current_id;	
	int row_l_bound = 0;
		int row_h_bound = 127;
		int column_l_bound = 0;
		int column_h_bound = 7;
		int truncate_col = 0;
		int truncate_row = 1;
		for(int j = 0; j < 6; j++) {
			if(str[j] == 'F') {
				row_h_bound = (row_l_bound + row_h_bound) / 2 + truncate_col;
			}
			else if(str[j] == 'B') {
				row_l_bound = (row_l_bound + row_h_bound) / 2 + truncate_col;
			}
			if(truncate_col) {
				truncate_col = 0;
			}
			else {
				truncate_col = 1;
			}
		}
		for(int k = 7; k < 9; k++) {
			if(str[k] == 'R') {
				cout << column_l_bound << " ";
				column_l_bound = (column_l_bound + column_h_bound) / 2 + truncate_row;
				cout << column_l_bound << endl;
			}
			else if(str[k] == 'L') {
				column_h_bound = (column_l_bound + column_h_bound) / 2 + truncate_row;
			}
			if(truncate_row) {
				truncate_row = 0;
			}
			else {
				truncate_row = 1;
			}
			cout << column_l_bound << " " << column_h_bound << endl;
		}
		if(str[6] == 'F') {
			current_id = 8 * row_l_bound;
		}
		else {
			current_id = 8 * row_h_bound;
		}
		if(str[9] == 'L') {
			current_id = current_id + column_l_bound;

		}
		else {
			current_id = current_id + column_h_bound;
		}
		cout << endl;
		cout << current_id << endl;
		return current_id;
}

int binary_highest_id(vector<string> strs) {
	int largest_id = -1;

	for(auto i: strs) {
		int current_id = id_value(i);
		if(current_id > largest_id) {
			largest_id = current_id;
		}
	}
	return largest_id;
}
int binary_lowest_id(vector<string> strs) {
	int smallest_id = 1023;

	for(auto i: strs) {
		int current_id = id_value(i);
		if(current_id < smallest_id) {
			smallest_id = current_id;
		}
	}
	return smallest_id;
	
}

int id_value(string str) {
	int current_id = 0;
	for(int j = 0; j < 10; j++) {
		if(str[j] == 'B' || str[j] == 'R') {
			current_id = current_id + pow(2, 9 - j);
		}
	}
	return current_id;
}

int shift_id_value(string str) {
	int current_id;
	if(str[0] == 'B') {
		current_id = 1;
	}
	else {
		current_id = 0;
	}
	for(int j = 1; j < 10; j++) {
		current_id = current_id << 1;
		if(str[j] == 'B' || str[j] == 'R') {
			current_id++;
		}
	}

	return current_id;
}

int where_is_my_seat(vector<string> strs, int lower, int upper) {
	int seat_filled[1024] = {0};
	for(auto i: strs) {
		int current_id = shift_id_value(i) - 1;
		seat_filled[current_id] = 1;
	}

	for(int i = lower; i < upper; i++) {
		if(seat_filled[i] == 0)
			return i + 1;
	}

	return -1;
}

void read_vector_string(vector<string> strs) {
	
	for(auto i: strs) {
		cout << i << endl;
	}
}
