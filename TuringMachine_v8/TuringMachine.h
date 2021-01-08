#pragma once
#include <time.h>
#include "Head.h"
#include "Tape.h"
#include "FileManager.h"

/* След толкова секунди машината на Тюринг спира да работи, ако по друг начин не е спряла. 
   Това се прави с цел да се предпазим от встъпване на машината в безкраен цикъл по време на обработка на някоя лента.
   After this number of seconds, the Turing machine stops working if it has not otherwise stopped.
   This is done in order to prevent the machine from entering an endless cycle during the processing of a tape. */
const int SECONDS_BEFORE_END = 10;

/* Клас TuringMachine, който представлява машината на Тюринг.
   TuringMachine class, which is the Turing machine. */
class TuringMachine
{
private:
	Head head;																			///Глава. / Head.
	std::vector<Tape> tapes;															///Ленти. / Tapes.
	std::string state;																	///Състояние на машината / Machine state.
	std::vector<bool> results;															///Резултатите от обработката на лентите. / The results of the processing of the tapes.

	/* Функция, която копира стойностите на подадения обект.
	   A function that copies the values of the given object. */
	void copy(const TuringMachine&);

	/* Функция, която връща булева стойност в зависимост от това дали символния низ отговаря на изисквания формат за преход.
	   A function that returns a boolean value depending on whether the character string matches the required transition format. */
	bool checkTransitionFormat(const std::string&);

	/* Функция, която чете машина на Тюринг от файл.
	   A function that reads a Turing machine from a file. */
	void readMachineFromFile();

	/* Функция, която чете ленти от файл.
	   A function that reads tapes from a file. */
	void readTapesFromFile();

	/* Функция, която чете машина на Тюринг от конзолата.
	   A function that reads a Turing machine from the console. */
	void readMachineFromConsole();

	/* Функция, която чете ленти от конзолата.
	   A function that reads tapes from the console. */
	void readTapesFromConsole();

	/* Функция, която помага на потребителя да избере от къде да бъде прочетена машината.
	   A function that helps the user choose how to enter the machine. */
	void optionSelectingMachine();

	/* Функция, която помага на потребителя да избере от къде да бъдат прочетени лентите.
	   A function that helps the user choose how to enter the tapes. */
	void optionSelectingTapes();

	/* Функция, която помага на потребителя да избере как да бъдат представени резултатите от работата на машината - дали във файл или в конзолата.
	   A function that gives a choice of how to present the results of machine processing of the tapes - in a file or in the console. */
	void optionSelectingInspection(const std::vector<int>&);

public:
	/* Конструктор по подразбиране. Задействат се функциите optionSelectingMachine() и optionSelectingTapes().
	   Default constructor. The optionSelectingMachine() and optionSelectingTapes() functions are activated. */
	TuringMachine();
	TuringMachine(Head&, std::vector<Tape>&, std::string&);								///Конструктор с параметри. / Constructor with parameters.
	TuringMachine(const TuringMachine&);												///Копиращ конструктор. / Copy constructor.
	TuringMachine& operator=(const TuringMachine&);										///Предефиниране на оператор за присвояване = / Redefine assignment operator =

	/* Функция, която съхранява в машината всяка лента от подадения вектор с ленти.
	   A function that stores in the machine each tape of the given vector of tapes. */
	void addTapes(const std::vector<Tape>&);

	/* Функция, която връща като резултат булева стойност в зависимост от това дали всички ленти в машината са обработени успешно.
	   A function that returns a boolean value as a result depending on whether all lanes in the machine have been processed successfully. */
	const bool processingSuccessful();

	/* Функция, която при избор за представяне на резултатите на конзолата, оцветява символа, над който се намира главата, в червено.
	   When the user selects the results to be displayed on the console, this function colors the symbol above the head in red. */
	void markHeadPosition(const char&);

	/* Функция, която връща като резултат главата.
	   A function that returns the head as a result. */
	const Head& getHead() const;

	/* Функция, която връща като резултат лентите.
	   A function that returns the tapes as a result. */
	const std::vector<Tape>& getTapes() const;

	/* Функция, която връща като резултат състоянието на машината.
	   A function that returns the machine state as a result. */
	const std::string& getState() const;

	/* Функция, която връща като резултат вектора от резултатите от обработката на лентите.
	   A function that returns the vector of the results of the tapes processing as a result. */
	const std::vector<bool>& getResults() const;

	/* Функция, която обработва лентите в машината. При достигане на състояние halt машината приключва работа с лентата, която е в процес на обработка и тя се счита за обработена успешно. 
	   В противен случай лентата се счита за неуспешно обработена - неоткриване на подходящ преход, безкраен цикъл. Задейства се функцията optionSelectingInspection().
	   A function that processes the belts in the machine. When the halt state is reached, the machine finishes working with the tape, which is in the process of processing and it is considered to have been processed successfully. 
	   Otherwise, the tape is considered unsuccessful processed - failure to detect a suitable transition, endless cycle. The optionSelectingInspection() function is activated. */
	void run();

	/* Функция, която задейства run() на текущата машина. След това всички ленти се прехвърлят на подадената машина за допълнителна обработка от нея.
	   A function that activates run() on the current machine. Then all the tapes are transferred to the given machine for additional processing by it. */
	void compose(TuringMachine&);

	/* Функция, която задейства run() на текущата машина. След това, в зависимост от резултата дали всички ленти са обработени успешно или не, се избира съответно първата или втората 
	   от подадените и на избраната машина се подават копия на лентите от преди тяхната обработка от текущата машина, тоест на двете машини се подават едни и същи ленти.
	   A function that activates run() on the current machine. Then, depending on whether all the tapes have been processed successfully or not, the first or second of the given machines 
	   respectively is selected and copies of the tapes before their processing of the current machine are fed to the selected machine, i.e. the same tapes are fed to both machines. */
	void branch(TuringMachine&, TuringMachine&);

	/* Функция, която от всички ленти в машината прави една обща лента.
	   A function that makes all the tapes in the machine into a common tape. */
	void toSingleTape();
};

