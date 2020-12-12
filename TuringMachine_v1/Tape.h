#pragma once
#include <iostream>
#include <vector>
#include <string>

class Tape {
private:
	std::vector<char> cells;

	void copy(const Tape&);

public:
    Tape();
    Tape(std::string&);
    Tape(const Tape&);
    Tape& operator=(const Tape&);

    std::vector<char>& getCells();

    friend std::ostream& operator<<(std::ostream&, const Tape&);
};

