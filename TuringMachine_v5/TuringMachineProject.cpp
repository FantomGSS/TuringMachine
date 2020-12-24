#include "TuringMachine.h"

int main()
{
	TuringMachine one = TuringMachine();
	TuringMachine two = TuringMachine();
	//TuringMachine three = TuringMachine();

	//one.run();
	one.compose(two);
}
