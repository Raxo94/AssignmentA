#pragma once
#include "Housing.h"
#include <iostream>   
#include <sstream>   

using namespace std;

class HousingRegister
{
private:
	Housing ** houses = nullptr;
	unsigned int houseCount = 0;

public:
	HousingRegister();
	~HousingRegister();

	void addHousing();
	const stringstream toString();

};