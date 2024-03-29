#pragma once
#include <string>

struct Student {
	Student(std::string surna, std::string& na, std::string& fac, const unsigned int& gr) :
		surname(surna), name(na), faculty(fac), group(gr) {}
	Student() = default;
	bool Empty() { return surname.empty() && name.empty() && faculty.empty() && group == 0; }

	//Сериализация
	template<class Archive>
	void serialize(Archive & archive) {
		archive(surname, name, faculty, group);
	}

	std::string surname;
	std::string name;
	std::string faculty;
	unsigned int group;
};

