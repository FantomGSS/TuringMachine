#include "FileManager.h"

void FileManager::copy(const FileManager& fileManager)
{
    filePath = fileManager.filePath;
}

const std::string FileManager::getFileName()
{
    int index = filePath.find_last_of('\\');
    std::string name;
    if (index != -1)
    {
        name = filePath.substr(index + 1);
    }
    else
    {
        name = filePath;
    }

    return name;
}

void FileManager::printErrorMessage()
{
    std::cerr << '\n';
    std::cerr << "There was a problem opening file with name: " << getFileName() << '\n';
    std::cerr << '\n';
}

void FileManager::printSuccessSaveMessage()
{
    std::cout << "===========================================================" << std::endl;
    std::cout << "All changes are saved successfully in the file " << getFileName() << "!" << std::endl;
    std::cout << "===========================================================" << std::endl;
}

void FileManager::printSuccessReadMessage()
{
    std::cout << "===========================================================" << std::endl;
    std::cout << "Successfully opened " << getFileName() << "!" << std::endl;
    std::cout << "===========================================================" << std::endl;
}

void FileManager::printSuccessCreateMessage()
{
    std::cout << "===========================================================" << std::endl;
    std::cout << "Successfully created " << getFileName() << "!" << std::endl;
    std::cout << "===========================================================" << std::endl;
}

FileManager::FileManager(std::string& filePath)
{
    this->filePath = filePath;
}

FileManager::FileManager(const FileManager& fileManager)
{
    copy(fileManager);
}

FileManager& FileManager::operator=(const FileManager& fileManager)
{
    if (this != &fileManager)
    {
        this->copy(fileManager);
    }
    return *this;
}

const bool FileManager::fileExists()
{
    bool fileExists = false;
    std::ifstream inputFileStream;
    inputFileStream.open(filePath, std::ios::in);

    if (inputFileStream.good())
    {
        fileExists = true;
        inputFileStream.close();
    }

    return fileExists;
}

const bool FileManager::checkFilePath()
{
    bool validFilePath = true;
    if (filePath.find(">") != -1 || filePath.find("<") != -1
        || filePath.find("/") != -1 || filePath.find("|") != -1)
    {
        std::cout << INVALID_PATH << std::endl;
        validFilePath = false;
    }

    return validFilePath;
}

void FileManager::getLinesFromFile(std::vector<std::string>& lines)
{
    std::string line;
    int lineCounter = 0;
    std::ifstream inputFileStream;
    inputFileStream.open(filePath, std::ios::in);

    if (inputFileStream.is_open()) {
        while (getline(inputFileStream, line))
        {
            lines.push_back(line);
        }
        inputFileStream.close();
        printSuccessReadMessage();
    }
    else {
        printErrorMessage();
    }
}

void FileManager::saveResult(std::vector<Tape>& tapes, std::vector<bool>& results, std::vector<int>& headPositions)
{
    std::ofstream outputFileStream;
    outputFileStream.open(filePath, std::ios::out);

    if (outputFileStream.is_open()) 
    {
        for (int i = 0; i < tapes.size(); i++)
        {
            outputFileStream << tapes[i];
            if (results[i])
            {
                outputFileStream << PROCESSED_SUCCESSFULLY;
            }
            else
            {
                outputFileStream << NOT_PROCESSED_SUCCESSFULLY;
            }

            outputFileStream << ' ' << headPositions[i] << '\n';
        }

        outputFileStream.close();
        printSuccessSaveMessage();
    }
    else 
    {
        printErrorMessage();
    }
}
