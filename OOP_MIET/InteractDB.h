#pragma once
#include "Database.h"
#include "CorrectInput.h"
#include "LetterInteract.h"
#include <iostream>

//Универсальный интерфейс работы с базой данных
namespace InteractDB {
	//Функция получает базу данных и точный шаблонный параметр с уточнёнными диалоговыми
	//функциями. Добавляет элемент в базу данных.
	//Вызываем как InteractDB::AddElement<FoodInteract>(db);
	template <class InteractType, class ItemType>
	void AddElement(Database<ItemType>& db) {
		//cout something
		ItemType item = InteractType::InputData();
		db.Add(item);
	}

	//Функция получает базу данных и точный шаблонный параметр с уточнёнными диалоговыми
	//функциями. Добавляет несколько элементов в базу данных. 
	template <class InteractType, class ItemType>
	void AddFewElements(Database<ItemType>& db) {
		unsigned int count = 0;
		cout << "Enter amount of elements, which you want to create\n"
			"or type 0 if you don't:\n" <<
			"Enter: ";
		int amount = CorrectInput::EnterIntNum();
		system("CLS");
		ClearCin(cin);

		for (int i = 0; i < amount; ++i){
			std::cout << "Enter " << i + 1 << " element: " << "\n";
			AddElement<InteractType>(db);
		}
	}

	//Функция получает через явные шаблонные аргументы класс взаимодействия b тип хранимый в базе данных
	//Диалог создания базы данных.
	//Вызываем как CreateDatabaseWith<FoodInteract, Food>()
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

	//Диалог поиска элементов
	template <class InteractType, class ItemType>
	ItemType FindElement(Database<ItemType>& db) {
		auto predic = InteractType::GetFindCritery();
		ItemType found = db.Find(predic);
		if (found.Empty())
			cout << "Element not found!\n";

		return found;
	}

	//Диалог фильтра элементов - возвращаемый базу данных элементы которых
	//удовлетворяют предикату InteractType::GetFilterCritery.
	template <class InteractType, class ItemType>
	Database<ItemType> FilterElements(Database<ItemType>& db) {
		auto predic = InteractType::GetFilterCritery();
		Database<ItemType> new_db = db.Filter(predic);
		if(new_db.Empty())
			cout << "There's nothing to filter!\n";

		return new_db;
	}

	//Диалог сортировки элементов, меняет порядок элементов переданной базы данных.
	template <class InteractType, class ItemType>
	void SortElements(Database<ItemType>& db) {
		auto predic = InteractType::GetSortCritery();
		db.Sort(predic);
	}

	//Диалог восстановления базы данных из предыдущего сохранения, файла с именем
	//database_dump_namefile. Вызываем RestoreDbWith<Food>()
	template <class InteractType, class ItemType>
	Database<ItemType> RestoreDbWith() {
		const std::string database_dump_namefile = InteractType::GetFilename();
		cout << "Do you want to restore data from the last save?\n"
			    "\'Y\' - yes, \'N\' - no\n"
			    "Enter: ";
		char choice;
		cin >> choice;
		system("CLS");
		
		Database<ItemType> rs_db;
		if (choice == 'Y') {
			try {
				FileIO file(database_dump_namefile);
				rs_db = file.ReadBinary(rs_db, database_dump_namefile);
			}
			catch (domain_error e) {
				cout << e.what() << endl;
				return RestoreDbWith<InteractType, ItemType>();
			}
		}
		else if (choice == 'N') {
			return Database<ItemType>();
		}
		else {
			ClearCin(cin);
			cout << "Incorrect input, try again!\n";
			return RestoreDbWith<InteractType, ItemType>();
		}

		return rs_db;
	}

	//Диалог сохранения базы данных в файл с именем
	//database_dump_namefile.
	template <class InteractType, class ItemType>
	void SaveDb(const Database<ItemType>& db) {
		const std::string database_dump_namefile = InteractType::GetFilename();
		cout << "Do you want to save data to file?\n"
			"\'Y\' - yes, \'N\' - no\n"
			"Enter: ";
		char choice;
		cin >> choice;

		if (choice == 'Y') {
			try {
				FileIO file(database_dump_namefile);
				file.WriteBinary(db, database_dump_namefile);
				std::cout << "The " + database_dump_namefile + " file was successfully saved.\n";
			}
			catch (domain_error e) {
				FileIO file(database_dump_namefile);
				file.Create(database_dump_namefile);
				file.WriteBinary(db, database_dump_namefile);
				cout << e.what() << endl;
				return;
			}
		}
		else if (choice == 'N') {
			return;
		}
		else {
			ClearCin(cin);
			cout << "Incorrect input, try again!\n";
			return SaveDb<InteractType>(db);
		}
	}

	//Функция получает базу данных и выводит её в виде таблицы
	template <class InteractType, class ItemType>
	void PrintTable(Database<ItemType>& db) {
		if (db.Empty()) {
			std::cout << "There's nothing to show!\n";
			return;
		}
		InteractType::PrintColumnNames();
		for (int i = 0; i < db.Size(); ++i)
			InteractType::OutputData(db[i]);
	}

};




