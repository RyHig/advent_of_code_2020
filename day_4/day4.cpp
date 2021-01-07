#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> open_file(string file_name);
int all_eight(vector<string> strs);
int validate_parameter(string str, size_t start);

int main() {

	vector<string> passport = open_file("input");

	cout << all_eight(passport) << endl;
}

vector<string> open_file(string file_name) {
	ifstream hill_grid;
	vector<string> strs;

	hill_grid.open(file_name);
	if(!hill_grid) {
		cout << "MAKE SURE the input file is located in the correct directory." << endl;
		strs.clear();
	}
	else {
		string read_in;
		
		while(getline(hill_grid, read_in)) {
			strs.push_back(read_in);
		}
	}
	return strs;
}

int all_eight(vector<string> strs) {
	// need to find all needed things.
	// ecl, pid, eyr, hcl, byr, iyr, hgt .. cid not needed or don't care.
	int counter = 0;
	int wait_til_blank = 0;

	size_t ecl = string::npos;		
	size_t pid = string::npos;
	size_t eyr = string::npos;
	size_t hcl = string::npos;
	size_t byr = string::npos;
	size_t iyr = string::npos;
	size_t hgt = string::npos;
	for(auto i: strs) {
		if(wait_til_blank){
			ecl = string::npos;
			pid = string::npos;
			eyr = string::npos;
			hcl = string::npos;
			byr = string::npos;
			iyr = string::npos;
			hgt = string::npos;
			if(i == "") { 
				wait_til_blank = 0;
			}
			continue;
		}
		else if(i == "") {		
			ecl = string::npos;
			pid = string::npos;
			eyr = string::npos;
			hcl = string::npos;
			byr = string::npos;
			iyr = string::npos;
			hgt = string::npos;
			
		}
		if(i.find("ecl") != string::npos) {
			ecl = i.find("ecl");
		}
		if(i.find("pid") != string::npos) {
			pid = i.find("pid");
		}
		if(i.find("eyr") != string::npos) {
			eyr = i.find("eyr");
		}
		if(i.find("hcl") != string::npos) {
			hcl = i.find("hcl");
		}
		if(i.find("byr") != string::npos) {
			byr = i.find("byr");
		}
		if(i.find("iyr") != string::npos) {
			iyr = i.find("iyr");
		}
		if(i.find("hgt") != string::npos) {
			hgt = i.find("hgt");
			validate_parameter(i, hgt);
		}
		if(ecl != string::npos && pid != string::npos && eyr != string::npos && hcl != string::npos && \
				byr != string::npos && iyr != string::npos && hgt != string::npos) {
			
			counter++;
			
			wait_til_blank = 1;		
			ecl = string::npos;
			pid = string::npos;
			eyr = string::npos;
			hcl = string::npos;
			byr = string::npos;
			iyr = string::npos;
			hgt = string::npos;	
		}
	}
	return counter;
}

int validate_parameter(string str, size_t start) {
	size_t i = start;
	while(1) {
		if(str[i] == ' ' || i >= str.size()) {
			break;
		}

		else {
			cout << str[i];
			
		}
		i++;
	}
	cout << endl;
	return 0;
}
