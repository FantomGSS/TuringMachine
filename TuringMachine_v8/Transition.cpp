#include "Transition.h"

void Transition::copy(const Transition& transition)
{
	conditionSymbol = transition.conditionSymbol;
	conditionState = transition.conditionState;
	newSymbol = transition.newSymbol;
	newState = transition.newState;
	command = transition.command;
}

Transition::Transition()
{
	conditionSymbol = '\0';
	conditionState = "";
	newSymbol = '\0';
	newState = "";
	command = '\0';
}

Transition::Transition(std::string& transitionExpression)
{
	std::regex rgx(FORMAT_TRANSITION);
	std::smatch sm;
	std::regex_match(transitionExpression, sm, rgx);

	conditionSymbol = sm[1].str()[0];
	conditionState = sm[2];
	newSymbol = sm[3].str()[0];
	newState = sm[4];
	command = sm[5].str()[0];
}

Transition::Transition(const Transition& transition)
{
	copy(transition);
}

Transition& Transition::operator=(const Transition& transition)
{
	if (this != &transition) {
		this->copy(transition);
	}
	return *this;
}

const char& Transition::getConditionSymbol() const
{
	return conditionSymbol;
}

const std::string& Transition::getConditionState() const
{
	return conditionState;
}

const char& Transition::getNewSymbol() const
{
	return newSymbol;
}

const std::string& Transition::getNewState() const
{
	return newState;
}

const char& Transition::getCommand() const
{
	return command;
}

std::ostream& operator<<(std::ostream& output, const Transition& transition)
{
	output << transition.conditionSymbol << "{" << transition.conditionState << "} -> " << transition.newSymbol << "{" << transition.newState << "}" << transition.command << '\n';

	return output;
}
