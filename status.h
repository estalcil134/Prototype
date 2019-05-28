#ifndef STATUS_H
#define STATUS_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

class Status{
private:
	string name;
	string type; //passive, on-hit, etc.

	int health;
	int bonus_stats[10];
	// ATK, MATK, DEF, MDEF, STR, DEX, INT, LUK, ACC, EVA

	uint status_life;
	bool isHeal;

public:
	Status(){
		name = "None"; type = "None"; health = 0;
		for(int i = 0; i < 10; i++){ bonus_stats[i] = 0; }
		isHeal = false;
	}
	Status(string n, string t, int h, int bstats[10], uint life, bool isH = false){
		name = n; type = t; health = h;
		bonus_stats[10] = *bstats;
		isHeal = isH;
	}

	~Status(){

	}

	int getStat(int i){
		if(i < 0 || i > 10){return 0; }
		return this->bonus_stats[i];
	}

	void printInfo(){
		string bstat_names[10] = {"Attack", "M.Attack", "Defense", "M.Defense", "Strength", "Dexterity", "Intelligence", "Luck", "Accuracy", "Evasion"};
		cout<<"Info of "<< this->name <<"\n";
		cout<<"Type: "<< this->type <<"\n";
		if(this->health > 0){
			if(this->isHeal){
				cout<<"HP Healed Per Turn: ";
			}
			else{
				cout<<"Damage Taken Per Turn: ";
			}
			cout<< this->health <<"\n";
		}
		else{cout<<"No effect to HP\n"; }
		for(int i = 0; i < 10; i++){
			cout<<"Bonus "<<left<<setw(11)<< bstat_names[i]<<": "<< this->bonus_stats[i] <<"\n";
		}
		cout<<"Turns Remaining: "<< this->status_life <<"\n";
	}

	void end(){
		if(status_life > 0){return; }

		delete this;
	}
	void passTurn(){ status_life--; this->end(); }

};

#endif