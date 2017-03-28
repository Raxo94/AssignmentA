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
	House(unsigned int IDNumber, unsigned int rent, unsigned int livingArea, unsigned int roomCount,string adress, string typeOfHouse);
	const unsigned int getRent();
	const unsigned int getRoomCount();
	const unsigned int getIDNumber();
	const string toString();
};