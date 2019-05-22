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
void PartyMember::take_damage(Monster& attacker, uint dmg, string dmg_type){
	cout<<"\n"<< this->name <<" was attacked by " << attacker.getName() <<"!\n";
	uint dmg_dealt = dmg;
	/* WIP: damage calculation */

	this->currHP -= dmg_dealt;
	if(this->currHP < 0){this->currHP = 0; }
	cout<< this->name <<" took " << dmg_dealt <<" damage.\n";
	this->die(attacker);
}


void PartyMember::attack(Monster& target){
	uint dmg = 100;
	/* WIP: damage calculation */
	target.take_damage(*this, dmg, "Physical");
}

//=============================================================================

void Monster::die(PartyMember& slayer){
	if(this->currHP > 0){return; }

	uint givenEXP = this->expCalc();
	cout<< this->name <<" was slain!\n";
	cout<< slayer.getName() <<" gets "<< givenEXP <<" EXP.\n";
	slayer.gainEXP(givenEXP);
}
void Monster::take_damage(PartyMember& slayer, uint dmg, string dmg_type){
	cout<<"\n"<< this->name <<" was attacked by " << slayer.getName() <<"!\n";
	uint dmg_dealt = dmg;
	/* WIP: damage calculation */

	this->currHP -= dmg_dealt;
	if(this->currHP < 0){this->currHP = 0; }
	cout<< this->name <<" took " << dmg_dealt <<" damage.\n";
	this->die(slayer);
}

void Monster::attack(PartyMember& target){
	uint dmg = 100;
	/* WIP: damage calulation */
	target.take_damage(*this, dmg, "Physical");
}

//==========================================================================

void battle(Party main_party, MonsterParty opposition){
	uint turn_counter = 0;
	while(true){
		turn_counter++;
		cout<<"Turn "<< turn_counter <<"\n";
		/* WIP: Battling System */

		break;
	}
}