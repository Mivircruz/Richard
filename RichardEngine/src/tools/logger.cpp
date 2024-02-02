/*
* spdlog uses a library called fmtlib which, in turn, uses a Microsoft extension called std::checked_array_iterator.
* Microsoft deprecated stdext::checked_array_iterator with microsoft/STL#3818, which means its use will now result in a warning. 
* This issue was raised in fmtlib issue 3540 and then fixed. An issue was also raised in spdlog issue 2912, but still remains open.
* Thus, the warning is disabled so spdlog can run.
*/
#define _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS

#include "tools/logger.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Richard::Tools {
	/*Public methods*/

	int Logger::Initialize() {
		spdlog::set_level(spdlog::level::trace);
		spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] %v%$");
		spdlog::stdout_color_mt(RICHARD_CONSOLE_NAME);
		return 0;
	}

	void Logger::SetLevel(log_level level) {
		spdlog::get(RICHARD_CONSOLE_NAME)->set_level((spdlog::level::level_enum) level);
	}

	void Logger::Trace(std::string message) {
		spdlog::get(RICHARD_CONSOLE_NAME)->trace(message);
	}

	void Logger::Info(std::string message) {
		spdlog::get(RICHARD_CONSOLE_NAME)->info(message);
	}

	void Logger::Warning(std::string message) {
		spdlog::get(RICHARD_CONSOLE_NAME)->warn(message);
	}

	void Logger::Debug(std::string message) {
		spdlog::get(RICHARD_CONSOLE_NAME)->debug(message);
	}

	void Logger::Error(std::string message) {
		spdlog::get(RICHARD_CONSOLE_NAME)->error(message);
	}

	void Logger::Critical(std::string message) {
		spdlog::get(RICHARD_CONSOLE_NAME)->critical(message);
	}

	void Logger::Shutdown() {
		spdlog::shutdown();
	}
}