#include <iostream>
#include "HousingRegister.h"
using namespace std;

enum Choices{ZERO,ADDHOUSE,PRESENTHOUSES,EXIT};

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

		switch (choice)
		{
			case(ADDHOUSE): 
				housingRegister.addHousing();
				break;

			case(PRESENTHOUSES): 
				cout << "You are Amazing \n";
				break;
		}

		std::cin.clear();
		fflush(stdin);
		

		cout << "\n \n \n"; // Time for next user input
	} while (choice != EXIT);

	return 0;
}