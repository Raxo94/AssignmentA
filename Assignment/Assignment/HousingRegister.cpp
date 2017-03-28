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


void HousingRegister::addHouse(House* newHouse)
{
	
	houses[houseCount] = newHouse;
	houseCount += 1;

	//this will work aslong as we dont actually make more than 2 houses

}

const string HousingRegister::toString()
{
	stringstream stream;

	for (unsigned int i = 0; i < houseCount; i++)
	{
		stream << houses[i]->toString() << "\n";
	}
	
	return stream.str();
}



