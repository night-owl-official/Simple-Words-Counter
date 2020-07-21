#include "Helpers.h"

#include <fstream>

std::string ReadFile(const std::string& filePath) {
	// Try to open the given file
	std::ifstream inputFile;
	inputFile.open(filePath);

	// Don't continue if the file didn't open correctly
	if (!inputFile.is_open())	return "";

	// Keep reading until the end of the file
	std::string textFile = "";
	while (!inputFile.eof())	std::getline(inputFile, textFile, '\0');

	// Close the file
	inputFile.close();

	return textFile;
}

unsigned int GetWordsCount(const std::string& txt) {
	return 1;
}