#pragma once

#include <string>

/// <summary>
/// Properties of a text file
/// </summary>
struct TextFile {
	std::string text;
	unsigned int wordsCount;
};

/// <summary>
/// Reads the given file and returns it as a string
/// </summary>
/// <param name="filePath">The path to the file</param>
/// <returns>The text in the file</returns>
std::string ReadFile(const std::string& filePath);

/// <summary>
/// Counts how many words are in the given text file
/// </summary>
/// <param name="txt">The text to count words from</param>
/// <returns>The number of words in the text</returns>
unsigned int GetWordsCount(const std::string& txt);
