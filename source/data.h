#ifndef DATA_H
#define DATA_H

typedef void(*logprintf_t)(char* format, ...);

namespace DynamicData
{
	cell AMX_NATIVE_CALL new_dynamic_data_int(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL add_dynamic_data_int(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL get_dynamic_data_int(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL size_dynamic_data_int(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL find_dynamic_data_int(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL remove_dynamic_data_int(AMX* amx, cell* params);
	//
	cell AMX_NATIVE_CALL new_dynamic_data_float(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL add_dynamic_data_float(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL get_dynamic_data_float(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL size_dynamic_data_float(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL find_dynamic_data_float(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL remove_dynamic_data_float(AMX* amx, cell* params);
	//
	cell AMX_NATIVE_CALL new_dynamic_data_string(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL add_dynamic_data_string(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL get_dynamic_data_string(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL size_dynamic_data_string(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL find_dynamic_data_string(AMX* amx, cell* params);
	cell AMX_NATIVE_CALL remove_dynamic_data_string(AMX* amx, cell* params);
};

#endif
