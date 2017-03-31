#pragma once
#include <iostream>   
#include <sstream>   
#include "House.h"
#include "GlobalDefinitions.h"

#define INITIALARRAYSIZE  2

using namespace std;

class HousingRegister
{
private:
	House ** houses = nullptr;
	unsigned int houseListSize = 0, houseCount = 0;
	void expandHouses();
	void decrementHouses();

	unsigned int generateUniqueID();

public:
	HousingRegister();
	~HousingRegister();

	unsigned int getHouseCount();

	void addHouse(House* newHouse);
	bool removeHouse(unsigned int ID);
	bool editHouse(unsigned int ID, House* editedHouse);
	void toString(string* &listOfHouseStrings, unsigned int &stringCount); //fills parameter stringArray with string for each house in register
	void HousingRegister::toString(string* &listOfHouseStrings, unsigned int &stringCount, int cullingRent, int OnlyShowWithThisRoomCount, string type); //this will only string the houses with matching parameters
	const string toStringFileData();
	void createHousesFromFileData(string* HouseList, unsigned int newHousesCount);
	void printSize(); 
	int findID(unsigned int ID); //Returns index of ÍD in house Array. returns -1 if it id does not exist
	

};