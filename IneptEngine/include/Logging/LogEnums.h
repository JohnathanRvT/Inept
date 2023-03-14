#pragma once

namespace IneptEngine::Logging
{
	/**
	 * Enum representing the different colors that can be used for log messages.
	 */
	enum LogColor {
		DEFAULT,
		BLACK,
		RED,	 // Error
		GREEN,	 // Info
		YELLOW,	 // Warning
		BLUE,	 // Debug
		MAGENTA, // Trace
		CYAN,
		WHITE
	};

	/**
	 * Enum representing the different logging levels that can be used.
	 */
	enum LogLevel {
		/**
		 * Used for log messages that indicate a serious problem or error in the system.
		 * These messages should be used to alert the developer to a problem that needs to be addressed as soon as possible.
		 */
		LOGERROR,

		/**
		 * Used for log messages that indicate a potential problem or issue in the system.
		 * These messages should be used to alert the developer to a problem that may need to be addressed in the future.
		 */
		 LOGWARNING,

		 /**
		  * Used for log messages that provide general information about the system.
		  * These messages can be useful for tracking the progress of the system or for understanding its overall behavior.
		  */
		  LOGINFO,

		  /**
		   * Used for log messages that are only needed when debugging the system.
		   * These messages can be useful for understanding the internal state of the system or for tracking down specific problems.
		   */
		   LOGDEBUG,

		   /**
			* Used for log messages that provide detailed information about the system.
			* These messages can be useful for understanding the fine-grained behavior of the system, but may not be needed in normal operation.
			*/
			LOGTRACE
	};
}// namespace IneptEngine::Logging