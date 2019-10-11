#pragma once

#include <iostream>
#include <string>
#include "Mail.h"

using namespace std;

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
		Buffer.index = EnterInt();
		ClearCin(cin);
		cout << "Enter reciver_adresss: ";
		getline(cin, Buffer.reciever_adress);
		ClearCin(cin);
		cout << "Enter reciver_name: ";
		Buffer.reciever_name = EnterLetters();
		ClearCin(cin);
		cout << "Enter sender_adresss: ";
		getline(cin, Buffer.sender_adress);
		ClearCin(cin);
		cout << "Enter sender_name: ";
		Buffer.sender_name = EnterLetters();
		ClearCin(cin);
		cout << "Enter cost: ";
		Buffer.cost = EnterDouble();
		ClearCin(cin);
		
		return Buffer;
	}

	static auto GetFindCritery() {
		cout << "Type the sender adress to find: ";
		string buffer = EnterLetters();;
		return [&buffer](Mail m) { return m.sender_name == buffer; };
	}

	static auto GetFilterCritery() {
		cout << "Type the index for filtering: ";;
		unsigned int buffer = EnterInt();
		return [&buffer](Mail m) { return m.index == buffer; };
	}

	static auto GetSortCritery() {
		cout << "Sorting by increasing cost.\n";
		return [](Mail x, Mail y) { return x.cost < y.cost; };
	}

	static void OutputData(Mail buffer) {
		cout << buffer.index << "\t" << buffer.reciever_adress << "\t" << buffer.reciever_name << "\t" << buffer.sender_adress << "\t" << buffer.sender_name << "\t" << buffer.cost;
	}
};


