#include <Logging/Log.h>

namespace IneptEngine::Logging
{
	std::ostream* Log::output = &std::cout;

	void Log::Init(std::ostream* output)
	{
		Log::output = output;
	}

	void Log::setOutput(std::ostream* output) {
		Log::output = output;
	}

	void Log::logMessage(LogLevel level, const std::string& message, bool isVerbose, std::string func, std::string file, int line) {
		LogColor color;
		switch (level) {
		case LogLevel::LOGERROR:
			color = LogColor::RED;
			break;
		case LogLevel::LOGWARNING:
			color = LogColor::YELLOW;
			break;
		case LogLevel::LOGDEBUG:
			color = LogColor::GREEN;
			break;
		case LogLevel::LOGINFO:
			color = LogColor::WHITE;
			break;
		case LogLevel::LOGTRACE:
			color = LogColor::MAGENTA;
			break;
		default:
			color = LogColor::DEFAULT;
			break;
		}
		std::string msg = message;
		if (isVerbose) {
			msg = std::format("{} |Function: {} File: {} Line: {}|", message, func, file, line);
		}
		*output << toColorCode(color) << "[" + toString(level) + "]"; //Date&Time : "[" << std::format("{:%T}", std::chrono::system_clock::now()) << "] - " << 
		*output << " " << msg << toColorCode(color) << "\n"; //Color: << toColorCode(DEFAULT) 
	}

	void Log::logMessageEx(const std::string& message, LogLevel level, LogColor color) {
		*output <<  "[" << toString(level) << "] " << message << "\n"; //toColorCode(color) << //<< "\033[0m"
	}

	std::string Log::toString(LogLevel level) {
		switch (level) {
		case LogLevel::LOGERROR:
			return "ERROR";
		case LogLevel::LOGWARNING:
			return "WARNING";
		case LogLevel::LOGINFO:
			return "INFO";
		case LogLevel::LOGDEBUG:
			return "DEBUG";
		case LogLevel::LOGTRACE:
			return "TRACE";
		default:
			return "UNKNOWN";
		}
	}

	std::string Log::toColorCode(LogColor color) {
		if (color == LogColor::BLACK) {
			return "\033[30m";
		}
		else if (color == LogColor::RED) {
			return "\033[31m";
		}
		else if (color == LogColor::GREEN) {
			return "\033[32m";
		}
		else if (color == LogColor::YELLOW) {
			return "\033[33m";
		}
		else if (color == LogColor::BLUE) {
			return "\033[34m";
		}
		else if (color == LogColor::MAGENTA) {
			return "\033[35m";
		}
		else if (color == LogColor::CYAN) {
			return "\033[36m";
		}
		else if (color == LogColor::WHITE) {
			return "\033[37m";
		}
		else if (color == LogColor::DEFAULT) {
			return "\033[0m";
		}
		else {
			return "\033[0m";
		}
	}
}// namespace IneptEngine::Logging
