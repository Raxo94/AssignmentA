#include "housingRegister.h"

void HousingRegister::expandHouses()
{
		houseListSize++;
		House  **newArray = new House*[houseListSize];
		memcpy(newArray, houses, (sizeof(House*) * houseCount) );
		delete[] houses;
		houses = newArray;
}

void HousingRegister::decrementHouses()
{
		houseListSize--;
		House  **newArray = new House*[houseListSize];
		memcpy(newArray, houses, (sizeof(House*) * (houseCount) ) );
		delete[] houses;
		houses = newArray;
}

const unsigned int HousingRegister::generateUniqueID()
{
	unsigned int firstDigit;
	unsigned int secondDigit;
	unsigned int thirdDigit;

	unsigned int testID;

	unsigned int maxAmountOfHouses = 500;
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
	houses = new House*[INITIALARRAYSIZE];
	houseListSize = INITIALARRAYSIZE;
	houseCount = 0;
}

HousingRegister::HousingRegister(const HousingRegister & other)
{
	//since we are creting a new house register we dont need to delete anything
	this->houses = new House*[other.houseListSize]; 
	
	for (unsigned int i = 0; i < other.houseCount; i++)
	{

		//deepcopy
		this->houses[i] = new House;
		*this->houses[i] = *other.houses[i];

	}
	this->houseCount = other.houseCount;
	this->houseListSize = other.houseListSize;
	
}


HousingRegister& HousingRegister::operator=(const HousingRegister & other)
{
	if (this != &other) //if the instanses are not pointing to the same memory adress
	{
		//step 1: delete old allocated data
		for (unsigned int i = 0; i < this->houseCount; i++)
		{
			delete this->houses[i];
		}
		delete[] this->houses; //is this possible not a value

		//step2: copy the new data
		this->houses = new House*[other.houseListSize]; 
		
		for (unsigned int i = 0; i < other.houseCount; i++)
		{

			//deepcopy
			this->houses[i] = new House;
			*this->houses[i] = *other.houses[i];

		}
		this->houseCount = other.houseCount;
		this->houseListSize = other.houseListSize;
	}

	return *this;
}

HousingRegister::~HousingRegister()
{
	for (unsigned int i = 0; i<houseCount; i++) //dont delete for the whole list. Only for houses
		delete houses[i];
	delete[] houses;

}

const unsigned int HousingRegister::getHouseCount()
{
	return this->houseCount;
}


void HousingRegister::addHouse(House* newHouse)
{
	if (newHouse->getIDNumber() == 0)
	{
		newHouse->setIDNumber(generateUniqueID());
	}
	
	if (houseCount >= INITIALARRAYSIZE)
		expandHouses();

	houses[houseCount] = newHouse;
	houseCount++;
}

const bool HousingRegister::removeHouse(const unsigned int ID)
{
	unsigned int index = findID(ID);
	
	if (index != -1)
	{
		delete houses[index];
		unsigned int remaining = houseCount - index -1;
		for (unsigned int i = 0; i < (remaining); i++)
		{
			houses[index + i] = houses[index + i + 1];
		}
		if (houseCount > INITIALARRAYSIZE)
		{
			houseCount--;
			decrementHouses();
		}
		else
		{
			houseCount--;
		}
			
		return true;
	}
		
	else 
		return false;
}

const bool HousingRegister::editHouse(const unsigned int ID, House* editedHouse)
{
	unsigned int index = findID(ID);

	if (index != -1)
	{
		delete houses[index]; //delete old. 
		houses[index] = editedHouse; //replace with new
		houses[index]->setIDNumber(ID);
	}
	return false;
}

void HousingRegister::toString(string* &listOfHouseStrings,unsigned int &stringCount) 
{
	for (unsigned int i = 0; i < houseCount; i++)
	{
		listOfHouseStrings[i] = houses[i]->toString();
	}
	stringCount = houseCount;

}

void HousingRegister::toString(string* &listOfHouseStrings, unsigned int &stringCount, int cullingRent, const int OnlyShowWithThisRoomCount, const string type) //presents specific houses
{
	stringCount = 0;
	for (unsigned int i = 0; i < houseCount; i++)
	{
		if (houses[i]->getRent() < cullingRent)
		{

			if (OnlyShowWithThisRoomCount < 0 || OnlyShowWithThisRoomCount == houses[i]->getRoomCount())
			{
				if (type == houses[i]->getType() || type == "")
				{
					listOfHouseStrings[stringCount] = houses[i]->toString();
					stringCount++;
				}
			}
		}
		
	}

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

void HousingRegister::createHousesFromFileData(const string* HouseList, const unsigned int newHousesCount)
{
	unsigned int tempID, tempArea, tempRoomCount, tempRent;
	string tempAdress, tempType;

	//the order is ID adress type meters rooms rent
	for (unsigned int i = 0; i < (newHousesCount * LINESPERHOUSE); i+=LINESPERHOUSE)
	{
		tempID = atoi(HouseList[i].c_str());
		tempAdress = HouseList[i + 1];
		tempType = HouseList[i + 2];
		tempArea = atoi(HouseList[i+3].c_str());
		tempRoomCount = atoi(HouseList[i+4].c_str());
		tempRent = atoi(HouseList[i + 5].c_str());

		
		addHouse(new House(tempRent, tempArea, tempRoomCount, tempAdress, tempType));
	}
}

const int HousingRegister::findID(const unsigned int ID)
{
	int index = -1;
	for (unsigned int i = 0; i < houseCount; i++)
	{
		if (ID == houses[i]->getIDNumber())
		{
			index = i;
		}
	}
	return index;
}


