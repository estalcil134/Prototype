#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

class Equipment{
private:
	string name;
	int req_lvl;
	string slot;
	string type;
public:
	Equipment(){
		name = "None"; req_lvl = 0; slot = "None"; type = "None";
	}
	Equipment(string _name){
		name = _name; req_lvl = 0; slot = "None"; type = "None";
	}

	string getName(){return name; }
	int getLevel(){return req_lvl; }
	string getSlot(){return slot; }
	string getType(){return type; } 


	void setName(string _name){name = _name; }
	void setSlot(string _slot){slot = _slot; }
	void setType(string _type){type = _type; }

	void print(){
		cout<<"Equipment Info\n";
		cout<<"Name:           "<< this->name <<"\n";
		cout<<"Required Level: "<< this->req_lvl <<"\n";
		cout<<"Equipment Slot: "<< this->slot <<"\n";
	}
	
	int getHP(){return 0; }
	int getStat(uint choose){return 0; }
	int getAcc(){return 0; }
	int getEva(){return 0; }
	void printMore(){cout<<"should not be printed\n"; }

};

class Headgear : public Equipment{
private:
	int bonus_HP;
	int bonus_stats[6];
	//atk, matk, str, dex, int, luk
	int bonus_acc;
	int bonus_eva;
public:
	Headgear() : bonus_stats{0,0,0,0,0,0} {
		this->setSlot("Headgear");
	}
	Headgear(string _name): bonus_stats{0,0,0,0,0,0}{
		this->setSlot("Headgear");
		this->setName(_name);
	}
	
	Headgear(string _name, int bHP, int atk, int matk,
		int str, int dex, int int_, int luk, 
		int b_acc, int b_eva) : 
		bonus_stats{ atk, matk, str, dex, int_, luk } {
			this->setSlot("Headgear");
			this->setName(_name);
			bonus_HP = bHP;
			bonus_acc = b_acc;
			bonus_eva = b_eva;
	}

	int getHP(){return bonus_HP; }
	int getStat(uint choose){
		if(choose == 0){return bonus_stats[0]; }
		else if(choose == 1){return bonus_stats[1]; }
		else if(choose == 2){return bonus_stats[2]; }
		else if(choose == 3){return bonus_stats[3]; }
		else if(choose == 4){return bonus_stats[4]; }
		else if(choose == 5){return bonus_stats[5]; }
		else{return 0; }
	}
	int getAcc(){return bonus_acc; }
	int getEva(){return bonus_eva; }

	void printMore(){
		cout<<"Equipment Info\n";
		cout<<"Name:           "<< this->getName() <<"\n";
		cout<<"Required Level: "<< this->getLevel() <<"\n";
		cout<<"Equipment Slot: "<< this->getSlot() <<"\n";
		cout<<"Bonus Stats\n";
		cout<<left<<"Bonus HP:   "<<setw(3)<< bonus_HP <<"\n";
		cout<<left<<"Bonus ATK:  "<<setw(3)<< bonus_stats[0] <<"\n";
		cout<<left<<"Bonus MATK: "<<setw(3)<< bonus_stats[1] <<"\n";
		cout<<left<<"Bonus STR:  "<<setw(3)<< bonus_stats[2] <<"\n";
		cout<<left<<"Bonus DEX:  "<<setw(3)<< bonus_stats[3] <<"\n";
		cout<<left<<"Bonus INT:  "<<setw(3)<< bonus_stats[4] <<"\n";
		cout<<left<<"Bonus LUK:  "<<setw(3)<< bonus_stats[5] <<"\n";
		cout<<left<<"Bonus ACC:  "<<setw(3)<< bonus_acc <<"\n";
		cout<<left<<"Bonus EVA:  "<<setw(3)<< bonus_eva <<"\n";
	}
};

class UpperBody : public Equipment{
private:
	int bonus_HP;
	int bonus_stats[6];
	//atk, matk, str, dex, int, luk
	int bonus_acc;
	int bonus_eva;
public:
	UpperBody() : bonus_stats{0,0,0,0,0,0} {
		this->setSlot("Upper Body");
	}
	UpperBody(string _name) : bonus_stats{0,0,0,0,0,0} {
		this->setSlot("Upper Body");
		this->setName(_name);
	}

	UpperBody(string _name, int bHP, int atk, int matk,
		int str, int dex, int int_, int luk, 
		int b_acc, int b_eva) : 
		bonus_stats{ atk, matk, str, dex, int_, luk } {
			this->setSlot("Upper Body");
			this->setName(_name);
			bonus_HP = bHP;
			bonus_acc = b_acc;
			bonus_eva = b_eva;
	}

	int getHP(){return bonus_HP; }
	int getStat(uint choose){
		if(choose == 0){return bonus_stats[0]; }
		else if(choose == 1){return bonus_stats[1]; }
		else if(choose == 2){return bonus_stats[2]; }
		else if(choose == 3){return bonus_stats[3]; }
		else if(choose == 4){return bonus_stats[4]; }
		else if(choose == 5){return bonus_stats[5]; }
		else{return 0; }
	}
	int getAcc(){return bonus_acc; }
	int getEva(){return bonus_eva; }

	void printMore(){
		cout<<"Equipment Info\n";
		cout<<"Name:           "<< this->getName() <<"\n";
		cout<<"Required Level: "<< this->getLevel() <<"\n";
		cout<<"Equipment Slot: "<< this->getSlot() <<"\n";
		cout<<"Bonus Stats\n";
		cout<<left<<"Bonus HP:   "<<setw(3)<< bonus_HP <<"\n";
		cout<<left<<"Bonus ATK:  "<<setw(3)<< bonus_stats[0] <<"\n";
		cout<<left<<"Bonus MATK: "<<setw(3)<< bonus_stats[1] <<"\n";
		cout<<left<<"Bonus STR:  "<<setw(3)<< bonus_stats[2] <<"\n";
		cout<<left<<"Bonus DEX:  "<<setw(3)<< bonus_stats[3] <<"\n";
		cout<<left<<"Bonus INT:  "<<setw(3)<< bonus_stats[4] <<"\n";
		cout<<left<<"Bonus LUK:  "<<setw(3)<< bonus_stats[5] <<"\n";
		cout<<left<<"Bonus ACC:  "<<setw(3)<< bonus_acc <<"\n";
		cout<<left<<"Bonus EVA:  "<<setw(3)<< bonus_eva <<"\n";
	}
};

class LowerBody : public Equipment{
private:
	int bonus_HP;
	int bonus_stats[6];
	//atk, matk, str, dex, int, luk
	int bonus_acc;
	int bonus_eva;
public:
	LowerBody() : bonus_stats{0,0,0,0,0,0} {
		this->setSlot("Lower Body");
	}
	LowerBody(string _name) : bonus_stats{0,0,0,0,0,0} {
		this->setSlot("Lower Body");
		this->setName(_name);
	}

	LowerBody(string _name, int bHP, int atk, int matk,
		int str, int dex, int int_, int luk, 
		int b_acc, int b_eva) : 
		bonus_stats{ atk, matk, str, dex, int_, luk } {
			this->setSlot("Lower Body");
			this->setName(_name);
			bonus_HP = bHP;
			bonus_acc = b_acc;
			bonus_eva = b_eva;
	}

	int getHP(){return bonus_HP; }
	int getStat(uint choose){
		if(choose == 0){return bonus_stats[0]; }
		else if(choose == 1){return bonus_stats[1]; }
		else if(choose == 2){return bonus_stats[2]; }
		else if(choose == 3){return bonus_stats[3]; }
		else if(choose == 4){return bonus_stats[4]; }
		else if(choose == 5){return bonus_stats[5]; }
		else{return 0; }
	}
	int getAcc(){return bonus_acc; }
	int getEva(){return bonus_eva; }
};

class Shoes : public Equipment{
private:
	int bonus_HP;
	int bonus_stats[6];
	//atk, matk, str, dex, int, luk
	int bonus_acc;
	int bonus_eva;
public:
	Shoes() : bonus_stats{0,0,0,0,0,0} {
		this->setSlot("Shoes");
	}
	Shoes(string _name) : bonus_stats{0,0,0,0,0,0} {
		this->setSlot("Shoes");
		this->setName(_name);
	}

	Shoes(string _name, int bHP, int atk, int matk,
		int str, int dex, int int_, int luk, 
		int b_acc, int b_eva) : 
		bonus_stats{ atk, matk, str, dex, int_, luk } {
			this->setSlot("Shoes");
			this->setName(_name);
			bonus_HP = bHP;
			bonus_acc = b_acc;
			bonus_eva = b_eva;
	}

	int getHP(){return bonus_HP; }
	int getStat(uint choose){
		if(choose == 0){return bonus_stats[0]; }
		else if(choose == 1){return bonus_stats[1]; }
		else if(choose == 2){return bonus_stats[2]; }
		else if(choose == 3){return bonus_stats[3]; }
		else if(choose == 4){return bonus_stats[4]; }
		else if(choose == 5){return bonus_stats[5]; }
		else{return 0; }
	}
	int getAcc(){return bonus_acc; }
	int getEva(){return bonus_eva; }
};

class Weapon : public Equipment{
private:
	int bonus_HP;
	int bonus_stats[6];
	//atk, matk, str, dex, int, luk
	int bonus_acc;
	int bonus_eva;
public:
	Weapon() : bonus_stats{0,0,0,0,0,0} {
		this->setSlot("Main Hand");
	}
	Weapon(string _name, bool sh = false) : bonus_stats{0,0,0,0,0,0} {
		if(!sh){ this->setSlot("Main Hand"); }
		else{ this->setSlot("Sub Hand"); }
		
		this->setName(_name);
	}

	Weapon(string _name, int bHP, int atk, int matk,
		int str, int dex, int int_, int luk, 
		int b_acc, int b_eva, bool sh = false) : 
		bonus_stats{ atk, matk, str, dex, int_, luk } {
			if(!sh){ this->setSlot("Main Hand"); }
			else{ this->setSlot("Sub Hand"); }
			this->setName(_name);
			bonus_HP = bHP;
			bonus_acc = b_acc;
			bonus_eva = b_eva;
	}

	int getHP(){return bonus_HP; }
	int getStat(uint choose){
		if(choose == 0){return bonus_stats[0]; }
		else if(choose == 1){return bonus_stats[1]; }
		else if(choose == 2){return bonus_stats[2]; }
		else if(choose == 3){return bonus_stats[3]; }
		else if(choose == 4){return bonus_stats[4]; }
		else if(choose == 5){return bonus_stats[5]; }
		else{return 0; }
	}
	int getAcc(){return bonus_acc; }
	int getEva(){return bonus_eva; }
};

