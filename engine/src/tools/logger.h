#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <iostream>

/*
* This is the name of the console where the logs will be printed in.
*/
#define RICHARD_CONSOLE_NAME "Richard console"

/*
* log_level represents all the possible log levels available for logging. 
* Each level is used for different things:
* LEVEL_TRACE: Useful to trace the code and try to find one part of a function specifically.
* LEVEL_DEBUG: Information that is diagnostically helpful to people more than just developers (IT, sysadmins, etc.).
* LEVEL_INFO: Generally useful information to log (service start/stop, configuration assumptions, etc).
* LEVEL_WARNING: Anything that can potentially cause application oddities, but for which the app automatically recovers. (Such as switching from a primary to backup server, retrying an operation, missing secondary data, etc.)
* LEVEL_ERROR: Any error which is fatal to the operation, but not the service or application (can't open a required file, missing data, etc.). These errors will force user (administrator, or direct user) intervention.
* LEVEL_CRITICAL: Any error that is forcing a shutdown of the service or application to prevent data loss (or further data loss).
*/
typedef enum log_level {
	LEVEL_TRACE,
	LEVEL_DEBUG,
	LEVEL_INFO,
	LEVEL_WARNING,
	LEVEL_ERROR,
	LEVEL_CRITICAL
} log_level;


namespace Richard::Tools {
	class Logger {
	public:
		/*Methods*/

		/*
		* Constructor. It creates the object Logger.
		*/
		inline Logger() {};

		/*
		* Destructor. It destroys the objetc Logger.
		*/
		inline ~Logger() {};

		/*
		* Initialize() initializes all the Logger member variables.
		* It also set the log level to LEVEL_TRACE (which means that it prints every log level)
		* It returns 0 in case of success or a non-zero value otherwise.
		*
		* WARNING
		* This method should only be called by the engine, which is the responsible for initializing all tools and managers.
		*/
		static int Initialize();

		/*
		* SetLevel() sets the log level
		*
		* WARNING
		* This method should only be called by the engine, which is the responsible for initializing all tools and managers.
		*/
		static void SetLevel(log_level level);

		/*
		* Trace() logs the message passed as an argument as a LEVEL_TRACE message.
		*/
		static void Trace(std::string message);
		
		/*
		* Debug() logs the message passed as an argument as a LEVEL_DEBUG message.
		*/
		static void Debug(std::string message);

		/*
		* Info() logs the message passed as an argument as a LEVEL_INFO message.
		*/
		static void Info(std::string message);

		/*
		* Warning() logs the message passed as an argument as a LEVEL_WARNING message.
		*/
		static void Warning(std::string message);

		/*
		* Error() logs the message passed as an argument as a LEVEL_ERROR message.
		*/
		static void Error(std::string message);

		/*
		* Critical() logs the message passed as an argument as a LEVEL_CRITICAL message.
		*/
		static void Critical(std::string message);

		/*
		* Shutdown() cleans up the environment that Initialize() method set up.
		*/
		static void Shutdown();
	};
}

#endif