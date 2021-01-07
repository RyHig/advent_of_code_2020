#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<string> open_and_read_file(string file_name);
int highest_seat_id(vector<string> strs);
int test_one(string str);
int binary_highest_id(vector<string> strs);
int binary_lowest_id(vector<string> strs);
int id_value(string str);
int shift_id_value(string str);
int where_is_my_seat(vector<string> strs, int lower, int upper);
void read_vector_string(vector<string> strs);
