#pragma once
#include <iostream>
#include <string>
#include <regex>

const std::string FORMAT_TRANSITION = "^(.)[{](.+)[}][ ][-][>][ ](.)[{](.+)[}]([L|R|S])$";

class Transition
{
private:
	char conditionSymbol;
	std::string conditionState;
	char newSymbol;
	std::string newState;
	char direction;

	void copy(const Transition&);

public:
	Transition();
	Transition(std::string&);
	Transition(const Transition&);
	Transition& operator=(const Transition&);

	const char& getConditionSymbol() const;
	const std::string& getConditionState() const;
	const char& getNewSymbol() const;
	const std::string& getNewState() const;
	const char& getDirection() const;

	friend std::ostream& operator<<(std::ostream&, const Transition&);
};

