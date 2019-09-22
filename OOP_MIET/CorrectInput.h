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
				if (isalpha(*beg) == false)//проверка каждого символа на букву
					key = 0;
			if (key == 0)
				cout << "enter text again" << endl;
			else
				return text;
		}

	}

	double EnterDoubleNum()
	{
		while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
		{
			cout << "Enter a double value: ";
			double a;
			cin >> a;
			if (cin.fail() or a < 0) // если предыдущее извлечение оказалось неудачным,
			{
				cin.clear(); // то возвращаем cin в 'обычный' режим работы
				cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			}

			else // если всё хорошо, то возвращаем a
				return a;
		}
	}
	unsigned int EnterIntNum()
	{
		while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
		{
			cout << "Enter a unsigned int value: ";
			unsigned int a;
			cin >> a;
			if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
			{
				cin.clear(); // то возвращаем cin в 'обычный' режим работы
				cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			}
			else // если всё хорошо, то возвращаем a
				return a;
		}
	}
};









