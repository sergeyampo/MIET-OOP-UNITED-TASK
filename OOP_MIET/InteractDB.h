#pragma once
#include "Database.h"
#include "CorrectInput.h"
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
			"or type 0 if you don't: ";
		int amount = CorrectInput::EnterIntNum();

		for (int i = 0; i < amount; i++)
			AddElement<InteractType>(db);
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
		if (found.empty())
			cout << "Element not found!" << endl;

		return found;
	}

	//Диалог фильтра элементов - возвращаемый базу данных элементы которых
	//удовлетворяют предикату InteractType::GetFilterCritery.
	template <class InteractType, class ItemType>
	 Database<ItemType> FilterElements(const Database<ItemType>& db) {
		auto predic = InteractType::GetFilterCritery();
		Database<ItemType> new_db = db.Filter(predic);

		return new_db;
	}

	//Диалог сортировки элементов, меняет порядок элементов переданной базы данных.
	template <class InteractType, class ItemType>
	 void SortElements(Database<ItemType>& db) {
		auto predic = FoodInteract::GetSortCritery();
		db.Sort(predic);
	}
};




