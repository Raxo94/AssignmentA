#include "HousingRegister.h"

HousingRegister::HousingRegister()
{
	houses = new Housing*[2];
}

HousingRegister::~HousingRegister()
{
	for (unsigned int i = 0; i<houseCount; i++)
		delete[] houses[i];
	delete[] houses;
}


void HousingRegister::addHousing()
{
	Housing * newPointer = new Housing;
	houses[houseCount] = newPointer;
	houseCount += 1;

	//this will work aslong as we dont actually make more than 2 houses

}



