#pragma once
#include "IController.h"

class UABController : public IController
{
public:
	UABController();
	virtual ~UABController();
	
	virtual void OnAwake() override;
	virtual void OnStart() override;
	virtual void OnUpdate() override;
	virtual void OnLateUpdate() override;
	virtual void OnEnd() override;

	ILogger* GetLogger() const override;
	BaseConfig* GetConfig() const override;
	IBlackBoard* GetBlackboard() const override;

private:
	
	ILogger* m_logger;
	BaseConfig* m_config;
	IBlackBoard* m_board;
};
