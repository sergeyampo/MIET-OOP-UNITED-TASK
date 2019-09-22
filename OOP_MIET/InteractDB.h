#pragma once
#include "Database.h"
#include "CorrectInput.h"
#include <iostream>

//������������� ��������� ������ � ����� ������
namespace InteractDB {
	//������� �������� ���� ������ � ������ ��������� �������� � ���������� �����������
	//���������. ��������� ������� � ���� ������.
	//�������� ��� InteractDB::AddElement<FoodInteract>(db);
	template <class InteractType, class ItemType>
	static void AddElement(Database<ItemType>& db) {
	    //cout something
		ItemType item = InteractType::InputData();
		db.Add(item);
	}

	//������� �������� ���� ������ � ������ ��������� �������� � ���������� �����������
	//���������. ��������� ��������� ��������� � ���� ������. 
	template <class InteractType, class ItemType>
	static void AddFewElements(Database<ItemType>& db) {
		unsigned int count = 0;
		cout << "Enter amount of elements, which you want to create\n"
			"or type 0 if you don't: ";
		int amount = CorrectInput::CorrectInput::EnterIntNum();

		for (int i = 0; i < amount; i++)
			AddElement<InteractType>(db);
	}

	//������� �������� ����� ����� ��������� ��������� ����� �������������� b ��� �������� � ���� ������
	//������ �������� ���� ������.
	//�������� ��� CreateDatabaseWith<FoodInteract, Food>()
	template <class InteractType, class ItemType>
	static Database<ItemType> CreateDatabaseWith() {
		cout << "Enter the size of DataBase: ";
		int k = 0;
		k = CorrectInput::EnterIntNum();
		Database<ItemType> db(k, ItemType());
		for (int i = 0; i < k; i++)
			db[i] = InteractType::InputData();

		return db;
	}

	//������ ������ ���������
	template <class InteractType, class ItemType>
	static ItemType FindElement(Database<ItemType>& db) {
		auto predic = InteractType::GetFindCritery();
		ItemType found = db.Find(predic);
		if (found.empty())
			cout << "Element not found!" << endl;

		return found;
	}

	//������ ������� ��������� - ������������ ���� ������ �������� �������
	//������������� ��������� InteractType::GetFilterCritery.
	template <class InteractType, class ItemType>
	static Database<ItemType> FilterElements(const Database<ItemType>& db) {
		auto predic = InteractType::GetFilterCritery();
		Database<ItemType> new_db = db.Filter(predic);

		return new_db;
	}

	//������ ���������� ���������, ������ ������� ��������� ���������� ���� ������.
	template <class InteractType, class ItemType>
	static void SortElements(Database<ItemType>& db) {
		auto predic = FoodInteract::GetSortCritery();
		db.Sort(predic);
	}
};


//���������������� ����� �������������� � ��������
class FoodInteract {
public:
	FoodInteract() = delete;
	~FoodInteract() = delete;

	//����� ������� ����� ���� �����

	static Food InputData() {
		Food Buffer;
		cout << "enter fam" << endl;
		Buffer.fam = CorrectInput::EnterSym();
		cout << "enter type" << endl;
		Buffer.type = CorrectInput::EnterIntNum();
		cout << "enter wight" << endl;
		Buffer.weight = CorrectInput::EnterDoubleNum();
		cout << "enter count" << endl;
		Buffer.count = CorrectInput::EnterIntNum();
		cout << "enter cost" << endl;
		Buffer.cost = CorrectInput::EnterDoubleNum();
		return Buffer;
		//�������� InputIndex(), InputRecAdress() ...
		//���� ������� false ������ �� ����� �������� �� ��� ���
		//������ ����� � ������� ������������ ������ ��� ���

	}


	static auto GetFindCritery() {

		string buffer = CorrectInput::EnterSym();
		return [buffer](Food m) { return m.fam == buffer; };

		//���� �� ������� �� return [](Food m) { return m.index == �������� ������ ������������� };
	   //���� ������� �� ����� � ������������ �� ���� ������� ����� 1 � 2 ����� 15
	   //������ ����� � ������� ������������ ������ ��� ���
	   //�� ���� �������� ���� ���� return GetFindCritery();
	}


	static auto GetFilterCritery() {

		unsigned int buffer = CorrectInput::EnterIntNum();
		return [buffer](Food m) { return m.type == buffer; };

		//������ ������� �������� ������� � ����������
		//������ ������� - ��������.
		//"�������� ��� �� ������ �����������, �� �����
		//�� �������"
		//���� �������� �� ����� ������
	   //return [](Food m) { return m.name == "�������� ��� �������������" };
	   //���� �� ������� �� return [](Food m) { return m.index == �������� ������ ������������� };
	   //���� ������� �� ����� � ������������ �� ���� ������� ����� 1 � 2 ����� 15
	   //������ ����� � ������� ������������ ������ ��� ���
	   //�� ���� �������� ���� ���� return GetFilterCritery();
	   //�� ����������
	}
	template <class Func>
	static void GetSortCritery() {
		cout << "enter critery of search:" << endl << "1-fam" << endl << "2-type" << endl << "3-wight" << endl << "4-count" << endl << "5-cost" << endl;
		unsigned int k = 0;
		cin >> k;
		if (k == 1)
		{
			string buffer = CorrectInput::EnterSym();
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

