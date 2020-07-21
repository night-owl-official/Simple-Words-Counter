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

	unsigned int count = 0;
	char currentChar = ' ';
	char previousChar = ' ';

	// Loop through the entire string
	size_t i = 0;
	while (txt[i] != '\0') {
		// Current character is this character
		currentChar = txt[i];

		// Increase the count if it's a word
		if (IsWord(currentChar, previousChar, shouldIncludeNumbers))	count++;

		// Previous character becomes the current one
		previousChar = currentChar;

		// Move to the next character
		i++;
	}

	return count;
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
	// Numbers might be included as words depending on the given parameter
	bool isCurrentCharAlphaNumeric = doNumbersCount ?
		(IsAlpha(current) || IsNumber(current)) :
		IsAlpha(current);

	// When the previous character is some type of whitespace and
	// the current one is alphanumeric, then it's a word
	return IsWhiteSpace(previous) && isCurrentCharAlphaNumeric;
}