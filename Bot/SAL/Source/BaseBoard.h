#pragma once

#include "IBlackBoard.h"
#include "IController.h"
#include <map>

typedef std::map<std::string, std::any> BlackBoard;

class BaseBoard : public IBlackBoard
{
public:
	BaseBoard();
	virtual ~BaseBoard();

	virtual std::any GetValue(std::string a_name) override;
	virtual SnapShot GetSnapShot() override;

	virtual void SetValue(std::string a_name, std::any a_value) override;
	virtual void OnUpdate(IController* a_owner) override;
	virtual void OnDraw(int x, int y) override;

private:
	BlackBoard m_blackBoard;
};


