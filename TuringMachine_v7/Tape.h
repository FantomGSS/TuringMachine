#pragma once
#include <iostream>
#include <vector>
#include <string>

const char EMPTY_CELL = '_';                                                            ///Чрез този символ се попълват празните клетки в потенциално безкрайната двупосочна лента.
                                                                                        ///This symbol fills empty cells in the potentially infinite two-way tape.

/* Клас Tape, който представлява лента, която се състои от потенциално безкраен брой клетки.
   Tape class, which is a tape that consists of a potentially infinite number of cells. */
class Tape 
{
private:
	std::vector<char> cells;                                                            ///Клетките в лентата. / The cells in the tape.

    /* Функция, която копира стойностите на подадения обект.
       A function that copies the values of the given object. */
	void copy(const Tape&);

    /* Функция, която съхранява подадения символ в края на вектора. 
       A function that stores the given symbol at the end of the vector. */
    void pushBackCell(const char&);

    /* Функция, която съхранява подадения символ в началото на вектора.
       A function that stores the given symbol at the beginning of the vector. */
    void pushFrontCell(const char&);

public:
    Tape();                                                                             ///Конструктор по подразбиране. / Default constructor.
    Tape(std::string&);                                                                 ///Конструктор с параметри. / Constructor with parameters.
    Tape(const Tape&);                                                                  ///Копиращ конструктор. / Copy constructor.
    Tape& operator=(const Tape&);                                                       ///Предефиниране на оператор за присвояване = / Redefine assignment operator =

    /* Функция, която допълва лентата с по една празна клетка в началото и в края. Целта е да се покаже, че лентата може да бъде безкрайна.
       A function that complements the bar with one empty cell at the beginning and one at the end. The purpose is to show that the tape can be infinite. */
    void formInfiniteTape();

    /* Функция, която по подадени позиция в лентата и символ, трие символа на тази позиция и записва подадения.
       Ако позицията е начална или крайна, в лентата съответно в началото или в края се допълва празна клетка, за да се запази безкрайността.
       By a given position in the tape, this function deletes the symbol at that position and saves the given symbol at that location.
       If the position is initial or end, an empty cell respectively is added to the tape at the beginning or end, to maintain infinity. */
    void setCell(const int&, const char&);

    /* Функция, която връща като резултат лентата (вектора от клетки). 
       A function that returns the tape (vector of cells) as a result. */
    const std::vector<char>& getCells() const;

    friend std::ostream& operator<<(std::ostream&, const Tape&);                        ///Предефиниране на оператор за вмъкване << / Redefine insert operator <<
};

