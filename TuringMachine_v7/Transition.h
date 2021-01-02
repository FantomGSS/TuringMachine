#pragma once
#include <iostream>
#include <string>
#include <regex>

/* ���� � �������� (������ �����), �� ����� ������������ ������ �� �������� ���� ������. <������><���������> -> <������><���������><�������> 
   ��������� ���� �� ���� L, R ��� S. ��������� ����������� � ���� ������� ������, ������� ��� ��� �������. 
   This is the format (regex expression) in which a transition must look. <symbol><state> -> <symbol><state><command> 
   The command can be L, R or S. Respectively move one position to the left, right or without change. */
const std::string FORMAT_TRANSITION = "^(.)[{](.+)[}][ ][-][>][ ](.)[{](.+)[}]([L|R|S])$";

/* ���� Transition, ����� ������������ ������ � �������� �� ������.
   Transition class, which is a transition in the Turing machine. */
class Transition
{
private:
	char conditionSymbol;																///������� ������. / Conditional symbol.
	std::string conditionState;															///������� ���������. / Conditional state.
	char newSymbol;																		///��� ������. / New symbol.
	std::string newState;																///���� ���������. / New state.
	char command;																		///�������. / Command.

	/* �������, ����� ������ ����������� �� ��������� �����.
	   A function that copies the values of the given object. */
	void copy(const Transition&);

public:
	Transition();																		///����������� �� ������������. / Default constructor.
	Transition(std::string&);															///����������� � ���������. / Constructor with parameters.
	Transition(const Transition&);														///������� �����������. / Copy constructor.
	Transition& operator=(const Transition&);											///������������� �� �������� �� ����������� = / Redefine assignment operator =

	/* �������, ����� ����� ���� �������� �������� ������. 
	   A function that returns the conditional symbol as a result. */
	const char& getConditionSymbol() const;

	/* �������, ����� ����� ���� �������� ��������� ���������. 
	   A function that returns the conditional state as a result. */
	const std::string& getConditionState() const;

	/* �������, ����� ����� ���� �������� ����� ������.
	   A function that returns the new symbol as a result. */
	const char& getNewSymbol() const;

	/* �������, ����� ����� ���� �������� ������ ���������.
	   A function that returns the new state as a result. */
	const std::string& getNewState() const;

	/* �������, ����� ����� ���� �������� ���������.
	   A function that returns the command as a result. */
	const char& getCommand() const;

	friend std::ostream& operator<<(std::ostream&, const Transition&);					///������������� �� �������� �� �������� << / Redefine insert operator <<
};

