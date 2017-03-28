#include "HousingRegister.h"

HousingRegister::HousingRegister()
{
	houses = new House*[2];
}

HousingRegister::~HousingRegister()
{
	for (unsigned int i = 0; i<houseCount; i++)
		delete[] houses[i];
	delete[] houses;
}


void HousingRegister::addHouse()
{
	House * newPointer = new House;
	houses[houseCount] = newPointer;
	houseCount += 1;

	//this will work aslong as we dont actually make more than 2 houses

}

const string HousingRegister::toString()
{
	stringstream stream;

	for (unsigned int i = 0; i < houseCount; i++)
	{
		stream <<"House ID: " << houses[i]->getIDNumber() << " Rent: " << houses[i]->getRent() <<"Number of Rooms: " <<houses[i]->getRoomCount() << "\n";
	}
	
	return stream.str();
}



