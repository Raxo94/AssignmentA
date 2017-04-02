#include "House.h"


House::House()
{
}


House::House( const unsigned int rent, const unsigned int livingArea, const unsigned int roomCount, const string adress, const string typeOfHouse)
{
	this->IDNumber = 0;
	this->rent = rent;
	this->livingArea = livingArea;
	this->roomCount = roomCount;

	this->adress = adress;
	this->typeOfHouse = typeOfHouse;
}

House::House(const unsigned int ID, const unsigned int rent, const unsigned int livingArea, const unsigned int roomCount, const string adress, const string typeOfHouse)
{
	this->IDNumber = ID;
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

const string House::getType()
{
	return this->typeOfHouse;
}

void House::setIDNumber(const unsigned int newID)
{
	this->IDNumber = newID;
}

void House::setAdress(const string newAdress)
{
	this->adress = newAdress;
}

void House::setType(const string newType)
{
	this->typeOfHouse = newType;
}

void House::setLivingArea(const unsigned int newArea)
{
	this->livingArea = newArea;
}

void House::setRoomCount(const unsigned int newRoomCount)
{
	this->roomCount = newRoomCount;
}

void House::setRent(const unsigned int newRent)
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
