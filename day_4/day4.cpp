#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> open_file(string file_name);
int all_eight(vector<string> strs);

int main() {

	vector<string> passport = open_file("input");

	int counter = all_eight(passport);
	cout << counter << endl;
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
	int wait_til_blank= 0;

	size_t ecl = 0;		
	size_t pid = 0;
	size_t eyr = 0;
	size_t hcl = 0;
	size_t byr = 0;
	size_t iyr = 0;
	size_t hgt = 0;
	cout << strs.size() << endl;
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
		if(ecl == string::npos) {
			ecl = i.find("ecl");
		}
		if(pid == string::npos) {
			pid = i.find("pid");
		}
		if(eyr == string::npos) {
			eyr = i.find("eyr");
		}
		if(hcl == string::npos) {
			hcl = i.find("hcl");
		}
		if(byr == string::npos) {
			byr = i.find("byr");
		}
		if(iyr == string::npos) {
			iyr = i.find("iyr");
		}
		if(hgt == string::npos) {
			hgt = i.find("hgt");
		}
		if(ecl && pid && eyr && hcl && byr && iyr && hgt) {
			/*cout << ecl << " ";
			cout << pid << " ";
			cout << eyr << " ";
			cout << hcl << " ";
			cout << byr << " ";
			cout << iyr << " ";
			cout << hgt << endl;
			*/
			counter++;
			
			wait_til_blank = 1;		
			ecl = string::npos;
			pid = string::npos;
			eyr = string::npos;
			hcl = string::npos;
			byr = string::npos;
			iyr = string::npos;
			hgt = string::npos;	
			continue;
		}
	}
	return counter;
}
