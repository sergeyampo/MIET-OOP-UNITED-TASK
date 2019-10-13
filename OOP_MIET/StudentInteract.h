#pragma once

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

class StudentInteract {
public:
	StudentInteract() = delete;
	~StudentInteract() = delete;

	//Общая функция ввода всех полей
	static Student InputData() {
		Student Buffer;
		string input;

		ClearCin(std::cin);

		cout << "Enter surname: ";
		getline(std::cin, Buffer.surname);

		cout << "Enter name: ";
		getline(std::cin, Buffer.name);

		cout << "Enter faculty: ";
		getline(std::cin, Buffer.faculty);

		cout << "Enter group: ";
		Buffer.group = CorrectInput::EnterIntNum();
		ClearCin(std::cin);

		return Buffer;
	}

	static auto GetFindCritery() {
		cout << "Type the surname to find: ";
		std::string buffer;
		ClearCin(std::cin);
		getline(std::cin, buffer);
		return [&buffer](Student m) { return m.surname == buffer; };
	}

	static auto GetFilterCritery() {
		cout << "Type the group for filtering: ";;
		unsigned int buffer = CorrectInput::EnterIntNum();
		return [&buffer](Student m) { return m.group == buffer; };
	}

	//Add smart string comparing
	static auto GetSortCritery() {
		cout << "Sorting by increasing cost.\n";
		return [](Student x, Student y) { return (x.surname < y.surname) || (x.surname == y.surname && x.name < y.name); };
	}

	static void OutputData(Student buffer) {
		cout << buffer.faculty << "\t" << buffer.group << "\t" << buffer.surname << "\t" << buffer.name << "\n";
	}

	static const std::string& GetFilename() {
		return filename;
	}

	static void PrintColumnNames() {
		std::cout << "Faculty\t" << "Group\t" << "Surname\t" << "Name\n";
	}

	static auto GetTableHeader() {
		return "Faculty Group Surname Name\n";
	}

private:
	inline static const std::string filename = "DatabaseOfStudents.cereal";
};