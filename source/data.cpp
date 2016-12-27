#include <map>
#include <vector>

#include "SDK\amx\amx.h"
#include "SDK\plugincommon.h"

#include "data.h"
#include "native.h"

extern logprintf_t logprintf;

#define CHECK_PARAMS(m, n) \
	if (params[0] != (m * 4)) \
	{ \
		logprintf("*** %s: Expecting %d parameter(s), but found %d", n, m, params[0] / 4); \
		return 0; \
	}

DynamicDataInt		dynamicdataint;
DynamicDataFloat	dynamicdatafloat;
DynamicDataString	dynamicdatastring;

cell AMX_NATIVE_CALL DynamicData::new_dynamic_data_int(AMX* amx, cell* params)
{
	return static_cast<cell>(dynamicdataint.new_dynamic_data_int());
}
cell AMX_NATIVE_CALL DynamicData::add_dynamic_data_int(AMX* amx, cell* params)
{
	CHECK_PARAMS(2, "add_dynamic_data_int");
	dynamicdataint.add_dynamic_data_int(
		static_cast<int>(params[1]), static_cast<int>(params[2])
		);
	return 0;
}
cell AMX_NATIVE_CALL DynamicData::get_dynamic_data_int(AMX* amx, cell* params)
{
	CHECK_PARAMS(2, "get_dynamic_data_int");
	return static_cast<cell>(
		dynamicdataint.get_dynamic_data_int(
			static_cast<int>(params[1]), static_cast<int>(params[2]))
		);
}
cell AMX_NATIVE_CALL DynamicData::size_dynamic_data_int(AMX* amx, cell* params)
{
	CHECK_PARAMS(1, "size_dynamic_data_int");
	return static_cast<cell>(
		dynamicdataint.size_dynamic_data_int(
			static_cast<int>(params[1]))
		);
}
cell AMX_NATIVE_CALL DynamicData::find_dynamic_data_int(AMX* amx, cell* params)
{
	CHECK_PARAMS(2, "find_dynamic_data_int");
	return static_cast<cell>(
		dynamicdataint.find_dynamic_data_int(
			static_cast<int>(params[1]), static_cast<int>(params[2]))
		);
}
cell AMX_NATIVE_CALL DynamicData::remove_dynamic_data_int(AMX* amx, cell* params)
{
	CHECK_PARAMS(2, "remove_dynamic_data_int");
	dynamicdataint.remove_dynamic_data_int(
		static_cast<int>(params[1]), static_cast<int>(params[2])
		);
	return 0;
}
//
cell AMX_NATIVE_CALL DynamicData::new_dynamic_data_float(AMX* amx, cell* params)
{
	return static_cast<cell>(dynamicdatafloat.new_dynamic_data_float());
}
cell AMX_NATIVE_CALL DynamicData::add_dynamic_data_float(AMX* amx, cell* params)
{
	CHECK_PARAMS(2, "add_dynamic_data_float");
	dynamicdatafloat.add_dynamic_data_float(
		static_cast<int>(params[1]), amx_ctof(params[2])
		);
	return 0;
}
cell AMX_NATIVE_CALL DynamicData::get_dynamic_data_float(AMX* amx, cell* params)
{
	CHECK_PARAMS(2, "get_dynamic_data_float");
	const float f =
		(float)dynamicdatafloat.get_dynamic_data_float(
			static_cast<int>(params[1]), static_cast<int>(params[2])
			);

	return amx_ftoc(f);
}
cell AMX_NATIVE_CALL DynamicData::size_dynamic_data_float(AMX* amx, cell* params)
{
	CHECK_PARAMS(1, "size_dynamic_data_float");
	return static_cast<cell>(
		dynamicdatafloat.size_dynamic_data_float(
			static_cast<int>(params[1]))
		);
}
cell AMX_NATIVE_CALL DynamicData::find_dynamic_data_float(AMX* amx, cell* params)
{
	CHECK_PARAMS(2, "find_dynamic_data_float");
	return static_cast<cell>(
		dynamicdatafloat.find_dynamic_data_float(
			static_cast<int>(params[1]), amx_ctof(params[2]))
		);
}
cell AMX_NATIVE_CALL DynamicData::remove_dynamic_data_float(AMX* amx, cell* params)
{
	CHECK_PARAMS(2, "remove_dynamic_data_float");
	dynamicdatafloat.remove_dynamic_data_float(
		static_cast<int>(params[1]), amx_ctof(params[2])
		);
	return 0;
}
//
cell AMX_NATIVE_CALL DynamicData::new_dynamic_data_string(AMX* amx, cell* params)
{
	return static_cast<cell>(dynamicdatafloat.new_dynamic_data_float());
}
cell AMX_NATIVE_CALL DynamicData::add_dynamic_data_string(AMX* amx, cell* params)
{
	CHECK_PARAMS(2, "add_dynamic_data_string");

	int len = NULL;
	cell *addr = NULL;

	amx_GetAddr(amx, params[1], &addr);
	amx_StrLen(addr, &len);

	if (len)
	{
		len++;

		char* text = new char[len];
		amx_GetString(text, addr, 0, len);

		dynamicdatastring.add_dynamic_data_string(
			static_cast<int>(params[1]), text
			);

		delete[] text;
	}
	return 0;
}
cell AMX_NATIVE_CALL DynamicData::get_dynamic_data_string(AMX* amx, cell* params)
{
	CHECK_PARAMS(2, "get_dynamic_data_string");
	const std::string s =
		dynamicdatastring.get_dynamic_data_string(
			static_cast<int>(params[1]), static_cast<int>(params[2])
		);

	cell* addr = NULL;

	amx_GetAddr(amx, params[3], &addr);
	amx_SetString(addr, s.c_str(), 0, 0, params[4]);
	return 0;
}
cell AMX_NATIVE_CALL DynamicData::size_dynamic_data_string(AMX* amx, cell* params)
{
	CHECK_PARAMS(1, "size_dynamic_data_string");
	return static_cast<cell>(
		dynamicdatastring.size_dynamic_data_string(
			static_cast<int>(params[1]))
		);
}
cell AMX_NATIVE_CALL DynamicData::find_dynamic_data_string(AMX* amx, cell* params)
{
	CHECK_PARAMS(2, "find_dynamic_data_string");

	int len = NULL, pos;
	cell *addr = NULL;

	amx_GetAddr(amx, params[1], &addr);
	amx_StrLen(addr, &len);

	if (len)
	{
		len++;

		char* text = new char[len];
		amx_GetString(text, addr, 0, len);

		pos = dynamicdatastring.find_dynamic_data_string(
				static_cast<int>(params[1]), text
			);

		delete[] text;
	}
	return static_cast<cell>(pos);
}
cell AMX_NATIVE_CALL DynamicData::remove_dynamic_data_string(AMX* amx, cell* params)
{
	CHECK_PARAMS(2, "remove_dynamic_data_string");

	int len = NULL;
	cell *addr = NULL;

	amx_GetAddr(amx, params[1], &addr);
	amx_StrLen(addr, &len);

	if (len)
	{
		len++;

		char* text = new char[len];
		amx_GetString(text, addr, 0, len);

		dynamicdatastring.remove_dynamic_data_string(
			static_cast<int>(params[1]), text
		);

		delete[] text;
	}
	return 0;
}