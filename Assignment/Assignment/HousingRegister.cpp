#include "HousingRegister.h"

void HousingRegister::expandHouses()
{
	if (houseCount <= 0)
	{
		houseCount++;
		House  **newArray = new House*[houseCount];
		houses = newArray;
	}
	else
	{
		houseCount++;
		House  **newArray = new House*[houseCount];
		memcpy(newArray, houses, (sizeof(House*) * houseCount-1) );
		delete[] houses;
		houses = newArray;
	}


}

void HousingRegister::decrementHouses()
{
	if (houseCount > 0)
	{
		houseCount--;
		House  **newArray = new House*[houseCount];
		memcpy(newArray, houses, (sizeof(House*) * (houseCount) ) );
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

	unsigned int maxAmountOfHouses = 999; //this needs to be changed. Actually the amount of houses we can have to make it wrong is less
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
	if (newHouse->getIDNumber() == 0)
	{
		newHouse->setIDNumber(generateUniqueID());
	}
	expandHouses();
	houses[houseCount-1] = newHouse;
}

bool HousingRegister::removeHouse(unsigned int ID)
{
		unsigned int index = -1;
		for (unsigned int i = 0; i < houseCount; i++)
		{
			if (ID == houses[i]->getIDNumber())
			{
				index = i;
				delete houses[i];
			}
		}

		if (index != -1)
		{		
			unsigned int remaining = houseCount - index -1;
			
			for (unsigned int i = 0; i < (remaining); i++)
			{
				houses[index + i] = houses[index + i + 1];
			}
			decrementHouses();
			return true;
		}
		
		else 
			return false;
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

const string HousingRegister::toStringFileData()
{
	stringstream stream;

	for (unsigned int i = 0; i < houseCount; i++)
	{
		stream << houses[i]->toStringData();
	}

	return stream.str();
}

void HousingRegister::createHousesFromFileData(string * HouseList, unsigned int houseCount)
{
	unsigned int tempID, tempArea, tempRoomCount, tempRent;
	string tempAdress, tempType;

	//the order is ID adress type meters rooms rent
	for (unsigned int i = 0; i < houseCount; i++)
	{
		tempID = atoi(HouseList[i].c_str());
		tempType = HouseList[i + 1];
		tempAdress = HouseList[i + 2];
		tempArea = atoi(HouseList[i+3].c_str());
		tempRoomCount = atoi(HouseList[i+4].c_str());
		tempRent = atoi(HouseList[i + 5].c_str());

		
		addHouse(new House(tempID,tempRent, tempArea, tempRoomCount, tempAdress, tempType));
		cout << "\n";
	}
}



