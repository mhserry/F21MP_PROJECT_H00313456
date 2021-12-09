#pragma once

#include <string>

class ILogger 
{
public:
	ILogger() = default;
	virtual ~ILogger() = default;

	void virtual LogInfo(std::string a_msg, std::string a_infoHeader)  = 0;
	void virtual LogError(std::string a_err, std::string a_errHeader)  = 0;
	void virtual LogHeader(std::string a_header) = 0;
	
	template <class TValue>
	void LogValue(std::string a_msg, std::string a_valHeader, TValue a_value);
};

template<class TValue>
inline void ILogger::LogValue(std::string a_msg, std::string a_valHeader, TValue a_value)
{
	LogInfo(a_msg + ": " + std::to_string(a_value), a_valHeader);
}
