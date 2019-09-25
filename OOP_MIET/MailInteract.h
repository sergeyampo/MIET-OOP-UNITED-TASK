#include <iostream>
#include <string>
#include "Mail.h"

//������ ���� ������ ����� ����� ���� ShopInteract, CafeInteract, SexInteract
class MailInteract {
public:
	MailInteract() = delete;
	~MailInteract() = delete;

	//����� ������� ����� ���� �����
	static Mail InputData() {
		Mail Buffer;
		cout << "enter index" << endl;
		Buffer.index = EnterIntNum();
		cout << "enter reciver_adresss" << endl;
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
		string buffer = EnterSym();
		return [](Mail m) { return m.sender_adress == buffer; };
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
		return [](Mail m) { return m.index == buffer; };
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


