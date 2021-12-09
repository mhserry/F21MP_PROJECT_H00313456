#pragma once

#include <vector>
#include <string>
#include <memory>
#include <map>

// ========================= DEFINITIONS ========================== //
#pragma region Type-defs

typedef Helpers::ProtossState ProtossGameState;
typedef StrategyAdapters::RuleBasedAdapter<ProtossGameState> RBAdapter_Protoss;
typedef StrategyAdapters::UtilityBasedAdapter<ProtossGameState> UAdapter_Protoss;

typedef StrategyControllers::StrategyController<RBAdapter_Protoss> RBStrategyController;
typedef StrategyControllers::StrategyController<UAdapter_Protoss> UStrategyController;

typedef std::pair<std::string, float> AdapationResult;
typedef std::vector<AdapationResult> AdaptationResultList;
typedef RuleBasedImplementation::StateMachine FSM;
typedef RuleBasedImplementation::IStrategyState StrgyState;
typedef UtilityBasedImplementation::IScorer<ProtossGameState> IScorer_Protoss;

typedef std::pair<RuleBasedImplementation::ITransition*, RuleBasedImplementation::IStrategyState*> TransitionStatePair;
typedef std::vector<TransitionStatePair> Transitions;
typedef std::map<RuleBasedImplementation::IStrategyState*, Transitions> TransitionMap;

#pragma endregion

namespace Helpers
{
	enum class AdapterType
	{
		Rule_Based,
		Utlity_Based,
		Evolutionary_Based,
		DRL_Based
	};

	struct ProtossState 
	{
		int numZealots;          
		int numPylons;        
		int numDragoons;         
		int numProbes;           
		int numNexusCompleted;  
		int numNexusAll;         
		int numCyber;            
		int numCannon;          
		int numScout;           
		int numReaver;           
		int numDarkTeplar;
	};
}

namespace BWAPI 
{
	extern class Player;
}

namespace StrategyControllers
{
	#pragma region Strategy Controller

	template <class TConcreteAdapter>
	class StrategyController 
	{
	public:
		StrategyController();
		virtual ~StrategyController();

		virtual void OnInit();
		virtual void OnFrame(const BWAPI::Player& a_owner); 

	protected:
		std::unique_ptr<TConcreteAdapter> m_adapter;
	};

	#pragma endregion
}

namespace StrategyAdapters
{
	#pragma region IAdapter

	template<class TRaceState>
	class IAdapter 
	{
	public:
		IAdapter() = default;
		virtual ~IAdapter() = default;
		
		virtual void OnStart() = 0;
		virtual void OnUpdate() = 0;
		virtual AdaptationResultList GetAdaptationResults(TRaceState a_gState) = 0;
		virtual const std::string& GetAdaptedStrategy(TRaceState a_gState) = 0;
	};

	#pragma endregion

	#pragma region Rule-based Adapter

	template<class TRaceState>
	class RuleBasedAdapter : public IAdapter <TRaceState>
	{
		
	public:
		RuleBasedAdapter();
		virtual ~RuleBasedAdapter();

		virtual void OnStart() override;
		virtual void OnUpdate() override;
		virtual AdaptationResultList GetAdaptationResults(TRaceState a_gState) override;
		virtual const std::string& GetAdaptedStrategy(TRaceState a_gState) override;

		FSM& GetFSM() const;

	private:
		std::unique_ptr<FSM> m_stateMachine; 
	};

	#pragma endregion

	template <class TRaceState>
	class UtilityBasedAdapter : public IAdapter<TRaceState> 
	{
	public:
		UtilityBasedAdapter();
		virtual ~UtilityBasedAdapter();

		virtual void OnStart() override;
		virtual void OnUpdate() override;
		virtual AdaptationResultList GetAdaptationResults(TRaceState a_gState) override;
		virtual const std::string& GetAdaptedStrategy(TRaceState a_gState) override;

	private:
		std::unique_ptr<UScorer> m_scorer;
		std::unique_ptr<StrgyState> m_currentState;
	};


	class EvolutionaryBasedAdapter {};
	class DRLBasedAdapter {};
}

namespace RuleBasedImplementation 
{
	class StrategyStateContainer 
	{
		static StrategyState Drop;
		static StrategyState ZealotRush;
		static StrategyState DragoonRush;
		static StrategyState DTRush;
	};

	class IStrategyState
	{
	public:
		IStrategyState() = default;
		virtual ~IStrategyState() = default;

		virtual void OnEnter() = 0;
		virtual void OnExit() = 0;
		virtual void OnUpdate();
	};

	class StrategyState : public IStrategyState 
	{
	public:
		StrategyState(const std::string& a_strategyName);
		virtual ~StrategyState() = default;

		virtual void OnEnter() override;
		virtual void OnExit() override;

		std::string GetStrategyName();
	};

	class StateMachine
	{
	public:
		void Update();
		IStrategyState& GetCurrentState() const;

	private:
		std::unique_ptr<TransitionMap> m_transitions;
		std::unique_ptr<IStrategyState> m_currentState;
	};

	class ITransition
	{
	public:
		ITransition() = default;
		virtual ~ITransition() = default;

		virtual bool ToTransition() = 0;
	};

	class FixedTransition : public ITransition 
	{
	public:
		FixedTransition() = default;
		virtual ~FixedTransition() = default;

		virtual bool ToTransition() override;
	};
}

namespace UtilityBasedImplementation
{
	template <class TRaceState>
	class IScorer 
	{
	public:
		IScorer() = default;
		virtual ~IScorer() = default;

		virtual void Score(TRaceState a_gState) = 0;
	};

	template <class TRaceState>
	class WeightedScorer : public IScorer<TRaceState> 
	{
		WeightedScorer() = default;
		virtual ~WeightedScorer() = default;

		virtual void Score(TRaceState a_gState) override;

		float GetWeight() const;
		float GetRank() const;
	};
}

namespace EvolutionaryBasedImplementation
{
}

namespace DRLBasedImplementation
{
}

// ========================= IMPLEMENTATIONS ========================== //

#ifdef STRGY_ADPT_IMPLEMENTATION_H

#endif