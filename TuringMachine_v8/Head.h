#pragma once
#include "Transition.h"

/* ���� Head, ����� ������������ ���������� (����� �� ������ �� ������), ����� ��������� ����� �� ������� (�������).
   ������� ���� �� ����, ������� � ������ ���� ������� � ���� �� �� ����� ���������� �� �������.
   Head class, which is a device (head of the Turing machine) that executes a set of rules (transitions).
   The head can read, delete and print new characters and can move in both directions on the tape. */
class Head
{
private:
	int position;																		///��������� �� ������� ����� �������. / The position of the head on the tape.
	std::vector<Transition> transitions;												///����� �� ������� (�������). / Set of rules (transitions).

	/* �������, ����� ������ ����������� �� ��������� �����.
	   A function that copies the values of the given object. */
	void copy(const Head&);

public:
	Head();																				///����������� �� ������������. / Default constructor.
	Head(std::vector<Transition>&);														///����������� � ���������. / Constructor with parameters.
	Head(const Head&);																	///������� �����������. / Copy constructor.
	Head& operator=(const Head&);														///������������� �� �������� �� ����������� = / Redefine assignment operator =

	/* �������, ����� ��������� ������� � ���� ������� �������.
	   A function that moves the head one position to the right. */
	void positionToTheRight();

	/* �������, ����� ��������� ������� � ���� ������� ������.
	   A function that moves the head one position to the left. */
	void positionToTheLeft();

	/* �������, ����� ��������� ������� � ������� �������.
	   Function that moves the head to the starting position. */
	void restartPosition();

	/* �������, ����� �� �������� ������ � ��������� �� ��������, ����� ������������ ������ � ����� �������� ������� ��� �������.
	   ����� �� -1 ���� ��������, ��� �� �� ������ ������, ����� �� �������� �� ���������� �������.
	   By a given symbol and state of the machine, this function searches for the required transition and returns its position in the vector.
	   -1 is returned as a result if no transition is found that meets the given conditions. */
	const int& findTransition(char&, const std::string&);

	/* �������, ����� ����� ���� �������� ��������� �� �������.
	   A function that returns the head position as a result. */
	const int& getPosition() const;

	/* �������, ����� ����� ���� �������� ������� �� �������.
	   A function that returns the vector of transitions as a result. */
	const std::vector<Transition>& getTransitions() const;

	/* �������, ����� ��������� ��������� ������ ��� ������� �� �������.
	   A function that stores the given transition in the vector of transitions. */
	void addTransition(const Transition&);
};

