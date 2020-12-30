#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> open_file(string file_name);
int tree_counting(vector<string> strs);
unsigned long long tree_changing_step_size(vector<string> strs, int x_steps[], int y_steps[], int size);

int main() {
	int sum_one = 0;
	unsigned long long sum_two = 0;
	vector<string> grid = open_file("input");
	int x_steps[5] = {1, 3, 5, 7, 1};
	int y_steps[5] = {1, 1, 1, 1, 2};
	sum_one = tree_counting(grid);
	sum_two = tree_changing_step_size(grid, x_steps, y_steps, 5);
	cout << "sum one: " << sum_one << endl;
	cout << "sum two: " << sum_two << endl;
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

int tree_counting(vector<string> strs) {
	int rows = strs.size();
	int columns = strs[0].size();
	int x = 0;
	int y = 0;
	int counter = 0;
	while(y < rows) {
		if(strs[y][x] == ('#')) {
			counter++;
		}
		y = y + 1;
		x = (x + 3) % columns;
	}

	return counter;
}

unsigned long long tree_changing_step_size(vector<string> strs, int x_steps[], int y_steps[], int size) {
	int rows = strs.size();
	int columns = strs[0].size();
	unsigned long long total = 1;
	for(int i = 0; i < size; i++) {
		int x_step = x_steps[i];
		int y_step = y_steps[i];
		int x = 0;
		int y = 0;
		int counter = 0;

		cout << x_step << " " << y_step << endl;
		while(y < rows) {
			if(strs[y][x] == '#') {
				counter++;
			}
		
			y = y + y_step;
			x = (x + x_step) % columns;
		}
		cout << counter << endl;
		total = total * (unsigned long long) counter;
	}
	return total;
}
