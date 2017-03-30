#pragma once
#include "House.h"
#include <iostream>   
#include <sstream>   

#define linesPerHouse  6

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
	bool removeHouse(unsigned int ID);
	const string toString();
	const string toStringFileData();
	void createHousesFromFileData(string* HouseList, unsigned int houseCount);
	

};