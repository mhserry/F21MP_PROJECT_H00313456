#pragma once

#include "IGameEnvironment.h"
#include "UAlbertaBotModule.h"

class BWGameEnvironment : public IGameEnvironment
{
public: 
	BWGameEnvironment(int a_runCount, int a_gameCount);
	virtual ~BWGameEnvironment() = default;

	virtual void Init() override;
	virtual RunInfo Run() override;
	virtual void Stop() override;

private:
	void Connect();
	void Reconnect();
	void Tick(UAlbertaBot::UAlbertaBotModule* a_bot);
	void ClientUpdate();
	bool IsInGame();
	bool IsConnected();

	int m_runs;
	int m_games;
};