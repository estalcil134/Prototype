#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>

//#include "partymember.h"
//#include "monster.h"
#include "battle.h"

using namespace std;


int main(int argc, char const *argv[]){
	
	PartyMember typeNull = PartyMember("Type Null", "None");
	typeNull.printInfo();

	//Party poke = Party(typeNull);
	//cout<<"Party made! Size: "<< poke.size() <<"\n";

	typeNull.printInfo();

	Monster silvally = Monster("Silvally", "Unburdened Monster");
	silvally.printInfo();

	typeNull.attack(silvally);

	return 0;
}