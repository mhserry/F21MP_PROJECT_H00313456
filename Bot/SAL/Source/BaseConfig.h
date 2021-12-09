#pragma once

#include <string>
#include <map>

#include "Config.h"

typedef std::map<std::string, bool> ToggleConfig;
typedef std::map<std::string, float> ValueConfig;

class BaseConfig 
{
public:
	BaseConfig();

	ToggleConfig& GetToggleConfig();
	ValueConfig& GetValueConfig();

	float GetValue(std::string a_valName);
	bool GetToggle(std::string a_ToggleName);

protected:
	ToggleConfig m_toggleConfig;
	ValueConfig m_valueConfig;
};

#pragma endregion


