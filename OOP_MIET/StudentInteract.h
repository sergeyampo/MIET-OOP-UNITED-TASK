#pragma once

#include <iostream>
#include <string>
#include "Student.h"

//������ ���� ������ ����� ����� ���� ShopInteract, CafeInteract, SexInteract
class StudentInteract {
public:
	StudentInteract() = delete;
	~StudentInteract() = delete;

	//����� ������� ����� ���� �����
	static Student InputData() {
		Student Buffer;
		std::cout << "Enter surname " << std::endl;






		std::cout << "enter index" << std::endl;
		Buffer.index = EnterIntNum();
		std::cout << "enter reciver_adresss" << endl;
		Buffer.reciever_adress = EnterSym();
		cout << "enter reciver_name" << endl;
		Buffer.reciever_name = EnterSym();
		cout << "enter sender_adresss" << endl;
		Buffer.sender_adress = EnterSym();
		cout << "enter sender_name" << endl;
		Buffer.sender_name = EnterSym();
		cout << "enter cost" << endl;
		Buffer.cost = EnterDoubleNum();
		return Buffer;
		//�������� InputIndex(), InputRecAdress() ...
		//���� ������� false ������ �� ����� �������� �� ��� ���
		//������ ����� � ������� ������������ ������ ��� ���
		//�� ���� �������� ���� ���� return InputData();
	}

	template <class Func>
	static Func GetFindCritery() {
		//������ ������ ���� ��� ������ � ����� ���������� ������� (string)
		cout << "" << endl;

		string buffer = EnterSym();
		return [](Student s) { return s.surname == buffer; };
		//������ ������� �������� ������ � ����������
		//������ ������� - ��������.
		//"�������� ��� �� ������ ������, �� �����
		//�� �������"
		//���� �������� �� ����� ������
		//return [](Mail m) { return m.name == "�������� ��� �������������" };
		//���� �� ������� �� return [](Mail m) { return m.index == �������� ������ ������������� };
	   //���� ������� �� ����� � ������������ �� ���� ������� ����� 1 � 2 ����� 15
	   //������ ����� � ������� ������������ ������ ��� ���
	   //�� ���� �������� ���� ���� return GetFindCritery();
	}

	template <class Func>
	static Func GetFilterCritery() {
		unsigned int buffer = EnterIntNum();
		return [](Student s) { return s.group == buffer; };
		//������ ������� �������� ������� � ����������
		//������ ������� - ��������.
		//"�������� ��� �� ������ �����������, �� �����
		//�� �������"
		//���� �������� �� ����� ������
		//return [](Mail m) { return m.name == "�������� ��� �������������" };
		//���� �� ������� �� return [](Mail m) { return m.index == �������� ������ ������������� };
	   //���� ������� �� ����� � ������������ �� ���� ������� ����� 1 � 2 ����� 15
	   //������ ����� � ������� ������������ ������ ��� ���
	   //�� ���� �������� ���� ���� return GetFilterCritery();
	   //�� ����������
	}
	template <class Func>
	static void GetSortCritery() {
		return [](Mail x, Mail y) { return x.reciever_name < y.reciever_name; }
			//�� ���� �����
	}
};

//��� ��������, ��� �� � main.
Database<Mail> db;
InteractDB::AddElement(db);
Database<Mail> new_db = InteractDB::FilterElements(db);
Mail found = InteractDB::FindElement(new_db);
InteractDB::SortElements(new_db);


