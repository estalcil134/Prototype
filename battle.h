#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>

#include "partymember.h"
#include "monster.h"

using namespace std;

void PartyMember::die(Monster& attacker){
	if(this->currHP > 0){return; }

	cout<< this->name <<" has been slain by "<< attacker.getName() <<"!\n";
}
int PartyMember::take_damage(Monster& attacker, uint dmg, string dmg_type){
	cout<<"\n"<< this->name <<" was attacked by " << attacker.getName() <<"!\n";
	uint dmg_dealt = dmg;
	/* WIP: damage calculation */

	this->currHP -= dmg_dealt;
	if(this->currHP < 0){this->currHP = 0; }
	cout<< this->name <<" took " << dmg_dealt <<" damage.\n";
	this->die(attacker);
	return dmg_dealt;
}


void PartyMember::attack(Monster& target){
	uint dmg = 100;
	/* WIP: damage calculation */
	target.take_damage(*this, dmg, "Physical");
}


void PartyMember::useSkill(Skill used_skill, Monster& target){
	int dmg_dealt = 1;
	uint plus = 0; 
	if(this->getJob() == "Warrior"){ dmg_dealt = this->getStat(4); plus = this->getStat(5); }
	else if(this->getJob() == "Bowman"){ dmg_dealt = this->getStat(5); }
	else if(this->getJob() == "Magician"){ dmg_dealt = this->getStat(6); plus = this->getStat(7); }
	else if(this->getJob() == "Thief"){ dmg_dealt = this->getStat(7); plus = this->getStat(5); }
	else if(this->getJob() == "Gunner"){ dmg_dealt = this->getStat(5); plus = this->getStat(4); }
	else if(this->getJob() == "Muse"){ dmg_dealt = this->getStat(6); plus = this->getStat(5); }
	
	cout<<"current dmg total: "<<dmg_dealt<<"\n";
	dmg_dealt /= 4;
	cout<<"current dmg total: "<<dmg_dealt<<"\n";
	string dmg_type1 = used_skill.getDmg1();
	if(dmg_type1 == "Physical"){
		dmg_dealt *= this->getStat(0);
	}
	else if(dmg_type1 == "Magical"){
		dmg_dealt *= this->getStat(1);
	}

	cout<<"current dmg total: "<<dmg_dealt<<"\n";
	dmg_dealt *= used_skill.getPower();
	cout<<"current dmg total: "<<dmg_dealt<<"\n";
	dmg_dealt += plus;
	cout<<"current dmg total: "<<dmg_dealt<<"\n";
	dmg_dealt /= 10;
	cout<<"current dmg total: "<<dmg_dealt<<"\n";

	int fluctuate = ((rand() % 9) - 4);
	cout<<"fluctuation: "<<fluctuate<<"%\n";
	float variance = float(dmg_dealt) * (float(fluctuate) / float(100));
	cout<<"variance: "<<variance<<" dmg\n";

	dmg_dealt += variance;
	cout<<"current dmg total: "<<dmg_dealt<<"\n";
	if(dmg_dealt < 0){dmg_dealt = 0; }
	target.take_damage(*this, dmg_dealt, dmg_type1);
	
}
void PartyMember::useSkill(Skill used_skill, PartyMember& target){

}

void PartyMember::useSkill(uint skill_num, Monster& target){
	this->useSkill(this->getSkill(skill_num), target);
}
void PartyMember::useSkill(uint skill_num, PartyMember& target){
	this->useSkill(this->getSkill(skill_num), target);
}

//=============================================================================

void Monster::die(PartyMember& slayer){
	if(this->currHP > 0){return; }

	uint givenEXP = this->expCalc();
	cout<< this->name <<" was slain!\n";
	cout<< slayer.getName() <<" gets "<< givenEXP <<" EXP.\n";
	slayer.gainEXP(givenEXP);
}
int Monster::take_damage(PartyMember& slayer, uint dmg, string dmg_type){
	cout<<"\n"<< this->name <<" was attacked by " << slayer.getName() <<"!\n";
	uint dmg_dealt = dmg;
	/* WIP: damage calculation */

	this->currHP -= dmg_dealt;
	if(this->currHP < 0){this->currHP = 0; }
	cout<< this->name <<" took " << dmg_dealt <<" damage.\n";
	this->die(slayer);
	return dmg_dealt;
}

void Monster::attack(PartyMember& target){
	uint dmg = 100;
	/* WIP: damage calulation */
	target.take_damage(*this, dmg, "Physical");
}

//==========================================================================

class Battle{
private:
	uint turn_counter;


public:
	Battle(Party& player_side, MonsterParty& opposition){
		turn_counter = 0;
	}

	void fight(){
		cout<<"Fight started\n";
		while(true){
			this->turn_counter++;
			cout<<"Turn "<< this->turn_counter <<"\n";

			break;
		}
	}
	

};

#endif