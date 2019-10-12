#pragma once

#include <iostream>
#include <string>
#include "Mail.h"

//Каждый себе делает такой класс типо ShopInteract, CafeInteract, SexInteract
class MailInteract {
public:
	MailInteract() = delete;
	~MailInteract() = delete;

	//Общая функция ввода всех полей
	static Mail InputData() {
		Mail Buffer;
		std::string input;
		std::cout << "Enter index: ";
		Buffer.index = CorrectInput::EnterIntNum();
		ClearCin(std::cin);

		std::cout << "Enter reciever adresss: ";
		getline(std::cin, Buffer.reciever_adress);

		std::cout << "Enter reciever name: ";
		Buffer.reciever_name = CorrectInput::EnterSym();
		ClearCin(std::cin);

		std::cout << "Enter sender adresss: ";
		getline(std::cin, Buffer.sender_adress);

		std::cout << "Enter sender name: ";
		Buffer.sender_name = CorrectInput::EnterSym();
		ClearCin(std::cin);

		std::cout << "Enter cost: ";
		Buffer.cost = CorrectInput::EnterDoubleNum();
		ClearCin(std::cin);
		
		return Buffer;
	}

	static auto GetFindCritery() {
		std::cout << "Type the sender adress to find: ";
		std::string buffer;
		ClearCin(std::cin);
		getline(std::cin, buffer);

		return [buffer](Mail m) { return m.sender_adress == buffer; };
	}

	static auto GetFilterCritery() {
		std::cout << "Type the index for filtering: ";
		unsigned int buffer = CorrectInput::EnterIntNum();
		return [buffer](Mail m) { return m.index == buffer; };
	}

	static auto GetSortCritery() {
		std::cout << "Sorting by increasing cost.\n";
		return [](Mail x, Mail y) { return x.cost < y.cost; };
	}

	static void OutputData(Mail buffer) {
		std::cout << buffer.index << "\t" << buffer.reciever_adress << "\t" << buffer.reciever_name << "\t" << buffer.sender_adress << "\t" << buffer.sender_name << "\t" << buffer.cost << "\n";
	}

	static const std::string& GetFilename() {
		return filename;
	}

	static void PrintColumnNames() {
		std::cout << "Index\t" << "Rec. Adress\t" << "Rec. Name\t" << "Sen. Adress\t" << "Sen. Name\t" << "Cost\n";
	}

  private:
	  inline static const std::string filename = "DatabaseOfMails.cereal";
};


