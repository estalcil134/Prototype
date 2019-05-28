#ifndef PARTYMEMBER_H
#define PARTYMEMBER_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>

#include "equipment.h"
#include "ability.h"
#include "status.h"
#include "item.h"
#include "skill.h"

using namespace std;

class Monster;

class PartyMember{
private:
	string name;
	string job;
	string branch;
	uint lvl;

	uint currEXP;
	uint neededEXP;

	int currHP;
	uint maxHP;
	uint shield;
	uint stats[10];
	//atk, matk, def, mdef
	//str, dex, int, luk
	//acc, eva

	Equipment equipped[6];
	//head, top, bottom, shoes, main hand, sub hand

	vector<Ability> abilities;
	vector<Status> current_statuses;

	vector<Skill> usable_skills;

	bool isAlive; 

	bool actionTaken;
	//this is for battling purposes

public:
	PartyMember() : stats{0,0,0,0,0,0,0,0,0,0} {
		name = "N/A"; job = "N/A"; branch = "N/A"; lvl = 0;
		currEXP = 0; neededEXP = 0;
		currHP = 0; maxHP = 0; shield = 0; 
		
		for(int i = 0; i < 10; i++){
			Equipment tmp = Equipment();
			equipped[i] = tmp;
		}
		isAlive = true;
		actionTaken = false;
	}
	PartyMember(string _name, string _job) : stats{1,1,1,1,4,4,4,4,10,1} {
		name = _name;
		job = _job; branch = "N/A";

		lvl = 1;
		currEXP = 0; neededEXP = 25;
		currHP = 15; maxHP = 15; shield = 0;
		//stats = uint[6]{0};
		//acc = 10; eva = 1;
		for(int i = 0; i < 6; i++){
			Equipment tmp = Equipment();
			equipped[i] = tmp;
		}
		isAlive = true;
		actionTaken = false;
	}

	string getName(){ return this->name; }
	string getJob(){ return this->job; }

	uint getStat(int i){
		if(i < 0 || i > 10){return 0;}
		else{return this->stats[i]; }
	}

	Skill getSkill(uint num){
		return this->usable_skills[num];
	}

	bool equals(PartyMember other){
		/* WIP */
		return true;
	}

	// void die(Monster attacker){
	// 	if(this->currHP > 0){return; }

	// 	cout<< this->name <<" has been slain by "<< attacker.getName() <<"!\n";
	// }
	// void take_damage(Monster attacker, uint dmg){
	// 	cout<<"\n"<< this->name <<" was attacked by " << attacker.getName() <<"!\n";
	// 	uint dmg_dealt = dmg;
	// 	/* WIP: damage calculation */

	// 	cout<< this->name <<" took " << dmg_dealt <<" damage.\n";
	// 	this->die(attacker);
	// }

	// void attack(Monster target){
	// 	uint dmg = 100;
	// 	/* WIP: damage calculation */
	// 	target.take_damage(this, dmg);
	// }

	void gainAbility(Ability new_ability){
		cout<< this->name <<" gained a new Ability: "<< new_ability.getName() <<"!\n";
		this->abilities.push_back(new_ability);
	}
	void displayAbilities(){

	}
	int numAbilities(){return abilities.size(); }

	void learnSkill(Skill new_skill){
		cout<< this->name <<" learned a new Skill: "<< new_skill.getName() <<"!\n";
		this->usable_skills.push_back(new_skill);
	}

	void displaySkills(){

	}
	
	void useSkill(Skill used_skill, Monster& target);
	void useSkill(Skill used_skill, PartyMember& target);
	void useSkill(uint skill_num, Monster& target);
	void useSkill(uint skill_num, PartyMember& target);

	void die(Monster& attacker);
	int take_damage(Monster& attacker, uint dmg, string dmg_type);
	void attack(Monster& target);

	void recover(int healpoints){
		if(uint(this->currHP + healpoints) > this->maxHP){
			this->currHP = this->maxHP;
		}
		else{
			this->currHP += healpoints; 
		}
	}

	void use(Item& thing){
		/* WIP: Usage */

		//delete thing;
	}


	bool bonus(string enhance){
		if(enhance == "maxhp"){
			currHP += 10; maxHP += 10; 
			cout<<"Max HP increased.\n";
			return true;
		}
		else if(enhance == "str"){
			stats[4] += 3; 
			cout<<"Strength increased.\n";
			return true;
		}
		else if(enhance == "dex"){
			stats[5] += 3; 
			cout<<"Dexterity increased.\n";
			return true;
		}
		else if(enhance == "int"){
			stats[6] += 3; 
			cout<<"Intelligence increased.\n";
			return true;
		}
		else if(enhance == "luk"){
			stats[7] += 3; 
			cout<<"Luck increased.\n";
			return true;
		}
		else{
			cout<<"Invalid stat, please choose again\n";
			return false;
		}
	}
	void level_up(){
		if(currEXP < neededEXP){return; }

		cout<< this->name <<" leveled up!\n";
		lvl++;
		currHP += 5; maxHP += 5;
		for(int i = 2; i < 9; i++){
			stats[i]++;
			//increment defs, stats, and acc/eva
		}
		// stats[2]++; stats[3]++;
		// stats[4]++; stats[5]++;
		// stats[6]++; stats[7]++;
		// stats[8]++; stats[9]++;


		currEXP -= neededEXP;
		neededEXP += 100;

		string enhance;
		cout<<"What stat would you like to enhance?\n";
		cout<<"Choose one of the following(maxhp, str, dex, int, luk): ";
		while(true){
			cin >> enhance;
			if(bonus(enhance)){break; }
		}
		cout<<"\n";
		
		this->level_up();
	}
	void gainEXP(uint exp){
		cout<<"\n"<< this->name <<" gained " << exp <<" EXP!\n";
		this->currEXP += exp;
		this->level_up();
	}

	Equipment equip(Equipment gear){
		Equipment tmp = Equipment();
		if(gear.getLevel() > this->lvl){return tmp; }
		if(gear.getClass() != this->job || gear.getClass() != "None"){return tmp; }

		if(gear.getSlot() == "Headgear"){ 
			tmp = equipped[0];
			equipped[0] = gear; 
		}
		else if(gear.getSlot() == "Upper Body"){ 
			tmp = equipped[1];
			equipped[1] = gear; 
		}
		else if(gear.getSlot() == "Lower Body"){ 
			tmp = equipped[2];
			equipped[2] = gear; 
		}
		else if(gear.getSlot() == "Shoes"){ 
			tmp = equipped[3];
			equipped[3] = gear; 
		}
		else if(gear.getSlot() == "Main Hand"){ 
			tmp = equipped[4];
			equipped[4] = gear; 
		}
		else if(gear.getSlot() == "Sub Hand"){ 
			tmp = equipped[5];
			equipped[5] = gear; 
		}
		
		return tmp;
	}
	
	



	void printInfo(){
		int bHP = 0; int batk = 0; int bmatk = 0;
		int bstr = 0; int bdex = 0; int bint = 0; 
		int bluk = 0; int bacc = 0; int beva = 0;
		for(uint i = 0; i < 6;i++){
			bHP += equipped[i].getHP();
			batk += equipped[i].getStat(0);
			bmatk += equipped[i].getStat(1);
			bstr += equipped[i].getStat(2);
			bdex += equipped[i].getStat(3);
			bint += equipped[i].getStat(4);
			bluk += equipped[i].getStat(5);
			bacc += equipped[i].getStat(6);
			beva += equipped[i].getStat(7);
		}

		cout<<"Party Member Info\n";
		cout<<"Name:     "<< this->name <<"\n";
		cout<<"Job:      "<< this->job <<"\n";
		cout<<"Level:    "<< this->lvl <<"\n";
		cout<<"EXP:      "<<left<<setw(9)<< this->currEXP << " / " <<setw(9)<< this->neededEXP <<"\n";
		cout<<"Health:   "<<left<<setw(5)<< this->currHP + bHP << " / " <<setw(5)<< this->maxHP + bHP <<"\n";
		cout<<"Main Stats\n";
		cout<<"     STR: "<< this->stats[4] + bstr <<"\n";
		cout<<"     DEX: "<< this->stats[5] + bdex <<"\n";
		cout<<"     INT: "<< this->stats[6] + bint <<"\n";
		cout<<"     LUK: "<< this->stats[7] + bluk <<"\n";
		cout<<"     DEF: "<< this->stats[2] <<"\n";
		cout<<"    MDEF: "<< this->stats[3] <<"\n";
		cout<<"Accuracy: "<< this->stats[8] + bacc <<"\n";
		cout<<"Evasion:  "<< this->stats[9] + beva <<"\n";
		cout<<"Currently Equipped:\n";
		cout<<"Head Gear:  "<< this->equipped[0].getName() <<"\n";
		cout<<"Upper Body: "<< this->equipped[1].getName() <<"\n";
		cout<<"Lower Body: "<< this->equipped[2].getName() <<"\n";
		cout<<"Shoes:      "<< this->equipped[3].getName() <<"\n";
		cout<<"Main Hand:  "<< this->equipped[4].getName() <<"\n";
		cout<<"Sub Hand:   "<< this->equipped[5].getName() <<"\n";
	}
};


class Party{
private:
	vector<PartyMember> members; //members[0] is the leader
	vector<Item> inventory;
public:
	Party(PartyMember leader){
		members.push_back(leader);
	}

	bool contains(PartyMember member){
		for(uint i = 0; i < this->members.size(); i++){
			if(this->members[i].equals(member)){
				return true;
			}
		}
		return false;
	}

	Party(vector<PartyMember> new_party){
		members = new_party;
	}


	bool add(PartyMember new_member){
		if(this->contains(new_member)){
			return false;
		}
		else{
			this->members.push_back(new_member);
			return true;
		}
	}

	uint size(){return members.size(); }

	void printParty(){
		//prints out an overview of the party members
		cout<<"Party Members\n";
	}
	void printPartyBattle(int member1 = 0, int member2 = -1, int member3 = -1){
		//prints out the active members in battle
		cout<<" \n";
	}
};

#endif