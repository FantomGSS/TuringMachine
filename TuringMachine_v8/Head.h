#pragma once
#include "Transition.h"

/* Клас Head, който представлява устройство (глава на машина на Тюринг), което изпълнява набор от правила (преходи).
   Главата може да чете, изтрива и печата нови символи и може да се движи двупосочно по лентата.
   Head class, which is a device (head of the Turing machine) that executes a set of rules (transitions).
   The head can read, delete and print new characters and can move in both directions on the tape. */
class Head
{
private:
	int position;																		///Позицията на главата върху лентата. / The position of the head on the tape.
	std::vector<Transition> transitions;												///Набор от правила (преходи). / Set of rules (transitions).

	/* Функция, която копира стойностите на подадения обект.
	   A function that copies the values of the given object. */
	void copy(const Head&);

public:
	Head();																				///Конструктор по подразбиране. / Default constructor.
	Head(std::vector<Transition>&);														///Конструктор с параметри. / Constructor with parameters.
	Head(const Head&);																	///Копиращ конструктор. / Copy constructor.
	Head& operator=(const Head&);														///Предефиниране на оператор за присвояване = / Redefine assignment operator =

	/* Функция, която премества главата с една позиция надясно.
	   A function that moves the head one position to the right. */
	void positionToTheRight();

	/* Функция, която премества главата с една позиция наляво.
	   A function that moves the head one position to the left. */
	void positionToTheLeft();

	/* Функция, която премества главата в начална позиция.
	   Function that moves the head to the starting position. */
	void restartPosition();

	/* Функция, която по подадени символ и състояние на машината, търси необходимият преход и връща неговата позиция във вектора.
	   Връща се -1 като резултат, ако не се открие преход, който да отговаря на подадените условия.
	   By a given symbol and state of the machine, this function searches for the required transition and returns its position in the vector.
	   -1 is returned as a result if no transition is found that meets the given conditions. */
	const int& findTransition(char&, const std::string&);

	/* Функция, която връща като резултат позицията на главата.
	   A function that returns the head position as a result. */
	const int& getPosition() const;

	/* Функция, която връща като резултат вектора от преходи.
	   A function that returns the vector of transitions as a result. */
	const std::vector<Transition>& getTransitions() const;

	/* Функция, която съхранява подадения преход във вектора от преходи.
	   A function that stores the given transition in the vector of transitions. */
	void addTransition(const Transition&);
};

