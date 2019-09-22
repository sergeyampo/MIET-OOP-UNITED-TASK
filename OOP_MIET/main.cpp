#include "Database.h"
#include "Mail.h"
#include "Food.h"
#include "FileIO.h"
#include "InteractDB.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
	//Примеры
	Database<Mail> db;
	string s = "Sasha";
	Mail m(675000, "s", "s", "s", "s", float(12.55));
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

	new_db.Add({ 12, "asda", "asdasd", "asdasd", "asd", 12.5 });
	ofstream fout("file.bin", ios_base::binary | ios_base::out | ios_base::trunc);
	fout.write(reinterpret_cast<char*>(&new_db), sizeof(new_db));
	fout.close();

	Database<Mail> mn;
	ifstream fin("file.bin", ios_base::binary | ios_base::in);
	fin.read(reinterpret_cast<char*>(&mn), sizeof(Database<Mail>));

	//Работа с InteractDB
	Database<Food> database = InteractDB::CreateDatabaseWith<FoodInteract, Food>();
	Food f = InteractDB::FindElement<FoodInteract>(database);

	return 0;
}
