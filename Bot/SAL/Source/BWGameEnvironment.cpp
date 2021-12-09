#include "BWGameEnvironment.h"

BWGameEnvironment::BWGameEnvironment(int a_runCount, int a_gameCount) : m_runs(a_runCount), m_games(a_gameCount)
{
}

void BWGameEnvironment::Init()
{
}

RunInfo BWGameEnvironment::Run()
{
	PROFILE_FUNCTION();

	RunInfo info{};

	UAlbertaBot::UAlbertaBotModule testBot;

	while(IsInGame()) 
	{
		Tick(&testBot);
		info.winner = false;
		info.numberOfFrames = BWAPI::Broodwar->getFrameCount();
		info.fitness = 500;
		
		ClientUpdate();

		if(!IsConnected()) 
		{
			break;
		}
	}

	std::cout << "Game Over" << "\n";
	return info;
}

void BWGameEnvironment::Stop()
{
	BWAPI::Broodwar->leaveGame();
	BWAPI::BWAPIClient.disconnect();
}

void BWGameEnvironment::Connect()
{
	BWAPI::BWAPIClient.connect();
}

void BWGameEnvironment::Reconnect()
{
	while (!BWAPI::BWAPIClient.connect())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds{ 1000 });
	}
}

void BWGameEnvironment::Tick(UAlbertaBot::UAlbertaBotModule* a_bot)
{
	while (IsInGame())
	{
		// Handle each of the events that happened on this frame of the game
		for (const BWAPI::Event& e : BWAPI::Broodwar->getEvents())
		{
			switch (e.getType())
			{
				case BWAPI::EventType::MatchStart:   { a_bot->onStart();				      break; }
				case BWAPI::EventType::MatchFrame:   { a_bot->onFrame();                      break; }
				case BWAPI::EventType::MatchEnd:     { a_bot->onEnd(e.isWinner());		      break; }
				case BWAPI::EventType::UnitShow:     { a_bot->onUnitShow(e.getUnit());        break; }
				case BWAPI::EventType::UnitHide:     { a_bot->onUnitHide(e.getUnit());        break; }
				case BWAPI::EventType::UnitCreate:   { a_bot->onUnitCreate(e.getUnit());      break; }
				case BWAPI::EventType::UnitMorph:    { a_bot->onUnitMorph(e.getUnit());       break; }
				case BWAPI::EventType::UnitDestroy:  { a_bot->onUnitDestroy(e.getUnit());     break; }
				case BWAPI::EventType::UnitRenegade: { a_bot->onUnitRenegade(e.getUnit());    break; }
				case BWAPI::EventType::UnitComplete: { a_bot->onUnitComplete(e.getUnit());    break; }
				case BWAPI::EventType::SendText:     { a_bot->onSendText(e.getText());        break; }
			}
		}
	}
}

void BWGameEnvironment::ClientUpdate()
{
	BWAPI::BWAPIClient.update();
}

bool BWGameEnvironment::IsInGame()
{
	return BWAPI::BWAPIClient.isConnected() && BWAPI::Broodwar->isInGame();
}

bool BWGameEnvironment::IsConnected()
{
	return BWAPI::BWAPIClient.isConnected();
}
