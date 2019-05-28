#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

class Skill{
private:
	string name;
	string type; //offensive, defensive
	string dmg_type1; //physical, magical, true
	string dmg_type2; //normal, phasing, piercing

	string resource;
	int cost;

	int basePower;
	bool isHeal;


public:
	Skill(){
		name = "N/A"; type = "None";
		dmg_type1 = "None"; dmg_type2 = "None";
		resource = "Mana"; cost = 0;
		basePower = 0; isHeal = false;
	}
	Skill(string n, string t, string dt1, string dt2, string rsrse, int c, int bp, bool isH = false){
		name = n; type = t;
		dmg_type1 = dt1; dmg_type2 = dt2;
		resource = rsrse; cost = c;
		basePower = bp; isHeal = isH;
	}

	string getName(){return name; }
	string getType(){return type; }
	string getDmg1(){return dmg_type1; }
	string getDmg2(){return dmg_type2; }
	string getResource(){return resource; }
	int getCost(){return cost; }
	int getPower(){return basePower; }
	bool isHealing(){return this->isHeal; }


};

#endif