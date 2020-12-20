#pragma once
#include <time.h>
#include "Head.h"
#include "Tape.h"
#include "FileManager.h"

const int SECONDS_BEFORE_END = 10;

class TuringMachine
{
private:
	Head head;
	std::vector<Tape> tapes;
	std::string state;
	std::vector<bool> results;

	void copy(const TuringMachine&);

	bool checkTransitionFormat(std::string&);

	void readMachineFromFile();
	void readTapesFromFile();

	void readMachineFromConsole();
	void readTapesFromConsole();

	void optionSelectingMachine();
	void optionSelectingTapes();
	void optionSelectingInspection(std::vector<int>&);

public:
	TuringMachine(); 
	TuringMachine(Head&, std::vector<Tape>&, std::string&);
	TuringMachine(const TuringMachine&);
	TuringMachine& operator=(const TuringMachine&);

	void addTapes(const std::vector<Tape>&);
	const bool processingSuccessful();
	void markHeadPosition(const char&);

	const Head& getHead() const;
	const std::vector<Tape>& getTapes() const;
	const std::string& getState() const;
	const std::vector<bool>& getResults() const;

	void run();
	void compose(TuringMachine&);
	void continueWith(TuringMachine&, TuringMachine&);
	void toSingleTape();
};

