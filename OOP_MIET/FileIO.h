#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <filesystem>
#include <stdexcept>

void ClearCin(std::istream& in) {
	in.clear();
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class FileIO {
public:
	FileIO() = default;
	~FileIO() = default;
	FileIO(const FileIO& file) = default;
	FileIO(FileIO&& file) = default;

	template <class T>
	T ReadBinary(T& obj, const std::string& file = filename) {
		if (!FileExist(file))
			throw std::domain_error("File with " + file + " name doesn't exist.");

		std::ifstream fin(file, ios_base::in | ios_base::binary);
		if (!fin.is_open())
			throw std::domain_error("Can't open " + file + " file.");

		fin.read(reinterpret_cast<char*>(&obj), sizeof(T));
		return obj;
	}

	template <class T>
	void WriteBinary(T& obj, const std::string& file = filename) {
		if (!FileExist(file))
			throw std::domain_error("File with " + file + " name doesn't exist.");

		std::ofstream fout(file, ios_base::out | ios_base::binary | ios_base::trunc);
		if (!fout.is_open())
			throw std::domain_error("Can't open " + file + " file.");

		fout.write(reinterpret_cast<char*>(&obj), sizeof(obj));
	}

	//	string ReadText(const std::string& file = filename);
	//	void WriteText(const std::string& file = filename);

private:
	bool FileExist(const std::string& name) { return std::filesystem::exists(name.c_str()); }

	std::string filename;

};
