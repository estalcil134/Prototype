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
public:
	Ability(){
		name = "None"; type = "None"; healHP = 0;
	}



	string getName(){return name; }
	string getType(){return type; }

};