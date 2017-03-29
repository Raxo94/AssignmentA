#pragma once
#include "House.h"
#include <iostream>   
#include <sstream>   

using namespace std;

class HousingRegister
{
private:
	House ** houses = nullptr;
	unsigned int houseCount = 0;
	void expandHouses();
	void decrementHouses();
	unsigned int generateUniqueID();

public:
	HousingRegister();
	~HousingRegister();

	void addHouse(House* newHouse);
	void removeHouse(unsigned int ID);
	const string toString();

};