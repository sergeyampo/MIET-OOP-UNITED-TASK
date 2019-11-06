#pragma once


#include <experimental/filesystem>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "Database.h"
#include "Letter.h"
#include "Food.h"
#include "FileIO.h"
#include "Student.h"
#include"CorrectInput.h"

using namespace std;
using namespace std::chrono;
namespace fs = experimental::filesystem;


class PathIO
{	
    vector<fs::path> ps;
	fs::path current;
public:	
	PathIO() = default;
	~PathIO() = default;

	template <class Type>
	void First()
	{
		fs::path temp = fs::current_path();
		temp = temp.parent_path();		
		if (typeid(Type) == typeid(Food))
			temp /= "Food";
		else
		if (typeid(Type) == typeid(Letter))
			temp /= "Letter";
		else
		if (typeid(Type) == typeid(Student))
			temp /= "Student";
		
		if (!fs::exists(temp))
		{
			fs::create_directory(temp)
		}
		current = temp;
		for (auto& p : fs::directory_iterator(temp)){
			ps.push_back(p.path());
		};
	}
	template <class InteractType, class ItemType>
	fs::path ChooseFirst()
	{ 		
		cout << "0-Get Last Save<3\n";
		for (int i=0;i<ps.size();i++)
		{
			cout << i+1<<" - " << ps[i].filename() << "\n";
		}
		cout << ps.size() << "-CreateFile\n";
		cout << "enter your choise";
		int n;
		cin >> n;
		if (n == 0)
		{
			if (ps.size() != 0)
			{
				return GetLast();
			}
			else
			{
				cout << "There are no files\n";
				return "";
			}
;
		}
		else if (n == ps.size())
		{
			Createfile();
		}
		else 
			return ps[n-1]
	}
	fs::path Choose(fs::path pat)
	{		
		cout << "0-GoBack\n";
		for (int i = 0; i < ps.size(); i++)
		{
			cout << "1-" << ps[i].filename() << "\n";
		}
		cout << ps.size() << "-CreateFile\n";
		cout << "enter your choise";
		int n;
		cin >> n;
		if (n == 0)
		{
			return fs::path pat;
		}
		else if (n == ps.size())
		{
			return Createfile();
		}
		else
			return ps[n - 1]
	}

	fs::path Getcurrent()
	{
		return current;
	}

	fs::path Createfile(fs::path pat)
	{
		cout << "enter fileName(onlystring)\n";
		string filename = CorrectInput::EnterSym();//ÊÀÊÎÅ ÐÀÑØÈÐÅÍÈÅ ÄËß ÔÀÉËÀ????????????????????????????????
		temp = pat + filename;
		FileIO.Create(temp);
		return temp;
	}
	fs::path GetLast()
	{
		auto LastTime = fs::last_write_time(ps[0]);
		temp = ps[0];
		for (auto p : ps)
		{
			if (fs::last_write_time(p) > LastTime)
			{
				temp = p;
				LastTime = fs::last_write_time(p);
			}				
		}
		return temp;
	}


};

