#pragma once
#include<iostream>
#include <string>

using namespace std;

namespace CorrectInput {
	string EnterSym()
	{

		string text;
		while (true)
		{
			bool key = 1;
			cin >> text;
			for (string::iterator beg = text.begin(); beg != text.end(); beg++)
				if (isalpha(*beg) == false)//�������� ������� ������� �� �����
					key = 0;
			if (key == 0)
				cout << "enter text again" << endl;
			else
				return text;
		}

	}

	double EnterDoubleNum()
	{
		while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ����� ���������� ��������
		{
			cout << "Enter a double value: ";
			double a;
			cin >> a;
			if (cin.fail() or a < 0) // ���� ���������� ���������� ��������� ���������,
			{
				cin.clear(); // �� ���������� cin � '�������' ����� ������
				cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			}

			else // ���� �� ������, �� ���������� a
				return a;
		}
	}
	unsigned int EnterIntNum()
	{
		while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ����� ���������� ��������
		{
			cout << "Enter a unsigned int value: ";
			unsigned int a;
			cin >> a;
			if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
			{
				cin.clear(); // �� ���������� cin � '�������' ����� ������
				cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			}
			else // ���� �� ������, �� ���������� a
				return a;
		}
	}
};









