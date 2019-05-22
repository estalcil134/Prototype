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

void newline(){cout<<"\n";}

int main(int argc, char const *argv[]){
	
	PartyMember typeNull = PartyMember("Type Null", "None");
	typeNull.printInfo();
	newline();
	//Party poke = Party(typeNull);
	//cout<<"Party made! Size: "<< poke.size() <<"\n";
	//typeNull.gainEXP(200);
	//typeNull.printInfo();
	/*
	Monster silvally = Monster("Silvally", "Unburdened Monster");
	silvally.printInfo();
	newline();
	*/
	//typeNull.attack(silvally);

	//typeNull.printInfo();
	
	Equipment head = Headgear("Crown of Poseidon", 8, 7, 6, 5, 4, 3, 2, 1, 0);
	Equipment ubody = UpperBody("Adamant Platemail", 8, 7, 6, 5, 4, 3, 2, 1, 0);
	Equipment lbody = LowerBody("Breezy Old Leggings", 8, 7, 6, 5, 4, 3, 2, 1, 0);
	Equipment shoes = Shoes("Hermes Treads", 8, 7, 6, 5, 4, 3, 2, 1, 0);
	Equipment mweap = Weapon("Excalibur", 8, 7, 6, 5, 4, 3, 2, 1, 0);
	Equipment sweap = Weapon("Paladin's Shield", 8, 7, 6, 5, 4, 3, 2, 1, 0, true);
	vector<Equipment> inventory;
	inventory.push_back(head); inventory.push_back(ubody);
	inventory.push_back(lbody); inventory.push_back(shoes);
	inventory.push_back(mweap); inventory.push_back(sweap);
	
	for(uint i = 0; i < 6; i++){
		typeNull.equip(inventory[i]);
		//inventory[i].printMore(); newline();
	}
	head.printMore();
	cout<< head.getStat(0) <<"\n";
	typeNull.printInfo();
	
	/*
	inventory.push_back(hat);
	inventory.push_back(weap);
	cout<< inventory[0].getName() <<"\n> "<< inventory[0].getSlot() <<"\n";
	cout<< inventory[1].getName() <<"\n> "<< inventory[1].getSlot() <<"\n";
	*/
	return 0;
}