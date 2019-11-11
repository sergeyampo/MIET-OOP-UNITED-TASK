#pragma once

#include <iostream>
#include <string>
#include "Letter.h"


class LetterInteract {
public:
	LetterInteract() = delete;
   ~LetterInteract() = delete;


	//Общая функция ввода всех полей
	static Letter InputData() {
		Letter Buffer;
		std::string input;
		std::cout << "Enter index: ";
		Buffer.SetIndex(CorrectInput::EnterIntNum());
		ClearCin(std::cin);

		std::cout << "Enter reciever adresss: ";
		if (std::string input; getline(std::cin, input))
			Buffer.SetRecieverAddress(input);

		std::cout << "Enter reciever name: ";
		Buffer.SetRecieverName(CorrectInput::EnterSym());
		ClearCin(std::cin);

		std::cout << "Enter sender adresss: ";
		if (std::string input; getline(std::cin, input))
			Buffer.SetSenderAddress(input);

		std::cout << "Enter sender name: ";
		Buffer.SetSenderName(CorrectInput::EnterSym());
		ClearCin(std::cin);

		std::cout << "Enter cost: ";
		Buffer.SetCost(CorrectInput::EnterDoubleNum());
		ClearCin(std::cin);
		
		return Buffer;
	}

	static auto GetFindCritery() {
		std::cout << "Type the sender adress to find: ";
		ClearCin(std::cin);
		Man cmp;
		if (string buffer; getline(std::cin, buffer))
			cmp.SetAddress(buffer);

		return [cmp](Letter m) { return m == cmp; };
	}

	static auto GetFilterCritery() {
		std::cout << "Type the index for filtering: ";
		unsigned int buffer = CorrectInput::EnterIntNum();
		return [buffer](Letter m) { return m.GetIndex() == buffer; };
	}

	static auto GetSortCritery() {
		std::cout << "Sorting by increasing cost.\n";
		return [](Letter x, Letter y) { return x.GetCost() < y.GetCost(); };
	}

	static void OutputData(Letter buffer) {
		std::cout << buffer.GetIndex() << "\t" << buffer.GetRecieverAdress() << "\t" << buffer.GetRecieverName() << "\t" << buffer.GetSenderAddress() << "\t" << buffer.GetSenderName() << "\t" << buffer.GetCost() << "\n";
	}

	static const std::string& GetFilename() {
		return filename;
	}

	static void PrintColumnNames() {
		std::cout << "Index\t" << "Rec. Adress\t" << "Rec. Name\t" << "Sen. Adress\t" << "Sen. Name\t" << "Cost\n";
	}

	static string GetTableHeader()
	{
		return "Index|Rec. Adress|Rec. Name|Sen. Adress|Sen. Name|Cost\n"
	}

	static string GetFolderName()
	{
		return "Letter";
	}

  private:
	  inline static const std::string filename = "DatabaseOfLetters.cereal";
};


