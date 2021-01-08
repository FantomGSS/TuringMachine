#pragma once
#include <iostream>
#include <vector>
#include <string>

const char EMPTY_CELL = '_';                                                            ///���� ���� ������ �� �������� �������� ������ � ����������� ����������� ���������� �����.
                                                                                        ///This symbol fills empty cells in the potentially infinite two-way tape.

/* ���� Tape, ����� ������������ �����, ����� �� ������ �� ����������� �������� ���� ������.
   Tape class, which is a tape that consists of a potentially infinite number of cells. */
class Tape 
{
private:
	std::vector<char> cells;                                                            ///�������� � �������. / The cells in the tape.

    /* �������, ����� ������ ����������� �� ��������� �����.
       A function that copies the values of the given object. */
	void copy(const Tape&);

    /* �������, ����� ��������� ��������� ������ � ���� �� �������. 
       A function that stores the given symbol at the end of the vector. */
    void pushBackCell(const char&);

    /* �������, ����� ��������� ��������� ������ � �������� �� �������.
       A function that stores the given symbol at the beginning of the vector. */
    void pushFrontCell(const char&);

public:
    Tape();                                                                             ///����������� �� ������������. / Default constructor.
    Tape(std::string&);                                                                 ///����������� � ���������. / Constructor with parameters.
    Tape(const Tape&);                                                                  ///������� �����������. / Copy constructor.
    Tape& operator=(const Tape&);                                                       ///������������� �� �������� �� ����������� = / Redefine assignment operator =

    /* �������, ����� ������� ������� � �� ���� ������ ������ � �������� � � ����. ����� � �� �� ������, �� ������� ���� �� ���� ���������.
       A function that complements the bar with one empty cell at the beginning and one at the end. The purpose is to show that the tape can be infinite. */
    void formInfiniteTape();

    /* �������, ����� �� �������� ������� � ������� � ������, ���� ������� �� ���� ������� � ������� ���������.
       ��� ��������� � ������� ��� ������, � ������� ��������� � �������� ��� � ���� �� ������� ������ ������, �� �� �� ������ �������������.
       By a given position in the tape, this function deletes the symbol at that position and saves the given symbol at that location.
       If the position is initial or end, an empty cell respectively is added to the tape at the beginning or end, to maintain infinity. */
    void setCell(const int&, const char&);

    /* �������, ����� ����� ���� �������� ������� (������� �� ������). 
       A function that returns the tape (vector of cells) as a result. */
    const std::vector<char>& getCells() const;

    friend std::ostream& operator<<(std::ostream&, const Tape&);                        ///������������� �� �������� �� �������� << / Redefine insert operator <<
};

