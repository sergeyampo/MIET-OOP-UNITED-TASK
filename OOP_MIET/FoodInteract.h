#pragma once

#include "Food.h"
#include "CorrectInput.h"
#include <iostream>
#include <string>

//���������������� ����� �������������� � ��������
class FoodInteract {
public:
	FoodInteract() = delete;
	~FoodInteract() = delete;

	//����� ������� ����� ���� �����

	static Food InputData() {
		Food Buffer;
		std::cout << "enter fam" << std::endl;
		Buffer.fam = CorrectInput::EnterSym();
		std::cout << "enter type" << std::endl;
		Buffer.type = CorrectInput::EnterIntNum();
		std::cout << "enter wight" << std::endl;
		Buffer.weight = CorrectInput::EnterDoubleNum();
		std::cout << "enter count" << std::endl;
		Buffer.count = CorrectInput::EnterIntNum();
		std::cout << "enter cost" << std::endl;
		Buffer.cost = CorrectInput::EnterDoubleNum();
		return Buffer;
		//�������� InputIndex(), InputRecAdress() ...
		//���� ������� false ������ �� ����� �������� �� ��� ���
		//������ ����� � ������� ������������ ������ ��� ���

	}


	static auto GetFindCritery() {

		std::string buffer = CorrectInput::EnterSym();
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
		std::cout << "enter critery of search:" << std::endl << "1-fam" << std::endl << "2-type" << std::endl << "3-wight" << std::endl << "4-count" << std::endl << "5-cost" << std::endl;
		unsigned int k = 0;
		cin >> k;
		if (k == 1)
		{
			std::string buffer = CorrectInput::EnterSym();
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