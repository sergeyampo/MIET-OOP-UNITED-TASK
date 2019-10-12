#pragma once
#include <string>
#include <iostream>

struct Mail {
	Mail(const unsigned int& ind, const std::string& rec_adr, const std::string& rec_name, const std::string& sen_adr, const std::string& sen_name, const float& cst) :
		index(ind), reciever_adress(rec_adr), reciever_name(rec_name), sender_adress(sen_adr), sender_name(sen_name), cost(cst) { }
	Mail() = default;
	~Mail() = default;

	bool Empty() { return index == 0 && reciever_adress.empty() && reciever_name.empty() && sender_adress.empty() && sender_name.empty() && cost == 0.00; }

	//Сериализация
	template<class Archive>
	void serialize(Archive & archive) {
		archive(index, reciever_adress, reciever_name, sender_adress, sender_name, cost);
	}

	Mail& operator=(const Mail& rhs) { std::tie(index, reciever_adress, reciever_name, sender_adress, sender_name, cost) = 
                                       std::tie(rhs.index, rhs.reciever_adress, rhs.reciever_name, rhs.sender_adress, rhs.sender_name, rhs.cost);
	                                   return *this; }
	std::ostream& Write(std::ostream& out) {
		out << index << "\t" << reciever_adress << "\t" << reciever_name << "\t" << sender_adress << "\t" << sender_name << "\t" << cost << "\n";
		return out;
	}

   unsigned int index;
   std::string reciever_adress;
   std::string reciever_name;
   std::string sender_adress;
   std::string sender_name;
   double cost;
};

inline std::ostream& operator<<(std::ostream& out, Mail& m) {
	return m.Write(out);
}