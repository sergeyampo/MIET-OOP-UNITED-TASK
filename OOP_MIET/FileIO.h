#pragma once
#include "cereal/archives/binary.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/array.hpp"
#include "cereal/types/base_class.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <filesystem>
#include <stdexcept>
#include <sstream>

void ClearCin(std::istream& in) {
	in.clear();
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//Класс для сериализации и сохранения и считывания объектов с помощью библиотеки cereal
	class FileIO {
	public:
		FileIO() = default;
		~FileIO() = default;
		FileIO(const FileIO& file) = default;
		FileIO(FileIO&& file) = default;
		explicit FileIO(const std::string& n) : filename(n) { }

		//Класс принимает объект и название файла из которого
		//мы бинарно считаем данные в этот объект
		template <class T>
		T ReadBinary(T obj, const std::string& file) {
			if (!FileExist(file))
				throw std::domain_error("File with " + file + " name doesn't exist.");

			filename = file;
			std::ifstream fin(file, ios_base::in | ios_base::binary);
			if (!fin.is_open())
				throw std::domain_error("Can't open " + file + " file.");

			cereal::BinaryInputArchive iarchive(fin);
			iarchive(obj);

			return obj;
		}

		//Класс принимает объект и название файла, куда мы бинарно запишем данные
		//из этого объекта
		template <class T>
		void WriteBinary(T obj, const std::string& file) {
			if (!FileExist(file)) 
				throw std::domain_error("File with " + file + " name doesn't exist. Creating it. Try again!");
			

			filename = file;
			std::ofstream fout(file, ios_base::out | ios_base::binary | ios_base::trunc);
			if (!fout.is_open())
				throw std::domain_error("Can't open " + file + " file.");

			cereal::BinaryOutputArchive oarchive(fout);
			oarchive(obj);
		}

		//Класс создаёт новый файл с переданным именем
		void Create(const std::string& file) {
			std::ofstream fout(filename.c_str());
			fout.close();
			if (!std::filesystem::exists(file.c_str()))
				throw std::domain_error("File with " + file + " name cannot be created!");
		}

		std::string GetName() { return filename; }
		void SetName(const std::string& name) { filename = name; }

		//	string ReadText(const std::string& file = filename);
		//	void WriteText(const std::string& file = filename);

	private:
		//Функция проверяет наличие указанного файла в папке C++17
		bool FileExist(const std::string& name) { return std::filesystem::exists(name.c_str()); }

		std::string filename;

	};