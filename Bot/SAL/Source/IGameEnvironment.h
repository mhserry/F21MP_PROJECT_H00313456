#pragma once

enum class GameStatus
{
	INITIALIZED = 0,
	RUNNING = 1,
	EXIT = 2,
};

struct RunInfo
{
	bool winner;
	double fitness;
	double gameTime;
	double numberOfFrames;
};

class IGameEnvironment
{
public:
	IGameEnvironment() = default;
	virtual ~IGameEnvironment() = default;

	virtual void Init() = 0;
	virtual RunInfo Run() = 0;
	virtual void Stop() = 0;
};

