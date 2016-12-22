#ifndef DRINK_HPP
#define DRINK_HPP
#include <string>

class Drink {
private:
	std::string name;
	std::string type;
	long percentAlc;
	std::string specificType;
public:
	Drink();
	Drink(std::string name, std::string type, long percentAlc, std::string specificType);
	std::string getName();
	std::string getType();
	long getPercentAlc();
	std::string getSpecificType();	
};
#endif /* DRINK_HPP */
