#include "Header.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void battle(homeless& player, enemy *foe, bool &endofgame) {

	bool game = true;
	us choise;

	if (foe->get_type() == Bird) {

		while (player.get_hp() > 0 && game) {

			print_battle(player, foe);

			color(player);

			if (player.get_food() > 0)
				cout << "1. Attack (-2 Food)" << endl;
			cout << "2. Leave (-1$)" << endl;
			cout << "Enter your choise: ";
			input(choise);

			if (player.get_food() <= 0 && choise == 1) {
				player.get_money() -= 1;
				system("cls");
				cout << "You left battleground, (-1$)" << endl;
				system("pause");
				game = false;
			}

			switch (choise) {
			case 1:
				cout << "Nice hit !" << endl;
				player.get_food() -= 2;
				foe->get_hp() -= player.get_attack();
				break;

			case 2:
				system("cls");
				cout << "Kurlick Kurlick !" << endl;
				PlaySound(TEXT("D:\\hl\\lose0.wav"), NULL, SND_FILENAME | SND_ASYNC);
				player.get_money() -= 1;
				game = false;
				break;

			default:
				choise = 2;
			}

			if (foe->get_hp() <= 0) {
				game = false;
				system("cls");
				cout << "You win" << endl;
				us meat = rand() % 30 + rand() % 20;
				player.get_food() += meat;
				player.get_hp() += meat / 5;
				cout << "-------------" << endl;
				cout << "Meat:  " << meat << endl;
				cout << "-------------" << endl;
				system("pause");

			}

			if (game) {
				print_battle(player, foe);
				cout << foe->get_name() << " has attacked you!" << endl;
				player.get_hp() -= foe->get_attack();
				loading_short();
			}

			if (player.get_hp() <= 0) {
				system("cls");
				game = false;
				endofgame = true;
			}

		} //while
	} //if

	if (foe->get_type() == Dog) {

		while (player.get_hp() > 0 && game) {

			print_battle(player, foe);

			color(player);

			if (player.get_food() > 0)
				cout << "1. Attack (-3 Food)" << endl;
			cout << "2. Leave (-1.5$)" << endl;
			cout << "Enter your choise: ";
			input(choise);

			if (player.get_food() <= 0 && choise == 1) {
				player.get_money() -= 1.5;
				system("cls");
				cout << "You left battleground, (-1.5$)" << endl;
				system("pause");
				game = false;
			}

			switch (choise) {
			case 1:
				cout << "Nice hit !" << endl;
				player.get_food() -= 3;
				foe->get_hp() -= player.get_attack();
				break;

			case 2:
				system("cls");
				cout << "Gav-Gav!" << endl;
				PlaySound(TEXT("D:\\hl\\lose0.wav"), NULL, SND_FILENAME | SND_ASYNC);
				player.get_money() -= 1;
				game = false;
				break;

			default:
				choise = 2;
			}

			if (foe->get_hp() <= 0) {
				game = false;
				system("cls");
				cout << "You win" << endl;
				us meat = rand() % 40 + rand() % 30;
				player.get_food() += meat;
				player.get_hp() += meat / 5;
				cout << "-------------" << endl;
				cout << "Meat:  " << meat << endl;
				cout << "-------------" << endl;
				system("pause");

			}

			if (game) {
				print_battle(player, foe);
				cout << foe->get_name() << " has attacked you!" << endl;
				player.get_hp() -= foe->get_attack();
				loading_short();
			}

			if (player.get_hp() <= 0) {
				system("cls");
				game = false;
				endofgame = true;
			}

		} //while
	} //if

	if (foe->get_type() == Bum) {

		print_battle(player, foe);

		float a;
		float b;
		float have_to_pay_money;
		us have_to_pay_food;

		a = rand() % 2;
		b = rand() % 100 + 1;
		have_to_pay_money = a + (b / 100);
		have_to_pay_food = rand() % 75;

		cout << "1. Pay $ (" << have_to_pay_money << ")" << endl;
		cout << "2. Pay Food (" << have_to_pay_food << ")" << endl;
		cout << "3. Fight" << endl;
		cout << "Enter your choise: ";
		input(choise);

		print_battle(player, foe);

		switch (choise) {

		case 1:
			game = false;
			system("cls");
			foe->voice();
			PlaySound(TEXT("D:\\hl\\lose0.wav"), NULL, SND_FILENAME | SND_ASYNC);
			player.get_money() -= have_to_pay_money;
			break;
		case 2:
			game = false;
			system("cls");
			foe->voice();
			PlaySound(TEXT("D:\\hl\\lose0.wav"), NULL, SND_FILENAME | SND_ASYNC);
			player.get_food() -= have_to_pay_food;
			break;
		case 3:
			while (player.get_hp() > 0 && game) {

				print_battle(player, foe);
				color(player);

				if (player.get_food() > 0)
					cout << "1. Attack (-5 Food)" << endl;
				cout << "2. Leave (-3$)" << endl;
				cout << "Enter your choise: ";
				input(choise);

				if (player.get_food() <= 0 && choise == 1) {
					player.get_money() -= 3;
					system("cls");
					cout << "You left battleground, (-3$)" << endl;
					system("pause");
					game = false;
				}

				switch (choise) {
				case 1:
					cout << "Nice hit !" << endl;
					player.get_food() -= 5;
					foe->get_hp() -= player.get_attack();
					break;

				case 2:
					system("cls");
					cout << "Kurlick Kurlick !" << endl;
					PlaySound(TEXT("D:\\hl\\lose0.wav"), NULL, SND_FILENAME | SND_ASYNC);
					player.get_money() -= 1;
					game = false;
					break;

				default:
					choise = 2;
				}

				if (foe->get_hp() <= 0) {
					system("cls");
					cout << "You win !" << endl;
					game = false;
					us food = rand() % 50 + rand() % 50;
					us pills = rand() % 3 + rand() % 2;
					float money;
					a = rand() % 3;
					b = rand() % 100;
					money = a + (b / 100);

					cout << "-------------" << endl;
					cout << "Food:  " << food << endl;
					cout << "Pills: " << pills << endl;
					cout << "Money: " << money << endl;
					cout << "-------------" << endl;

					player.get_food() += food;
					player.get_hp() += food / 5;
					player.get_hp() += pills * 10;
					player.get_money() += money;

					system("pause");


				}

				if (game) {
					print_battle(player, foe);
					cout << foe->get_name() << " has attacked you!" << endl;
					player.get_hp() -= foe->get_attack();
					loading_short();
				}

				if (player.get_hp() <= 0) {
					system("cls");
					game = false;
					endofgame = true;
				}

			} //while
			break;
		default:
			choise = 2;
		}//switch
	} //if

}
void location_battle(homeless& player, enemy *foe, bool &endofgame) {

	bool game = true;
	us choise;

	if (foe->get_type() == Bird) {

		while (player.get_hp() > 0 && game) {

			print_battle(player, foe);

			color(player);

			cout << "1. Attack (-2 Food)" << endl;
			cout << "Enter your choise: ";
			input(choise);

			if (player.get_food() <= 0 && choise == 1) {
				player.get_money() -= 5;
				system("cls");
				cout << "You left battleground, (-5$)" << endl;
				system("pause");
				game = false;
			}

			switch (choise) {
			case 1:
				cout << "Nice hit !" << endl;
				player.get_food() -= 2;
				foe->get_hp() -= player.get_attack();
				break;

			default:
				choise = 1;
			}

			if (foe->get_hp() <= 0) {
				game = false;
				system("cls");
				cout << "You win" << endl;
				us meat = rand() % 30 + rand() % 20;
				player.get_food() += meat;
				player.get_hp() += meat / 5;
				cout << "-------------" << endl;
				cout << "Meat:  " << meat << endl;
				cout << "-------------" << endl;
				system("pause");

			}

			if (game) {
				print_battle(player, foe);
				cout << foe->get_name() << " has attacked you!" << endl;
				player.get_hp() -= foe->get_attack();
				loading_short();
			}

			if (player.get_hp() <= 0) {
				system("cls");
				game = false;
				endofgame = true;
			}

		} //while
	} //if

	if (foe->get_type() == Dog) {

		while (player.get_hp() > 0 && game) {

			print_battle(player, foe);

			color(player);

			cout << "1. Attack (-3 Food)" << endl;
			cout << "Enter your choise: ";
			input(choise);

			if (player.get_food() <= 0 && choise == 1) {
				player.get_money() -= 5;
				system("cls");
				cout << "You left battleground, (-5$)" << endl;
				system("pause");
				game = false;
			}

			switch (choise) {
			case 1:
				cout << "Nice hit !" << endl;
				player.get_food() -= 3;
				foe->get_hp() -= player.get_attack();
				break;

			default:
				choise = 1;
			}

			if (foe->get_hp() <= 0) {
				game = false;
				system("cls");
				cout << "You win" << endl;
				us meat = rand() % 40 + rand() % 30;
				player.get_food() += meat;
				player.get_hp() += meat / 5;
				cout << "-------------" << endl;
				cout << "Meat:  " << meat << endl;
				cout << "-------------" << endl;
				system("pause");

			}

			if (game) {
				print_battle(player, foe);
				cout << foe->get_name() << " has attacked you!" << endl;
				player.get_hp() -= foe->get_attack();
				loading_short();
			}

			if (player.get_hp() <= 0) {
				system("cls");
				game = false;
				endofgame = true;
			}

		} //while
	} //if

	if (foe->get_type() == Bum) {

		while (player.get_hp() > 0 && game) {

			print_battle(player, foe);
			color(player);

			cout << "1. Attack (-5 Food)" << endl;
			cout << "Enter your choise: ";
			input(choise);

			if (player.get_food() <= 0 && choise == 1) {
				player.get_money() -= 5;
				system("cls");
				cout << "You left battleground, (-5$)" << endl;
				system("pause");
				game = false;
			}

			switch (choise) {
			case 1:
				cout << "Nice hit !" << endl;
				player.get_food() -= 5;
				foe->get_hp() -= player.get_attack();
				break;

			default:
				choise = 1;
			}

			if (foe->get_hp() <= 0) {
				float a, b;
				system("cls");
				cout << "You win !" << endl;
				game = false;
				us food = rand() % 50 + rand() % 50;
				us pills = rand() % 3 + rand() % 2;
				float money;
				a = rand() % 3;
				b = rand() % 100;
				money = a + (b / 100);

				cout << "-------------" << endl;
				cout << "Food:  " << food << endl;
				cout << "Pills: " << pills << endl;
				cout << "Money: " << money << endl;
				cout << "-------------" << endl;

				player.get_food() += food;
				player.get_hp() += food / 5;
				player.get_hp() += pills * 10;
				player.get_money() += money;

				system("pause");
			}

			if (game) {
				print_battle(player, foe);
				cout << foe->get_name() << " has attacked you!" << endl;
				player.get_hp() -= foe->get_attack();
				loading_short();
			}

			if (player.get_hp() <= 0) {
				system("cls");
				game = false;
				endofgame = true;
			}

		} //while
	} //if
}
void print_battle(homeless& player, enemy *foe) {

	system("cls");

	cout << "-----------------------" << endl;

	cout << "\t" << foe->get_name() << endl;

	cout << "-----------------------" << endl;

	cout << "Hp\t\tAttack" << endl;
	cout << foe->get_hp() << "\t\t";
	cout << foe->get_attack() << "\t\t";

	cout << endl << "-----------------------" << endl;

	cout << "=======================" << endl;

	cout << "-----------------------" << endl;

	cout << "\t" << player.get_name() << endl;

	cout << "-----------------------" << endl;

	cout << "Hp\tFood\tAttack" << endl;
	cout << player.get_hp() << "\t";
	cout << player.get_food() << "\t";
	cout << player.get_attack() << "\t";

	cout << endl << "-----------------------" << endl;

}
void input(us &out) {


	switch (_getch()) {

	case '0':
		out = 0;
		break;

	case '1':
		out = 1;
		break;

	case '2':
		out = 2;
		break;

	case '3':
		out = 3;
		break;

	case '4':
		out = 4;
		break;

	case '5':
		out = 5;
		break;

	case '6':
		out = 6;
		break;

	case '7':
		out = 7;
		break;

	case '8':
		out = 8;
		break;

	case '9':
		out = 9;
		break;

	default:
		out = 1;
	}
}
void info() {

	PlaySound(TEXT("D:\\hl\\mann.wav"), NULL, SND_FILENAME | SND_ASYNC);

	system("cls");

	cout << "     |||||||||||||||" << endl;
	cout << "     |              \\" << endl;
	cout << "     |               |" << endl;
	cout << "    _|            ___/" << endl;
	cout << "   / \\            (o)\\" << endl;
	cout << "  | |\\             _  \\" << endl;
	cout << "  | |/            (____)" << endl;
	cout << "   \\__/          /   |" << endl;
	cout << "    /           /  ___)" << endl;
	cout << "   /    \\       \\    _)" << endl;
	cout << "  \\      \\           /" << endl;
	cout << "\\/ \\      \\_________/" << endl;
	cout << " \\/ \\      /" << endl;
	cout << "  \\/ \\    /" << endl;
	cout << "   \\/ \\  /" << endl;
	cout << "" << endl;

	cout << "O   O   O O    O   O   O O O  O      O O O  O O  O O     " << endl;
	cout << "O   O  O   O  O O O O  O      O      O      O    O         " << endl;
	cout << "O O O  O   O  O  O  O  O O O  O      O O O   O    O        " << endl;
	cout << "O   O  O   O  O     O  O      O      O        O    O       " << endl;
	cout << "O   O   O O   O     O  O O O  O O O  O O O  O O  O O      " << endl;
	cout << endl;
	cout << "O O   O   O   O   O   O  O       O O   O O O   O O   O O   " << endl;
	cout << "O        O O O O  O   O  O      O   O    O    O   O  O  O  " << endl;
	cout << " O    O  O  O  O  O   O  O      O O O    O    O   O  O O   " << endl;
	cout << "  O   O  O     O  O   O  O      O   O    O    O   O  O  O  " << endl;
	cout << "O O   O  O     O   O O   O O O  O   O    O     O O   O  O  " << endl;

	slp1;
	slp1;

	cout << endl << endl << "The Game \"Homeless simulator\" can" << endl; slp1;
	cout << "teach you how to survive if you" << endl; slp1;
	cout << "will have lost all your money and hope." << endl << endl; slp1;

	cout << endl << "The autor don't want anybody to hurt" << endl; slp1;
	cout << "This game was made just for fun." << endl; slp1;

	cout << endl << endl << "GAME INFO" << endl; slp1;

	cout << endl << "Locations: " << endl; slp1;
	cout << "Bus Statios -> Here you can find another bums, dogs, and some rubbish." << endl; slp1;
	cout << "Park -> Here you can fight with birds, dogs and also meet some boms." << endl; slp1;
	cout << "Streets -> Here you can search for staff in rubbish bins, and meet some dogs and birds." << endl; slp1;
	cout << "BumShop -> Here you can buy pills, food and improve your weapon. " << endl; slp1;

	slp1;

	cout << endl << "Features:" << endl; slp1;
	cout << "Bums: You can pay or fight." << endl; slp1;
	cout << "Birds: You can fight or leave." << endl; slp1;
	cout << "Dogs: You can fight or leave." << endl; slp1;
	cout << "Pills: One pill = 10 Hp." << endl; slp1;
	cout << "Meat: One meat = 1 Food and 0.2 Hp." << endl; slp1;
	cout << "Money: For money you can buy pills, food, and also improve feapon." << endl; slp1;
	cout << "Red: you have a few HP." << endl; slp1;
	cout << "Yellow: you have a few Food." << endl; slp1;
	cout << "Blue: you have no money." << endl; slp1;
	cout << "Be careful, every your step needs a food." << endl; slp1;

	slp1;

	cout << endl << "Districts:" << endl; slp1;
	cout << "For fight for Boyarka you need (Hp: 250 | Food: 225 | Attack: 20)." << endl; slp1;
	cout << "For fight for Pivnichnyy you need (Hp: 500 | Food: 250 | Attack: 30)." << endl; slp1;
	cout << "For fight for Yubileynyy you need (Hp: 750 | Food: 275 | Attack: 40)." << endl; slp1;

	slp1;

	cout << endl << "To win you need to occupy all areas! " << endl; slp1;

	slp1;
	cout << endl << "\aGood luck !" << endl;
	system("pause");
}
void loading_long_print() {

	cout << "O   O   O O    O   O   O O O  O      O O O  O O  O O     " << endl;
	cout << "O   O  O   O  O O O O  O      O      O      O    O         " << endl;
	cout << "O O O  O   O  O  O  O  O O O  O      O O O   O    O        " << endl;
	cout << "O   O  O   O  O     O  O      O      O        O    O       " << endl;
	cout << "O   O   O O   O     O  O O O  O O O  O O O  O O  O O      " << endl;
	cout << endl;
	cout << "O O   O   O   O   O   O  O       O O   O O O   O O   O O   " << endl;
	cout << "O        O O O O  O   O  O      O   O    O    O   O  O  O  " << endl;
	cout << " O    O  O  O  O  O   O  O      O O O    O    O   O  O O   " << endl;
	cout << "  O   O  O     O  O   O  O      O   O    O    O   O  O  O  " << endl;
	cout << "O O   O  O     O   O O   O O O  O   O    O     O O   O  O  " << endl;

	slp1;

	cout << "Loading";
	for (us i = 0; i < 50; i++) {
		cout << "-";
		Sleep(50);
	}
	cout << endl << "\a\t\t\tSuccses" << endl;
	slp1;
}
void loading_long() {
	cout << "Loading";
	for (us i = 0; i < 47; i++) {
		cout << "-";
		Sleep(20);
	}
	cout << endl << "\a\t\t\tSuccses" << endl;
	Sleep(1000);

}
void loading_short() {
	cout << "Loading";
	Sleep(500);
	for (us i = 0; i < 3; i++) {
		cout << "-";
		Sleep(250);
	}
	cout << "\a" << endl;;
}
void loading_mid() {
	cout << "Loading";
	Sleep(500);
	for (us i = 0; i < 3; i++) {
		cout << "-";
		slp1;
	}
	cout << "\a" << endl;;
}
void color(homeless& player) {

	if (player.get_hp() <= 25 || player.get_food() <= 25 || player.get_money() <= 0) {

		if (player.get_hp() <= 25) {
			system("color 04"); // red
		}

		if (player.get_food() <= 25) {
			system("color 06"); // yellow
		}

		if (player.get_money() <= 0) {
			system("color 03"); // blue
		}

	}
	else {
		system("color 70");
	}

}
void BumShop(homeless& player) {

	loading_long();

	PlaySound(TEXT("D:\\hl\\shop0.wav"), NULL, SND_FILENAME | SND_ASYNC);

	us buy = 1;

	while (buy != 0) {

		color(player);

		system("cls");
		cout << "=================================================" << endl;

		cout << "\t\t    BumShop" << endl;

		cout << "=================================================" << endl;

		cout << "\t\t  Hello " << player.get_name() << "!" << endl;

		cout << "=================================================" << endl;

		cout << "\tHp\t\tAttack\t\tFood" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "\t" << player.get_hp() << "\t\t";
		cout << player.get_attack() << "\t\t";
		cout << player.get_food() << endl;

		cout << "=================================================" << endl;

		cout << "Type:\tPills\t\tFood\t\tAttack" << endl;
		cout << "Add:\t5\t\t15\t\t5" << endl;
		cout << "Cost:\t1$\t\t0.25$\t\t2.75$" << endl;

		cout << "=================================================" << endl;

		cout << "0.Exit" << "\t";
		cout << "1.Pills" << "\t\t";
		cout << "2.Food" << "\t\t";
		cout << "3.Attack" << endl;
		cout << "=================================================" << endl;
		cout << "Ballance: " << player.get_money() << endl;
		cout << "What are you going to buy: ";
		input(buy);
		cout << endl;
		if (buy == 1 && player.get_money() - 1 >= 0) {
			cout << "Succses" << endl;
			player.get_money() -= 1;
			player.get_hp() += 5 * 10;
		}
		else if (buy == 1 && player.get_money() - 1 < 0) {
			cout << "Not enough money !";
		}


		if (buy == 2 && player.get_money() - 0.25 >= 0) {
			cout << "Succses" << endl;
			player.get_money() -= 0.25;
			player.get_hp() += 3;
			player.get_food() += 15;
		}
		else if (buy == 2 && player.get_money() - 0.25 < 0) {
			cout << "Not enough money !";
		}


		if (buy == 3 && player.get_money() - 2.75 >= 0) {
			cout << "Succses" << endl;
			player.get_money() -= 2.75;
			player.get_attack() += 5;
		}
		else if (buy == 3 && player.get_money() - 2.75 < 0) {
			cout << "Not enough money !";
		}
		loading_short();
	}
}
void BusStation(homeless& player, bool &endofgame) {

	us choise;
	enemy *foe = null;

	PlaySound(TEXT("D:\\hl\\mann.wav"), NULL, SND_FILENAME | SND_ASYNC);

	while (!endofgame && player.get_food() > 0) {

		color(player);

		system("cls");
		cout << "     Bus Station: " << endl;

		cout << "=====================" << endl;

		cout << "Hp\tAttack\tFood" << endl;
		cout << player.get_hp() << "\t";
		cout << player.get_attack() << "\t";
		cout << player.get_food() << "\t" << endl;

		cout << "=====================" << endl;

		cout << "1. Go on (-5 Food)" << endl;
		cout << "2. Leave (-8 Food)" << endl;
		cout << "What are you going to do: ";
		input(choise);

		if (choise == 2) {
			player.get_food() -= 8;
			break;
		}

		if (choise == 1) {
			player.get_food() -= 5;

			us situation = rand() % 3;

			if (situation == 0) {
				system("cls");
				cout << "You've met a dog!" << endl;
				foe = new dog(player);
				loading_short();
				battle(player, foe, endofgame);
				loading_short();
			}
			else if (situation == 1) {
				system("cls");
				cout << "You've met a bum!" << endl;
				loading_short();
				foe = new bum(player);
				battle(player, foe, endofgame);
				loading_short();
			}
			else if (situation == 2) {
				system("cls");
				cout << "You've found a rubbish bin.." << endl;
				loading_short();
				float a, b;
				us food = rand() % 20;
				us pills = rand() % 5;
				float money;
				a = rand() % 2;
				b = rand() % 100;
				money = a + (b / 100);
				cout << "------------------" << endl;
				cout << "Food: " << food << endl;
				cout << "Pills: " << pills << endl;
				cout << "Money: " << money << endl;
				cout << "------------------" << endl;
				player.get_food() += food;
				player.get_hp() += food / 5;
				player.get_hp() += pills * 10;
				player.get_money() += money;

				system("pause");
			}

		}
		else {
			player.get_food() -= 8;
			break;
		}

		if (player.get_food() <= 0) {
			player.get_money() -= 1;
			cout << "You have no food to continue (-1$)" << endl;
			system("pause");
			BumShop(player);
		}

	}

}
void Park(homeless& player, bool &endofgame) {

	us choise;

	enemy *foe = null;

	PlaySound(TEXT("D:\\hl\\duhast.wav"), NULL, SND_FILENAME | SND_ASYNC);

	while (!endofgame && player.get_food() > 0) {

		color(player);

		system("cls");
		cout << "        Park: " << endl;

		cout << "=====================" << endl;

		cout << "Hp\tAttack\tFood" << endl;
		cout << player.get_hp() << "\t";
		cout << player.get_attack() << "\t";
		cout << player.get_food() << "\t" << endl;

		cout << "=====================" << endl;

		cout << "1. Go on (-3 Food)" << endl;
		cout << "2. Leave (-5 Food)" << endl;
		cout << "What are you going to do: ";
		input(choise);

		if (choise == 2) {
			player.get_food() -= 5;
			break;
		}

		if (choise == 1) {
			player.get_food() -= 3;

			us situation = rand() % 3;

			if (situation == 0) {
				system("cls");
				cout << "You've met a dog!" << endl;
				foe = new dog(player);
				loading_short();
				battle(player, foe, endofgame);
				loading_short();
			}

			else if (situation == 1) {
				system("cls");
				cout << "You've met a bum!" << endl;
				loading_short();
				foe = new bum(player);
				battle(player, foe, endofgame);
				loading_short();
			}
			else if (situation == 2) {
				system("cls");
				cout << "You've met a bird!" << endl;
				foe = new bird(player);
				loading_short();
				battle(player, foe, endofgame);
				loading_short();
			}

		}
		else {
			player.get_food() -= 5;
			break;
		}

		if (player.get_food() <= 0) {
			player.get_money() -= 1;
			cout << "You have no food to continue (-1$)" << endl;
			system("pause");
		}
	}
}
void Streets(homeless& player, bool &endofgame) {

	us choise;

	enemy *foe = null;

	PlaySound(TEXT("D:\\hl\\pussy.wav"), NULL, SND_FILENAME | SND_ASYNC);

	while (!endofgame && player.get_food() > 0) {

		color(player);

		system("cls");
		cout << "       Streets: " << endl;

		cout << "=====================" << endl;

		cout << "Hp\tAttack\tFood" << endl;
		cout << player.get_hp() << "\t";
		cout << player.get_attack() << "\t";
		cout << player.get_food() << "\t" << endl;

		cout << "=====================" << endl;

		cout << "1. Go on (-5 Food)" << endl;
		cout << "2. Leave (-10 Food)" << endl;
		cout << "3. Ask for an alms (-10 Food)" << endl;
		cout << "Where are you going: ";
		input(choise);

		cout << endl;

		if (choise == 2) {
			player.get_food() -= 10;
			break;
		}

		if (choise == 1) {

			player.get_food() -= 5;
			us situation = rand() % 3;

			if (situation == 0) {
				system("cls");
				cout << "You've met a dog!" << endl;
				foe = new dog(player);
				loading_short();
				battle(player, foe, endofgame);
				loading_short();
			}
			else if (situation == 1) {
				system("cls");
				cout << "You've met a bird!" << endl;
				foe = new bird(player);
				loading_short();
				battle(player, foe, endofgame);
				loading_short();
			}
			else if (situation == 2) {
				system("cls");
				cout << "You've found a rubbish bin.." << endl;
				float a, b;
				us food = rand() % 20;
				us pills = rand() % 5;
				float money;
				a = rand() % 2;
				b = rand() % 100;
				money = a + (b / 100);

				cout << "------------------" << endl;
				cout << "Food: " << food << endl;
				cout << "Pills: " << pills << endl;
				cout << "Money: " << money << endl;
				cout << "------------------" << endl;

				system("pause");

				player.get_food() += food;
				player.get_hp() += food / 5;
				player.get_hp() += pills * 10;
				player.get_money() += money;
			}
		}
		else if (choise == 3) {

			player.get_food() -= 10;

			us alms = rand() % 4;

			if (alms == 0) {
				cout << "You've got a hit!" << endl;
				us hit = (player.get_hp() / 5) + rand() % (player.get_hp() / 5);
				cout << "Hp: -" << hit << "hp" << endl;
				player.get_hp() -= hit;
				if (player.get_hp() <= 0) {
					endofgame = true;
				}
			}
			else if (alms == 1) {
				cout << "You've got a hit!" << endl;
				us hit = (player.get_hp() / 5) + rand() % (player.get_hp() / 5);
				cout << "Hp: -" << hit << "hp" << endl;
				player.get_hp() -= hit;
				if (player.get_hp() <= 0) {
					endofgame = true;
				}
			}
			else if (alms == 2) {
				cout << "Go away dirty bum! " << endl;
			}
			else if (alms == 3) {
				cout << "Kind human pity you." << endl;
				float money;
				float a, b;
				a = rand() % 1;
				b = rand() % 100 + 1;
				money = a + (b / 100);
				cout << "Money: " << money << endl;
				player.get_money() += money;
			}

			loading_short();

		}
		else {
			player.get_food() -= 10;
			break;
		}

		if (player.get_food() <= 0) {
			player.get_money() -= 1;
			cout << "You have no food to continue (-1$)" << endl;
			system("pause");
			BumShop(player);
		}

	}

}
void location_1(homeless& player, bool &endofgame, bool &is_location_1) {


	if (is_location_1) {
		cout << "You have already occuped Boyarka !" << endl;
		system("pause");
	}
	else if (!is_location_1) {

		enemy *foe = null;

		system("cls");
		cout << "You came to Boyarka, this is district of dislike" << endl;
		cout << "That's why you have to show your bum muscles !" << endl;
		system("pause");
		system("cls");

		cout << "Do you think this birds come with peace?" << endl;
		system("pause");
		system("cls");

		for (us i = 0; i < 3; i++) {

			PlaySound(TEXT("D:\\hl\\alllocation.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (i != 1)
				cout << "Next one" << endl;
			loading_mid();
			foe = new bird(player);
			location_battle(player, foe, endofgame);
		}

		system("cls");
		cout << "Doesn't matter like you dogs or not, They does't like you!" << endl;
		system("pause");
		system("cls");

		for (us i = 0; i < 2; i++) {

			PlaySound(TEXT("D:\\hl\\alllocation.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (i != 1)
				cout << "Next one" << endl;
			loading_mid();
			foe = new dog(player);
			location_battle(player, foe, endofgame);
		}

		system("cls");
		cout << "Couple bums are looking at you be careful!" << endl;
		system("pause");
		system("cls");

		PlaySound(TEXT("D:\\hl\\alllocation.wav"), NULL, SND_FILENAME | SND_ASYNC);


		cout << "There's one" << endl;
		loading_mid();
		foe = new bum(player);
		location_battle(player, foe, endofgame);


		if (player.get_hp() > 0) {
			system("cls");
			cout << "Congratulations, you occupied, the Boyarka!" << endl;
			is_location_1 = true;
			system("pause");

			PlaySound(TEXT("D:\\hl\\win.wav"), NULL, SND_FILENAME | SND_ASYNC);

		}
	}

}
void location_2(homeless& player, bool &endofgame, bool &is_location_2) {

	enemy *foe = null;

	if (is_location_2) {
		cout << "You have already occuped Pivnichnyy !" << endl;
		system("pause");
	}
	else if (!is_location_2) {

		system("cls");
		cout << "You came to Pivnichnyy, \nThere are a lot of strange creatures!";
		system("pause");

		system("cls");
		cout << "All here is strange like this birds!" << endl;
		system("pause");
		system("cls");

		for (us i = 0; i < 4; i++) {

			PlaySound(TEXT("D:\\hl\\alllocation.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (i != 1)
				cout << "Next one" << endl;
			loading_mid();
			foe = new bird(player);
			location_battle(player, foe, endofgame);
		}

		system("cls");
		cout << "And this dogs!" << endl;
		system("pause");
		system("cls");

		for (us i = 0; i < 3; i++) {

			PlaySound(TEXT("D:\\hl\\alllocation.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (i != 1)
				cout << "Next one" << endl;
			loading_mid();
			foe = new dog(player);
			location_battle(player, foe, endofgame);
		}

		system("cls");
		cout << "And this smells bums!" << endl;
		system("pause");
		system("cls");

		for (us i = 0; i < 1; i++) {

			PlaySound(TEXT("D:\\hl\\alllocation.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (i != 1)
				cout << "Next one" << endl;
			loading_mid();
			foe = new bum(player);
			location_battle(player, foe, endofgame);
		}

		if (player.get_hp() > 0) {

			PlaySound(TEXT("D:\\hl\\win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			system("cls");
			cout << "Congratulations, you occupied, the Pivnichnyy!" << endl;
			is_location_2 = true;
			system("pause");
		}
	}
}
void location_3(homeless& player, bool &endofgame, bool &is_location_3) {

	if (is_location_3) {
		cout << "You have already occuped Yubileynyy !" << endl;
		system("pause");
	}
	else if (!is_location_3) {

		enemy *foe = null;

		system("cls");
		cout << "You came to Yubileynyy, and you have to fight till the end!";
		cout << "You win and you will have all, or you just die like a simple bum!";
		system("pause");

		system("cls");
		cout << "Look out! This birds are going to hurt you!" << endl;
		system("pause");
		system("cls");

		for (us i = 0; i < 5; i++) {

			PlaySound(TEXT("D:\\hl\\alllocation.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (i != 1)
				cout << "Next one" << endl;
			loading_mid();
			foe = new bird(player);
			location_battle(player, foe, endofgame);
		}

		system("cls");
		cout << "Watch out! Angry dogs is coming!" << endl;
		system("pause");
		system("cls");

		for (us i = 0; i < 4; i++) {

			PlaySound(TEXT("D:\\hl\\alllocation.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (i != 1)
				cout << "Next one" << endl;
			loading_mid();
			foe = new dog(player);
			location_battle(player, foe, endofgame);
		}

		system("cls");
		cout << "This bums wanna be rich and successfully, like you!" << endl;
		cout << "That's why they will beat, like you" << endl;
		system("pause");
		system("cls");

		for (us i = 0; i < 2; i++) {

			PlaySound(TEXT("D:\\hl\\alllocation.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (i != 1)
				cout << "Next one" << endl;
			loading_mid();
			foe = new bum(player);
			location_battle(player, foe, endofgame);
		}

		if (player.get_hp() > 0) {

			PlaySound(TEXT("D:\\hl\\win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			system("cls");
			cout << "Congratulations, you occupied, the Yubileynyy!" << endl;
			is_location_3 = true;
			system("pause");
		}
	}
}
void setcur(int x, int y) {//установка курсора на позицию  x y
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void battleground(homeless& player, bool &endofgame) {

	PlaySound(TEXT("D:\\hl\\pussy.wav"), NULL, SND_FILENAME | SND_ASYNC);

	//create arr
	us x = 15;
	us y = 70;
	us counter = 0;
	bool is_can_attack = false;
	us is_you_can_attack = 0;
	us last_damage = 0;
	us size = 3;
	bool stop = false;
	enemy **foe = new enemy*[size];

	// set player position
	player.set_x(9);
	player.set_y(5);

	foe[0] = new bird(player);
	foe[1] = new dog(player);
	foe[2] = new bum(player);

	//set enemy position

	for (us i = 0; i < size; i++) {

		int randx = 15;
		int randy = 50;

		foe[i]->set_x(randx);
		foe[i]->set_y(randy);
	}

	int presx = 2 + rand() % 15;
	int presy = 2 + rand() % 95;

	bool ispres = false;

	while (!endofgame || !stop) {

		counter++;
		//instead cls
		setcur(null, null);

		//border
		for (int i = 0; i < y; i++)
			cout << "#";
		cout << endl;

		//print
		for (us i = 0; i < x; i++) {
			for (us j = 0; j < y; j++) {

				bool print = false;
				
				if (j == 0 || j == y - 1) {
					cout << '#';
					print = true;
				}
				
					if (player.get_x() == i && player.get_y() == j) {
						cout << 'O';
						print = true;
					}

					if (foe[0]->get_x() == i && foe[0]->get_y() == j && foe[0]->get_hp() > 0) {
						cout << '*';
						print = true;
					}

					if (foe[1]->get_x() == i && foe[1]->get_y() == j && foe[1]->get_hp() > 0) {
						cout << '+';
						print = true;
					}

					if (foe[2]->get_x() == i && foe[2]->get_y() == j && foe[2]->get_hp() > 0) {
						cout << '@';
						print = true;
					}

					if (presx == i && presy == j && ispres) {
						cout << '$';
						print = true;
					}

				if (!print)
					cout << ' ';

			

				if (player.get_x() + 1 == 0) {
					player.get_x()++;
				}
				if (player.get_y() == 0) {
					player.get_y()++;
				}

				if (player.get_x() == x) {
					player.get_x()--;
				}
				if (player.get_y() + 1 == y) {
					player.get_y()--;
				}

			}
			cout << endl;
		}

		//border
		for (us i = 0; i < y; i++)
			cout << "#";
		cout << endl;

		// you move
		if (_kbhit()) {

			char button = _getch();

			if (button == 'a')
				player.get_y()--;

			else if (button == 'd')
				player.get_y()++;

			else if (button == 'w')
				player.get_x()--;

			else if (button == 's')
				player.get_x()++;
			//player attack
			else if (foe[0]->get_y() == player.get_y() && foe[0]->get_x() == player.get_x() && is_you_can_attack > 0 && button == 'j') {
				cout << "\a";
				foe[0]->get_hp() -= player.get_attack() / 2;
				is_you_can_attack--;
			}
			else if (foe[1]->get_y() == player.get_y() && foe[1]->get_x() == player.get_x() && is_you_can_attack > 0 && button == 'j') {
				cout << "\a";
				foe[1]->get_hp() -= player.get_attack() / 2;
				is_you_can_attack--;
			}
			else if (foe[2]->get_y() == player.get_y() && foe[2]->get_x() == player.get_x() && is_you_can_attack > 0 && button == 'j') {
				cout << "\a";
				foe[2]->get_hp() -= player.get_attack() / 2;
				is_you_can_attack--;
			}

			else if (button == 'x') {
				stop = true;
				break;
			}

		}


		// BIRD move
		if (foe[0]->get_hp() > 0) {

			foe[0]->moveto(player, counter, 2);

			// BIRD attack
			if (foe[0]->get_y() == player.get_y() && foe[0]->get_x() == player.get_x() && is_can_attack) {
				cout << "\a";
				player.get_hp() -= foe[0]->get_attack() / 7;
				last_damage = foe[0]->get_attack() / 7;
				is_can_attack = false;
			}
		}
		// DOG attack
		if (foe[1]->get_hp() > 0) {

			foe[1]->moveto(player, counter, 5);

			// DOG attack
			if (foe[1]->get_y() == player.get_y() && foe[1]->get_x() == player.get_x() && is_can_attack) {
				cout << "\a";
				player.get_hp() -= foe[1]->get_attack() / 7;
				last_damage = foe[1]->get_attack() / 7;
				is_can_attack = false;
			}
		}
		// BUM attack
		if (foe[2]->get_hp() > 0) {

			foe[2]->moveto(player, counter, 8);

			// BUM attack
			if (foe[2]->get_y() == player.get_y() && foe[2]->get_x() == player.get_x() && is_can_attack) {
				cout << "\a";
				player.get_hp() -= foe[2]->get_attack() / 7;
				last_damage = foe[2]->get_attack() / 7;
				is_can_attack = false;
			}
		}

		//counter, food--
		if (counter >= 1000) {
			counter = 0;
		}

		// reload for both attack
		if (counter % 50 == 0) {
			player.get_food()--;
			is_you_can_attack++;
		}
		if (counter % 50 == 0) {
			is_can_attack = true;
		}
		
		if (counter % 50 == 0) {
		foe[0]->get_hp() += player.get_attack() / 5;
		foe[1]->get_hp() += player.get_attack() / 7;
		foe[2]->get_hp() += player.get_attack() / 9;
		}
		
		if (player.get_food() <= 0 || player.get_hp() <= 0) {
			endofgame = true;
			break;
		}

		if (player.get_x() == presx && player.get_y() == presy && ispres) {
			cout << "\a";
			us food = rand() % 50 + rand() % 50;
			us pills = rand() % 3 + rand() % 2;
			float money;
			us a = rand() % 3;
			us b = rand() % 100;
			money = a + (b / 100);
			player.get_food() += food;
			player.get_hp() += food / 5;
			player.get_hp() += pills * 10;
			player.get_money() += money;
			ispres = false;
			is_you_can_attack += 10;
		}
		//rand pres
		if (counter % 500 == 0) {
			system("cls");
			presx = 2 + rand() % 10;
			presy = 2 + rand() % 60;
			ispres = true;
		}

		if (foe[0]->get_hp() < 0 && foe[1]->get_hp() < 0 && foe[2]->get_hp() < 0) {
			system("cls");
			cout << "Fuck, what is this?!" << endl;
			cout << "Is it dog?" << endl;
			cout << "Is it dirty bum?" << endl;
			cout << "Is it your shit?" << endl;
			cout << "NO U BLIND IDIOTS !1!!!1" << endl;
			cout << "This is fucking alians, here, lets go in space ship!" << endl;
			cout << "Hey you, you looks like a rich man, you'll be our captain!" << endl;
			us choise;
			cout << "1. You have no choise" << endl;
			cout << "2. Make this shit fly" << endl;
			input(choise);
			if (choise == 2) {
				lastbattle(player, endofgame);
			}
		}

		//you
		cout << "=======================================================" << endl;
		cout << "Last damage: " << last_damage << " | Attack: " << is_you_can_attack << endl;
		cout << "=======================================================" << endl;
		cout << "Hp\t\tAttack\t\tFood\t\tMoney" << endl;
		cout << player.get_hp() << "\t\t";
		cout << player.get_attack() << "\t\t";
		cout << player.get_food() << "\t\t";
		cout << player.get_money() << "$\t\t";
		cout << endl;
		cout << "=======================================================" << endl;
		cout << "Move: w, s, a, d,          Attack: j,          Exit: x" << endl;
		cout << "=======================================================" << endl;

	}//while

	for (us i = 0; i < 3; i++) {
		delete foe[i];
	}
	delete[] foe;
}
void lastbattle(homeless& player, bool &endofgame) {

	system("cls");

	PlaySound(TEXT("D:\\hl\\mann.wav"), NULL, SND_FILENAME | SND_ASYNC);

	us x = 15;
	us y = 70;
	us counter = 0;
	us is_you_can_attack = 0;
	bool is_can_attack = false;
	bool is_can_fire = false;
	int last_damage = 0;
	us bulletcounter = 0;
	boss foe(player);
	foe.set_hp(1488);
	foe.set_x(7);
	foe.set_y(60);

	player.set_x(7);
	player.set_y(5);

	bullet bul;
	bullet enemybul;

	vector <bullet> byl;
	byl.push_back(bul);
	byl.push_back(bul);
	byl.push_back(bul);

	//cout << byl.size() << endl;
	//system("pause");

	while (!endofgame) {

		setcur(null, null);

		//border
		for (us i = 0; i < y + 1; i++)
			cout << "#";
		cout << endl;
		//print
		for (us i = 0; i < x; i++) {
			for (us j = 0; j < y; j++) {

				bool print = false;

				if (j == 0 || j == y - 1) {
					cout << '#';
				}
					
				if (player.get_x() == i && player.get_y() == j) {
						cout << '>';
						print = true;
				}

				if (foe.get_x() == i && foe.get_y() == j && foe.get_hp() > 0) {
						BLUE;
						cout << '&';
						lightGreyBackground;
						print = true;
				}

				if (byl[bulletcounter].get_x() == i && byl[bulletcounter].get_y() == j && byl[bulletcounter].get_isexist()) {
						YELLOW;
						cout << '-';
						lightGreyBackground;
						print = true;
				}

				if (enemybul.get_x() == i && enemybul.get_y() == j) {
						RED;
						cout << '*';
						lightGreyBackground;
						print = true;
				}

				if (!print)
					cout << ' ';
				
				// go out border check
				if (player.get_x() + 1 == 0) {
					player.get_x()++;
				}
				if (player.get_y() + 1 == 0) {
					player.get_y()++;
				}
				if (player.get_x() == x) {
					player.get_x()--;
				}
				if (player.get_y() + 1 == y) {
					player.get_y()--;
				}

			}
			cout << endl;
		}
		//border
		for (us i = 0; i < y + 1; i++)
			cout << "#";
		cout << endl;

		// you move
		if (_kbhit()) {

			char button = _getch();

			if (button == 'a')
				player.get_y()--;

			else if (button == 'd')
				player.get_y()++;

			else if (button == 'w')
				player.get_x()--;

			else if (button == 's')
				player.get_x()++;

			else if (button == 'j') {
				try {
					byl[bulletcounter].set_isexist(true);
					byl[bulletcounter].set_x(player.get_x());
					byl[bulletcounter].set_y(player.get_y());
					bulletcounter++;
					if (bulletcounter >= 2)
						bulletcounter = 0;	
					bulletcounter++;
				}
				catch (...) {
					cout << "unknown eror ";
					system("pause");
				}
			}
		}

		//enemy move
		if (foe.get_hp() > 0) {

			foe.moveto(player, counter, 10);

			if (foe.get_y() == player.get_y() && foe.get_x() == player.get_x() && is_can_attack) {
				cout << "\a";
				player.get_hp() -= foe.get_attack() / 5;
				last_damage = foe.get_attack() / 5;
				is_can_attack = false;
			}
			if (is_can_fire) {
				enemybul.set_x(foe.get_x());
				enemybul.set_y(foe.get_y());
				is_can_fire = false;
			}

		}
		// enemy bullet move
		if (enemybul.get_x() > player.get_x() && counter % 5 == 0) {
			enemybul.get_x()--;
		}
		if (enemybul.get_x() < player.get_x() && counter % 5 == 0) {
			enemybul.get_x()++;
		}
		if (enemybul.get_y() > player.get_y()) {
			enemybul.get_y()--;
		}
		if (enemybul.get_y() < player.get_y()) {
			enemybul.get_y()++;
		}

		// your bullet move
		byl[bulletcounter].get_y()++;

		//bullet check
	//	for (us i = 0; i < byl.size(); i++) {
			if (byl[bulletcounter].get_x() == foe.get_x() && byl[bulletcounter].get_y() == foe.get_y() && byl[bulletcounter].get_isexist()) {
				foe.get_hp() -= player.get_attack() - rand() % 25;
				cout << "\a";
			}
	//	}
		if (enemybul.get_x() == player.get_x() && enemybul.get_y() == player.get_y() && is_can_attack) {
			cout << "\a";
			int dam = rand() % 5 + 5;
			player.get_hp() -= dam;
			last_damage = dam;
			is_can_attack = false;
		}

		counter++;
		if (counter >= 1000) {
			counter = 0;
		}

		if (counter % 250 == 0) {
			system("cls");
		}
		//let enemy attack
		if (counter % 25 == 0) {
			player.get_food() -= 3;
			is_can_attack = true;
			is_can_fire = true;
		}
		//if player die
		if (player.get_hp() <= 0 || player.get_food() <= 0) {
			endofgame = true;
			break;
		}
		//win
		if (foe.get_hp() <= 0) {
			system("cls");
			PlaySound(TEXT("D:\\hl\\win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			cout << "==========================================================" << endl;
			cout << "\t\t <(Homko speech)>" << endl;
			cout << "\tYou see that guy?" << endl;
			cout << "\tHe just wanted to become one of top bum of Rivne" << endl;
			cout << "\tDo you see what it turned into??" << endl;
			cout << "\tAnyway, he is a hero!!" << endl;
			cout << "\tI wish it would never happen again!" << endl;
			cout << "\tWhat can you say?" << endl;
			cout << "==========================================================" << endl;
			us choise;
			cout << "1. What??" << endl;
			cout << "2. I will protect our city till I die" << endl;
			cout << "3. OH, thank for all of it, but I'm going down" << endl;
			cout << "==========================================================" << endl;
			input(choise);
			if (choise == 2) {
				break;
			}
			else if (choise == 3) {
				cout << "Congratulations, you complite this stupid game for whole 100%" << endl;
				system("pause");
				info();
				break;
			}
		}

		//you
		cout << "=======================================================" << endl;
		cout << "Last damage: " << last_damage << " | Enemy hp: " << foe.get_hp() << endl;
		cout << "=======================================================" << endl;
		cout << "Hp\t\tAttack\t\tFood\t\tMoney" << endl;
		cout << player.get_hp() << "\t\t";
		cout << player.get_attack() << "\t\t";
		cout << player.get_food() << "\t\t";
		cout << player.get_money() << "$\t\t";
		cout << endl;
		cout << "=======================================================" << endl;
		cout << " Move: w, s, a, d,                             Fire: j," << endl;
		cout << "=======================================================" << endl;

	}//while
}