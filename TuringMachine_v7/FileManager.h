#pragma once
#include <fstream>
#include "Tape.h"
#include "Messages.h"

/* ���� FileManager, ����� �������� �� ���������� ������ � ����� ����.
   FileManager class, which is responsible for proper file handling. */
class FileManager
{
private:
	std::string filePath;																///�������� ���, ����� ������������ ��� ��� ��������� ������� � �����, � ������������ �� �����.
																						///A character string that represents a path in the file system and the file name and extension.
	/* �������, ����� ������ ����������� �� ��������� �����.
	   A function that copies the values of the given object. */
	void copy(const FileManager&);

	/* �������, ����� �� ��������� ��� ����� ���� ����� � ������������ �� �����. 
	   A function that takes only the file name and extension from the character string. */
	const std::string getFileName();

	/* ���������, ����� �� ������� ��� ���������� ������ �� ����� �� �������� �� ����. 
	   A message that is displayed when an error occurs while opening a file. */
	void printErrorMessage();

	/* ���������, ����� �� ������� ��� ������� ��������� �� ������������ �� ����.
	   A message that is displayed when the contents of a file are successfully read. */
	void printSuccessReadMessage();

	/* ���������, ����� �� ������� ��� ������� ��������� �� ����.
	   A message that is displayed when a file is successfully created. */
	void printSuccessCreateMessage();

public:
	FileManager(std::string&);															///����������� � ���������. / Constructor with parameters.
	FileManager(const FileManager&);													///������� �����������. / Copy constructor.
	FileManager& operator=(const FileManager&);											///������������� �� �������� �� ����������� = / Redefine assignment operator =

	/* �������, ����� ��������� ���� ���������� ������, ����� � ������� �� ��������� ���.
	   A function that checks if the file specified by the character string exists. */
	const bool fileExists();

	/* �������, ����� ��������� ���� ���������� ��� � �������.
	   A function that checks if the character string is valid. */
	const bool checkFilePath();

	/* �������, ����� ������ ����, ���� ��� �� ��� ������ ���������� � ��������� �������� ��� ��������� ��������.
	   A function that opens a file, reads all the content line by line and stores the lines in the given vector. */
	void getLinesFromFile(std::vector<std::string>&);

	/* �������, ����� ������� ���� � �� ������� � ������������ ���������� �� ����� ����� � ��������: ���������, ��������� �� ������� � ������� �� �������.
	   A function that creates a file and fill it with the necessary information for each tape in the machine: processing (tapes), tape status (results) and head position. */
	void saveResult(std::vector<Tape>&, std::vector<bool>&, std::vector<int>&);
};

