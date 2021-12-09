#pragma once
#include "Common.h"

class ILogger;
class BaseConfig;
class IBlackBoard;

namespace BWAPI 
{
	class Game;
}

class IController
{
public:
	IController() = default;
	virtual ~IController() = default;

	virtual void OnAwake() = 0;
	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnLateUpdate() = 0;
	virtual void OnEnd() = 0;

	virtual ILogger* GetLogger() const = 0;
	virtual BaseConfig* GetConfig() const = 0;
	virtual IBlackBoard* GetBlackboard() const = 0;
};

