#pragma once

#include "Food.h"
#include "CorrectInput.h"
#include <iostream>
#include <string>

//Пользовательский класс взаимодействий и диалогов
class FoodInteract {
public:
	FoodInteract() = delete;
	~FoodInteract() = delete;

	//Общая функция ввода всех полей

	static Food InputData() {
		Food Buffer;
		std::cout << "enter fam" << "\n";
		Buffer.fam = CorrectInput::EnterSym();
		std::cout << "enter type" << "\n";
		Buffer.type = CorrectInput::EnterIntNum();
		std::cout << "enter wight" << "\n";
		Buffer.weight = CorrectInput::EnterDoubleNum();
		std::cout << "enter count" << "\n";
		Buffer.count = CorrectInput::EnterIntNum();
		std::cout << "enter cost" << "\n";
		Buffer.cost = CorrectInput::EnterDoubleNum();
		return Buffer;
		//Вызываем InputIndex(), InputRecAdress() ...
		//Если вернули false значит всё плохо вызываем их ещё раз
	    //Чистим поток и говорим пользователю ввести ещё раз

	}
	
	//Функция вывода
	static void OutputData(Food Buffer){
		cout << Buffer.fam << "\t" << Buffer.type << "\t" << Buffer.weight << "\t" << Buffer.count <<"\t"<<Buffer.cost <<"\t" << "\n";;
	}


	static auto GetFindCritery() {

		std::string buffer = CorrectInput::EnterSym();
		return [buffer](Food m) { return m.fam == buffer; };

		//если по индексу то return [](Food m) { return m.index == введённый индекс пользователем };
	    //Если вернули всё плохо и пользователь не смог выбрать между 1 и 2 нажав 15
	    //Чистим поток и говорим пользователю ввести ещё раз
	    //То есть вызываем саму себя return GetFindCritery();
	}


	static auto GetFilterCritery() {

		unsigned int buffer = CorrectInput::EnterIntNum();
		return [buffer](Food m) { return m.type == buffer; };

		//Просим выбрать критерий фильтра и возвращаем
		//лямбда функцию - предикат.
		//"Выберите как вы хотите фильтровать, по имени
		//По индексу"
		//Если например по имени делаем
		//return [](Food m) { return m.name == "введённое имя пользователем" };
		//если по индексу то return [](Food m) { return m.index == введённый индекс пользователем };
		//Если вернули всё плохо и пользователь не смог выбрать между 1 и 2 нажав 15
		//Чистим поток и говорим пользователю ввести ещё раз
		//То есть вызываем саму себя return GetFilterCritery();
		//Всё аналогично
	}
	template <class Func>
	static void GetSortCritery() {
		std::cout << "enter critery of search:" << "\n" << "1-fam" << "\n" << "2-type" << "\n" << "3-wight" << "\n" << "4-count" << "\n" << "5-cost" << "\n";
		unsigned int k = 0;
		cin >> k;
		if (k == 1)
		{
			std::string buffer = CorrectInput::EnterSym();
			return [buffer](Food m, Food n) { return m.fam < n.fam; };
		}
		if (k == 2)
		{
			unsigned int buffer = CorrectInput::EnterIntNum();
			return [buffer](Food m, Food n) { return m.type < n.type; };
		}
		if (k == 3)
		{
			double buffer = CorrectInput::EnterDoubleNum();
			return [buffer](Food m, Food n) { return m.wight < n.wight; };
		}
		if (k == 4)
		{
			double buffer = CorrectInput::EnterIntNum();
			return [buffer](Food m, Food n) { return m.count < n.wight; };
		}
		if (k == 5)
		{
			double buffer = CorrectInput::EnterDoubleNum();
			return [buffer](Food m, Food n) { return m.cost < n.cost; };
		}
		else
		{
			GetSortCritery();
		}

	}

};
