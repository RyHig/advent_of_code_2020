#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void read_vector(vector<int> vec) {
	int i;
	int length = vec.size();
	for(i = 0; i < length; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}
// largest multiplication is 1010 * 1010. or 1_020_100. 
// 2^16 (65_535) unsigned short < 1_020_100 < 2^31 - 1 (2_147_483_647) signed int
int two_entries(vector<int> vec) {
	int i, j;
	int length = vec.size();

	for(i = 0; i < (length - 1); i++) {
		for(j = i + 1; j < length; j++) {
			if(vec[i] + vec[j] == 2020) {
				cout << vec[i] << " * " << vec[j] << endl;
				return vec[i] * vec[j];
			}
		}
	}
	return -1;
}
// can be int because largest number can be is 673 * 673 * 674. 305_274_146
// as stated above (line 16) 305_274_146 falls between 2^16 - 1 < 305_274_146 < 2^31 - 1.
int three_entries(vector<int> vec) {

	int i, j, k;
	int length = vec.size();

	for(i = 0; i < (length - 2); i++) {
		for(j = i + 1; j < (length - 1); j++) {
			for(k = j + 1; k < length; k++) {
				if(vec[i] + vec[j]  + vec[k] == 2020) {
					cout << vec[i] << " * " << vec[j] << " * " << vec[k] << endl;
					return vec[i] * vec[j] * vec[k];
				}
			}

		}
	}
	
	return -1;
}

int main() {
	ifstream report_values;
	report_values.open("input");
	if(!report_values) {
		cout << "file doesn't exist." << endl;
	}
	else {
		int read_value;
		vector<int> report_vector;
		while(!report_values.eof()) {
			report_values >> read_value;

			report_vector.push_back(read_value);
		}
	
		cout << two_entries(report_vector) << endl;
		cout << three_entries(report_vector) << endl;
	}

	return 0;
}
