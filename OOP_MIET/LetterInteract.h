#pragma once

#include <iostream>
#include <string>
#include "Letter.h"


class LetterInteract {
public:
	LetterInteract() = delete;
   ~LetterInteract() = delete;


	//Общая функция ввода всех полей
	static shared_ptr<Letter> InputData() {
		std::cout << "Which type of letter you want to create:\n"
			      << "1)Letter with weight but no cost.\n"
		          << "2)Letter without weight but with cost.\n"
				  << "Enter a number: ";
		char choice;
		cin >> choice;
		system("CLS");

		if (choice != '1' && choice != '2'){ 
			ClearCin(cin); 
			return InputData(); 
		}

		shared_ptr<Letter> ret_buf(new Letter());
		Letter Buffer;
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

		if (choice == '1') {
			double cost;
			std::cout << "Enter cost: ";
			cost = CorrectInput::EnterDoubleNum();
			ClearCin(std::cin);
			ret_buf.reset(new Letter2(Buffer, cost));
		}
		else if (choice == '2') {
			double weight;
			std::cout << "Enter weight: ";
			weight = CorrectInput::EnterDoubleNum();
			ClearCin(std::cin);
			ret_buf.reset(new Letter1(Buffer, weight));
		}

			return ret_buf;
	}

	static auto GetFindCritery() {
		std::cout << "Type the sender adress to find: ";
		ClearCin(std::cin);
		Man cmp;
		if (string buffer; getline(std::cin, buffer))
			cmp.SetAddress(buffer);

		return [cmp](shared_ptr<Letter> m) { return m->GetSenderAddress() == cmp.GetAddress(); }; }

	static auto GetFilterCritery() {
		std::cout << "Type the index for filtering: ";
		unsigned int buffer = CorrectInput::EnterIntNum();
		return [buffer](shared_ptr<Letter> m) { return m->GetIndex() == buffer; };
	}

	static auto GetSortCritery() {
		std::cout << "Sorting by increasing cost.\n";
		return [](shared_ptr<Letter> x, shared_ptr<Letter> y) { return x->GetCost() < y->GetCost(); }; }

	static void OutputData(shared_ptr<Letter> buffer) {
		std::cout << buffer->GetIndex() << "\t" << buffer->GetRecieverAdress() << "\t" << buffer->GetRecieverName() << "\t" << buffer->GetSenderAddress() << "\t" << buffer->GetSenderName() << "\t" << buffer->GetCost() << "\t" << buffer->GetWeight() << "\n";
	}

	static const std::string& GetFilename() {
		return filename;
	}

	static void PrintColumnNames() {
		std::cout << "Index\t" << "Rec. Adress\t" << "Rec. Name\t" << "Sen. Adress\t" << "Sen. Name\t" << "Cost\t" << "Weight\n";
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


