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
/// <param name="shouldIncludeNumbers">Should numbers be counted as words?</param>
/// <returns>The number of words in the text</returns>
unsigned int GetWordsCount(const std::string& txt, bool shouldIncludeNumbers);

/// <summary>
/// Takes a character and returns whether or not it's a letter
/// </summary>
/// <param name="c">The character to check</param>
/// <returns>Is the character a letter?</returns>
bool IsAlpha(char c);

/// <summary>
/// Takes a character and returns whether or not it's a number
/// </summary>
/// <param name="c">The character to check</param>
/// <returns>Is the character a number?</returns>
bool IsNumber(char c);

/// <summary>
/// Takes a character and returns whether or not is a whitespace
/// </summary>
/// <param name="c">The character to check</param>
/// <returns>Is the character a whitespace?</returns>
bool IsWhiteSpace(char c);

/// <summary>
/// Takes two characters and decides whether it was the last one in a word or not
/// </summary>
/// <param name="current">The character currently being iterated</param>
/// <param name="previous">The character previously being iterated</param>
/// <param name="doNumbersCount">Do numbers count as a word?</param>
/// <returns>Is the character the last one in a word?</returns>
bool IsWord(char current, char previous, bool doNumbersCount);
