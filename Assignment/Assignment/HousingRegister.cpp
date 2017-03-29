#include "HousingRegister.h"

void HousingRegister::expandHouses()
{
	if (houseCount <= 0)
	{
		House  **newArray = new House*[houseCount + 1];
		houses = newArray;
	}
	else
	{
		House  **newArray = new House*[houseCount + 1];
		memcpy(newArray, houses, (sizeof(House*) * houseCount) );
		delete[] houses;
		houses = newArray;
	}


}

unsigned int HousingRegister::generateUniqueID()
{
	unsigned int firstDigit;
	unsigned int secondDigit;
	unsigned int thirdDigit;
	unsigned int testID;

	unsigned int maxAmountOfHouses = 999;
	bool unique;

	do
	{
		unique = true;
		firstDigit = (rand() % 9) + 1;
		secondDigit = (rand() % 9) + 1;
		thirdDigit = (rand() % 9) + 1;
		testID = firstDigit + (secondDigit * 10) + (thirdDigit * 100); 
		
		for (unsigned int  i = 0; i < houseCount; i++)
		{
			if (testID == houses[i]->getIDNumber())
			{
				unique = false;
			}
		}

	} while (unique != true && houseCount<maxAmountOfHouses);

	return testID;

}

HousingRegister::HousingRegister()
{
	
}

HousingRegister::~HousingRegister()
{
	for (unsigned int i = 0; i<houseCount; i++)
		delete houses[i];
	delete[] houses;

}


void HousingRegister::addHouse(House* newHouse)
{
	newHouse->setIDNumber(generateUniqueID());
	expandHouses();
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



