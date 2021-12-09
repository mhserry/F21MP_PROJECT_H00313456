#include "UABController.h"
#include "BaseLogger.h"
#include "BaseConfig.h"
#include "BaseBoard.h"
#include "BWAPI.h"

UABController::UABController()
{
	m_logger = new BaseLogger;
	m_config = new BaseConfig;
	m_board = new BaseBoard;
}

UABController::~UABController()
{
	delete m_logger;
	delete m_config;
	delete m_board;

	m_logger = nullptr;
	m_config = nullptr;
	m_board = nullptr;
}

void UABController::OnAwake()
{
	try
	{
		BWAPI::Broodwar->printf(" I AM AWAKE: CONTROLLER");
	}
	catch (std::exception ex)
	{
		m_logger->LogError(ex.what(), "!!ERROR: ");
	}
}

void UABController::OnStart()
{
	try 
	{
		BWAPI::Broodwar->printf(" I AM STARTED: CONTROLLER");
	} 
	catch(std::exception ex) 
	{
		m_logger->LogError(ex.what(), "!!ERROR: ");
	}
}

void UABController::OnUpdate()
{
	try
	{
		m_board->OnUpdate(this);
	}
	catch (std::exception ex)
	{
		m_logger->LogError(ex.what(), "!!ERROR: ");
	}
}

void UABController::OnLateUpdate()
{

}

void UABController::OnEnd()
{
	try
	{
		BWAPI::Broodwar->printf(" I AM ENDING: CONTROLLER");
	}
	catch (std::exception ex)
	{
		m_logger->LogError(ex.what(), "!!ERROR: ");
	}
}

ILogger* UABController::GetLogger() const
{
	return m_logger;
}

BaseConfig* UABController::GetConfig() const
{
	return m_config;
}

IBlackBoard* UABController::GetBlackboard() const
{
	return m_board;
}

