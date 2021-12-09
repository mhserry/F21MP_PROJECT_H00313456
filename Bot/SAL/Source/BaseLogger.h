#pragma once

#include "ILogger.h"

class BaseLogger : public ILogger
{
public:
	BaseLogger() = default;
	virtual ~BaseLogger() = default;

	void virtual LogInfo(std::string a_msg, std::string a_infoHeader) override;
	void virtual LogError(std::string a_err, std::string a_errHeader) override;
	void virtual LogHeader(std::string a_header) override;
private:
	int64_t GetTimeStamp() const;
	std::string GetTimeStampMsg() const;
};

