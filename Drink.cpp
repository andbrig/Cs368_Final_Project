#include "Drink.hpp"

Drink::Drink(std::string newname, std::string newtype, long newpercentAlc, std::string newSpecificType) {
	name = newname;
	type = newtype;
	percentAlc = newpercentAlc;
	specificType = newSpecificType;
}
std::string Drink::getName() {
	return name;
}
std::string Drink::getType() {
	return type;
}
long Drink::getPercentAlc() {
	return percentAlc;
}
std::string Drink::getSpecificType() {
	return specificType;
}
 
