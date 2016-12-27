#include <map>
#include <vector>
#include <string>

#include "native.h"

int     DynamicDataInt::new_dynamic_data_int() {
	return fixed_index++;
}
void    DynamicDataInt::add_dynamic_data_int(int index, int value) {
	dynamic_data[index].push_back(value);
}
int     DynamicDataInt::get_dynamic_data_int(int index, int pos) {
	if ((unsigned)pos >= dynamic_data[index].size()) {
		return (0xFFFF);
	}
	return dynamic_data[index][pos];
}
int		DynamicDataInt::size_dynamic_data_int(int index) {
	return dynamic_data[index].size();
}
int     DynamicDataInt::find_dynamic_data_int(int index, int value) {
	std::vector< int > tmp_vec = dynamic_data[index];
	int pos = 0;
	for (int v : tmp_vec) {
		if (v == value) {
			break;
		}
		pos++;
	}
	return ((pos == tmp_vec.size()) ? (-1) : (pos));
}
void    DynamicDataInt::remove_dynamic_data_int(int index, int value) {
	int pos = find_dynamic_data_int(index, value);
	dynamic_data[index].erase(dynamic_data[index].begin() + pos);
}
int		DynamicDataInt::fixed_index = 0;


int     DynamicDataFloat::new_dynamic_data_float() {
	return fixed_index++;
}
void    DynamicDataFloat::add_dynamic_data_float(int index, float value) {
	dynamic_data[index].push_back(value);
}
float   DynamicDataFloat::get_dynamic_data_float(int index, int pos) {
	if ((unsigned)pos >= dynamic_data[index].size()) {
		return (0xFFFF);
	}
	return dynamic_data[index][pos];
}
int		DynamicDataFloat::size_dynamic_data_float(int index) {
	return dynamic_data[index].size();
}
int     DynamicDataFloat::find_dynamic_data_float(int index, float value) {
	std::vector< float > tmp_vec = dynamic_data[index];
	int pos = 0;
	for (float v : tmp_vec) {
		if (v == value) {
			break;
		}
		pos++;
	}
	return ((pos == tmp_vec.size()) ? (-1) : (pos));
}
void    DynamicDataFloat::remove_dynamic_data_float(int index, float value) {
	int pos = find_dynamic_data_float(index, value);
	dynamic_data[index].erase(dynamic_data[index].begin() + pos);
}
int		DynamicDataFloat::fixed_index = 0;


int				DynamicDataString::new_dynamic_data_string() {
	return fixed_index++;
}
void			DynamicDataString::add_dynamic_data_string(int index, std::string value) {
	dynamic_data[index].push_back(value);
}
std::string		DynamicDataString::get_dynamic_data_string(int index, int pos) {
	if ((unsigned)pos >= dynamic_data[index].size()) {
		return '\0';
	}
	return dynamic_data[index][pos];
}
int				DynamicDataString::size_dynamic_data_string(int index) {
	return dynamic_data[index].size();
}
int				DynamicDataString::find_dynamic_data_string(int index, std::string value) {
	std::vector< std::string > tmp_vec = dynamic_data[index];
	int pos = 0;
	for (std::string v : tmp_vec) {
		if (v == value) {
			break;
		}
		pos++;
	}
	return ((pos == tmp_vec.size()) ? (-1) : (pos));
}
void			DynamicDataString::remove_dynamic_data_string(int index, std::string value) {
	int pos = find_dynamic_data_string(index, value);
	dynamic_data[index].erase(dynamic_data[index].begin() + pos);
}
int				DynamicDataString::fixed_index = 0;
