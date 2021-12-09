#include "BaseConfig.h"

BaseConfig::BaseConfig()
{
	m_valueConfig = { {"h", 5}, {"Speed", Config::BWAPIOptions::SetLocalSpeed} };
	m_toggleConfig = { {"b", false}, {"Draw", Config::Debug::DrawBWTAInfo} };
}

ToggleConfig& BaseConfig::GetToggleConfig()
{
	return m_toggleConfig;
}

ValueConfig& BaseConfig::GetValueConfig()
{
	return m_valueConfig;
}

float BaseConfig::GetValue(std::string a_valName)
{
	return m_valueConfig[a_valName];
}

bool BaseConfig::GetToggle(std::string a_ToggleName)
{
	return m_toggleConfig[a_ToggleName];
}
