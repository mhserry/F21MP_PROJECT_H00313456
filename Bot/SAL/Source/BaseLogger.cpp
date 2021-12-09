#include "BaseLogger.h"
#include "Logger.h"
#include "Config.h"
#include <chrono>

void BaseLogger::LogInfo(std::string a_msg, std::string a_infoHeader)
{
	UAlbertaBot::Logger::LogAppendToFile(Config::Debug::LogFileName, a_infoHeader + ' ' + a_msg + ' ' +
		GetTimeStampMsg() + '\n');
}

void BaseLogger::LogError(std::string a_err, std::string a_errHeader)
{
	UAlbertaBot::Logger::LogAppendToFile(Config::Debug::ErrorLogFilename, a_errHeader + ' ' + a_err + ' ' +
		GetTimeStampMsg() + '\n');
}

void BaseLogger::LogHeader(std::string a_header)
{
	UAlbertaBot::Logger::LogAppendToFile(Config::Debug::LogFileName, a_header + '\n');
}

int64_t BaseLogger::GetTimeStamp() const
{
	return std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::system_clock::now().time_since_epoch()).count();
}

std::string BaseLogger::GetTimeStampMsg() const
{
	return "time: " + std::to_string(GetTimeStamp());
}
