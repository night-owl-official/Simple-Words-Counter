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

unsigned int GetWordsCount(const std::string& txt, bool shouldIncludeNumbers) {
	// Don't continue if the string is null or empty
	if (txt == "" || txt.empty())	return 0;


}

bool IsAlpha(char c) {
	// Is the character a letter in ASCII?
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c >= 'z');
}

bool IsNumber(char c) {
	// Is the character a digit in ASCII?
	return c >= '0' && c <= '9';
}

bool IsWhiteSpace(char c) {
	// Is it a whitespace type character?
	return c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f';
}

bool IsWord(char current, char previous, bool doNumbersCount) {
	bool isPreviousCharAlphaNumeric = doNumbersCount ?
		(IsAlpha(previous) || IsNumber(previous)) :
		IsAlpha(previous);

	return IsWhiteSpace(current) && isPreviousCharAlphaNumeric;
}