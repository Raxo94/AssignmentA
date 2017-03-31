#pragma once
#include <iostream>
#include <sstream>   

using namespace std;

class House
{
private:
	unsigned int IDNumber = 0, rent = 0, livingArea =0, roomCount = 0;
	string adress = "", typeOfHouse = "";
public:
	House();
	House( unsigned int ID, unsigned int rent, unsigned int livingArea, unsigned int roomCount, string adress, string typeOfHouse);
	House( unsigned int rent, unsigned int livingArea, unsigned int roomCount,string adress, string typeOfHouse);
	const unsigned int getRent();
	const unsigned int getRoomCount();
	const unsigned int getIDNumber();

	void setIDNumber(unsigned int newID);
	void setAdress(string newAdress);
	void setType(string newType);
	void setLivingArea(unsigned int newArea);
	void setRoomCount(unsigned int newRoomCount);
	void setRent(unsigned int newRent);

	const string toString();
	const string toStringData();
};