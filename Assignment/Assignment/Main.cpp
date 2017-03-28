#include <iostream>
#include "HousingRegister.h"
#include "House.h"
using namespace std;

enum Choices{ZERO,ADDHOUSE,PRESENTHOUSES,EXIT};
House* CreateNewHouse();

int main()
{ 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	HousingRegister housingRegister;

	unsigned int choice;
	do
	{
		cout << "Press the corresponding number input to Select an alternative \n";
		cout << "--- \n";
		cout << "1:Add housing \n";
		cout << "2:Present all Housings \n";
		//cout << "3:Present Housings with rent \n";
		
		cout << "3:Exit Program \n";
		cin >> choice;

		std::cin.clear();
		fflush(stdin);

		switch (choice)
		{
			case(ADDHOUSE): 
				housingRegister.addHouse(CreateNewHouse());
				break;

			case(PRESENTHOUSES): 
				cout << housingRegister.toString();
				getchar();
				break;
		}

		cout << "\n \n \n"; // Time for next user input
	} while (choice != EXIT);

	return 0;
}

House* CreateNewHouse()
{
	unsigned int tempID, tempArea, tempRoomCount, tempRent;
	string tempAdress, tempType;

	cout << "Give the new house a unique ID number: ";
	cin >> tempID;
	//if unique
	cout << "Give the house an adress: ";
	cin >> tempAdress;

	cout << "What type of house is it: ";
	cin >> tempType;

	cout << "How many square meters is the living area: ";
	cin >> tempArea;

	cout << "How many rooms are there: ";
	cin >> tempRoomCount;

	cout << "How much is the rent: ";
	cin >> tempRent;

	return new House(tempID, tempRent, tempArea, tempRoomCount, tempAdress, tempType);


}