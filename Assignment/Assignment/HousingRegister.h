#pragma once
#include "House.h"
#include <iostream>   
#include <sstream>   

using namespace std;

class HousingRegister
{
private:
	House ** houses = nullptr;
	unsigned int houseCount = 0;

public:
	HousingRegister();
	~HousingRegister();

	void addHouse();
	const string toString();

};