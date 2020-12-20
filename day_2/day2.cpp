#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <day1.hpp>

using namespace std;


int check_validity(string input);

int main() {
	ifstream password_file;
	password_file.open("input");
	if(!password_file) {
		cout << "MAKE SURE the input file is located in the correct directory." << endl;
	}
	else {
		string read_in;
		int sum = 0;
		
		while(getline(password_file, read_in)) {

			sum += check_validity(read_in);
		}

		cout << sum << endl;
		//password_file.close();
	}
	
}
// did a naive try.
// integers can be more than 1 character. welp.
/*int check_validity(string input) {
	//regex probably.
	int i, length = input.size();
	int min = input[0], max = input[2];
	char letter = input[4];
	int in_range = 0;
	
	for(i = 6; i < length - 1; i++) {
  if(input[i] == letter) {
			cout << input[i] << " " << letter << endl;
			in_range += 1;
		}
		if (in_range > max) {
			return 0;
		}
		cout << input[i];
	}
	cout << endl;
	if (in_range <= min) {
		return 0;
	}
	cout << min << " less than " << in_range << " less than " << max << endl; 
	return 1;
} */ 
