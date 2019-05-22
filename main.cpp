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
	
	Equipment head  = Equipment("Crown of Poseidon", "Headgear", 20, 8, 7, 6, 5, 4, 3, 2, 1, 0);
	Equipment ubody = Equipment("Adamant Platemail", "Upper Body", 13, 8, 7, 6, 5, 4, 3, 2, 1, 0);
	Equipment lbody = Equipment("UNIQLO Jeans", "Lower Body", 25, 8, 7, 6, 5, 4, 3, 2, 1, 0);
	Equipment shoes = Equipment("Hermes Treads", "Shoes", 64, 8, 7, 6, 5, 4, 3, 2, 1, 0);
	Equipment mweap = Equipment("Excalibur", "Main Hand", 99, 8, 7, 6, 5, 4, 3, 2, 1, 0);
	Equipment sweap = Equipment("Bishop's Cross", "Sub Hand", 66, 8, 7, 6, 5, 4, 3, 2, 1, 0);
	
	Equipment start_head  = Equipment("Ragged Hood", "Headgear", 1, 0, 0, 0, 0, 0, 0, 0, 1, 0);
	Equipment start_ubody = Equipment("Tattered Shirt", "Upper Body", 1, 5, 0, 0, 0, 0, 0, 1, 0, 0);
	Equipment start_lbody = Equipment("Breezy Old Leggings", "Lower Body", 1, 5, 0, 0, 0, 1, 0, 1, 0, 0);
	Equipment start_shoes = Equipment("Old Sandals", "Shoes", 1, 0, 0, 0, 0, 1, 0, 0, 2, 2);
	Equipment start_mweap = Equipment("Toy Sword", "Main Hand", 1, 0, 4, 0, 1, 0, 0, 0, 0, 0);
	Equipment start_sweap = Equipment("Pot Lid", "Sub Hand", 1, 0, 0, 0, 0, 0, 0, 0, 0, 3);

	vector<Equipment> inventory;
	inventory.push_back(head); inventory.push_back(ubody);
	inventory.push_back(lbody); inventory.push_back(shoes);
	inventory.push_back(mweap); inventory.push_back(sweap);
	
	for(uint i = 0; i < 6; i++){
		cout<<"Trying to equip "<< inventory[i].getName() <<"\n";
		typeNull.equip(inventory[i]);
		//inventory[i].printMore(); newline();
	} 
	newline();
	typeNull.printInfo(); newline();

	vector<Equipment> start_inventory;
	start_inventory.push_back(start_head); start_inventory.push_back(start_ubody);
	start_inventory.push_back(start_lbody); start_inventory.push_back(start_shoes);
	start_inventory.push_back(start_mweap); start_inventory.push_back(start_sweap);
	for(uint i = 0; i < 6; i++){
		cout<<"Trying to equip "<< start_inventory[i].getName() <<"\n";
		typeNull.equip(start_inventory[i]);
		//inventory[i].printMore(); newline();
	}
	newline();
	typeNull.printInfo(); newline();
	
	/*
	inventory.push_back(hat);
	inventory.push_back(weap);
	cout<< inventory[0].getName() <<"\n> "<< inventory[0].getSlot() <<"\n";
	cout<< inventory[1].getName() <<"\n> "<< inventory[1].getSlot() <<"\n";
	*/
	return 0;
}