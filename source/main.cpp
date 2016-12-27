#include "SDK\amx\amx.h"
#include "SDK\plugincommon.h"

#include "data.h"

logprintf_t logprintf;

extern void *pAMXFunctions;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

	logprintf("\n\n\t\t[DynamicData] plugin was loaded.\n\n");
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	logprintf("[DynamicData] plugin was unloaded.");
}

AMX_NATIVE_INFO PluginNatives[] =
{
	{ "new_dynamic_data_int", DynamicData::new_dynamic_data_int },
	{ "add_dynamic_data_int", DynamicData::add_dynamic_data_int },
	{ "get_dynamic_data_int", DynamicData::get_dynamic_data_int },
	{ "size_dynamic_data_int", DynamicData::size_dynamic_data_int },
	{ "find_dynamic_data_int", DynamicData::find_dynamic_data_int },
	{ "remove_dynamic_data_int", DynamicData::remove_dynamic_data_int },

	{ "new_dynamic_data_float", DynamicData::new_dynamic_data_float },
	{ "add_dynamic_data_float", DynamicData::add_dynamic_data_float },
	{ "get_dynamic_data_float", DynamicData::get_dynamic_data_float },
	{ "size_dynamic_data_float", DynamicData::size_dynamic_data_float },
	{ "find_dynamic_data_float", DynamicData::find_dynamic_data_float },
	{ "remove_dynamic_data_float", DynamicData::remove_dynamic_data_float },

	{ "new_dynamic_data_string", DynamicData::new_dynamic_data_string },
	{ "add_dynamic_data_string", DynamicData::add_dynamic_data_string },
	{ "get_dynamic_data_string", DynamicData::get_dynamic_data_string },
	{ "size_dynamic_data_string", DynamicData::size_dynamic_data_string },
	{ "find_dynamic_data_string", DynamicData::find_dynamic_data_string },
	{ "remove_dynamic_data_string", DynamicData::remove_dynamic_data_string },
	{ 0, 0 }
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	return amx_Register(amx, PluginNatives, -1);
}


PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
	return AMX_ERR_NONE;
}