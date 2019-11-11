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

//PathIO ������ ���� � main � � ������ ������ ��������: "������� ������ ����"
//�� ��� ����������.
class PathIO{	
    vector<fs::path> ps; //������ �����(� ������) ����� ��� ������������� ����
	fs::path current;
	fs::path currentFile;
public:	
	 PathIO() = default;
	~PathIO() = default;
	PathIO Set(PathIO secpat){
		ps = secpat.ps;
		current = secpat.current;
		currentFile = secpat.currentFile;

	}

	template <class InteractType>
	void CreateVector(){ //������ ��������
		fs::path curr_path = fs::current_path();
		curr_path = curr_path.parent_path();	
		string buffer = InteractType::GetFolderName();
		curr_path /= buffer;
		if (!fs::exists(curr_path))
			fs::create_directory(curr_path);
		current = curr_path;
		for (auto& p : fs::directory_iterator(curr_path))
			ps.push_back(p.path());		
	}
	
	void ListPathes()
	{
		for (int i = 0; i < ps.size(); i++)
			cout << i + 1 << " - " << ps[i].filename() << "\n";		
	}

	fs::path Getcurrent()
	{
		return current;
	}
	void AddPath(fs::path pat)	{
		ps.push_back(pat);
	}
	bool SamePath(fs::path pat) {
		bool key = true;
		for (auto p : ps)
			if (p == pat){
				key = false;
				cout << "File with " << p.filename() << " name exist... Try again\n";
				break;
		    }
		return key;
	}
	fs::path CreateFileName()
	{
		fs::path current_file = Getcurrent();
		cout << "Enter name of file: ";
		string buffer = CorrectInput::EnterSym();
		buffer += ".cereal";
		current_file /= buffer;
		if (!SamePath(current_file))
			CreateFileName();	
		currentFile = current_file;
		return current_file;
	}
	void SetCurrentFile(fs::path pat)
	{
		currentFile = pat;
	}
	fs::path GetCurrentFile()
	{
		return currentFile;
	}

	fs::path GetLast()
	{
		fs::path temp;
		//auto newest_file = std::min_element(begin(ps), end(ps), [](fs::path x, fs::path.y){ return fs::last_write_time(x) < fs::last_time_write(y); }));
		//return *newest_file;
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
	
	size_t Size() { return ps.size(); }	
	fs::path& operator[](const size_t& index) {
		return ps[index];
	}
	PathIO& operator=(PathIO secpat) {
		ps = secpat.ps;
		current = secpat.current;
		currentFile = secpat.currentFile;
		return *this;
	}

	
};

