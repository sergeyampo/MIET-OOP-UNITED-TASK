#pragma once

#include "FileIO.h"
#include <string>
#include <cctype>
#include <iostream>

bool IsDigits(std::string str) {
	int i = 0;
	int size = str.size();
	while (isdigit(str[i]) & i < size) {
		++i;
	}
	return (i == size);
}

bool IsRealNum(std::string str) {
	int i = 0;
	int size = str.size();
	bool PointFound = false;
	while ((isdigit(str[i]) || str[i]=='.') & i < size) {
		if (str[i] == '.' & !PointFound)
			PointFound = true;
		if (str[i] == '.' & PointFound)
			return false;
		++i;
	}
	return (i == size);
}

bool IsLetters(std::string str) {
	int i = 0;
	int size = str.size();
	while (isalpha(str[i]) & i < size) {
		++i;
	}
	return (i == size);
}

bool IsWords(std::string str) {
	int i = 0;
	int size = str.size();
	while ((isalpha(str[i]) || (isblank(str[i])) & i < size)) {
		++i;
	}
	return (i == size);
}

	/*
	static bool IsFilename(std::string str) {
		int i = 0;
		int size = str.size();
		while (isdigit(str[i]) & i < size) {
			++i;
		}
		return (i == size);
	}
	*/

int EnterInt() {
	std::string text;
	std::cin >> text;
	if (IsDigits(text))
		return stoi(text);
	else {
		ClearCin(std::cin);
		std::cout << "Incorrect input, repeat please";
		return EnterInt();
	}
}

double EnterDouble() {
	std::string text;
	std::cin >> text;
	if (IsRealNum(text))
		return stof(text);
	else {
		ClearCin(std::cin);
		std::cout << "Incorrect input, repeat please";
		return EnterDouble();
	}
}

std::string EnterLetters() {
	std::string text;
	std::cin >> text;
	if (IsLetters(text))
		return text;
	else {
		ClearCin(std::cin);
		std::cout << "Incorrect input, repeat please";
		return EnterLetters();
	}
}

std::string EnterWords() {
	std::string text;
	std::cin >> text;
	if (IsWords(text))
		return text;
	else {
		ClearCin(std::cin);
		std::cout << "Incorrect input, repeat please";
		return EnterWords();
	}
}