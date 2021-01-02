#pragma once
#include <iostream>
#include <string>
#include <regex>

/* Това е форматът (регекс израз), по който задължително трябва да изглежда един преход. <символ><състояние> -> <символ><състояние><команда> 
   Командата може да бъде L, R или S. Съответно преместване с една позиция наляво, надясно или без промяна. 
   This is the format (regex expression) in which a transition must look. <symbol><state> -> <symbol><state><command> 
   The command can be L, R or S. Respectively move one position to the left, right or without change. */
const std::string FORMAT_TRANSITION = "^(.)[{](.+)[}][ ][-][>][ ](.)[{](.+)[}]([L|R|S])$";

/* Клас Transition, който представлява преход в машината на Тюринг.
   Transition class, which is a transition in the Turing machine. */
class Transition
{
private:
	char conditionSymbol;																///Условен символ. / Conditional symbol.
	std::string conditionState;															///Условно състояние. / Conditional state.
	char newSymbol;																		///Нов символ. / New symbol.
	std::string newState;																///Ново състояние. / New state.
	char command;																		///Команда. / Command.

	/* Функция, която копира стойностите на подадения обект.
	   A function that copies the values of the given object. */
	void copy(const Transition&);

public:
	Transition();																		///Конструктор по подразбиране. / Default constructor.
	Transition(std::string&);															///Конструктор с параметри. / Constructor with parameters.
	Transition(const Transition&);														///Копиращ конструктор. / Copy constructor.
	Transition& operator=(const Transition&);											///Предефиниране на оператор за присвояване = / Redefine assignment operator =

	/* Функция, която връща като резултат условния символ. 
	   A function that returns the conditional symbol as a result. */
	const char& getConditionSymbol() const;

	/* Функция, която връща като резултат условното състояние. 
	   A function that returns the conditional state as a result. */
	const std::string& getConditionState() const;

	/* Функция, която връща като резултат новия символ.
	   A function that returns the new symbol as a result. */
	const char& getNewSymbol() const;

	/* Функция, която връща като резултат новото състояние.
	   A function that returns the new state as a result. */
	const std::string& getNewState() const;

	/* Функция, която връща като резултат командата.
	   A function that returns the command as a result. */
	const char& getCommand() const;

	friend std::ostream& operator<<(std::ostream&, const Transition&);					///Предефиниране на оператор за вмъкване << / Redefine insert operator <<
};

