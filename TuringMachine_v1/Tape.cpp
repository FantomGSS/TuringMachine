#include "Tape.h"

void Tape::copy(const Tape& tape)
{
	cells = tape.cells;
}

Tape::Tape() : cells() {}

Tape::Tape(std::string& tape)
{
	for (int i = 0; i < tape.length(); i++)
	{
		cells.push_back(tape[i]);
	}
}

Tape::Tape(const Tape& tape)
{
	copy(tape);
}

Tape& Tape::operator=(const Tape& tape)
{
	if (this != &tape) {
		this->copy(tape);
	}
	return *this;
}

std::vector<char>& Tape::getCells()
{
	return cells;
}

std::ostream& operator<<(std::ostream& output, const Tape& tape)
{
	for (int i = 0; i < tape.cells.size(); i++)
	{
		output << tape.cells[i];
	}
	output << '\n';

	return output;
}
