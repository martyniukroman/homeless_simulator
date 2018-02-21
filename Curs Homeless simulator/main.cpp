#include "Header.h"
//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main() {
	srand(time(null));

	//					LOGIC

	//	locations

	//	Bus Statios -> Here you can find another bums and some rubbish
	//	Park -> Here you can fight with birds and also meet some boms.
	//	BumShop -> Here you can buy pills, food and improve your weapon.
	//	Streets -> Here you can search for staff in a rubbish bins, and meet some dogs and birds

	// pills give u Hp
	// food give u food
	// for money u can buy some stuff in bumshop

	// bums (pay or fight),
	// if fight u can win sum staff
	// else u have to pay

	//	info();

	/*

	enemy *foe = NULL;
	foe = new bird(player);

	print_battle(player, foe);

	*/



	//				ISSUE
	// auto_save(), load_save(), firstly it was a functions.
	// the values wasn't assigned. fin done well. cout in set_hp() showed, 
	// that readed value appeared within
	// and succsesfuly assigned | but in main() there were default parrameters

	//				SOLUTION
	// auto_save(), load_save(), have been made like a methods in homeless class;

	//loading_long_print();
	//PlaySound(TEXT("D:\\hl\\start1.wav"), NULL, SND_FILENAME | SND_ASYNC);

	us choise;

	bool endofgame = false;

	bool is_location_1 = false;
	bool is_location_2 = false;
	bool is_location_3 = false;

	bool pass_1 = false;
	bool pass_2 = false;
	bool pass_3 = false;
	bool pass_4 = false;

	us is_save;

	cout << "1. Use existing profile." << endl;
	cout << "2. I'm new one." << endl;
	cout << "Enter your choise: ";
	input(is_save);

	homeless player;

	if (is_save == 1) {
		player.load_save(is_location_1, is_location_2, is_location_3);
	}
	else {
		player.choise_player();
		cout << "\nEnter name of your hero: ";
		player.enter_name();
	}

	while (player.get_hp() > 0, !endofgame) {

		PlaySound(TEXT("D:\\hl\\main.wav"), NULL, SND_FILENAME | SND_ASYNC);

		color(player);

		if (player.get_hp() >= 250 && player.get_food() >= 225 && player.get_attack() >= 20)
			pass_1 = true;
		if (player.get_hp() >= 500 && player.get_food() >= 250 && player.get_attack() >= 30)
			pass_2 = true;
		if (player.get_hp() >= 750 && player.get_food() >= 275 && player.get_attack() >= 40)
			pass_3 = true;
		if (is_location_1, is_location_2, is_location_3)
			pass_4 = true;


		player.print_all();

		cout << "1. Park (-3 Food)" << endl;
		cout << "2. Bus Station (-5 Food)" << endl;
		cout << "3. Streets (-8 Food)" << endl;
		cout << "4. BumShop (-10 Food)" << endl;

		if (pass_1)
			cout << "5. Fight for Boyarka (-25 food)" << endl;
		if (pass_2)
			cout << "6. Fight for Pivnichnyy (-50 food)" << endl;
		if (pass_3)
			cout << "7. Fight for Yubileynyy (-75 food)" << endl;

		cout << "--------------------" << endl;

		cout << "8. Info" << endl;
		cout << "9. Exit" << endl;
		if (pass_4)
			cout << "0. Battleground (beta)" << endl;

		cout << "Where are you going :";
		input(choise);
		cout << endl;

		if (choise == 1) {
			player.get_food() -= 3;
			Park(player, endofgame);
		}
		else if (choise == 2) {
			player.get_food() -= 5;
			BusStation(player, endofgame);
		}
		else if (choise == 3) {
			player.get_food() -= 8;
			Streets(player, endofgame);
		}
		else if (choise == 4) {
			player.get_food() -= 10;
			BumShop(player);
		}

		else if (choise == 5 && pass_1) {
			player.get_food() -= 25;
			location_1(player, endofgame, is_location_1);
		}
		else if (choise == 6 && pass_2) {
			player.get_food() -= 50;
			location_1(player, endofgame, is_location_2);
		}
		else if (choise == 7 && pass_3) {
			player.get_food() -= 75;
			location_1(player, endofgame, is_location_3);
		}

		else if (choise == 8) {
			info();
		}
		else if (choise == 9) {
			player.auto_save(is_location_1, is_location_2, is_location_3);
			break;
		}
		else if (choise == 0 && pass_4) {
			try {
				battleground(player, endofgame);
			}
			catch (...) {
				cout << "Some eror here";
				system("pause");
			}
		}

		if (endofgame) {
			system("cls");
			cout << "Game over !" << endl;
			cout << "You died !" << endl;
			PlaySound(TEXT("D:\\hl\\lose0.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("pause");
			system("pause");
			system("pause");
			break;
		}
		if (player.get_money() <= -10) {
			system("cls");
			cout << "Game over !" << endl;
			cout << "Bums have killed you because of money !" << endl;
			PlaySound(TEXT("D:\\hl\\lose0.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("pause");
			break;
		}
		if (player.get_food() <= 0) {
			system("cls");
			cout << "Game over !" << endl;
			cout << "You starve to death !" << endl;
			PlaySound(TEXT("D:\\hl\\lose0.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("pause");
			break;
		}


		player.auto_save(is_location_1, is_location_2, is_location_3);

	}//while



	 //system("pause");
	return 0;
}





