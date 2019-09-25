#include "Database.h"
#include "Mail.h"
#include "Food.h"
#include "FileIO.h"
#include "InteractDB.h"
#include "FoodInteract.h"
#include "MailInteract.h"
//#include "StudentInteract.h"
#include "InteractDB.h"

#include <string>
#include <iostream>
#include <fstream>

#define InterType FoodInteract
#define Type Food

using namespace std;

char ChooseFirstAction() {
	cout << "Choose an action:\n" <<
		"1)Add new element\n" <<
		"2)Print database\n" <<
		"3)Searching\n" <<
		"4)Filter\n" <<
		"5)Exit\n" <<
		"Enter number: ";
	char choice;
	cin >> choice;
	if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5') return choice;
	else { ClearCin(cin); return ChooseFirstAction(); }

	return '6';
}



int main() {
	Database<Type> db;
	db = InteractDB::RestoreDbWith<Type>();

	bool is_over = false;
	do {
		char act = ChooseFirstAction();
		if (act == '1') {
			InteractDB::AddFewElements<InterType>(db);
		}
		else if (act == '2') {
			InteractDB::PrintTable<InterType>(db);
		}
		else if (act == '3') {
			if (auto found_el = InteractDB::FindElement<InterType>(db); !found_el.Empty()) {
				cout << "Found element:\n";
				InterType::OutputData(found_el);
			}
		}
		else if (act == '4') {
			if (auto new_db = InteractDB::FilterElements<InterType>(db); !new_db.Empty()) {
				cout << "Filtered Elements:\n";
				InteractDB::PrintTable<InterType>(new_db);
			}
		}
		else if (act == '5')
			is_over = true;
	} while (!is_over);

}