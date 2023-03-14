#pragma once

//#include "lua.hpp"
//#include "Windowing/window.h"
//
//#include <format>
//#include <Logging/Log.h>
//
//namespace IneptEngine::Scripting {
//	lua_State* L;
//
//	std::string name;
//
//#define LUA_GLOBALSINDEX 0
//
//	static std::list<std::string> g_luaFNList;
//#define REGFN(fn) (lua_pushstring(L, "" #fn ""),      \
//				   lua_pushcfunction(L, lua_##fn),    \
//				   lua_settable(L, LUA_GLOBALSINDEX), \
//				   g_luaFNList.push_back("" #fn ""))
//
//
//#define PARAM_ERROR                                                      \
//	{                                                                    \
//		LOG_DEBUG("Lua param error in {0}!" ,__FUNCTION__); \
//	}
//#define LUA_FUNC_ARITY2(name, retluatype, luatype1, luatype2, rettype, type1, type2, code)          \
//	inline int lua_##name(lua_State* L) {                                                           \
//		if (!lua_gettop(L) == 2)                                                                    \
//			PARAM_ERROR;                                                                            \
//		luaL_argcheck(L, lua_is##luatype1(L, 1), 1, #luatype1 " expected");                         \
//		luaL_argcheck(L, lua_is##luatype2(L, 2), 2, #luatype2 " expected");                         \
//		rettype temp = (rettype)name((type1)lua_to##luatype1(L, 1), (type2)lua_to##luatype2(L, 2)); \
//		code                                                                                        \
//			lua_push##retluatype(L, temp);                                                          \
//		return 1;                                                                                   \
//	}
//
//#define LUA_FUNC_REG(name) lua_register(L, #name, lua_##name)
//
//
//	inline int SetCaption(int id, char* caption) {
//		//CGuiData* p = CGuiData::GetGui(id);
//
//		//if (!p)
//		//	return R_FAIL;
//
//		//p->SetCaption(caption);
//
//		LOG_TRACE("id:{0},caption:{1}", id, caption);
//		return 1;
//	}
//
//	LUA_FUNC_ARITY2(SetCaption,
//		number, number, string,
//		int, int, char*);
//
//	inline void InitLua() {
//		L = luaL_newstate();
//
//
//		LUA_FUNC_REG(SetCaption);
//
//
//		luaL_dofile(L, "initial.lua");
//
//		//if (lua_isfunction(L, -1))
//		//{
//		//	lua_pcall(L, 0, 1, 0);
//		//	const char* windname = lua_tolstring(L, -1, new size_t(100));
//		//	LOG_DEBUG(windname);
//		//	name = windname;
//		//}
//		LOG_DEBUG("Lua initialized!");
//	}
//
//
//	inline	void LoadScript(std::string path) {
//		luaL_loadfile(L, path.c_str());
//	}
//
//	inline void CloseLua() {
//		lua_close(L);
//	}
//}