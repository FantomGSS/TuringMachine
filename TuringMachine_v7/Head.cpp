#include "Head.h"

void Head::copy(const Head& head)
{
	position = head.position;
	transitions = head.transitions;
}

Head::Head() : position(1), transitions() {}

Head::Head(std::vector<Transition>& transitions)
{
	position = 1;
	this->transitions = transitions;
}

Head::Head(const Head& head)
{
	copy(head);
}

Head& Head::operator=(const Head& head)
{
	if (this != &head) {
		this->copy(head);
	}
	return *this;
}

void Head::positionToTheRight()
{
	position++;
}

void Head::positionToTheLeft()
{
	if (position != 0)
	{
		position--;
	}
}

void Head::restartPosition()
{
	position = 1;
}

const int& Head::findTransition(char& conditionSymbol, std::string& conditionState)
{
	int transitionNumber = -1;
	for (int i = 0; i < transitions.size(); i++)
	{
		if (transitions[i].getConditionSymbol() == conditionSymbol && transitions[i].getConditionState() == conditionState)
		{
			transitionNumber = i;
			break;
		}
	}

	return transitionNumber;
}

const int& Head::getPosition() const
{
	return position;
}

const std::vector<Transition>& Head::getTransitions() const
{
	return transitions;
}

void Head::addTransition(const Transition& transition)
{
	transitions.push_back(transition);
}
