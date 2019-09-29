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
		string input;
		cout << "Enter index: ";
		Buffer.index = CorrectInput::EnterIntNum();
		ClearCin(cin);

		cout << "Enter reciever adresss: ";
		getline(cin, Buffer.reciever_adress);

		cout << "Enter reciever name: ";
		Buffer.reciever_name = CorrectInput::EnterSym();
		ClearCin(cin);

		cout << "Enter sender adresss: ";
		getline(cin, Buffer.sender_adress);

		cout << "Enter sender name: ";
		Buffer.sender_name = CorrectInput::EnterSym();
		ClearCin(cin);

		cout << "Enter cost: ";
		Buffer.cost = CorrectInput::EnterDoubleNum();
		ClearCin(cin);
		
		return Buffer;
	}

	static auto GetFindCritery() {
		cout << "Type the sender adress to find: ";
		string buffer;
		ClearCin(std::cin);
		getline(std::cin, buffer);

		return [buffer](Mail m) { return m.sender_adress == buffer; };
	}

	static auto GetFilterCritery() {
		cout << "Type the index for filtering: ";
		unsigned int buffer = CorrectInput::EnterIntNum();
		return [buffer](Mail m) { return m.index == buffer; };
	}

	static auto GetSortCritery() {
		cout << "Sorting by increasing cost.\n";
		return [](Mail x, Mail y) { return x.cost < y.cost; };
	}

	static void OutputData(Mail buffer) {
		cout << buffer.index << "\t" << buffer.reciever_adress << "\t" << buffer.reciever_name << "\t" << buffer.sender_adress << "\t" << buffer.sender_name << "\t" << buffer.cost << "\n";
	}

	static const string& GetFilename() {
		return filename;
	}

  private:
	  inline static const std::string filename = "DatabaseOfMails.cereal";
};


