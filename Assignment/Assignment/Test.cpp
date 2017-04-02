#include <time.h>  
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>   
#include "housingRegister.h"
#include "House.h"
#include "GlobalDefinitions.h"

using namespace std;


void printResult(HousingRegister& housingRegister)
{
	string* stringList = new string[housingRegister.getHouseCount()];
	unsigned int StringCount;
	housingRegister.toString(stringList, StringCount);
	for (unsigned int i = 0; i < StringCount; i++)
		cout << stringList[i] << "\n";

	if (StringCount == 0)
		cout << "Register is empty";
	
	delete[] stringList;
	cout << "\n\n";
}

int renameToMain()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//1.create register

	HousingRegister* housingRegister = new HousingRegister;

	//2.add two houses
	housingRegister->addHouse(new House(1,9999, 100, 4, "TestStreet", "FirstHouse"));
	housingRegister->addHouse(new House(2,2000, 50, 4, "TestStreet", "SecondHouse"));
	
	//3.add another one, expand array,print
	housingRegister->addHouse(new House(3,3000, 1, 4, "TestStreet", "ThirdHouse"));
	printResult(*housingRegister);

	//4.attempting to remove nonexistant member,printing result

	if (housingRegister->removeHouse(0) == false) { cout << "failed to remove house with specified ID\n"; }
	printResult(*housingRegister);

	//5. delete existing member print result
	
	housingRegister->removeHouse(1);
	printResult(*housingRegister);
	
	//6.remove the remaining houses
	
	housingRegister->removeHouse(2);
	housingRegister->removeHouse(3);
	printResult(*housingRegister);
	
	//8. (because there is no 7) append 2 new houses, print result
	
	housingRegister->addHouse(new House(1, 9999, 100, 4, "HelloStreet", "FourthHouse"));
	housingRegister->addHouse(new House(2, 2000, 50, 4, "GoodbyeStreet", "FithHouse"));

	printResult(*housingRegister);

	//9. Test CopyConstructor and assignment operator
	
	//assignment 

	HousingRegister* assignedHousingRegister = new HousingRegister;
	assignedHousingRegister->addHouse(new House(0, 0, 0, "THIS_IS_FROM_ASSIGNMENT", "test"));

	*housingRegister = *assignedHousingRegister;
	delete assignedHousingRegister;

	printResult(*housingRegister);

	//copy 

	HousingRegister* copy = new HousingRegister(*housingRegister);
	printResult(*copy);
	delete copy;


	//10. SaveToFile

	ofstream myfileO;
	myfileO.open("SAVEDFILES/example.txt");
	myfileO << housingRegister->toStringFileData();
	myfileO.close();

	//11. LoadFromFile

	ifstream myfileI;
	myfileI.open("SAVEDFILES/example.txt");

	unsigned int lines = count(istreambuf_iterator<char>(myfileI), istreambuf_iterator<char>(), '\n');
	unsigned int houseCount = lines / LINESPERHOUSE;
	string* houseList = new string[lines];
	myfileI.seekg(0, ios::beg);

	if (myfileI.is_open() && (lines % LINESPERHOUSE) == 0 && houseCount > 0)
	{
		unsigned int i = 0;
		string line;
		while (getline(myfileI, line))
		{
			houseList[i] = line;
			i++;
		}

		myfileI.close();
		housingRegister->createHousesFromFileData(houseList, houseCount);
	}

	delete[] houseList;
	printResult(*housingRegister);

	delete housingRegister;
	getchar();
	return 0;
}