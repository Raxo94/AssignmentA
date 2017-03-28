#include "House.h"

House::House(unsigned int IDNumber, unsigned int rent, unsigned int roomCount)
{
	this->IDNumber = IDNumber;
	this->rent = rent;
	this->roomCount = roomCount;
}

House::House()
{
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
