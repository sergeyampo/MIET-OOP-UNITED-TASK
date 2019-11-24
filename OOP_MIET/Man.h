#pragma once
#include <string>
#include <tuple>
#include <iostream>

class Man {
  public:
    Man() = default;
   ~Man() = default;
    Man(const Man&) = default;
	Man(Man&&) = default;
	Man(const std::string& nm, const std::string& addr) : name(nm), address(addr) { }

	std::string GetName() const noexcept { return name; }
	void SetName(const std::string& arg) { name = arg; }

	std::string GetAddress() const noexcept { return address; }
	void SetAddress(const std::string& arg) { address = arg; }

	//Сериализация
	template<class Archive>
	void serialize(Archive & archive) {
		archive(name, address);
	}

	bool Empty() const { return name.empty() && address.empty(); }

	Man& operator=(const Man& rhs) { std::tie(name, address) = std::tie(rhs.name, rhs.address); return *this; }

	std::ostream& Write(std::ostream& out) {
		out << name << "\t" << address;
		return out;
	}

  private:
    std::string name;
	std::string address;
};