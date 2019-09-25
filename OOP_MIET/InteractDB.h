#pragma once
#include "Database.h"
#include "CorrectInput.h"
#include "MailInteract.h"
#include <iostream>

//Óíèâåðñàëüíûé èíòåðôåéñ ðàáîòû ñ áàçîé äàííûõ
namespace InteractDB {
	//Ôóíêöèÿ ïîëó÷àåò áàçó äàííûõ è òî÷íûé øàáëîííûé ïàðàìåòð ñ óòî÷í¸ííûìè äèàëîãîâûìè
	//ôóíêöèÿìè. Äîáàâëÿåò ýëåìåíò â áàçó äàííûõ.
	//Âûçûâàåì êàê InteractDB::AddElement<FoodInteract>(db);
	template <class InteractType, class ItemType>
	void AddElement(Database<ItemType>& db) {
		//cout something
		ItemType item = InteractType::InputData();
		db.Add(item);
	}

	//Ôóíêöèÿ ïîëó÷àåò áàçó äàííûõ è òî÷íûé øàáëîííûé ïàðàìåòð ñ óòî÷í¸ííûìè äèàëîãîâûìè
	//ôóíêöèÿìè. Äîáàâëÿåò íåñêîëüêî ýëåìåíòîâ â áàçó äàííûõ. 
	template <class InteractType, class ItemType>
	void AddFewElements(Database<ItemType>& db) {
		cout << "Enter amount of elements, which you want to create\n"
			"or type 0 if you don't:\n";
		int amount = CorrectInput::EnterIntNum();
		for (int i = 0; i < amount; i++)
			AddElement<InteractType>(db);
	}


	//template <class InteractType, class ItemType>
	//void OutputTableDB(Database<ItemType>& db) {
		//for (int i=0 )

	//}


	//Ôóíêöèÿ ïîëó÷àåò ÷åðåç ÿâíûå øàáëîííûå àðãóìåíòû êëàññ âçàèìîäåéñòâèÿ b òèï õðàíèìûé â áàçå äàííûõ
	//Äèàëîã ñîçäàíèÿ áàçû äàííûõ.
	//Âûçûâàåì êàê CreateDatabaseWith<FoodInteract, Food>()
	template <class InteractType, class ItemType>
	Database<ItemType> CreateDatabaseWith() {
		cout << "Enter the size of DataBase: ";
		int k = 0;
		k = CorrectInput::EnterIntNum();
		Database<ItemType> db(k, ItemType());
		for (int i = 0; i < k; i++)
			db[i] = InteractType::InputData();

		return db;
	}

	//Äèàëîã ïîèñêà ýëåìåíòîâ
	template <class InteractType, class ItemType>
	ItemType FindElement(Database<ItemType>& db) {
		auto predic = InteractType::GetFindCritery();
		ItemType found = db.Find(predic);
		if (found.Empty())
			cout << "Element not found!\n";


		return found;
	}

	//Äèàëîã ôèëüòðà ýëåìåíòîâ - âîçâðàùàåìûé áàçó äàííûõ ýëåìåíòû êîòîðûõ
	//óäîâëåòâîðÿþò ïðåäèêàòó InteractType::GetFilterCritery.
	template <class InteractType, class ItemType>
	Database<ItemType> FilterElements(Database<ItemType>& db) {
		auto predic = InteractType::GetFilterCritery();
		Database<ItemType> new_db = db.Filter(predic);
		if(new_db.Empty())
			cout << "There's nothing to filter!\n";

		return new_db;
	}

	//Äèàëîã ñîðòèðîâêè ýëåìåíòîâ, ìåíÿåò ïîðÿäîê ýëåìåíòîâ ïåðåäàííîé áàçû äàííûõ.
	template <class InteractType, class ItemType>
	void SortElements(Database<ItemType>& db) {
		auto predic = InteractType::GetSortCritery();
		db.Sort(predic);
	}

	//Äèàëîã âîññòàíîâëåíèÿ áàçû äàííûõ èç ïðåäûäóùåãî ñîõðàíåíèÿ, ôàéëà ñ èìåíåì
	//database_dump_namefile. Âûçûâàåì RestoreDbWith<Food>()
	template <class ItemType>
	Database<ItemType> RestoreDbWith() {
		const std::string database_dump_namefile = "Database.cereal";
		cout << "Do you want to restore data from the last save?\n"
			    "\'Y\' - yes, \'N\' - no\n"
			    "Enter: ";
		char choice;
		cin >> choice;
		
		Database<ItemType> rs_db;
		if (choice == 'Y') {
			try {
				FileIO file(database_dump_namefile);
				rs_db = file.ReadBinary(rs_db, database_dump_namefile);
			}
			catch (domain_error e) {
				cout << e.what() << endl;
				return RestoreDbWith<ItemType>();
			}
		}
		else if (choice == 'N') {
			return Database<ItemType>();
		}
		else {
			ClearCin(cin);
			cout << "Incorrect input, try again!\n";
			return RestoreDbWith<ItemType>();
		}

		return rs_db;
	}

	//Äèàëîã ñîõðàíåíèÿ áàçû äàííûõ â ôàéë ñ èìåíåì
	//database_dump_namefile.
	template <class ItemType>
	void SaveDb(const Database<ItemType>& db) {
		const std::string database_dump_namefile = "Database.cereal";
		cout << "Do you want to save data to file?\n"
			"\'Y\' - yes, \'N\' - no\n"
			"Enter: ";
		char choice;
		cin >> choice;

		if (choice == 'Y') {
			try {
				FileIO file(database_dump_namefile);
				file.WriteBinary(db, database_dump_namefile);
			}
			catch (domain_error e) {
				cout << e.what() << endl;
				return SaveDb(db);
			}
		}
		else if (choice == 'N') {
			return;
		}
		else {
			ClearCin(cin);
			cout << "Incorrect input, try again!\n";
			return SaveDb(db);
		}
	}
	
	//Ôóíêöèÿ ïîëó÷àåò áàçó äàííûõ è âûâîäèò å¸ â âèäå òàáëèöû
	template <class InteractType, class ItemType>
	void PrintTable(Database<ItemType>& db) {
		for (int i = 0; i < db.Size(); ++i) {
			InteractType::OutputData(db[i]);
			cout << "\n";
		}
	}

};




