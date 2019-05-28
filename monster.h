#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>


using namespace std;

class PartyMember;

class Monster{
private:
	string name;
	string type;

	uint lvl;
	int currHP;
	uint maxHP;

	uint stats[4]; //atk, matk, def, mdef

	uint acc;
	uint eva;

public:
	Monster() : stats{0} {
		name = "N/A"; type = "N/A";
		lvl = 0;
		currHP = 0; maxHP = 0;
		acc = 0; eva = 0;
	}
	Monster(string _name, string _type) : stats{4,4,4,4} {
		name = _name; 
		type = _type;
		lvl = 1;
		currHP = 10; maxHP = 10;
		acc = 10; eva = 1;
	}

	string getName(){return this->name; }

	uint expCalc(){
		uint exp = this->lvl * 200;
		/* WIP: exp calculation*/

		return exp;
	}


	// void die(PartyMember slayer){
	// 	if(this->currHP > 0){return; }

	// 	uint givenEXP = this->expCalc();
	// 	cout<< this->name <<" was slain!\n";
	// 	cout<< slayer.getName() <<" gets "<< givenEXP <<" EXP.\n";
	// 	slayer.gainEXP(givenEXP);
	// }
	// void take_damage(PartyMember slayer, uint dmg){
	// 	cout<<"\n"<< this->name <<" was attacked by " << slayer.getName() <<"!\n";
	// 	uint dmg_dealt = dmg;
	// 	/* WIP: damage calculation */

	// 	cout<< this->name <<" took " << dmg_dealt <<" damage.\n";
	// 	this->die(slayer);
	// }

	// void attack(PartyMember target){
	// 	uint dmg = 0;
	// 	/* WIP: damage calulation */
	// 	target.take_damage(this, dmg);
	// }
	void die(PartyMember& slayer);
	int take_damage(PartyMember& slayer, uint dmg, string dmg_type);
	void attack(PartyMember& target);

	void printInfo(){
		cout<<"Monster Info\n";
		cout<<"Name:     "<< this->name <<"\n";
		cout<<"Type:     "<< this->type <<"\n";
		cout<<"Level:    "<< this->lvl <<"\n";
		cout<<"Health:   "<<left<<setw(5)<< this->currHP <<" / "<<setw(5)<< this->maxHP <<"\n";
		cout<<"Main Stats\n";
		cout<<"     ATK: "<< this->stats[0] <<"\n";
		cout<<"    MATK: "<< this->stats[1] <<"\n";
		cout<<"     DEF: "<< this->stats[2] <<"\n";
		cout<<"    MDEF: "<< this->stats[3] <<"\n";
		cout<<"Accuracy: "<< this->acc <<"\n";
		cout<<"Evasion:  "<< this->eva <<"\n";
	}

};

class MonsterParty{
private:
	vector<Monster> members;
public:
	MonsterParty(Monster leader){
		members.push_back(leader);
	}
	/*
	bool contains(Monster member){
		for(uint i = 0; i < this->members.size(); i++){
			if(this->members[i].equals(member)){
				return true;
			}
		}
		return false;
	}
	*/
	MonsterParty(vector<Monster> new_party){
		members = new_party;
	}

	/*
	bool add(Monster new_member){
		if(this->contains(new_member)){
			return false;
		}
		else{
			this->members.push_back(new_member);
			return true;
		}
	}
	*/
	uint size(){return members.size(); }

	void printParty(){
		//prints out an overview of the party members
		cout<<"Party Members\n";
	}
	void printPartyBattle(int member1 = 0, int member2 = -1, int member3 = -1){
		//prints out the active members in battle
		string display_names = "";
		string display_HP = "";


		cout<<" \n";
	}
};

#endif