#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

size_t split(const string &input, vector<string> &split_string, char ch);
int part_one(string input);
int part_two(string input);

int main() {
	ifstream password_file;
	password_file.open("input");
	if(!password_file) {
		cout << "MAKE SURE the input file is located in the correct directory." << endl;
	}
	else {
		string read_in;
		int sum_one = 0;
		int sum_two = 0;

		while(getline(password_file, read_in)) {
			sum_one += part_one(read_in);
			sum_two += part_two(read_in);
		}

		cout << "sum one: " << sum_one << endl;
		cout << "sum two: " << sum_two << endl;
		//password_file.close();
	}
	return 1;

}

int part_one(string input) {
	vector<string> split_input;
	vector<string> bounds;
	split(input, split_input, ' ');
	char letter = split_input[1][0];
	string password = split_input[2];
	int counter = 0;

	split(split_input[0], bounds, '-');
	int lower_bound = stoi(bounds[0]);
	int upper_bound = stoi(bounds[1]);
	
	for(int i = 0; i < password.size(); i++) {
		if(password[i] == letter){
			counter++;
		}
	}
	if (counter >= lower_bound && counter <= upper_bound) {
		return 1;
	}
	return 0;
}

int part_two(string input) {
	vector<string> split_input;
	vector<string> bounds;
	split(input, split_input, ' ');
	char letter = split_input[1][0];
	string password = split_input[2];

	split(split_input[0], bounds, '-');
	int lower_bound = stoi(bounds[0]);
	int upper_bound = stoi(bounds[1]);

	if( (password[lower_bound - 1] == letter) ^ (password[upper_bound - 1] == letter) ) {
		return 1;
	}
	return 0;
}

size_t split(const string &input, vector<string> &split_string, char ch) {

	size_t pos = input.find( ch );
	size_t init_pos = 0;
	split_string.clear();

	while( pos != string::npos ) {
		split_string.push_back( input.substr( init_pos, pos - init_pos ) );
		init_pos = pos + 1;

		pos = input.find( ch, init_pos );
	}
	split_string.push_back( input.substr( init_pos, min( pos, input.size() ) - init_pos + 1) );

	return split_string.size();
}
