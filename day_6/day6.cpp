#include "function.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int questionnaire_part_one(vector<string> strs);
int sum_arr(int arr[], int size);
int questionnaire_part_two(vector<string> strs);
void clear_arr(int *arr, int size);

int main() {

	vector<string> strs = open_and_read_file("input");

	cout << questionnaire_part_one(strs) << endl;
	cout << questionnaire_part_two(strs) << endl;
}

int questionnaire_part_one(vector<string> strs) {
	int alpha[26] = {0};
	int total = 0;
	for(auto i: strs) {
		if(i == "") {
			total = total + sum_arr(alpha, 26);
			clear_arr(alpha, 26);
			continue;
		}
		for(auto j: i) {
			int pos = (int)j - 97;
			if(!alpha[pos]) {
				alpha[pos] = 1;
			}
		}
	}
	total = total + sum_arr(alpha, 26);
	return total;
}

int sum_arr(int arr[], int size) {
	int sum = 0;
	for(int i = 0; i < size; i++) {
		sum = sum + arr[i];
	}
	return sum;
}

int questionnaire_part_two(vector<string> strs) {
	int total = 0;
	int stable[26] = {0};
	int temp[26] = {0};
	int cleared = 1;
	for(auto i: strs) {
		if(i == "") {
			total = total + sum_arr(stable, 26);
			clear_arr(stable, 26);
			cleared = 1;
			continue;
		}
		for(auto j: i) {
			int pos = (int)j - 97;
			if(cleared) {
				stable[pos] = 1;
			}
			else {
				temp[pos] = 1;
			}
		}
		if(!cleared) {
			for(int j = 0; j < 26; j++) {
				if(stable[j] && !temp[j]) {
					stable[j] = 0;
				}
			}
		}
		clear_arr(temp, 26);
		cleared = 0;
	}
	total = total + sum_arr(stable, 26);
	return total;
}

void clear_arr(int *arr, int size) {

	for(int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}
