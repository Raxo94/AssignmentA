#include <time.h>  
#include <iostream>
#include <fstream>
#include <sstream>   
#include "HousingRegister.h"
#include "House.h"
using namespace std;

enum Choices{ZERO,ADDHOUSE,REMOVEHOUSE,PRESENTHOUSES, SAVETOFILE, LOADFROMFILE,EXIT};

#pragma region functionDeclaration
House* CreateNewHouse();
const unsigned int removeHouseUsingID();
void writeHouseRegisterToFile(string houseRegisterData);
bool readHouseRegisterFromFile(string* &houseList, unsigned int &houseCount);
bool isNumeric();
#pragma endregion




int main()
{ 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL));

	HousingRegister housingRegister;
	string currentHouseData; //used to get house data when writing to file
	string* houseList = nullptr; //used to get HouseData when reading from file
	unsigned int houseCount; //used when reading file
	unsigned int choice; //used to get menu input from user
	unsigned int removeID; //User input for which house to remove
	do
	{
		cout << "Press the corresponding number input to Select an alternative \n";
		cout << "--- \n";
		cout << "1:Add house \n";
		cout << "2:Remove House with ID \n";
		cout << "3:Present all Housings \n";
		cout << "4:Save register to file \n";
		cout << "5:Load register from file \n";
		
		cout << "6:Exit Program \n";
		cin >> choice;

		std::cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (choice)
		{

			case(ADDHOUSE): 
				housingRegister.addHouse(CreateNewHouse()); 
				break;
			
			case(REMOVEHOUSE):
				removeID = removeHouseUsingID();
				if( housingRegister.removeHouse(removeID) )
				{
					cout << "House with ID "<<  removeID << " Has been removed \n";
				}
				else
				{
					cout << "Failed to remove House with ID " << removeID << "\n";
				}
				break;

			case(PRESENTHOUSES): 
				cout << housingRegister.toString();
				getchar();
				break;

			case(SAVETOFILE):
				currentHouseData = housingRegister.toStringFileData();
				writeHouseRegisterToFile(currentHouseData);
				break;
			case(LOADFROMFILE):
				if(readHouseRegisterFromFile(houseList, houseCount))
					housingRegister.createHousesFromFileData(houseList, houseCount);
				break;

		}

		cout << "\n \n \n"; // Time for next user input
	} while (choice != EXIT);

	return 0;
}




House* CreateNewHouse()
{
	unsigned int tempArea, tempRoomCount, tempRent;
	string tempAdress, tempType;

	cout << "Give the house an adress: ";
	cin >> tempAdress;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "What type of house is it: ";
	cin >> tempType;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	do
	{
	cout << "How many square meters is the living area: ";
	cin >> tempArea;
	} while (!isNumeric());
	
	do
	{
	cout << "How many rooms are there: ";
	cin >> tempRoomCount;
	} while (!isNumeric());
	
	do
	{
	cout << "How much is the rent: ";
	cin >> tempRent;
	} while (!isNumeric());

	return new House(tempRent, tempArea, tempRoomCount, tempAdress, tempType);

}

const unsigned int removeHouseUsingID()
{
	unsigned int removeID;
	do
	{
		cout << "Enter ID of house to remove: ";
		cin >> removeID;

	} while (!isNumeric());
	return removeID;

}

void writeHouseRegisterToFile(string houseRegisterData)
{
	ofstream myfile;
	string userFileNameInput;
	stringstream filepath;
	
	cout << "Specify Filename to write (without path or file-extension): ";
	cin >> userFileNameInput;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	filepath << "SAVEDFILES/";
	filepath << userFileNameInput;
	filepath << ".txt";
	myfile.open(filepath.str());
	myfile << houseRegisterData;
	myfile.close();
	cout << "Your file has been saved \n";
	getchar();

}

bool readHouseRegisterFromFile(string* &houseList,unsigned int &houseCount)
{
	houseCount = 0;
	ifstream myfile;
	string userFileNameInput;
	stringstream filepath;
	string line;

	cout << "Specify Filename to read (without path or file-extension): ";
	cin >> userFileNameInput;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	filepath << "SAVEDFILES/";
	filepath << userFileNameInput;
	filepath << ".txt";
	myfile.open(filepath.str());

	unsigned int lines = std::count(std::istreambuf_iterator<char>(myfile),std::istreambuf_iterator<char>(), '\n'); 
	houseCount = lines / 6;
	houseList = new string[lines];
	myfile.seekg(0, ios::beg);

	if (myfile.is_open())
	{
		unsigned int i = 0;
		while (getline(myfile, line))
		{
			houseList[i] = line;
			i++;
		}

		if ((i % 6) != 0)
		{
			myfile.close();
		}
		else
		{
			myfile.close();
			cout << "File read sucessfully";
			return true;
		}
		
	}
	cout << "failure to read file";
	return false;
}

bool isNumeric()
{
	if (cin.fail())
	{
		// user didn't input a number
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	else
		return true;
}