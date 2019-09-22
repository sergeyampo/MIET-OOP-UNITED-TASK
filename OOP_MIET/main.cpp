#include "Database.h"
#include "Mail.h"
#include "Food.h"
#include "FileIO.h"
#include "InteractDB.h"
#include "FoodInteract.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
	//Примеры
	Mail m(675000, "s", "s", "s", "s", 12.55);
	Database<Mail> db(15, m);
	string s = "Sasha";
	db.Add(m);

	//Заполним отличающимеся по цене
	for (unsigned i = 1; i < 20; ++i)
		db.Add({ 6750000, "a", "b", "c", "d", float(12.5 + i) });

	cout << "Common list:\n";
	//Выведем цены
	for (size_t i = 0; i < db.Size(); ++i)
		cout << db[i].cost << "\n";

	//Поищем с указанным индексом 675000
	Mail found = db.Find([](Mail m) { return m.index == 675000; });
	//[](Mail m) { return m.index == 675000; } значит что мы делаем лямбда функцию
	//m - элемент базы данных, когда условия описанные в { } - теле функции выполняться
	//функция Find вернет этот m элемент он и присвоится found.

	cout << "Price greater than 20:\n";
	//Пофильтруем по цене выше 20
	auto new_db = db.Filter([](Mail m) { return m.cost > 20; });

	//Выведем цены
	for (size_t i = 0; i < new_db.Size(); ++i)
		cout << new_db[i].cost << "\n";

	FileIO files("Database.dat");

	//Работа с InteractDB
	Database<Food> database = InteractDB::CreateDatabaseWith<FoodInteract, Food>();
	InteractDB::AddElement<FoodInteract>(db);
	Food f = InteractDB::FindElement<FoodInteract>(database);

	return 0;
}
