#pragma once

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

class StudentInteract {
public:
	StudentInteract() = delete;
	~StudentInteract() = delete;

	//����� ������� ����� ���� �����
	static Student InputData() {
		Student Buffer;
		string input;

		cout << "Enter surname: ";
		getline(std::cin, Buffer.surname);

		cout << "\nEnter name: ";
		getline(std::cin, Buffer.name);

		cout << "\nEnter faculty: ";
		getline(std::cin, Buffer.faculty);

		cout << "\nEnter group: ";
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
		return [](Student x, Student y) { return x.surname + x.name < y.surname + y.name; };
	}
	

	static void OutputData(Student buffer) {
		cout << buffer.surname << "\t" << buffer.name << "\t" << buffer.faculty << "\t" << buffer.group << "\n";

	}

	static const std::string& GetFilename() {
		return filename;
	}

	static void PrintColumnNames() {
		std::cout << "Surname\t" << "Name\t" << "Faculty\t" << "Group\t";
	}

private:
	inline static const std::string filename = "DatabaseOfStudents.cereal";
};