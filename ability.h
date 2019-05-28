#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

class Ability{
private:
	string name;
	string type; //Passive, On-Hit, Touch, etc.

	int healHP;
	int bonus_stats[10];
	// ATK, MATK, DEF, MDEF, STR, DEX, INT, LUK, ACC, EVA

	uint turn_counter;
	uint turn_til_active;

public:
	Ability(){
		name = "None"; type = "None"; healHP = 0;
		for(int i = 0; i < 10; i++){ bonus_stats[i] = 0; }
	}

	string getName(){return name; }
	string getType(){return type; }
	uint getCount(){return turn_counter; }
	uint getTimeToActive(){return turn_til_active; }

	void activate(){
		if(turn_til_active != turn_counter){return; }

		turn_til_active = 0; 
		/* DO SOMETHING */
	}

	void passTurn(){ turn_til_active++; this->activate(); }


	void printInfo(){
		
	}

};


#endif