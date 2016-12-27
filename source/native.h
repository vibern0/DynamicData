#ifndef NATIVE_H
#define NATIVE_H

class DynamicDataInt
{
	static int fixed_index;
	std::map< int, std::vector< int > > dynamic_data;
public:
	DynamicDataInt() { }
	~DynamicDataInt() { }

	int     new_dynamic_data_int();
	void    add_dynamic_data_int(int index, int value);
	int     get_dynamic_data_int(int index, int pos);
	int		size_dynamic_data_int(int index);
	int     find_dynamic_data_int(int index, int value);
	void    remove_dynamic_data_int(int index, int value);
};

class DynamicDataFloat
{
	static int fixed_index;
	std::map< int, std::vector< float > > dynamic_data;
public:
	DynamicDataFloat() { }
	~DynamicDataFloat() { }

	int     new_dynamic_data_float();
	void    add_dynamic_data_float(int index, float value);
	float   get_dynamic_data_float(int index, int pos);
	int		size_dynamic_data_float(int index);
	int     find_dynamic_data_float(int index, float value);
	void    remove_dynamic_data_float(int index, float value);
};

class DynamicDataString
{
	static int fixed_index;
	std::map< int, std::vector< std::string > > dynamic_data;
public:
	DynamicDataString() { }
	~DynamicDataString() { }

	int				new_dynamic_data_string();
	void			add_dynamic_data_string(int index, std::string value);
	std::string		get_dynamic_data_string(int index, int pos);
	int				size_dynamic_data_string(int index);
	int				find_dynamic_data_string(int index, std::string value);
	void			remove_dynamic_data_string(int index, std::string value);
};

#endif