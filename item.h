#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>

#include "status.h"

using namespace std;

class Item{
private:
	string name;
	string type; //food, potion, etc.

	int healHP;
	int healMP;

	vector<Status> inflict_ailments;
	vector<Status> heal_ailments;

public:
	Item(){
		name = "N/A"; type = "N/A"; 
		healHP = 0; healMP = 0;
	}
	~Item(){

	}

	void printInfo(){
		
	}
};

#endif