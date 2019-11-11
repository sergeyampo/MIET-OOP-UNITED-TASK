#pragma once
#include "Database.h"
#include "CorrectInput.h"
#include "LetterInteract.h"
#include <iostream>
#include"Pathes.h"
#include "FileIO.h"

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
		if (found->Empty())
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

	template <class InteractType, class ItemType>
	Database<ItemType> RestoreDb(fs::path database_dump_namefile)
	{
		Database<ItemType> rs_db;
		if (database_dump_namefile != "")
		{
			FileIO file(database_dump_namefile.string());
			rs_db = file.ReadBinary(rs_db, database_dump_namefile.string());
		}
		return rs_db;
	}
	//СОЗДАНИЕ ФАЙЛА
	
	template <class InteractType, class ItemType>
	PathIO CreateFile(const Database<ItemType>& db, PathIO &pathes) //принимает PathIO
	{		
		fs::path current_file = pathes.CreateFileName();
			FileIO file(current_file.string());
			file.WriteBinary(db, current_file.string());
			pathes.AddPath(current_file);
			return pathes;
							   
	}
	template <class InteractType, class ItemType>
	Database<ItemType> ChooseFirstFile(PathIO& pathes){
		Database<ItemType> rs_db;
		if (pathes.Size() != 0)
		{
			cout << "Choose file to restore:\n";
		    cout << "0 - Get last save\n";
			pathes.ListPathes();
			cout << pathes.Size() + 1 << " - Don't restore, create new file\n";
			cout << "Enter the number: ";
			unsigned int n;
			n = CorrectInput::EnterIntNum();
			if (n == 0)
			{
				pathes.SetCurrentFile(pathes.GetLast());
				return RestoreDb<InteractType, ItemType>(pathes.GetCurrentFile());
			}
			else if (n == pathes.Size() + 1)
			{
				pathes.SetCurrentFile("");
				return  rs_db;
			}
			else if (n < pathes.Size() + 1)
			{
				pathes.SetCurrentFile(pathes[n - 1]);
				return RestoreDb<InteractType, ItemType>(pathes.GetCurrentFile());
			}
			else
				 ChooseFirstFile<InteractType,ItemType>(pathes);		
		}
		else
		{
			pathes.SetCurrentFile("");
			return  rs_db;
		}
	}

	template <class InteractType, class ItemType>
	Database<ItemType> ChooseFile(PathIO &pathes, Database<ItemType> db) {
		Database<ItemType> rs_db;		
			cout << "Choose file to restore:\n";
				cout << "0 - Return to the menu\n";
			pathes.ListPathes();
			cout << pathes.Size() + 1 << " - Create new file\n";
			cout << "Enter the number: ";
			int n;
			n = CorrectInput::EnterIntNum();
			if (n == 0)
			{
				return db;
			}
			else if (n == pathes.Size() + 1)
			{
				pathes.SetCurrentFile("");
				return rs_db;
			}
			else if (n < pathes.Size() + 1)
			{
				pathes.SetCurrentFile (pathes[n - 1]);
				return RestoreDb<InteractType, ItemType>(pathes[n - 1]);
			}
			else			
			ChooseFile<InteractType>(pathes, db);		

	}

	//сохранение бд в файл
	template <class InteractType, class ItemType>
	PathIO SaveData(const Database<ItemType>& db,PathIO& pat)
	{
		cout << "Do you want to save data to file?\n"
			"\'Y\' - yes, \'N\' - no\n"
			"Enter: ";
		char choice;
		cin >> choice;
		if (choice == 'Y') {
			if (pat.GetCurrentFile() != "")
			{
				FileIO file(pat.GetCurrentFile().string());
				file.WriteBinary(db,pat.GetCurrentFile().string());
			}
			else
				pat=CreateFile<InteractType>(db,pat);

			
		}
		else if (choice == 'N') {
			return pat;
		}
		else {
			ClearCin(cin);
			cout << "Incorrect input, try again!\n";
			return SaveData<InteractType>(db, pat);
		}
		return pat;
	}

	
	//Диалог сохранения базы данных в файл с именем
	//database_dump_namefile.
	template <class InteractType, class ItemType>
	void SaveDb(const Database<ItemType>& db ,fs::path database_dump_namefile) {
		cout << "Do you want to save data to file?\n"
			"\'Y\' - yes, \'N\' - no\n"
			"Enter: ";
		char choice;
		cin >> choice;

		if (choice == 'Y') {
			try {
				FileIO file(database_dump_namefile);
				file.WriteBinary(db, database_dump_namefile);
				//std::cout << "The " + database_dump_namefile + " file was successfully saved.\n";
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

	//Функция получает базу данных и выводит её в виде КРАСИВОЙ таблицы - IN PROCESS
	template <class InteractType, class ItemType>
	void NewPrintTable(Database<ItemType>& db) {

		//PUT IT AWAY (later)
		PrintTable<InteractType>(db);
		std::cout << "\n\n\n";

		if (db.Empty()) {
			std::cout << "There's nothing to show!\n";
			return;
		}

		string Header = InteractType::GetTableHeader();

		//Обработаем Header, получим кол-во полей и их длины
		int i = 0;
		int beg = 0;
		//int NumOfFields = 1;
		vector<string> ColumnNames;
		while (Header[i] != '\n') {
			if (Header[i] == '|' || Header[i] == '\n') {
				//++NumOfFields;
				string Field;
				Field.assign(Header, beg, i - beg);
				ColumnNames.push_back(Field);
				beg = i + 1;
			}
			++i;
		}
		int NumOfFields = ColumnNames.size();
		cout << "Number of fields = " << NumOfFields << '\n';
		


		/*
		int ibeg = 0;
		int i = 0;
		while (TableHeader[i] != '\n') {
			while (TableHeader[i] != '\n' && TableHeader[i] != ' ') {
				++i;
			}
			if (TableHeader[i] == '\n') break;
			//Length = a;
			++i;
		}
		*/

		//for (int i = 0; i < TableHeader.Size
		InteractType::PrintColumnNames();
		for (int i = 0; i < db.Size(); ++i)
			InteractType::OutputData(db[i]);
	}
};