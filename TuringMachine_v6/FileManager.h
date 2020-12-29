#pragma once
#include <fstream>
#include "Tape.h"
#include "Messages.h"

class FileManager
{
private:
	std::string filePath;

	void copy(const FileManager& fileManager);

	const std::string getFileName();
	void printErrorMessage();
	void printSuccessSaveMessage();
	void printSuccessReadMessage();
	void printSuccessCreateMessage();

public:
	FileManager(std::string&);
	FileManager(const FileManager&);
	FileManager& operator=(const FileManager&);

	const bool fileExists();
	const bool checkFilePath();
	void getLinesFromFile(std::vector<std::string>&);
	void saveResult(std::vector<Tape>&, std::vector<bool>&, std::vector<int>&);
};

