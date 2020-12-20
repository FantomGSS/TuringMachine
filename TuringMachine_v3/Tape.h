#pragma once
#include <iostream>
#include <vector>
#include <string>

const char EMPTY_CELL = '_';

class Tape {
private:
	std::vector<char> cells;

	void copy(const Tape&);

    void pushBackCell(const char&);
    void pushFrontCell(const char&);

public:
    Tape();
    Tape(std::string&);
    Tape(const Tape&);
    Tape& operator=(const Tape&);

    void formInfiniteTape();
    void setCell(const int&, const char&);

    const std::vector<char>& getCells() const;

    friend std::ostream& operator<<(std::ostream&, const Tape&);
};

