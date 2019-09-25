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
		cout << "enter index" << endl;
		Buffer.index = EnterIntNum();
		cout << "enter reciver_adresss" << endl;
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
		string buffer = EnterSym();
		return [](Mail m) { return m.sender_adress == buffer; };
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
		return [](Mail m) { return m.index == buffer; };
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


