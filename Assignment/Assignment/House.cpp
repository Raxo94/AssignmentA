#include "House.h"


House::House()
{
}

House::House(unsigned int ID, unsigned int rent, unsigned int livingArea, unsigned int roomCount, string adress, string typeOfHouse)
{
	this->IDNumber = ID;
	this->rent = rent;
	this->livingArea = livingArea;
	this->roomCount = roomCount;

	this->adress = adress;
	this->typeOfHouse = typeOfHouse;
}

House::House( unsigned int rent, unsigned int livingArea, unsigned int roomCount, string adress, string typeOfHouse)
{
	this->IDNumber = 0;
	this->rent = rent;
	this->livingArea = livingArea;
	this->roomCount = roomCount;

	this->adress = adress;
	this->typeOfHouse = typeOfHouse;
}

const unsigned int House::getRent()
{
	return this->rent;
}

const unsigned int House::getRoomCount()
{
	return this->roomCount;
}

const unsigned int House::getIDNumber()
{
	return this->IDNumber;
}

void House::setIDNumber(unsigned int newID)
{
	this->IDNumber = newID;
}

const string House::toString()
{
	stringstream stream;
	stream << "ID: " << IDNumber << ", Type of house: " << typeOfHouse << ", Adress: " << adress << ", Living Area: " << livingArea << ", Amount of rooms: " << roomCount << ", Rent: "<< rent;
	return stream.str();
}

const string House::toStringData()
{
	stringstream stream;
	stream << IDNumber << "\n" << typeOfHouse << "\n" << adress << "\n" << livingArea << "\n" << roomCount <<"\n"<< rent <<"\n";
	return stream.str();
}
