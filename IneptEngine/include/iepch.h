#pragma once

#ifdef INEPT_PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN      // Exclude rarely-used stuff from Windows headers
#include <Windows.h>
#include <Windowsx.h>
#include <wingdi.h>
#endif // INEPT_PLATFORM_WINDOWS

#include <functional>
#include <memory>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <format>

#include <mutex>

#include <vector>
#include <map>

#include <ctime>
#include <chrono>

#include <debugapi.h>


//#include <Logging/Log.h>
//using namespace IneptEngine::Logging;

//#include <Events/EventBus.h>
//#include <Events/ApplicationEvent.h>
//#include <Events/WindowEvent.h>
//#include <Events/KeyboardEvent.h>
//#include <Events/MouseEvent.h>
//using namespace IneptEngine::Events;

//
//#define INEPT_VERBOSEINFO(msg) Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGINFO, msg, true)
//#define INEPT_VERBOSETRACE(msg) Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGTRACE, msg, true)
//#define INEPT_VERBOSEDEBUG(msg) Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGDEBUG, msg, true)
//#define INEPT_VERBOSEWARNING(msg) Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGWARNING, msg, true)
//#define INEPT_VERBOSEERROR(msg) Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGERROR, msg, true)
//#define INEPT_UNDLINE(msg) std::format("\033[4m{}\033[24m",msg)
//#define INEPT_NEG(msg) std::format("\033[7m{}\033[27m",msg)
//
//#define INEPT_ENABLE_ASSERTS
//
//#ifdef INEPT_ENABLE_ASSERTS
//#define INEPT_ASSERT(type, msg) { if(!(type)) { INEPT_ERROR(msg); __debugbreak(); } }
//#else	
//#define INEPT_ASSERT(...)
//#endif
