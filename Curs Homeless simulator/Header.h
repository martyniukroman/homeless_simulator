#pragma once
#pragma comment(lib, "Winmm.lib")

#include <iostream>
#include <ctime>
#include "windows.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <mmsystem.h>
#include <conio.h>
#include <vector>



#define null 0
#define us unsigned short
#define ui unsigned int
#define slp1 Sleep(1000)

#define RED SetConsoleTextAttribute(hConsole, 12 + (7 * 16));
#define WHITE SetConsoleTextAttribute(hConsole, 15 + (7 * 16));
#define YELLOW SetConsoleTextAttribute(hConsole, 14 + (7 * 16));
#define BLUE SetConsoleTextAttribute(hConsole, 9 + (7 * 16));
#define GREEN SetConsoleTextAttribute(hConsole, 10 + (7 * 16));
#define blueBackground SetConsoleTextAttribute(hConsole, 15 + (1 * 16));
#define greenBackground SetConsoleTextAttribute(hConsole, 15 + (2 * 16));
#define lightRedBackground SetConsoleTextAttribute(hConsole, 15 + (12 * 16));
#define redBackground SetConsoleTextAttribute(hConsole, 15 + (4 * 16));
#define greyBackground SetConsoleTextAttribute(hConsole, 15 + (8 * 16));
#define leetColor SetConsoleTextAttribute(hConsole, 3);
#define lightGreyBackground SetConsoleTextAttribute(hConsole, 0 + (7 * 16));
#define battleHeal SetConsoleTextAttribute(hConsole, 5);
#define healColor SetConsoleTextAttribute(hConsole, 15 + (5 * 16));
#define homko SetConsoleTextAttribute(hConsole, 4);
#define deathColor SetConsoleTextAttribute(hConsole, 0+(4*16));

using namespace std;

enum Type { Bird = 1, Dog = 2, Bum = 3, Boss = 4 };

void input(us &out);

class homeless {
private:
	int x;
	int y;
	string name;
	int hp;
	int attack;
	int food;
	float money;
public:

	homeless() {
		this->name = "Player";
		this->hp = 100;
		this->attack = 5;
		this->food = 100;
		this->money = 0.5;
		this->x = 0;
		this->y = 0;
	}

	void choise_player() {

		us choise;
		system("cls");
		cout << "1.=====================================================" << endl;

		cout << "Hp\t\tAttack\t\tFood\t\tMoney" << endl;
		cout << "100\t\t5\t\t100\t\t0.5$" << endl;

		cout << "2.=====================================================" << endl;

		cout << "Hp\t\tAttack\t\tFood\t\tMoney" << endl;
		cout << "50\t\t10\t\t100\t\t0.5$" << endl;

		cout << "3.=====================================================" << endl;

		cout << "Hp\t\tAttack\t\tFood\t\tMoney" << endl;
		cout << "50\t\t5\t\t100\t\t1$" << endl;

		cout << "=======================================================" << endl;

		cout << "Choose your hero: ";
		input(choise);

		switch (choise) {

		case 1:

			this->hp = 100;
			this->attack = 5;
			this->food = 100;
			this->money = 0.5;
			break;

		case 2:

			this->hp = 50;
			this->attack = 10;
			this->food = 100;
			this->money = 0.5;
			break;

		case 3:

			this->hp = 50;
			this->attack = 5;
			this->food = 100;
			this->money = 1;
			break;


		default:
			this->hp = 100;
			this->attack = 5;
			this->food = 100;
			this->money = 0.5;
		}
	}

	void print_all() {
		if (hp <= 0) {
			cout << "You have no save" << endl;
		}
		else {

			string advices[12]
			{
				{ "Inhale before exhale!" },
				{ "Eror - advise lost :(" },
				{ "To get asleep close your eyes!" },
				{ "Get some paper under your clothes, it keeps your worm!" },
				{ "Well fry the meat, it kills the disease!" },
				{ "You can ask for an alms, on the streets!" },
				{ "Sometimes better pay then fight!" },
				{ "You can ask for an alms, on the streets!" },
				{ "Dont forget to improve your weapon" },
				{ "Take watch on colors, they can tell you something!" },
				{ "Stay strong!" },
				{ "Be careful, every your step needs a food!" },
			};

			system("cls");

			cout << "=======================================================" << endl;
			cout << "Advice: " << advices[rand() % 12] << endl;
			cout << "=======================================================" << endl;

			cout << "\t\t\t" << name << endl;
			cout << "Hp\t\tAttack\t\tFood\t\tMoney" << endl;
			cout << hp << "\t\t";
			cout << attack << "\t\t";
			cout << food << "\t\t";
			cout << money << "$\t\t";

			cout << endl;

			cout << "=======================================================" << endl;

		}
	}

	//-----set
	void set_name(string sname) {
		name = sname;
	}
	void set_hp(int shp) {
		//	cout << shp << endl;
		//	system("pause");
		this->hp = shp;
		//	cout << this->hp << endl;
		//	system("pause");
	}
	void set_attack(int sattack) {
		attack = sattack;
	}
	void set_food(int sfood) {
		food = sfood;
	}
	void set_money(float smoney) {
		money = smoney;
	}
	void set_x(int sx) {
		x = sx;
	}
	void set_y(int sy) {
		y = sy;
	}
	void enter_name() {
		getline(cin, this->name);
	}
	//-----get
	string get_name() {
		return name;
	}
	int& get_hp() {
		return hp;
	}
	int& get_attack() {
		return attack;
	}
	int& get_food() {
		return food;
	}
	float& get_money() {
		return money;
	}
	int& get_x() {
		return x;
	}
	int& get_y() {
		return y;
	}

	void auto_save(bool &is_location_1, bool &is_location_2, bool &is_location_3) {

		ofstream fout;

		fout.open("D:\\hl\\save.hl");

		if (!fout.is_open()) {
			cout << "some error" << endl;
			system("pause");
		}
		else {
			fout << hp << endl;
			fout << attack << endl;
			fout << food << endl;
			fout << money << endl;
			fout << is_location_1 << endl;
			fout << is_location_2 << endl;
			fout << is_location_3 << endl;
			fout << name << endl;

			fout.close();

			cout << "Saved" << endl;
		}


	}
	void load_save(bool &is_location_1, bool &is_location_2, bool &is_location_3) {

		ifstream fin;

		fin.open("D:\\hl\\save.hl");

		if (!fin.is_open()) {
			cout << "some error" << endl;
			system("pause");
		}
		else {

			fin >> hp;
			fin >> attack;
			fin >> food;
			fin >> money;
			fin >> is_location_1;
			fin >> is_location_2;
			fin >> is_location_3;
			fin.ignore();
			getline(fin, name);

			fin.close();
		}
	}

};

class enemy {
protected:
	int x;
	int y;
	int hp;
	us attack;
	string name;
	Type type;
public:

	enemy() {
		x = 5;
		y = 5;
	}
	/*
	enemy(enemy &copy) {
	this->x = copy.x;
	this->y = copy.y;
	this->hp = copy.hp;
	this->attack = copy.attack;
	this->name = copy.name;
	this->type = copy.type;
	}
	*/
	int& get_hp() {
		return hp;
	}
	us& get_attack() {
		return attack;
	}
	string get_name() {
		return name;
	}
	void set_x(int sx) {
		x = sx;
	}
	void set_y(int sy) {
		y = sy;
	}
	int& get_x() {
		return x;
	}
	int& get_y() {
		return y;
	}
	Type get_type() {
		return type;
	}
	void voice() {
		string phrases[5] // bums phrases
		{
			{ "Ok, no troubles..." },
			{ "Till the next time, loser!" },
			{ "Hate people like you!" },
			{ "Don't want to see you again." },
			{ "Get out from my way!" },
		};
		if (this->get_type() == Bum)
			cout << phrases[rand() % 5] << endl;
	}
	void moveto(homeless player, int counter, us speed) {
		if (this->x > player.get_x() && (counter % speed == 0)) {
			this->x--;
		}
		if (this->x < player.get_x() && (counter % speed == 0)) {
			this->x++;
		}
		if (this->y > player.get_y() && (counter % speed == 0)) {
			this->y--;
		}
		if (this->y < player.get_y() && (counter % speed == 0)) {
			this->y++;
		}
	}

};

class bird : public enemy {
protected:

public:

	bird(homeless player) {

		type = Bird;

		string names_birds[5] // Array with birds names
		{
			{ "Crow" },
			{ "Dove" },
			{ "Duck" },
			{ "Chicken" },
			{ "Owl" },
		};

		hp = (player.get_hp() / 3) + rand() % (player.get_hp() / 3);
		attack = (player.get_attack() / 3) + rand() % (player.get_attack() / 3);

		us randname = rand() % 5;

		switch (randname) {

		case 0:
			name = names_birds[0];
			break;

		case 1:
			name = names_birds[1];
			break;

		case 2:
			name = names_birds[2];
			break;

		case 3:
			name = names_birds[3];
			break;

		case 4:
			name = names_birds[4];
			break;
		}

	}
};

class dog : public enemy {
protected:

public:

	dog(homeless player) {

		type = Dog;

		string names_dogs[5] // Array with dogs names
		{
			{ "Barsik" },
			{ "Rex" },
			{ "Zhulik" },
			{ "Ursa" },
			{ "Black" },
		};

		hp = (player.get_hp() / 2) + rand() % (player.get_hp() / 2);
		attack = (player.get_attack() / 2) + rand() % (player.get_attack() / 2);

		us randname = rand() % 5;

		switch (randname) {

		case 0:
			name = names_dogs[0];
			break;

		case 1:
			name = names_dogs[1];
			break;

		case 2:
			name = names_dogs[2];
			break;

		case 3:
			name = names_dogs[3];
			break;

		case 4:
			name = names_dogs[4];
			break;
		}

	}
};

class bum : public enemy {
protected:

public:

	bum(homeless player) {

		type = Bum;

		string names_else_homeless[5]{
			{ "Pedro" },
			{ "Zhak" },
			{ "Patrick" },
			{ "Danil" },
			{ "George" },
		};

		hp = (player.get_hp() / 2) + rand() % (player.get_hp() / 2) % player.get_hp() / 5;
		attack = (player.get_attack() / 2) + rand() % (player.get_attack() / 2) % player.get_attack() / 5;

		us randname = rand() % 5;

		switch (randname) {

		case 0:
			name = names_else_homeless[0];
			break;

		case 1:
			name = names_else_homeless[1];
			break;

		case 2:
			name = names_else_homeless[2];
			break;

		case 3:
			name = names_else_homeless[3];
			break;

		case 4:
			name = names_else_homeless[4];
			break;
		}

	}
};

class boss : public enemy {
protected:

public:

	boss(homeless player) {
		type = Boss;
		hp = (player.get_hp() / 2) + rand() % (player.get_hp() / 2);
		attack = (player.get_attack() / 2) + rand() % (player.get_attack() / 2);
	}

	void set_hp(us shp) {
		this->hp = shp;
	}

	void fire() {

	}

};

class bullet {
protected:
	us x;
	us y;
	bool isexist;
public:

	bullet() {
		isexist = false;
	}

	void set_x(us sx) {
		x = sx;
	}
	void set_y(us sy) {
		y = sy;
	}
	void set_isexist(bool sisexist) {
		isexist = sisexist;
	}
	us& get_x() {
		return x;
	}
	us& get_y() {
		return y;
	}
	bool& get_isexist() {
		return isexist;
	}
};

void battle(homeless& player, enemy *foe, bool &endofgame);
void print_battle(homeless& player, enemy *foe);
void loading_short();
void loading_long_print();
void loading_long();
void loading_mid();
void color(homeless& player);
void BumShop(homeless& player);
void info();
void BusStation(homeless& player, bool &endofgame);
void Park(homeless& player, bool &endofgame);
void Streets(homeless& player, bool &endofgame);
void location_battle(homeless& player, enemy *foe, bool &endofgame);
void location_1(homeless& player, bool &endofgame, bool &is_location_1);
void location_2(homeless& player, bool &endofgame, bool &is_location_2);
void location_3(homeless& player, bool &endofgame, bool &is_location_3);
void battleground(homeless& player, bool &endofgame);
void setcur(int x, int y);
void lastbattle(homeless& player, bool &endofgame);




