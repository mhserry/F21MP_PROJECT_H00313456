#include <algorithm>

#include "BaseBoard.h"
#include "BWAPI.h"
#include "BaseLogger.h"

BaseBoard::BaseBoard()
{
}

BaseBoard::~BaseBoard()
{
}

std::any BaseBoard::GetValue(std::string a_name)
{
	if(!(m_blackBoard.find(a_name) == m_blackBoard.end())) 
	{
		return m_blackBoard[a_name];
	}
	
	return m_blackBoard.end();
}

SnapShot BaseBoard::GetSnapShot()
{
	SnapShot snapShot;
	for (auto const& [k, v] : m_blackBoard)
	{
		snapShot.push_back(std::make_pair(k, v));
	}
	
	return snapShot;
}


void BaseBoard::SetValue(std::string a_name, std::any a_value)
{
	if (!(m_blackBoard.find(a_name) == m_blackBoard.end()))
	{
		m_blackBoard[a_name] = a_value;
	}
	else
	{
		m_blackBoard.try_emplace(a_name, a_value);
	}
}

void BaseBoard::OnUpdate(IController* a_owner)
{
	auto self = BWAPI::Broodwar->self();
	auto enemy = BWAPI::Broodwar->enemy();

	int selfZealots = self->allUnitCount(BWAPI::UnitTypes::Protoss_Zealot);
	int selfDragoons = self->allUnitCount(BWAPI::UnitTypes::Protoss_Dragoon);
	int selfProbes = self->allUnitCount(BWAPI::UnitTypes::Protoss_Probe);
	int selfObservers = self->allUnitCount(BWAPI::UnitTypes::Protoss_Observer);
	int selfDarkTemplar = self->allUnitCount(BWAPI::UnitTypes::Protoss_Dark_Templar);
	int selfShuttle = self->allUnitCount(BWAPI::UnitTypes::Protoss_Shuttle);
	int selfNexus = self->allUnitCount(BWAPI::UnitTypes::Protoss_Nexus);
	int selfGateWay = self->allUnitCount(BWAPI::UnitTypes::Protoss_Gateway);
	int selfPylon = self->allUnitCount(BWAPI::UnitTypes::Protoss_Pylon);
	int selfObservatory = self->allUnitCount(BWAPI::UnitTypes::Protoss_Observatory);
	int selfCyberneticsCore = self->allUnitCount(BWAPI::UnitTypes::Protoss_Cybernetics_Core);
	int selfRoboticsFacility = self->allUnitCount(BWAPI::UnitTypes::Protoss_Robotics_Facility);
	int selfCitadelOfAdun = self->allUnitCount(BWAPI::UnitTypes::Protoss_Citadel_of_Adun);
	int selfTemplarArchives = self->allUnitCount(BWAPI::UnitTypes::Protoss_Templar_Archives);
	int selfGas = self->gas();
	int selfMinerals = self->minerals();
	int selfSupply = self->supplyTotal() - self->supplyUsed();
	int selfKillCount = self->killedUnitCount();

	int enemyZealots = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Zealot);
	int enemyDragoons = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Dragoon);
	int enemyProbes = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Probe);
	int enemyObservers = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Observer);
	int enemyDarkTemplar = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Dark_Templar);
	int enemyShuttle = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Shuttle);
	int enemyNexus = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Nexus);
	int enemyGateWay = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Gateway);
	int enemyPylon = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Pylon);
	int enemyObservatory = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Observatory);
	int enemyCyberneticsCore = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Cybernetics_Core);
	int enemyRoboticsFacility = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Robotics_Facility);
	int enemyCitadelOfAdun = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Citadel_of_Adun);
	int enemyTemplarArchives = enemy->visibleUnitCount(BWAPI::UnitTypes::Protoss_Templar_Archives);
	int enemyKillCount = enemy->killedUnitCount();

	SetValue("Self Zealots", selfZealots);
	SetValue("Self Dragoons", selfDragoons);
	SetValue("Self Probes", selfProbes);
	SetValue("Self Observers", selfObservers);
	SetValue("Self DarkTemplar", selfDarkTemplar);
	SetValue("Self Shuttle", selfShuttle);
	SetValue("Self Nexus", selfNexus);
	SetValue("Self Gateways", selfGateWay);
	SetValue("Self Pylon", selfPylon);
	SetValue("Self Observatory", selfObservatory);
	SetValue("Self Cybernetics Core", selfCyberneticsCore);
	SetValue("Self Robotics Facility", selfRoboticsFacility);
	SetValue("Self Citadel of Adun", selfCitadelOfAdun);
	SetValue("Self Templar Archivies", selfTemplarArchives);
	SetValue("Self Gas", selfGas);
	SetValue("Self Minerals", selfMinerals);
	SetValue("Self Supply", selfSupply);
	SetValue("Self Kill Count", selfKillCount);

	SetValue("Enemy Zealots", enemyZealots);
	SetValue("Enemy Dragoons", enemyDragoons);
	SetValue("Enemy Probes", enemyProbes);
	SetValue("Enemy Observers", enemyObservers);
	SetValue("Enemy DarkTemplar", enemyDarkTemplar);
	SetValue("Enemy Shuttle", enemyShuttle);
	SetValue("Enemy Nexus", enemyNexus);
	SetValue("Enemy Gateways", enemyGateWay);
	SetValue("Enemy Pylon", enemyPylon);
	SetValue("Enemy Observatory", enemyObservatory);
	SetValue("Enemy Cybernetics Core", enemyCyberneticsCore);
	SetValue("Enemy Robotics Facility", enemyRoboticsFacility);
	SetValue("Enemy Citadel of Adun", enemyCitadelOfAdun);
	SetValue("Enemy Templar Archivies", enemyTemplarArchives);
	SetValue("Enemy Kill Count", enemyKillCount);

	a_owner->GetLogger()->LogHeader("=== GAME STATE ===");
	for (auto const& [k, v] : m_blackBoard)
	{
		a_owner->GetLogger()->LogValue(k, "", std::any_cast<int>(v));
	}
}

void BaseBoard::OnDraw(int x, int y)
{
	
}
