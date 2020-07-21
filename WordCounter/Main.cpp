#include "Helpers.h"

int main(int argc, char** argv) {
	// Store the file to analyze
	TextFile randomFile;
	randomFile.text = ReadFile(argv[1]);

	// Make sure the given file path is correct
	if (randomFile.text != "") {
		// Count the words in the file
		randomFile.wordsCount = GetWordsCount(randomFile.text);

		printf("There are %d words in this file", randomFile.wordsCount);
	} else {
		// File path was probably wrong
		printf("There was an error in reading the file! Make sure the file path is correct.");
	}

	return 0;
}