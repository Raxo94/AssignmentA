#pragma once
#include <iostream>
#include <sstream>   

using namespace std;

class House
{
private:
	unsigned int IDNumber, rent, livingArea, roomCount;
	string adress, typeOfHouse;
public:
	House();
	House( const unsigned int rent,const unsigned int livingArea,const unsigned int roomCount,const string adress,const string typeOfHouse);
	House( const unsigned int ID, const unsigned int rent, const unsigned int livingArea, const unsigned int roomCount, const string adress, const string typeOfHouse);

	const unsigned int getRent();
	const unsigned int getRoomCount();
	const unsigned int getIDNumber();
	const string getType();

	void setIDNumber(const unsigned int newID);
	void setAdress(const string newAdress);
	void setType(const string newType);
	void setLivingArea(const unsigned int newArea);
	void setRoomCount(const unsigned int newRoomCount);
	void setRent(const unsigned int newRent);

	const string toString();
	const string toStringData();
};