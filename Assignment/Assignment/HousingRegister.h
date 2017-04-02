#pragma once
#include <iostream>   
#include <sstream>   
#include "House.h"
#include "GlobalDefinitions.h"

using namespace std;

class HousingRegister
{
private:
	House ** houses = nullptr;
	unsigned int houseListSize, houseCount;
	
	void expandHouses();
	void decrementHouses();
	const unsigned int generateUniqueID();

public:
	HousingRegister();
	HousingRegister(const HousingRegister& other); //Copy Constructor
	HousingRegister& operator=(const HousingRegister & other); //Assignment operator
	~HousingRegister(); //Destructor


	const unsigned int getHouseCount();
	const int findID(const unsigned int ID); //Returns index of ÍD in house Array. returns -1 if it id does not exist

	void addHouse(House* newHouse);
	const bool removeHouse(const unsigned int ID);
	const bool editHouse(const unsigned int ID, House* editedHouse);

	void toString(string* &listOfHouseStrings, unsigned int &stringCount); //Strings all houses
	void HousingRegister::toString(string* &listOfHouseStrings, unsigned int &stringCount, const int cullingRent, const int OnlyShowWithThisRoomCount,const string type); //Will only string the houses with matching parameters
	const string toStringFileData(); //returns string used for writing to file

	void createHousesFromFileData(const string* HouseList,const unsigned int newHousesCount); 

	
	

};


