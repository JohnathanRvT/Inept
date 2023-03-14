#pragma once

#include <string>
#include <iostream>
#include <format>
#include <iostream>
#include <chrono>

#include "LogEnums.h"

#define LOG_INFO(...) \
    IneptEngine::Logging::Log::logMessage( \
        IneptEngine::Logging::LogLevel::LOGINFO, \
        std::format(__VA_ARGS__)\
		)
#define LOG_TRACE(...) \
    IneptEngine::Logging::Log::logMessage( \
        IneptEngine::Logging::LogLevel::LOGTRACE, \
        std::format(__VA_ARGS__)\
		)
#define LOG_DEBUG(...) \
    IneptEngine::Logging::Log::logMessage( \
        IneptEngine::Logging::LogLevel::LOGDEBUG, \
        std::format(__VA_ARGS__)\
		)
#define LOG_WARNING(...) \
    IneptEngine::Logging::Log::logMessage( \
        IneptEngine::Logging::LogLevel::LOGWARNING, \
        std::format(__VA_ARGS__)\
		)
#define LOG_ERROR(...) \
    IneptEngine::Logging::Log::logMessage( \
        IneptEngine::Logging::LogLevel::LOGERROR, \
        std::format(__VA_ARGS__)\
		);\
		DebugBreak()

namespace IneptEngine::Logging
{
    /**
	 * Class that provides support for logging messages with different colors and levels.
	 */
	class Log {
	public:
		/**
		 * @fn static void Init();
		 * @brief Initializes Log class
		 */
		static void Init(std::ostream* output = &std::cout);
		/**
		 * @fn static void logMessage(LogLevel level, const std::string& message, bool isVerbose = false, std::string func = __builtin_FUNCTION(), std::string file = __builtin_FILE(), int line = __builtin_LINE());
		 * @brief Logs a message with the appropriate color based on the logging level.
		 *
		 * @param level The logging level for the message.
		 * @param message The message to log.
		 */
		static void logMessage(LogLevel level, const std::string& message, bool isVerbose = false, std::string func = __builtin_FUNCTION(), std::string file = __builtin_FILE(), int line = __builtin_LINE());
		/**
		 * @brief Logs a message with the specified logging level and color.
		 *
		 * @param message The message to log.
		 * @param level The logging level for the message.
		 * @param color The color to use for the message.
		 */
		static void logMessageEx(const std::string& message, LogLevel level, LogColor color);
		/**
		* @fn static void setOutput(std::ostream* output);
		* @brief Set the output stream for the log messages
		* This function sets the output stream for the log messages. By default,
		* the output stream is set to std::cout. However, this function allows
		* you to redirect the output stream to a different output, such as a file
		* or a stringstream.
		* @param output The output stream to redirect the log messages to
		*/
		static void setOutput(std::ostream* output);
	private:
		/**
		 * @fn static std::string toString(LogLevel level);
		 * @brief Converts a logging level to a string representation.
		 *
		 * @param level The logging level to convert.
		 * @return The string representation of the logging level.
		 */
		static std::string toString(LogLevel level);

		/**
		 * @fn static std::string toColorCode(LogColor color);
		 * @brief Converts a log color to an ANSI escape code.
		 *
		 * @param color The log color to convert.
		 * @return The ANSI escape code for the log color.
		 */
		static std::string toColorCode(LogColor color);

		static std::ostream* output;
	};
} // namespace IneptEngine::Logging
