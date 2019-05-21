#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>


using namespace std;

class Monster;

class PartyMember{
private:
	string name;
	string job;
	uint lvl;

	uint currEXP;
	uint neededEXP;

	uint currHP;
	uint maxHP;
	uint stats[6];

	uint acc;
	uint eva;



public:
	PartyMember() : stats{0} {
		name = "N/A"; job = "N/A"; lvl = 0;
		currEXP = 0; neededEXP = 0;
		currHP = 0; maxHP = 0;
		//stats = uint[6]{0}; //str, dex, int, luk, def, mdef
		acc = 0; eva = 0;
	}
	PartyMember(string _name, string _job) : stats{4} {
		name = _name;
		job = _job; 

		lvl = 1;
		currEXP = 0; neededEXP = 25;
		currHP = 15; maxHP = 15;
		//stats = uint[6]{0};
		acc = 10; eva = 10;
	}

	string getName(){ return this->name; }
	string getClass(){ return this->job; }

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
	void die(Monster attacker);
	void take_damage(Monster& attacker, uint dmg);
	void attack(Monster& target);


	bool bonus(string enhance){
		if(enhance == "maxhp"){
			currHP += 10; maxHP += 10; 
			cout<<"Max HP increased.\n";
			return true;
		}
		else if(enhance == "str"){
			stats[0] += 3; 
			cout<<"Strength increased.\n";
			return true;
		}
		else if(enhance == "dex"){
			stats[1] += 3; 
			cout<<"Dexterity increased.\n";
			return true;
		}
		else if(enhance == "int"){
			stats[2] += 3; 
			cout<<"Intelligence increased.\n";
			return true;
		}
		else if(enhance == "luk"){
			stats[3] += 3; 
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
		stats[0]++; stats[1]++;
		stats[2]++; stats[3]++;
		stats[4] += 2; stats[5] += 2;
		acc += 3; eva += 3;

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



	void printInfo(){
		cout<<"Party Member Info\n";
		cout<<"Name:     "<< this->name <<"\n";
		cout<<"Class:    "<< this->job <<"\n";
		cout<<"Level:    "<< this->lvl <<"\n";
		cout<<"EXP:      "<<left<<setw(9)<< this->currEXP << " / " <<setw(9)<< this->neededEXP <<"\n";
		cout<<"Health:   "<<left<<setw(5)<< this->currHP << " / " <<setw(5)<< this->maxHP <<"\n";
		cout<<"Main Stats\n";
		cout<<"     STR: "<< this->stats[0] <<"\n";
		cout<<"     DEX: "<< this->stats[1] <<"\n";
		cout<<"     INT: "<< this->stats[2] <<"\n";
		cout<<"     LUK: "<< this->stats[3] <<"\n";
		cout<<"     DEF: "<< this->stats[4] <<"\n";
		cout<<"    MDEF: "<< this->stats[5] <<"\n";
		cout<<"Accuracy: "<< this->acc <<"\n";
		cout<<"Evasion:  "<< this->eva <<"\n";
	}
};


class Party{
private:
	vector<PartyMember> members; //members[0] is the leader
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
};