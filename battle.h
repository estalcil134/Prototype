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

void PartyMember::die(Monster attacker){
	if(this->currHP > 0){return; }

	cout<< this->name <<" has been slain by "<< attacker.getName() <<"!\n";
}
void PartyMember::take_damage(Monster attacker, uint dmg){
	cout<<"\n"<< this->name <<" was attacked by " << attacker.getName() <<"!\n";
	uint dmg_dealt = dmg;
	/* WIP: damage calculation */

	cout<< this->name <<" took " << dmg_dealt <<" damage.\n";
	this->die(attacker);
}

void PartyMember::attack(Monster target){
	uint dmg = 100;
	/* WIP: damage calculation */
	target.take_damage(this, dmg);
}

//=============================================================================

void Monster::die(PartyMember slayer){
	if(this->currHP > 0){return; }

	uint givenEXP = this->expCalc();
	cout<< this->name <<" was slain!\n";
	cout<< slayer.getName() <<" gets "<< givenEXP <<" EXP.\n";
	slayer.gainEXP(givenEXP);
}
void Monster::take_damage(PartyMember slayer, uint dmg){
	cout<<"\n"<< this->name <<" was attacked by " << slayer.getName() <<"!\n";
	uint dmg_dealt = dmg;
	/* WIP: damage calculation */

	cout<< this->name <<" took " << dmg_dealt <<" damage.\n";
	this->die(slayer);
}

void Monster::attack(PartyMember target){
	uint dmg = 0;
	/* WIP: damage calulation */
	target.take_damage(this, dmg);
}