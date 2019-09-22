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
	//�������
	Database<Mail> db;
	string s = "Sasha";
	Mail m(675000, "s", "s", "s", "s", float(12.55));
	db.Add(m);

	//�������� ������������� �� ����
	for (unsigned i = 1; i < 20; ++i)
		db.Add({ 6750000, "a", "b", "c", "d", float(12.5 + i) });

	cout << "Common list:\n";
	//������� ����
	for (size_t i = 0; i < db.Size(); ++i)
		cout << db[i].cost << "\n";

	//������ � ��������� �������� 675000
	Mail found = db.Find([](Mail m) { return m.index == 675000; });
	//[](Mail m) { return m.index == 675000; } ������ ��� �� ������ ������ �������
	//m - ������� ���� ������, ����� ������� ��������� � { } - ���� ������� �����������
	//������� Find ������ ���� m ������� �� � ���������� found.

	cout << "Price greater than 20:\n";
	//����������� �� ���� ���� 20
	auto new_db = db.Filter([](Mail m) { return m.cost > 20; });

	//������� ����
	for (size_t i = 0; i < new_db.Size(); ++i)
		cout << new_db[i].cost << "\n";

	new_db.Add({ 12, "asda", "asdasd", "asdasd", "asd", 12.5 });
	ofstream fout("file.bin", ios_base::binary | ios_base::out | ios_base::trunc);
	fout.write(reinterpret_cast<char*>(&new_db), sizeof(new_db));
	fout.close();

	Database<Mail> mn;
	ifstream fin("file.bin", ios_base::binary | ios_base::in);
	fin.read(reinterpret_cast<char*>(&mn), sizeof(Database<Mail>));

	//������ � InteractDB
	Database<Food> database = InteractDB::CreateDatabaseWith<FoodInteract, Food>();
	Food f = InteractDB::FindElement<FoodInteract>(database);

	return 0;
}
