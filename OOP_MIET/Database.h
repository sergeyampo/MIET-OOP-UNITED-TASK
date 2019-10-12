#pragma once
#include "Mail.h"
#include "FileIO.h"
#include <vector>
#include <algorithm>

//Шаблонный класс - база данных для элементов различных типов, реализующая некоторые
//функции доступа и поиска.
template <class ItemType>
class Database {
public:
	//Конструкторы и деструктор
	Database() = default;
	//Конструктор для создания amount копий item объекта типа ItemType в базе данных.
	Database(const size_t& amount, const ItemType& item) : data(amount, item) { }
   ~Database() = default;
	Database(const Database& rhs) = default;

	//Функция добавления объектов в базу данных
	void Add(const ItemType& item) { data.emplace_back(item); }
	//Универсальная функция поиска в базе по предикату pred, принимающая функцию предиката
	//возвращающая найденные или пустой объект, хранящийся в базе.
	template <class Func>
	ItemType Find(Func pred) {
		auto found = find_if(data.begin(), data.end(), pred);
		if (found == data.end())
			return ItemType();

		return *found;
	}
	//Универсальная функция фильтра по критерию возвращающая отфильтрованный Database
	//объект.
	template <class Func>
	Database<ItemType> Filter(Func Criterion) {
		Database<ItemType> new_data;
		std::for_each(begin(data), end(data), [&new_data, &Criterion](const ItemType& it) { if (Criterion(it)) new_data.Add(it);  });

		return new_data;
	}
	//Функция принимает предикат по которому будем выбирать критерий сортировки, сортирует Database объект.
	template <class Func>
	void Sort(Func pred) { std::sort(begin(data), end(data), pred); }


	//Определяем оператор доступа по индексу.
	ItemType& operator[](const size_t& index) {
		return data[index];
	}
	//Функции состояния
	size_t Size() { return data.size(); }
	bool Empty() { return data.empty(); }

	//Функция сериализации
	template<class Archive>
	void serialize(Archive & archive) {
		archive(data);
	}

private:
	std::vector<ItemType> data;
};

