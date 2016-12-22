//	Andrew Briggs
//	briggs@wisc.edu 
//	CS 368
//	
//	Shubham Chamaria (Minimal)
//	chamaria@wisc.edu	
//	Cs368
//
//

#include <stdlib.h>
#include <string>
#include <iostream>
#include "Drink.hpp"
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>

void displayAllDrinks(std::vector<Drink>);
std::vector<Drink> searchDrinks(std::string keyword);
void fillDrinks(std::vector<Drink> &drinks);
//int calculateDrinks(int height, int weight, Drink drink);
std::vector<Drink> drinks;
int main() {
	std::string weight = "";
	std::string height = "";
	std::string inputFile = "drink.txt";
	fillDrinks(drinks);	
	while(1) {
		std::string keyword = "";
		std::string menu = "";
		std::cout << "WELCOME TO DRINKR 1.0" << std::endl;
		std::cout << "WARNING: Do not proceed further if you are under 21 years of age" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1. Search anything related to alcohol" << std::endl;
		std::cout << "2. View our Beers on Tap" << std::endl;
		std::cout << "3. View our Wine cellar" << std::endl;
		std::cout << "4. Check out our selection of Liquors" << std::endl;
		std::cout << "0. Quit" << std::endl;
		std::getline(std::cin, menu);
		if(menu == "1") {
        	//Search
			std::vector<Drink> tempVec;
               	 	std::cout<< "Search (Name, Type, Alcohol Percentage, Brand): " <<std::endl;
               	 	std::getline(std::cin, keyword);
        	        tempVec = searchDrinks(keyword);
                	displayAllDrinks(tempVec);
		}
		if(menu == "2"){
        		//Beers
			std::string temp1 = "beer";
			std::vector<Drink> tempVec2;
                        std::cout<< "BEER" << std::endl;
                        tempVec2 = searchDrinks(temp1);
                        displayAllDrinks(tempVec2);
		}
		if(menu == "3") {
       		 	//Wine
			std::vector<Drink> tempVec2;
                        std::cout<< "WINE" << std::endl;
                        tempVec2 = searchDrinks("wine");
                        displayAllDrinks(tempVec2);
		}
		if(menu == "4") {
       		 //
			std::vector<Drink> tempVec3;
                        std::cout<< "LIQUOR" << std::endl;
                        tempVec3 = searchDrinks("liquor");
                        displayAllDrinks(tempVec3);
		}
		if(menu == "0") {
        	//	Exit
			exit(0);
		}
	}
}
		//int tempInt = 0;
		/*std::cout<< "Choose your drink: "<< std::endl;
		std::getline(std::cin, keyword);
		std::vector<Drink> temp = searchDrinks(keyword);
		tempInt = calculateDrinks(60, 145, temp[0]);
		std::cout<< "To be safe, you should consume no more than " << tempInt << "total drinks in a moderate amount of time." <<  std::endl;
	}
}
*/
void fillDrinks(std::vector<Drink> &drinks)
{

        std::string line;
        std::string in = "drink.txt";
        std::ifstream inFile(in.c_str());
        while(std::getline(inFile, line))
        {
                std::vector<std::string> vect;
                std::stringstream stream(line);
                std::string words;
                while (std::getline(stream, words, ','))
                {
                        vect.push_back(words);
                }
                if(vect[0] == "beer")
                {
                        Drink x(vect[0], vect[1],stol(vect[3]), vect[2]);
                        drinks.push_back(x);
                }
                if(vect[0] == "wine")
                {
                        Drink x(vect[0], vect[1], stol(vect[2]), vect[3]);
                        drinks.push_back(x);
                }
                if(vect[0] == "liquor")
                {
                        Drink x(vect[0], vect[1], stol(vect[3]), vect[2]);
			drinks.push_back(x);
                }

        }
}
std::vector<Drink> searchDrinks(std::string keyValue) {
	std::vector<Drink> newVec;
	for(int i = 0; i < drinks.size(); i++) {
		if(drinks[i].getName().compare(keyValue)== 0) {
			newVec.push_back(drinks[i]);	
		}
		if(drinks[i].getType().compare(keyValue)==0) {
			newVec.push_back(drinks[i]);
		}
		if(drinks[i].getSpecificType().compare(keyValue)==0) {
			newVec.push_back(drinks[i]);
		}
	}
	return newVec;
}
void displayAllDrinks(std::vector<Drink> drink)
{
	int count = 0;
        for(int i = 0; i < drink.size(); i++)
        {
                        count++;
                        std::cout << count << ". " << drink[i].getName() << std::endl;
                        std::cout << "A.B.V.: " << drink[i].getPercentAlc() << std::endl;
                        std::cout << "Type: " << drink[i].getSpecificType() << std::endl;
           
        }
}

void displaySpecficDrinks(std::vector<Drink> &drinks, std::string type)
{
        int count = 0;
        for(int i = 0; i < drinks.size(); i++)
        {
                if(drinks[i].getType() == type)
                {
                        count++;
                        std::cout << count << ". " << drinks[i].getName() << std::endl;
                        std::cout << "A.B.V.: " << drinks[i].getPercentAlc() << std::endl;
                        std::cout << "Type: " << drinks[i].getSpecificType() << std::endl;
                }
        }
}

/*
int calculateDrinks(int cHeight, int cWeight, Drink d) {
	int level = 0;
	int tolerance = 0;
	float unitAlc = 0.0;
	int numDrinks = 0;
	if(cHeight > 60) {
		level = level + 2;
	}
	else 
		level = level + 1;
	if(cHeight > 64) {
		level++;
	}
	if(cHeight > 70) {
		level++;
	}
	if(cHeight > 72) {
		level++;;
	}
	if(cHeight > 75) {
		level = level + 2;
	}
	if(cWeight > 100) {
		level = level + 2;
	}
	else
		level = level + 1;
	if(cWeight > 120) {
		level++;
	}
	if(cWeight >=145) {
		level++;
	}
	if(cWeight >= 160) {
		level++;
	}
	if(cWeight >= 180) {
		level++;
	}
	if(cWeight >= 200) {
		level = level + 2;
	}
	tolerance = level *50;
	if(d.getType() == "liquor") {
		unitAlc = 1.5*(d.getPercentAlc());
	}
	if(d.getType() == "beer") {
		unitAlc = 12*(d.getPercentAlc());
	}
	if(d.getType() == "wine") {
		unitAlc = 8*(d.getPercentAlc());
	}
	while(tolerance > 0) {
		tolerance = tolerance - unitAlc;
		numDrinks++;
	}
	return numDrinks++;
}*/

