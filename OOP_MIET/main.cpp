﻿#include "Database.h"
#include "Letter.h"
#include "Food.h"
#include "FileIO.h"
#include "InteractDB.h"
#include "FoodInteract.h"
#include "LetterInteract.h"
#include "StudentInteract.h"
#include "InteractDB.h"
#include "Pathes.h"

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <memory>

#define InterType LetterInteract	
#define Type Letter

using namespace std;

char ChooseFirstAction(PathIO pat) {
	system("CLS");
	cout << "CurrentFile:"<<
		pat.GetCurrentFile().string()<<"\n"<<
		"Choose an action:\n" <<
		"1)Add new element\n" <<
		"2)Print database\n" <<
		"3)Searching\n" <<
		"4)Filter\n" <<
		"5)Sort\n"<<
		"6)Choose another File\n" <<
		"7)Exit\n"<<
		"Enter number: ";
	char choice;
	cin >> choice;
	system("CLS");

	if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6'||choice=='7') return choice;
	else { ClearCin(cin); return ChooseFirstAction(pat); }

	return '0';
}

//Функция ожидает нажатия Ок
istream& WaitEnter(istream& in, ostream& out) {
	out << "Press the enter to continue...";
	ClearCin(in);
	in.get();

	return in;
}

int main() {
	//Восстановление базы данных с файла
	Database<Type> db;
	PathIO FilePathes;
	FilePathes.CreateVector<InterType>();
	db = InteractDB::ChooseFirstFile<InterType,shared_ptr<Type> >(FilePathes);	

	//Циклический запрос дейстаия
	bool is_over = false;
	do {
		
		char act = ChooseFirstAction(FilePathes);
		if (act == '1') {
			InteractDB::AddFewElements<InterType>(db);
		}
		else if (act == '2') {
			InteractDB::PrintTable<InterType>(db);
			WaitEnter(cin, cout);
		}
		else if (act == '3') {
			if (!db.Empty()) {
				if (auto found_el = InteractDB::FindElement<InterType>(db); !found_el->Empty()) {
					cout << "Found element:\n";
					InterType::OutputData(found_el);
				}
			}
			else
				cout << "There's nothing to find!\n";

			WaitEnter(cin, cout);
		}
		else if (act == '4') {
			if (!db.Empty()) {
				if (auto new_db = InteractDB::FilterElements<InterType>(db); !new_db.Empty()) {
					cout << "Filtered Elements:\n";
					//Do you want to save...
					InteractDB::PrintTable<InterType>(new_db);
					cout << "Do you want to save...\n"
						"Y-YES,another sym NO";
					char chs;
					cin >> chs;
					if (chs == 'Y' || chs == 'y')
						InteractDB::CreateFile<InterType>(new_db, FilePathes);											   						 					  			
				}
			}
			else
				cout << "There's nothing to find!\n";

			WaitEnter(cin, cout);
		}
		else if (act == '5') {
			if (!db.Empty()) {
				InteractDB::SortElements<InterType>(db);
				cout << "Sorted Elements:\n";
				InteractDB::PrintTable<InterType>(db);
			}
			else
				cout << "There's nothing to sort!\n";
			WaitEnter(cin, cout);
		}
		else if (act == '6') {		
			if (!db.Empty()) {
				cout << "Do you want to save current File";
				FilePathes=InteractDB::SaveData<InterType>(db, FilePathes);
			}
			db=InteractDB::ChooseFile<InterType>(FilePathes,db);
			
		}

		else if(act == '7'){
			if(!db.Empty())
			  InteractDB::SaveData<InterType>(db, FilePathes);
			
			is_over = true;
			cout << "Waiting for closing...";
			this_thread::sleep_until(chrono::system_clock::now() + 2.5s);
		}
	} while (!is_over);

	return 0;
}