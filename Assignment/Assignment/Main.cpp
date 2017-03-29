#include <time.h>  
#include <iostream>
#include "HousingRegister.h"
#include "House.h"
using namespace std;

enum Choices{ZERO,ADDHOUSE,REMOVEHOUSE,PRESENTHOUSES,EXIT};
House* CreateNewHouse();
bool isNumeric();

int main()
{ 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL));

	HousingRegister housingRegister;

	unsigned int choice;
	do
	{
		cout << "Press the corresponding number input to Select an alternative \n";
		cout << "--- \n";
		cout << "1:Add house \n";
		cout << "2:Remove House \n";
		cout << "3:Present all Housings \n";
		//cout << "4:Present Housings with rent \n";
		
		cout << "4:Exit Program \n";
		cin >> choice;

		std::cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (choice)
		{

			case(ADDHOUSE): 
				housingRegister.addHouse(CreateNewHouse()); 
				break;
			
			case(REMOVEHOUSE):
				//housingRegister.addHouse(CreateNewHouse()); 
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
	unsigned int tempArea, tempRoomCount, tempRent;
	string tempAdress, tempType;

	cout << "Give the house an adress: ";
	cin >> tempAdress;

	cout << "What type of house is it: ";
	cin >> tempType;

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