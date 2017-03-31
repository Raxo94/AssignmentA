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

void House::setAdress(string newAdress)
{
	this->adress = newAdress;
}

void House::setType(string newType)
{
	this->typeOfHouse = newType;
}

void House::setLivingArea(unsigned int newArea)
{
	this->livingArea = newArea;
}

void House::setRoomCount(unsigned int newRoomCount)
{
	this->roomCount = newRoomCount;
}

void House::setRent(unsigned int newRent)
{
	this->rent = newRent;
}

const string House::toString()
{
	stringstream stream;
	stream << "ID: " << IDNumber << ", Adress: " << adress << ", Type of house: " << typeOfHouse << ", Living Area: " << livingArea << ", Amount of rooms: " << roomCount << ", Rent: "<< rent;
	return stream.str();
}

const string House::toStringData()
{
	stringstream stream;
	stream << IDNumber << "\n" << adress << "\n" << typeOfHouse << "\n" << livingArea << "\n" << roomCount <<"\n"<< rent <<"\n";
	return stream.str();
}
