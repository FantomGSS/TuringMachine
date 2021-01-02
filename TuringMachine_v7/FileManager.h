#pragma once
#include <fstream>
#include "Tape.h"
#include "Messages.h"

/* Клас FileManager, който отговаря за правилната работа с даден файл.
   FileManager class, which is responsible for proper file handling. */
class FileManager
{
private:
	std::string filePath;																///Символен низ, който представлява път във файловата система и името, и разширението на файла.
																						///A character string that represents a path in the file system and the file name and extension.
	/* Функция, която копира стойностите на подадения обект.
	   A function that copies the values of the given object. */
	void copy(const FileManager&);

	/* Функция, която от символния низ взема само името и разширението на файла. 
	   A function that takes only the file name and extension from the character string. */
	const std::string getFileName();

	/* Съобщение, което се изкарва при възникнала грешка по време на отваряне на файл. 
	   A message that is displayed when an error occurs while opening a file. */
	void printErrorMessage();

	/* Съобщение, което се изкарва при успешно прочитане на съдържанието на файл.
	   A message that is displayed when the contents of a file are successfully read. */
	void printSuccessReadMessage();

	/* Съобщение, което се изкарва при успешно създаване на файл.
	   A message that is displayed when a file is successfully created. */
	void printSuccessCreateMessage();

public:
	FileManager(std::string&);															///Конструктор с параметри. / Constructor with parameters.
	FileManager(const FileManager&);													///Копиращ конструктор. / Copy constructor.
	FileManager& operator=(const FileManager&);											///Предефиниране на оператор за присвояване = / Redefine assignment operator =

	/* Функция, която проверява дали съществува файлът, който е посочен от символния низ.
	   A function that checks if the file specified by the character string exists. */
	const bool fileExists();

	/* Функция, която проверява дали символният низ е валиден.
	   A function that checks if the character string is valid. */
	const bool checkFilePath();

	/* Функция, която отваря файл, чете ред по ред цялото съдържание и съхранява редовете във подадения векторът.
	   A function that opens a file, reads all the content line by line and stores the lines in the given vector. */
	void getLinesFromFile(std::vector<std::string>&);

	/* Функция, която създава файл и го попълва с необходимата информация за всяка лента в машината: обработка, състояние на лентата и позиция на главата.
	   A function that creates a file and fill it with the necessary information for each tape in the machine: processing (tapes), tape status (results) and head position. */
	void saveResult(std::vector<Tape>&, std::vector<bool>&, std::vector<int>&);
};

