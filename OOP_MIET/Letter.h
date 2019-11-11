#pragma once
#include "Man.h"
#include <string>
#include <iostream>

class Letter {
  public:
	Letter(const unsigned int& ind, const Man& rec, const Man& sen) : index(ind), reciever(rec), sender(sen) { }
	Letter() = default;
    virtual ~Letter() = default;
    Letter(const Letter&) = default;
    Letter(Letter&&) = default;


	virtual bool Empty() const { return index == 0 && reciever.Empty() && sender.Empty(); }

	//Сериализация
	template<class Archive>
	void serialize(Archive & archive) {
		archive(index, reciever, sender);
	}

	Letter& operator=(const Letter& rhs) { std::tie(index, reciever, sender) = std::tie(rhs.index, rhs.reciever, rhs.sender);
	                                   return *this; }
	
	virtual std::ostream& Write(std::ostream& out) {
		out << index << "\t";
		reciever.Write(out);
		out << "\t";
		sender.Write(out);
		out << "\t";

		return out;
	}

	unsigned GetIndex() const noexcept { return index; }
	void SetIndex(const unsigned& arg) { index = arg; }

	std::string GetRecieverAdress() const noexcept { return reciever.GetAddress(); }
	void SetRecieverAddress(const std::string& arg) { reciever.SetAddress(arg); }
	
	std::string GetRecieverName() const noexcept { return reciever.GetName(); }
	void SetRecieverName(const std::string& arg) { reciever.SetName(arg); }
	
	std::string GetSenderAddress() const noexcept { return sender.GetAddress(); }
	void SetSenderAddress(const std::string& arg) { sender.SetAddress(arg); }

	std::string GetSenderName() const noexcept { return sender.GetName(); }
	void SetSenderName(const std::string& arg) { sender.SetName(arg); }

	virtual double GetCost() const noexcept { return 0; }
	virtual double GetWeight() const noexcept { return 0; }

  private:
   unsigned int index;
   Man reciever;
   Man sender;
};

//Письмо, имеющее массу
class Letter1 : public Letter {
  public:
	Letter1() : Letter() {}
   ~Letter1() = default;
    Letter1(const Letter1& l) : Letter(l) { }
	Letter1(const unsigned int& ind, const Man& rec, const Man& sen, const double& wght, const double& cst) : Letter(ind, rec, sen), weight(wght) { }
	Letter1(const Letter& l, const double& w) : Letter(l), weight(w) { }
	
	bool Empty() const override { return Letter::Empty() && weight == 0.00; }

	//Сериализация
	template<class Archive>
	void serialize(Archive & archive) {
		archive(cereal::base_class<Letter>(this), weight);
	}

	std::ostream& Write(std::ostream& out) override {
		Letter::Write(out);
		out << weight << "\n";

		return out;
	}

	double GetWeight() const noexcept override { return weight; }
	void SetWeight(const double& arg) { weight = arg; }
	double GetCost() const noexcept override { return 0; }

  private:
	  double weight;
};

//Письмо имеющее стоимость
class Letter2 : public Letter {
 public:
   Letter2() : Letter() {}
  ~Letter2() = default;
   Letter2(const Letter2& l) : Letter(l) { }
   Letter2(const unsigned int& ind, const Man& rec, const Man& sen, const double& cst) : Letter(ind, rec, sen), cost(cst) { }
   Letter2(const Letter& l, const double& cst) : Letter(l) { SetCost(cst); }

   bool Empty() const override { return Letter::Empty() && cost == 0.00; }

   std::ostream& Write(std::ostream& out) override {
	   Letter::Write(out);
	   out << cost << "\n";

	   return out;
   }

   //Сериализация
   template<class Archive>
   void serialize(Archive & archive) {
	   archive(cereal::base_class<Letter>(this), cost);
   }

  double GetCost() const noexcept override { return cost; }
  void SetCost(const double& arg) { cost = arg; }
  double GetWeight() const noexcept override { return 0; }

  private:
	  double cost;
};

inline std::ostream& operator<<(std::ostream& out, Letter& m) {
	return m.Write(out);
}