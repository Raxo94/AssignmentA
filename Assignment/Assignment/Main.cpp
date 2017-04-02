#include <time.h>  
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>   
#include "housingRegister.h"
#include "House.h"
#include "GlobalDefinitions.h"

using namespace std;

enum Choices
{
ZERO,
ADD_HOUSE,
EDIT_HOUSE,
REMOVE_HOUSE,
PRESENT_HOUSES,
PH_SPECIFY_LOWER_RENT,
PH_SPECIFY_TYPE_ROOM,
SAVE_TO_FILE, 
LOAD_FROM_FILE,
EXIT,
COPY_CONSTRUCTOR,
ASSIGNMENT_OPERATOR
};


#pragma region functionDeclaration
void addHouse(HousingRegister& housingRegister);
House* createNewHouse(HousingRegister& housingRegister);
void editHouse(HousingRegister& housingRegister);
void RemoveHouse(HousingRegister& housingRegister);

const unsigned int SpecifyID();
void presentHouseRegister(HousingRegister* housingRegister, const unsigned int choice);
void writeHouseRegisterToFile(HousingRegister& housingRegister);
void readHouseRegisterFromFile(HousingRegister & housingRegister);
const bool isNumeric();
#pragma endregion




int main()
{ 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL));
	
	
	HousingRegister* originalHousingRegister = new HousingRegister;
	HousingRegister* assignedHousingRegister = new HousingRegister; //used for testing assigment operator
	HousingRegister* copiedHousingRegister = nullptr;				//used for testing copyConstructor;
	HousingRegister* housingRegister = originalHousingRegister;		//will point to different registers
	assignedHousingRegister->addHouse(new House( 9999, 100, 4, "AssignmentTest", "InitialHouse"));
	



	unsigned int houseCount; //used when reading file
	unsigned int choice; //used to get menu input from user
	
	
	
	do //program loop
	{
		cout << "Press the corresponding number input to Select an alternative \n";
		cout << "--- \n";
		cout << "1:Add house \n";
		cout << "2:Edit House with specified ID \n";
		cout << "3:Remove House with specified ID \n";
		cout << "4:Present all Houses \n";
		cout << "5:Present all Houses with lower than specified rent \n";
		cout << "6:Present all Houses with specified type and room amount \n";
		cout << "7:Save register to file \n";
		cout << "8:Load register from file \n";
		cout << "10: Test CopyConstructor\n";
		cout << "11: Test Assignment_Operator\n\n";
	
		cout << "9:Exit Program \n\n";

		cout << "input: ";
		cin >> choice;

		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');

		switch (choice)
		{

		case(ADD_HOUSE) :
			addHouse(*housingRegister);
			break;

		case(EDIT_HOUSE) :
			editHouse(*housingRegister);
			break;

		case(REMOVE_HOUSE) :
			RemoveHouse(*housingRegister);
			break;

		case(PRESENT_HOUSES) :
			presentHouseRegister(housingRegister, choice);
			break;

		case(PH_SPECIFY_LOWER_RENT) :
			presentHouseRegister(housingRegister, choice);
			break;

		case(PH_SPECIFY_TYPE_ROOM) :
			presentHouseRegister(housingRegister, choice);
			break;

		case(SAVE_TO_FILE) :
			writeHouseRegisterToFile(*housingRegister);
			break;

		case(LOAD_FROM_FILE) :
			readHouseRegisterFromFile(*housingRegister);
			break;

		case(COPY_CONSTRUCTOR) :
			copiedHousingRegister = new HousingRegister(*housingRegister); //copy from the current register;
			delete housingRegister;										  //delete the current register to test if a deepcopy has been made
			housingRegister = copiedHousingRegister;					 //Replace the current with the copied
			originalHousingRegister = nullptr;							// the first time we copy we delete the originalhouseRegister. Now we need to make sure not to delete it again.
			break;

		case(ASSIGNMENT_OPERATOR):
			*housingRegister = *assignedHousingRegister;						// assign the assignedHouse register to currently used register.
			break;

		}

		cout << "\n \n \n"; 
	
	} while (choice != EXIT);


	//Exiting program
	delete originalHousingRegister;
	delete assignedHousingRegister;
	delete copiedHousingRegister;


	return 0;
}



//Functions
void addHouse(HousingRegister& housingRegister)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	housingRegister.addHouse(createNewHouse(housingRegister));

	SetConsoleTextAttribute(hConsole, GREEN);
	cout << "house has been added";
	SetConsoleTextAttribute(hConsole, STANDARDCOLOR);
	getchar();
}

House* createNewHouse(HousingRegister& housingRegister)
{
	unsigned int tempArea, tempRoomCount, tempRent;
	string tempAdress, tempType;
	 

	cout << "Give the house an adress: ";
	cin >> tempAdress;
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');

	cout << "What type of house is it: ";
	cin >> tempType;
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');

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




void editHouse(HousingRegister & housingRegister)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned int specifiedID = SpecifyID();
	if (housingRegister.findID(specifiedID) != -1)
	{
		housingRegister.editHouse(specifiedID, createNewHouse(housingRegister));
		SetConsoleTextAttribute(hConsole, GREEN);
		cout << "House with ID " << specifiedID << " Has been Edited";
	}
	else
	{
		SetConsoleTextAttribute(hConsole, RED);
		cout << "Failed to find House with the ID " << specifiedID;
	}
	SetConsoleTextAttribute(hConsole, STANDARDCOLOR);
	getchar();
}

void RemoveHouse(HousingRegister & housingRegister)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned int specifiedID = SpecifyID();
	if (housingRegister.removeHouse(specifiedID))
	{
		SetConsoleTextAttribute(hConsole, GREEN);
		cout << "House with ID " << specifiedID << " Has been removed";
	}
	else
	{
		SetConsoleTextAttribute(hConsole, RED);
		cout << "Failed to remove House with ID " << specifiedID;
	}
	SetConsoleTextAttribute(hConsole, STANDARDCOLOR);
	getchar();
}

const unsigned int SpecifyID()
{
	unsigned int ID;
	do
	{
		cout << "Enter ID of the house: ";
		cin >> ID;

	} while (!isNumeric());
	return ID;

}


void presentHouseRegister(HousingRegister* housingRegister,const unsigned int choice)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //used to change color of text
	unsigned int maxStringCount = housingRegister->getHouseCount();
	unsigned int actualStringCount;
	if (maxStringCount > 0)
	{
		string* stringList = new string[maxStringCount]; //alocate
		
		if (choice == PRESENT_HOUSES)
		{
			housingRegister->toString(stringList,actualStringCount);
		}
		else if (choice == PH_SPECIFY_LOWER_RENT)
		{
			unsigned int chosenRent = 0;
			do
			{
				cout << "show houses with rent below: ";
				cin >>chosenRent;

			} while (!isNumeric());
			housingRegister->toString(stringList, actualStringCount, chosenRent, -1, "");
		}
		else if (choice == PH_SPECIFY_TYPE_ROOM)
		{
			unsigned int chosenRoomCount = 0;
			string chosenType = "";

			cout << "show houses with the type: ";
			cin >> chosenType;

			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');

			do
			{
				cout << "show houses with a room count of: ";
				cin >> chosenRoomCount;

			} while (!isNumeric());

			housingRegister->toString(stringList, actualStringCount, INFINITE, chosenRoomCount, chosenType);
		}
		SetConsoleTextAttribute(hConsole, YELLOW);
		for (size_t i = 0; i < actualStringCount; i++)
		{
			cout << "\n" << stringList[i];
		}
		delete[] stringList; //delete
	}
	else
	{
		SetConsoleTextAttribute(hConsole, RED);
		cout << "No houses in register";
	}
	SetConsoleTextAttribute(hConsole, STANDARDCOLOR);
	getchar();
}


void writeHouseRegisterToFile(HousingRegister& housingRegister)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //used to change color of text
	ofstream myfile;
	string userFileNameInput;
	stringstream filepath;
	
	cout << "Specify Filename to write (without path or file-extension): ";
	cin >> userFileNameInput;
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');

	filepath << "SAVEDFILES/";
	filepath << userFileNameInput;
	filepath << ".txt";
	myfile.open(filepath.str());
	myfile << housingRegister.toStringFileData();
	myfile.close();

	SetConsoleTextAttribute(hConsole, GREEN); 
	cout << "Your file has been saved \n";
	SetConsoleTextAttribute(hConsole, STANDARDCOLOR); 
	getchar();

}

void readHouseRegisterFromFile(HousingRegister & housingRegister)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //used to change color of text
	string* houseList = nullptr; //used to get HouseData when reading from file

	unsigned int houseCount = 0;
	ifstream myfile;
	string userFileNameInput;
	stringstream filepath;
	string line;

	cout << "Specify Filename to read (without path or file-extension): ";
	cin >> userFileNameInput;
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');

	filepath << "SAVEDFILES/";
	filepath << userFileNameInput;
	filepath << ".txt";
	myfile.open(filepath.str());

	unsigned int lines = count(istreambuf_iterator<char>(myfile),istreambuf_iterator<char>(), '\n'); 
	houseCount = lines / LINESPERHOUSE;
	houseList = new string[lines];
	myfile.seekg(0, ios::beg);

	if (myfile.is_open() && (lines % LINESPERHOUSE) == 0 && houseCount > 0)
	{
		unsigned int i = 0;
		while (getline(myfile, line))
		{
			houseList[i] = line;
			i++;
		}

		myfile.close();
		SetConsoleTextAttribute(hConsole, GREEN); 
		cout << "File read sucessfully";
		SetConsoleTextAttribute(hConsole, STANDARDCOLOR); 
		housingRegister.createHousesFromFileData(houseList, houseCount);
		
	}
	else
	{
		myfile.close();
		SetConsoleTextAttribute(hConsole, RED);
		cout << "failure to read file";
		SetConsoleTextAttribute(hConsole, STANDARDCOLOR);
	}
	getchar();
	delete[] houseList;
}

const bool isNumeric()
{
	if (cin.fail())
	{
		// user didn't input a number
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		return false;
	}
	else
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		return true;
}