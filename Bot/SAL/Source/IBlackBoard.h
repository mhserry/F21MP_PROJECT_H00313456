#pragma once

#include <string>
#include <any>
#include <list>

class IController;

typedef std::list<std::pair<std::string, std::any>> SnapShot;

class IBlackBoard
{
public:
	IBlackBoard() = default;
	virtual ~IBlackBoard() = default;

	virtual std::any GetValue(std::string a_name) = 0;
	virtual SnapShot GetSnapShot() = 0;

	virtual void SetValue(std::string a_name, std::any a_value) = 0;
	virtual void OnUpdate(IController* a_owner) = 0;
	virtual void OnDraw(int x, int y) = 0;
};