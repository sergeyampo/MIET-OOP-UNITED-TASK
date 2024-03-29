﻿#pragma once
#include <string>

struct Food {
	Food(const std::string& fam_, const unsigned int& type_, const double& weight_, const unsigned int& count_, const double& cst) :
		fam(fam_), type(type_), weight(weight_), count(count_), cost(cst) { }
	Food() = default;

	std::string fam;
	unsigned int type;
	double weight;
	unsigned int count;
	double cost;

	bool Empty() { return fam=="" && type == 0 && weight == 0 && count == 0 && cost == 0.00; }
	//Сериализация
	template<class Archive>
	void serialize(Archive & archive) {
		archive(fam, type, weight, count, cost);
	}
};

