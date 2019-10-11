#pragma once

#include <iostream>
#include <string>
#include "Student.h"
#include "FileIO.h"
#include "CorrectInput.h"

using namespace std;

//Каждый себе делает такой класс типо ShopInteract, CafeInteract, SexInteract
class StudentInteract {
public:
	StudentInteract() = delete;
	~StudentInteract() = delete;

	//Общая функция ввода всех полей
	static Student InputData() {
		Student Buffer;
		string input;
		cout << "Enter surname: ";
		Buffer.surname = EnterLetters();
		cout << "\nEnter name: ";
		Buffer.name = EnterLetters();
		cout << "\nEnter faculty: ";
		Buffer.faculty = EnterLetters();
		cout << "\nEnter group: ";
		Buffer.group = EnterInt();
		return Buffer;
	}

	static auto GetFindCritery() {
		cout << "Type the surname to find: ";
		string buffer = EnterLetters();;
		return [&buffer](Student m) { return m.surname == buffer; };
	}

	static auto GetFilterCritery() {
		cout << "Type the group for filtering: ";;
		unsigned int buffer = EnterInt();
		return [&buffer](Student m) { return m.group == buffer; };
	}

	static auto GetSortCritery() {
		cout << "Sorting by increasing cost.\n";
		return [](Student x, Student y) { return x.surname < y.surname; };
	}

	static void OutputData(Student buffer) {
		cout << buffer.surname << "\t" << buffer.name << "\t" << buffer.faculty << "\t" << buffer.group << "\n";
	}
};





/*
#pragma once

#include <iostream>
#include <string>
#include "Student.h"

//Каждый себе делает такой класс типо ShopInteract, CafeInteract, SexInteract
class StudentInteract {
public:
	StudentInteract() = delete;
	~StudentInteract() = delete;

	//Общая функция ввода всех полей
	static Student InputData() {
		Student Buffer;
		std::cout << "Enter surname " << std::endl;

		//Cделать ввод на той же строке, где выводится просьба о вводе.




		std::cout << "enter index" << std::endl;
		Buffer.index = EnterIntNum();
		std::cout << "enter reciver_adresss" << endl;
		Buffer.reciever_adress = EnterSym();
		cout << "enter reciver_name" << endl;
		Buffer.reciever_name = EnterSym();
		cout << "enter sender_adresss" << endl;
		Buffer.sender_adress = EnterSym();
		cout << "enter sender_name" << endl;
		Buffer.sender_name = EnterSym();
		cout << "enter cost" << endl;
		Buffer.cost = EnterDoubleNum();
		return Buffer;
		//Вызываем InputIndex(), InputRecAdress() ...
		//Если вернули false значит всё плохо вызываем их ещё раз
		//Чистим поток и говорим пользователю ввести ещё раз
		//То есть вызываем саму себя return InputData();
	}

	template <class Func>
	static Func GetFindCritery() {
		//диалог выбора поля для поиска и ввода поискового запроса (string)
		cout << "" << endl;

		string buffer = EnterSym();
		return [](Student s) { return s.surname == buffer; };
		//Просим выбрать критерий поиска и возвращаем
		//лямбда функцию - предикат.
		//"Выберите как вы хотите искать, по имени
		//По индексу"
		//Если например по имени делаем
		//return [](Mail m) { return m.name == "введённое имя пользователем" };
		//если по индексу то return [](Mail m) { return m.index == введённый индекс пользователем };
	   //Если вернули всё плохо и пользователь не смог выбрать между 1 и 2 нажав 15
	   //Чистим поток и говорим пользователю ввести ещё раз
	   //То есть вызываем саму себя return GetFindCritery();
	}

	template <class Func>
	static Func GetFilterCritery() {
		unsigned int buffer = EnterIntNum();
		return [](Student s) { return s.group == buffer; };
		//Просим выбрать критерий фильтра и возвращаем
		//лямбда функцию - предикат.
		//"Выберите как вы хотите фильтровать, по имени
		//По индексу"
		//Если например по имени делаем
		//return [](Mail m) { return m.name == "введённое имя пользователем" };
		//если по индексу то return [](Mail m) { return m.index == введённый индекс пользователем };
	   //Если вернули всё плохо и пользователь не смог выбрать между 1 и 2 нажав 15
	   //Чистим поток и говорим пользователю ввести ещё раз
	   //То есть вызываем саму себя return GetFilterCritery();
	   //Всё аналогично
	}
	template <class Func>
	static void GetSortCritery() {
		return [](Mail x, Mail y) { return x.reciever_name < y.reciever_name; }
			//Всё тоже самое
	}
};

//Как вызывать, это всё в main.
Database<Mail> db;
InteractDB::AddElement(db);
Database<Mail> new_db = InteractDB::FilterElements(db);
Mail found = InteractDB::FindElement(new_db);
InteractDB::SortElements(new_db);

*/
