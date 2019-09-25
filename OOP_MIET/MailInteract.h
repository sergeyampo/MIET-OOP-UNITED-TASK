#pragma once

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
		Buffer.index = CorrectInput::EnterIntNum();
		cout << "enter reciver_adresss" << endl;
		Buffer.reciever_adress = CorrectInput::EnterSym();
		cout << "enter reciver_name" << endl;
		Buffer.reciever_name = CorrectInput::EnterSym();
		cout << "enter sender_adresss" << endl;
		Buffer.sender_adress = CorrectInput::EnterSym();
		cout << "enter sender_name" << endl;
		Buffer.sender_name = CorrectInput::EnterSym();
		cout << "enter cost" << endl;
		Buffer.cost = CorrectInput::EnterDoubleNum();
		return Buffer;
		//�������� InputIndex(), InputRecAdress() ...
		//���� ������� false ������ �� ����� �������� �� ��� ���
		//������ ����� � ������� ������������ ������ ��� ���
		//�� ���� �������� ���� ���� return InputData();
	}

	static auto GetFindCritery() {
		string buffer = CorrectInput::EnterSym();
		return [&buffer](Mail m) { return m.sender_adress == buffer; };
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

	static auto GetFilterCritery() {
		unsigned int buffer = CorrectInput::EnterIntNum();
		return [&buffer](Mail m) { return m.index == buffer; };
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

	static auto GetSortCritery() {
		return [](Mail x, Mail y) { return x.reciever_name < y.reciever_name; };
			//�� ���� �����
	}
};


