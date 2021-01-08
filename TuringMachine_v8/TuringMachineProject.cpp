#include "TuringMachine.h"

int main()
{
	/* 
	   �� ��������, ���� ���������� �� ���������� ����������, ���� �� ���������� ������������ � �������� �������� �������:
	   For convenience, after starting the console application, you can use the content in the following text files:
	
	   TuringMachine one - EntryOfFirstMachine.txt (��������� �� �������� �� ������ ���� ���� ������� / Input of the Turing machine only through files)
	   TuringMachine two - ManualEntryOfSecondMachine.txt (��������� �� �������� �� ������ ���� ���� ��������� / Input of the Turing machine only through the console)
	   TuringMachine three - MixedEntryOfThirdMachine.txt (��������� �� �������� �� ������ ���� ���� � ���� ��������� / Input of the Turing machine through a file and the through console)
	*/

	TuringMachine one = TuringMachine();
	//one.toSingleTape();
	//std::cout << one.getTapes().front();
	one.run();

	/*
	TuringMachine one = TuringMachine();
	TuringMachine two = TuringMachine();
	one.compose(two);
	*/

	/*
	TuringMachine one = TuringMachine();
	TuringMachine two = TuringMachine();
	TuringMachine three = TuringMachine();
	one.branch(two, three);
	*/
}
