#pragma once

class House
{
private:
	unsigned int rent = 0, roomCount = 0, IDNumber = 0;
public:
	House();
	House(unsigned int IDNumber, unsigned int rent, unsigned int roomCount);
	const unsigned int getRent();
	const unsigned int getRoomCount();
	const unsigned int getIDNumber();
};