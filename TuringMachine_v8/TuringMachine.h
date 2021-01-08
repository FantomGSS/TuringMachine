#pragma once
#include <time.h>
#include "Head.h"
#include "Tape.h"
#include "FileManager.h"

/* ���� ������� ������� �������� �� ������ ����� �� ������, ��� �� ���� ����� �� � ������. 
   ���� �� ����� � ��� �� �� ��������� �� ��������� �� �������� � �������� ����� �� ����� �� ��������� �� ����� �����.
   After this number of seconds, the Turing machine stops working if it has not otherwise stopped.
   This is done in order to prevent the machine from entering an endless cycle during the processing of a tape. */
const int SECONDS_BEFORE_END = 10;

/* ���� TuringMachine, ����� ������������ �������� �� ������.
   TuringMachine class, which is the Turing machine. */
class TuringMachine
{
private:
	Head head;																			///�����. / Head.
	std::vector<Tape> tapes;															///�����. / Tapes.
	std::string state;																	///��������� �� �������� / Machine state.
	std::vector<bool> results;															///����������� �� ����������� �� �������. / The results of the processing of the tapes.

	/* �������, ����� ������ ����������� �� ��������� �����.
	   A function that copies the values of the given object. */
	void copy(const TuringMachine&);

	/* �������, ����� ����� ������ �������� � ���������� �� ���� ���� ��������� ��� �������� �� ���������� ������ �� ������.
	   A function that returns a boolean value depending on whether the character string matches the required transition format. */
	bool checkTransitionFormat(const std::string&);

	/* �������, ����� ���� ������ �� ������ �� ����.
	   A function that reads a Turing machine from a file. */
	void readMachineFromFile();

	/* �������, ����� ���� ����� �� ����.
	   A function that reads tapes from a file. */
	void readTapesFromFile();

	/* �������, ����� ���� ������ �� ������ �� ���������.
	   A function that reads a Turing machine from the console. */
	void readMachineFromConsole();

	/* �������, ����� ���� ����� �� ���������.
	   A function that reads tapes from the console. */
	void readTapesFromConsole();

	/* �������, ����� ������ �� ����������� �� ������ �� ���� �� ���� ��������� ��������.
	   A function that helps the user choose how to enter the machine. */
	void optionSelectingMachine();

	/* �������, ����� ������ �� ����������� �� ������ �� ���� �� ����� ��������� �������.
	   A function that helps the user choose how to enter the tapes. */
	void optionSelectingTapes();

	/* �������, ����� ������ �� ����������� �� ������ ��� �� ����� ����������� ����������� �� �������� �� �������� - ���� ��� ���� ��� � ���������.
	   A function that gives a choice of how to present the results of machine processing of the tapes - in a file or in the console. */
	void optionSelectingInspection(const std::vector<int>&);

public:
	/* ����������� �� ������������. ���������� �� ��������� optionSelectingMachine() � optionSelectingTapes().
	   Default constructor. The optionSelectingMachine() and optionSelectingTapes() functions are activated. */
	TuringMachine();
	TuringMachine(Head&, std::vector<Tape>&, std::string&);								///����������� � ���������. / Constructor with parameters.
	TuringMachine(const TuringMachine&);												///������� �����������. / Copy constructor.
	TuringMachine& operator=(const TuringMachine&);										///������������� �� �������� �� ����������� = / Redefine assignment operator =

	/* �������, ����� ��������� � �������� ����� ����� �� ��������� ������ � �����.
	   A function that stores in the machine each tape of the given vector of tapes. */
	void addTapes(const std::vector<Tape>&);

	/* �������, ����� ����� ���� �������� ������ �������� � ���������� �� ���� ���� ������ ����� � �������� �� ���������� �������.
	   A function that returns a boolean value as a result depending on whether all lanes in the machine have been processed successfully. */
	const bool processingSuccessful();

	/* �������, ����� ��� ����� �� ����������� �� ����������� �� ���������, �������� �������, ��� ����� �� ������ �������, � �������.
	   When the user selects the results to be displayed on the console, this function colors the symbol above the head in red. */
	void markHeadPosition(const char&);

	/* �������, ����� ����� ���� �������� �������.
	   A function that returns the head as a result. */
	const Head& getHead() const;

	/* �������, ����� ����� ���� �������� �������.
	   A function that returns the tapes as a result. */
	const std::vector<Tape>& getTapes() const;

	/* �������, ����� ����� ���� �������� ����������� �� ��������.
	   A function that returns the machine state as a result. */
	const std::string& getState() const;

	/* �������, ����� ����� ���� �������� ������� �� ����������� �� ����������� �� �������.
	   A function that returns the vector of the results of the tapes processing as a result. */
	const std::vector<bool>& getResults() const;

	/* �������, ����� ��������� ������� � ��������. ��� ��������� �� ��������� halt �������� ��������� ������ � �������, ����� � � ������ �� ��������� � �� �� ����� �� ���������� �������. 
	   � �������� ������ ������� �� ����� �� ��������� ���������� - ����������� �� �������� ������, �������� �����. ��������� �� ��������� optionSelectingInspection().
	   A function that processes the belts in the machine. When the halt state is reached, the machine finishes working with the tape, which is in the process of processing and it is considered to have been processed successfully. 
	   Otherwise, the tape is considered unsuccessful processed - failure to detect a suitable transition, endless cycle. The optionSelectingInspection() function is activated. */
	void run();

	/* �������, ����� ��������� run() �� �������� ������. ���� ���� ������ ����� �� ���������� �� ���������� ������ �� ������������ ��������� �� ���.
	   A function that activates run() on the current machine. Then all the tapes are transferred to the given machine for additional processing by it. */
	void compose(TuringMachine&);

	/* �������, ����� ��������� run() �� �������� ������. ���� ����, � ���������� �� ��������� ���� ������ ����� �� ���������� ������� ��� ��, �� ������ ��������� ������� ��� ������� 
	   �� ���������� � �� ��������� ������ �� ������� ����� �� ������� �� ����� ������� ��������� �� �������� ������, ����� �� ����� ������ �� ������� ���� � ���� �����.
	   A function that activates run() on the current machine. Then, depending on whether all the tapes have been processed successfully or not, the first or second of the given machines 
	   respectively is selected and copies of the tapes before their processing of the current machine are fed to the selected machine, i.e. the same tapes are fed to both machines. */
	void branch(TuringMachine&, TuringMachine&);

	/* �������, ����� �� ������ ����� � �������� ����� ���� ���� �����.
	   A function that makes all the tapes in the machine into a common tape. */
	void toSingleTape();
};

