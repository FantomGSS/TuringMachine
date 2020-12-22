#include "Tape.h"

void Tape::copy(const Tape& tape)
{
	cells = tape.cells;
}

Tape::Tape()
{
	formInfiniteTape();
}

Tape::Tape(std::string& tape)
{
	for (int i = 0; i < tape.length(); i++)
	{
		cells.push_back(tape[i]);
	}

	formInfiniteTape();
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

void Tape::pushBackCell(const char& cell)
{
	cells.push_back(cell);
}

void Tape::pushFrontCell(const char& cell)
{
	cells.insert(cells.begin(), cell);
}

void Tape::formInfiniteTape()
{
	this->pushFrontCell(EMPTY_CELL);
	this->pushBackCell(EMPTY_CELL);
}

void Tape::setCell(const int& index, const char& newCell)
{
	if (cells[index] == EMPTY_CELL && index == 0)
	{
		cells[index] = newCell;
		this->pushFrontCell(EMPTY_CELL);
	}
	else if (cells[index] == EMPTY_CELL && index == cells.size() - 1)
	{
		cells[index] = newCell;
		this->pushBackCell(EMPTY_CELL);
	}
	else
	{
		cells[index] = newCell;
	}
}

const std::vector<char>& Tape::getCells() const
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
