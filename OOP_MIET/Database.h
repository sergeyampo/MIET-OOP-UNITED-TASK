#pragma once
#include "Mail.h"
#include <vector>
#include <algorithm>

//��������� ����� - ���� ������ ��� ��������� ��������� �����, ����������� ���������
//������� ������� � ������.
template <class ItemType>
class Database {
public:
	//������������ � ����������
	Database() = default;
	//����������� ��� �������� amount ����� item ������� ���� ItemType � ���� ������.
	Database(const size_t& amount, const ItemType& item) : data(amount, item) { }
   ~Database() = default;
	Database(const Database& rhs) = default;

	//������� ���������� �������� � ���� ������
	void Add(const ItemType& item) { data.emplace_back(item); }
	//������������� ������� ������ � ���� �� ��������� pred, ����������� ������� ���������
	//������������ ��������� ��� ������ ������, ���������� � ����.
	template <class Func>
	ItemType Find(Func pred) {
		auto found = find_if(data.begin(), data.end(), pred);
		if (found == data.end())
			return ItemType();

		return *found;
	}
	//������������� ������� ������� �� �������� ������������ ��������������� Database
	//������.
	template <class Func>
	Database<ItemType> Filter(Func Criterion) {
		Database<ItemType> new_data;
		std::for_each(begin(data), end(data), [&new_data, Criterion](const ItemType& it) { if (Criterion(it)) new_data.Add(it);  });

		return new_data;
	}
	//������� ��������� �������� �� �������� ����� �������� �������� ����������, ��������� Database ������.
	template <class Func>
	void Sort(Func pred) { std::sort(begin(data), end(data), pred); }


	//���������� �������� ������� �� �������.
	ItemType& operator[](const size_t& index) {
		return data[index];
	}
	//������� ���������
	size_t Size() { return data.size(); }
	bool Empty() { return data.empty(); }


private:
	std::vector<ItemType> data;
};

