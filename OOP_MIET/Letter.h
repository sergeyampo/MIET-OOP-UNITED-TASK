#pragma once
#include "Man.h"
#include <string>
#include <iostream>

class Letter {
  public:
	Letter(const unsigned int& ind, const Man& rec, const Man& sen, const float& cst) : index(ind), reciever(rec), sender(sen), cost(cst) { }
	Letter() = default;
   ~Letter() = default;
    Letter(const Letter&) = default;
    Letter(Letter&&) = default;


	bool Empty() const { return index == 0 && reciever.Empty() && sender.Empty() && cost == 0.00; }

	//Сериализация
	template<class Archive>
	void serialize(Archive & archive) {
		archive(index, reciever, sender, cost);
	}

	Letter& operator=(const Letter& rhs) { std::tie(index, reciever, sender, cost) = std::tie(rhs.index, rhs.reciever, rhs.sender, rhs.cost);
	                                   return *this; }
	
	std::ostream& Write(std::ostream& out) {
		out << index << "\t";
		reciever.Write(out);
		out << "\t";
		sender.Write(out);
		out << "\t";
		out << cost << "\n";
		return out;
	}

	unsigned GetIndex() const noexcept { return index; }
	void SetIndex(const unsigned& arg) { index = arg; }

	std::string GetRecieverAdress() const noexcept { return reciever.GetAddress(); }
	void SetRecieverAddress(const std::string& arg) { reciever.SetName(arg); }
	
	std::string GetRecieverName() const noexcept { return reciever.GetName(); }
	void SetRecieverName(const std::string& arg) { reciever.SetName(arg); }
	
	std::string GetSenderAddress() const noexcept { return sender.GetAddress(); }
	void SetSenderAddress(const std::string& arg) { sender.SetAddress(arg); }

	std::string GetSenderName() const noexcept { return sender.GetName(); }
	void SetSenderName(const std::string& arg) { sender.SetName(arg); }

	double GetCost() const noexcept { return cost; }
	void SetCost(const double& arg) { cost = arg; }

	//SENSELESS, Erase it!
	bool operator==(const Man& rhs) { return sender.GetAddress() == rhs.GetAddress(); }


  private:
   unsigned int index;
   Man reciever;
   Man sender;
   double cost;
};

inline std::ostream& operator<<(std::ostream& out, Letter& m) {
	return m.Write(out);
}