#pragma once
#include "Transition.h"

class Head
{
private:
	int position;
	std::vector<Transition> transitions;

	void copy(const Head&);

public:
	Head();
	Head(std::vector<Transition>&);
	Head(const Head&);
	Head& operator=(const Head&);

	void positionToTheRight();
	void positionToTheLeft();
	void restartPosition();
	const int& findTransition(char&, std::string&);

	const int& getPosition() const;
	const std::vector<Transition>& getTransitions() const;

	void addTransition(const Transition&);
};

