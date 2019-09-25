#pragma once

#include "Food.h"
#include "CorrectInput.h"
#include <iostream>
#include <string>

//Ïîëüçîâàòåëüñêèé êëàññ âçàèìîäåéñòâèé è äèàëîãîâ
class FoodInteract {
public:
	FoodInteract() = delete;
	~FoodInteract() = delete;

	//Îáùàÿ ôóíêöèÿ ââîäà âñåõ ïîëåé

	static Food InputData() {
		Food Buffer;
		std::cout << "enter fam" << std::"\n";
		Buffer.fam = CorrectInput::EnterSym();
		std::cout << "enter type" << std::"\n";
		Buffer.type = CorrectInput::EnterIntNum();
		std::cout << "enter wight" << std::"\n";
		Buffer.weight = CorrectInput::EnterDoubleNum();
		std::cout << "enter count" << std::"\n";
		Buffer.count = CorrectInput::EnterIntNum();
		std::cout << "enter cost" << std::"\n";
		Buffer.cost = CorrectInput::EnterDoubleNum();
		return Buffer;
		//Âûçûâàåì InputIndex(), InputRecAdress() ...
		//Åñëè âåðíóëè false çíà÷èò âñ¸ ïëîõî âûçûâàåì èõ åù¸ ðàç
		//×èñòèì ïîòîê è ãîâîðèì ïîëüçîâàòåëþ ââåñòè åù¸ ðàç

	}
	
	//Функция вывода
	static void OutputData(Food Buffer){
		cout << Buffer.fam << "\t" << Buffer.type << "\t" << Buffer.weight << "\t" << Buffer.count <<"\t"<<Buffer.cost <<"\t" << "\n";;
	}


	static auto GetFindCritery() {

		std::string buffer = CorrectInput::EnterSym();
		return [buffer](Food m) { return m.fam == buffer; };

		//åñëè ïî èíäåêñó òî return [](Food m) { return m.index == ââåä¸ííûé èíäåêñ ïîëüçîâàòåëåì };
	   //Åñëè âåðíóëè âñ¸ ïëîõî è ïîëüçîâàòåëü íå ñìîã âûáðàòü ìåæäó 1 è 2 íàæàâ 15
	   //×èñòèì ïîòîê è ãîâîðèì ïîëüçîâàòåëþ ââåñòè åù¸ ðàç
	   //Òî åñòü âûçûâàåì ñàìó ñåáÿ return GetFindCritery();
	}


	static auto GetFilterCritery() {

		unsigned int buffer = CorrectInput::EnterIntNum();
		return [buffer](Food m) { return m.type == buffer; };

		//Ïðîñèì âûáðàòü êðèòåðèé ôèëüòðà è âîçâðàùàåì
		//ëÿìáäà ôóíêöèþ - ïðåäèêàò.
		//"Âûáåðèòå êàê âû õîòèòå ôèëüòðîâàòü, ïî èìåíè
		//Ïî èíäåêñó"
		//Åñëè íàïðèìåð ïî èìåíè äåëàåì
	   //return [](Food m) { return m.name == "ââåä¸ííîå èìÿ ïîëüçîâàòåëåì" };
	   //åñëè ïî èíäåêñó òî return [](Food m) { return m.index == ââåä¸ííûé èíäåêñ ïîëüçîâàòåëåì };
	   //Åñëè âåðíóëè âñ¸ ïëîõî è ïîëüçîâàòåëü íå ñìîã âûáðàòü ìåæäó 1 è 2 íàæàâ 15
	   //×èñòèì ïîòîê è ãîâîðèì ïîëüçîâàòåëþ ââåñòè åù¸ ðàç
	   //Òî åñòü âûçûâàåì ñàìó ñåáÿ return GetFilterCritery();
	   //Âñ¸ àíàëîãè÷íî
	}
	template <class Func>
	static void GetSortCritery() {
		std::cout << "enter critery of search:" << std::"\n" << "1-fam" << std::"\n" << "2-type" << std::"\n" << "3-wight" << std::"\n" << "4-count" << std::"\n" << "5-cost" << std::"\n";
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
