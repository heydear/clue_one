#include "game.h"
#include "show.h"

string criminal[3];
string cards[18];

PLAYER user("USER");
PLAYER com1("LEFT");
PLAYER com2("RIGHT");



int gameSetting() {
	int check = 0;

	selectCriminal(); // 범인, 범행장소, 범행도구 선택

	showCardsSquare(0, 21);

	gotoxy(3, 23);
	cout << "카드를 지급합니다...";

	cardShuffle();
	
	for (int i = 0; i < CARDS_COUNT - 3; i += 3) {
		user.initCards(::cards[i]);
		com1.initCards(::cards[i + 1]);
		com2.initCards(::cards[i + 2]);
	}

	showSquare(68, 0);
	user.getCards(true, 68, 0);
	showSquare(0, 0);
	com1.getCards(false, 0, 0);
	com2.getCards(false, 0, 10);

	gotoxy(3, 24);
	cout << "6개의 카드가 제공되었습니다. 이제 추리를 시작해보세요!";
	gotoxy(3, 26);
	cout << "(아무 키나 누르면 다음으로 넘어갑니다..)";

	_getch();

	showCards(16, 23);

	check = gameStart();

	user.setInstance();
	com1.setInstance();
	com2.setInstance();

	showSquare(0, 0);
	showSquare(68, 0);

	return check;
}

int gameStart() {
	int check = 0, menu, count = 0;
	bool flag = true;

	while (true) {
		if (user.getDice() == 0)
			showGameMenu(true, 33, 13);
		else
			showGameMenu(false, 33, 13);
		menu = _getch() - '0';

		if (menu == 3) break;
		else if (menu == 1) {
			count++;

			user >> moving();

			user.showXY();

			gotoxy(72, 13);
			cout << "도착까지 남은 주사위";
			gotoxy(72, 14);
			cout << "[" << user.getDice() << "]";

			if (user.getXY() == 10)
				flag = false;
		}
		else if (menu == 2 && user.getDice() == 0) {
			count++;

			check = checkCriminal(flag);
			user.setDice(-1);
		}
		else {
			showMenuSquare(28, 11);
			gotoxy(38, 14);
			cout << "잘못된 입력입니다.";
			gotoxy(39, 15);
			cout << "다시 입력하세요.";
			gotoxy(36, 17);
			cout << "(아무 키나 누르세요.)";

			// 사용자의 반응을 체크하기 위한 용도
			_getch();
		}

		if (check == 1 || check == 3) break;

		if (count >= 1 && user.getDice() != 0) {
			randMove(&com1);
			if (com1.getDice() == -1)
				check = randCard(&com1, &com2, &user);

			if (check == 1 || check == 3) break;

			randMove(&com2);
			if (com2.getDice() == -1)
				check = randCard(&com2, &com1, &user);

			if (check == 1 || check == 3) break;
		}
		count = 0;

		showCards(16, 23);
	}

	return check;
}

void cardShuffle() {
	int count = 0;

	for (int i = 0; i < CARDS_COUNT; i++)
	{
		if (i < PLACE_COUNT) {
			if (!criminal[0].compare(PLACE[i]))
				continue;

			::cards[count] = PLACE[i];
		}
		else if (i < PLACE_COUNT + CHARACTER_COUNT) {
			if (!criminal[1].compare(CHARACTER[i - PLACE_COUNT]))
				continue;

			::cards[count] = CHARACTER[i - PLACE_COUNT];
		}
		else {
			if (!criminal[2].compare(WEAPON[i - PLACE_COUNT - CHARACTER_COUNT]))
				continue;

			::cards[count] = WEAPON[i - PLACE_COUNT - CHARACTER_COUNT];
		}

		count++;
	}

	srand((unsigned int)time(0));
	int rn;
	int shuffleCardsCount = CARDS_COUNT - 3;
	string temp;
	for (int i = 0; i < shuffleCardsCount - 1; i++) {
		rn = myRand(shuffleCardsCount - i) + i;
		temp = ::cards[i];
		::cards[i] = ::cards[rn];
		::cards[rn] = temp;
	}
}

void selectCriminal() {
	srand((unsigned int)time(0));

	criminal[0] = PLACE[myRand(PLACE_COUNT)];
	criminal[1] = CHARACTER[myRand(CHARACTER_COUNT)];
	criminal[2] = WEAPON[myRand(WEAPON_COUNT)];

	showCardsSquare(0, 21);

	gotoxy(3, 23);
	cout << "범인과 범행도구, 범행장소가 무작위로 선택되었습니다.";
	gotoxy(3, 25);
	cout << "(아무 키나 누르면 다음으로 넘어갑니다..)";

	_getch();
}

int checkCriminal(bool flag) {
	char check;
	char place[9], character[9], weapon[9];
	int result = 0, count = 0;

	while (true) {
		showMenuSquare(28, 11);

		gotoxy(34, 13);
		cout << "┌────────────────────────┐";
		gotoxy(34, 14);
		cout << "│▶ 범인 :               │";
		gotoxy(34, 15);
		cout << "│▶ 장소 :               │";
		gotoxy(34, 16);
		cout << "│▶ 무기 :               │";
		gotoxy(34, 17);
		cout << "└────────────────────────┘";

		// 현재 위치한 장소로 자동 입력
		gotoxy(46, 15);
		cout << PLACE[user.getPlace() - 1];

		gotoxy(46, 14);
		scanf("%s", character);

		gotoxy(46, 16);
		scanf("%s", weapon);
		/*if (!strcmp(weapon, ""))
			continue;*/

		if (find(begin(CHARACTER), end(CHARACTER), character) == end(CHARACTER) || find(begin(WEAPON), end(WEAPON), weapon) == end(WEAPON)) {
			showMenuSquare(28, 11);
			gotoxy(38, 14);
			cout << "잘못된 입력입니다.";
			gotoxy(39, 15);
			cout << "다시 입력하세요.";
			gotoxy(36, 16);
			cout << "(아무 키나 누르세요.)";

			_getch();
		}
		else
			break;

		//for (int i = 0; i < 18; i++) { // 유효성 검사
		//	if (!strcmp(CHARACTER[i], character))
		//		count++;
		//	if (!strcmp(WEAPON[i], weapon))
		//		count++;
		//}

		/*if (count != 2) {
			showMenuSquare(28, 11);
			gotoxy(38, 14);
			cout << "잘못된 입력입니다.";
			gotoxy(39, 15);
			cout << "다시 입력하세요.";
			gotoxy(36, 16);
			cout << "(아무 키나 누르세요.)";

			count = 0;

			_getch();
		} else {
			break;
		}*/
	}

	showCardsSquare(0, 21);

	if (user.getPlace() != 0) { // 최종 추리가 아닐 경우
		gotoxy(3, 22);
		cout << "플레이어의 카드 탐색 중...";

		if (com2.checkCards(character, place, weapon, 0, 10)) {
			gotoxy(3, 24);
			cout << "플레이어 [RIGHT] 가 당신에게 카드 한 장을 공개하였습니다.";
		}
		else if (com1.checkCards(character, place, weapon, 0, 0)) {
			gotoxy(3, 24);
			cout << "플레이어 [LEFT] 가 당신에게 카드 한 장을 공개하였습니다.";
		}
		else {
			gotoxy(3, 24);
			cout << "공개된 카드가 없습니다.";
		}

		gotoxy(3, 26);
		cout << "(아무 키나 누르면 메뉴로 돌아갑니다..)";
	}
	else {
		gotoxy(3, 22);
		if (!criminal[0].compare(place) && !criminal[1].compare(character) && !criminal[2].compare(weapon)) {
			cout << "추리에 성공했습니다!!!";
		}
		else {
			cout << "추리에 실패했습니다...";
		}
		gotoxy(3, 24);
		cout << "새로운 게임을 진행하시겠습니까? (Y/N)";

		gotoxy(3, 25);
		while (true) {
			check = _getch();

			switch (toupper(check)) {
			case 'Y':
				result = 1; break;
			case 'N':
				result = 3; break;
			default:
				gotoxy(3, 26);
				cout << "잘못된 입력입니다. 다시 입력하세요.";
				gotoxy(3, 25);
			}

			if (result == 1 || result == 3)
				break;
		}
	}

	_getch();

	return result;
}

int myRand(int m) {
	return (rand() % m);
}

DICE* moving() {
	char menu[9];
	int index = -1;
	int dice = myRand(6) + 1;
	DICE* point = new DICE;

	while (true) {
		showPlace(33, 13);
		gotoxy(36, 14);
		//menu = _getch() - '0';

		scanf("%s", menu);
		if (!strcmp(menu, ""))
			continue;

		// 입력 받은 값이 배열에 있는 값인지 유효성 검사
		/*if (strcmp("CLUE", menu) == 0)
			index = 0;

		for (int i = 0; i < PLACE_COUNT; i++) {
			if (strcmp(PLACE[i], menu) == 0) {
				index = i + 1;

				break;
			}
		}

		if (index < 0) {
			showMenuSquare(28, 11);
			gotoxy(38, 14);
			cout << "잘못된 입력입니다.";
			gotoxy(39, 15);
			cout << "다시 입력하세요.";
			gotoxy(36, 17);
			cout << "(아무 키나 누르세요.)";

			_getch();
		}
		else {
			point = new DICE(PLACE_POS[index]);
			point->setDice(dice);

			break;
		}*/

		auto it = std::find(begin(PLACE), end(PLACE), menu);

		if (!strcmp(menu, "CLUE")) {
			index = 0;
			point = new DICE(PLACE_POS[index]);
			point->setDice(dice);
			break;
		}
		else if (it != end(PLACE)) {
			index = std::distance(PLACE, it) + 1;
			point = new DICE(PLACE_POS[index]);
			point->setDice(dice);
			break;
		}
		else {
			showMenuSquare(28, 11);
			gotoxy(38, 14);
			cout << "잘못된 입력입니다.";
			gotoxy(39, 15);
			cout << "다시 입력하세요.";
			gotoxy(36, 17);
			cout << "(아무 키나 누르세요.)";

			_getch();
		}

		/*try {
			point = new DICE(PLACE_POS[menu]);
			point->setDice(dice);

			break;
		}
		catch (...) {
			showMenuSquare(28, 11);
			gotoxy(38, 14);
			cout << "잘못된 입력입니다.";
			gotoxy(39, 15);
			cout << "다시 입력하세요.";
			gotoxy(36, 17);
			cout << "(아무 키나 누르세요.)";

			_getch();
		}*/

		/*if (menu == 0) {
			point = new DICE(5, 5);
			point->setDice(dice); break;
		}
		else if (menu == 1) {
			point = new DICE(2, 9);
			point->setDice(dice); break;
		}
		else if (menu == 2) {
			point = new DICE(5, 8);
			point->setDice(dice); break;
		}
		else if (menu == 3) {
			point = new DICE(8, 9);
			point->setDice(dice); break;
		}
		else if (menu == 4) {
			point = new DICE(2, 6);
			point->setDice(dice); break;
		}
		else if (menu == 5) {
			point = new DICE(7, 6);
			point->setDice(dice); break;
		}
		else if (menu == 6) {
			point = new DICE(9, 4);
			point->setDice(dice); break;
		}
		else if (menu == 7) {
			point = new DICE(1, 3);
			point->setDice(dice); break;
		}
		else if (menu == 8) {
			point = new DICE(4, 2);
			point->setDice(dice); break;
		}
		else if (menu == 9) {
			point = new DICE(8, 1);
			point->setDice(dice); break;
		}
		else {
			showMenuSquare(28, 11);
			gotoxy(38, 14);
			cout << "잘못된 입력입니다.";
			gotoxy(39, 15);
			cout << "다시 입력하세요.";
			gotoxy(36, 17);
			cout << "(아무 키나 누르세요.)";

			_getch();
		}*/
	}

	user.setPlace(index);

	showCardsSquare(0, 21);

	gotoxy(3, 22);
	if (index == 0)
		cout << "[CLUE] (으)로 이동합니다.";
	else
		cout << "[" << PLACE[index - 1] << "] (으)로 이동합니다.";

	gotoxy(3, 24);
	cout << "주사위를 굴립니다...";

	gotoxy(3, 25);
	cout << "[" << dice << "] 이(가) 나왔습니다.";

	gotoxy(3, 27);
	cout << "(아무 키나 누르면 메뉴로 돌아갑니다..)";

	_getch();

	return point;
}

void randMove(PLAYER* com) {
	int check = 0;
	int menu = 0;
	int dice = myRand(6) + 1;
	DICE* point = new DICE;

	while (com->getDice() == -1) {
		menu = myRand(9) + 1;

		for (int i = 0; i < com->getCount(); i++) {
			if (!PLACE[menu - 1].compare(com->getCard(i)))
				continue;
		}

		point = new DICE(PLACE_POS[menu]);

		/*if (menu == 1) {
			point = new DICE(2, 9);
		}
		else if (menu == 2) {
			point = new DICE(5, 8);
		}
		else if (menu == 3) {
			point = new DICE(8, 9);
		}
		else if (menu == 4) {
			point = new DICE(2, 6);
		}
		else if (menu == 5) {
			point = new DICE(7, 6);
		}
		else if (menu == 6) {
			point = new DICE(9, 4);
		}
		else if (menu == 7) {
			point = new DICE(1, 3);
		}
		else if (menu == 8) {
			point = new DICE(4, 2);
		}
		else if (menu == 9) {
			point = new DICE(8, 1);
		}*/

		if (abs(com->getXY() - point->getXY()) <= 10) {
			com->operator>>(point);
			com->setPlace(menu);
			break;
		}
	}

	// 모든 카드를 획득했을 경우 추리장소로 이동
	if (com->getCount() >= 15) {
		point = new DICE(PLACE_POS[0]);
		com->operator>>(point);
		com->setPlace(0);
	}

	com->setDice(com->getDice() - dice);

	showCardsSquare(0, 21);

	gotoxy(3, 22);
	cout << "플레이어 [" << com->getName() << "] 가 [";

	if (com->getPlace() == 0)
		cout << "CLUE]";
	else
		cout << PLACE[com->getPlace() - 1] << "]";

	if (com->getDice() <= 0) {
		cout << "(으)로 이동했습니다.";
		com->setDice(-1);
	}
	else
		cout << "(으)로 이동 중입니다.";

	gotoxy(3, 24);
	cout << "(아무 키나 누르면 메뉴로 돌아갑니다..)";

	_getch();
}

int randCard(PLAYER* com, PLAYER* com2, PLAYER* user) {
	int check, count = 0, result = 0;
	string cards[3];
	bool flag = true;

	while (count < 1) {
		check = myRand(CHARACTER_COUNT);

		for (int i = 0; i < com->getCount(); i++) {
			if (!CHARACTER[check].compare(com->getCard(i)))
				flag = false;
		}

		if (flag) {
			cards[0] = CHARACTER[check];
			count++;
		}
		else
			flag = true;
	}

	cards[1] = PLACE[com->getPlace() - 1];

	count = 0;
	while (count < 1) {
		check = myRand(WEAPON_COUNT);

		for (int i = 0; i < com->getCount(); i++) {
			if (!WEAPON[check].compare(com->getCard(i)))
				flag = false;
		}

		if (flag) {
			cards[2] = WEAPON[check];
			count++;
		}
		else
			flag = true;
	}

	showCardsSquare(0, 21);

	gotoxy(3, 22);
	cout << "플레이어 [" << com->getName() << "] 가";
	gotoxy(3, 23);
	cout << "[" << cards[0] << "]";
	gotoxy(3, 24);
	cout << "[" << cards[1] << "]";
	gotoxy(3, 25);
	cout << "[" << cards[2] << "]";
	gotoxy(3, 26);
	cout << "카드를 추리하였습니다.";

	gotoxy(3, 28);
	cout << "(아무 키나 누르면 다음으로 넘어갑니다..)";

	_getch();

	showCardsSquare(0, 21);

	if (com->getPlace() == 0) {
		gotoxy(3, 22);
		if (!criminal[0].compare(cards[1]) && !criminal[1].compare(cards[0]) && !criminal[2].compare(cards[2])) {
			cout << "추리에 성공했습니다!!!";

			gotoxy(3, 24);
			cout << "새로운 게임을 진행하시겠습니까? (Y/N)";

			gotoxy(3, 25);
			while (true) {
				check = _getch();

				switch (toupper(check)) {
				case 'Y':
					result = 1; break;
				case 'N':
					result = 3; break;
				default:
					gotoxy(3, 26);
					cout << "잘못된 입력입니다. 다시 입력하세요.";
					gotoxy(3, 25);
				}

				if (result == 1 || result == 3)
					break;
			}
		}
		else {
			cout << "추리에 실패했습니다...";
		}
	}
	else {
		showCardsSquare(0, 21);

		count = 0;
		for (int i = 0; i < com2->getCount(); i++) {
			if (!cards[0].compare(com2->getCard(i))) {
				com->setCard(cards[0]); count++; break;
			}
			else if (!cards[1].compare(com2->getCard(i))) {
				com->setCard(cards[1]); count++; break;
			}
			else if (!cards[2].compare(com2->getCard(i))) {
				com->setCard(cards[2]); count++; break;
			}
		}

		if (count == 0) {
			int y = 13, menu;
			int flag[3] = { -1, -1, -1 };

			for (int i = 0; i < user->getCount(); i++) {
				if (!cards[0].compare(user->getCard(i))) {
					flag[0] = i;
				}
				else if (!cards[1].compare(user->getCard(i))) {
					flag[1] = i;
				}
				else if (!cards[2].compare(user->getCard(i))) {
					flag[2] = i;
				}
			}

			while (true) {
				showMenuSquare(28, 11);

				gotoxy(3, 22);
				cout << "플레이어 [" << com->getName() << "] 에게 공개할 카드를 선택하세요.";

				gotoxy(33, y);
				cout << "┌─────카드공개────┐";
				if (flag[0] != -1) {
					gotoxy(33, ++y);
					cout << "│▶ " << user->getCard(flag[0]) << "(" << flag[0] << ")";
				}
				if (flag[1] != -1) {
					gotoxy(33, ++y);
					cout << "│▶ " << user->getCard(flag[1]) << "(" << flag[1] << ")";
				}
				if (flag[2] != -1) {
					gotoxy(33, ++y);
					cout << "│▶ " << user->getCard(flag[2]) << "(" << flag[2] << ")";
				}
				gotoxy(33, ++y);
				cout << "└─────────────┘";

				gotoxy(33, 18);
				cout << "▶ ";
				menu = _getch() - '0';

				if ((menu == flag[0]) || (menu == flag[1]) || (menu == flag[2]))
					break;
				else {
					showMenuSquare(28, 11);
					gotoxy(38, 14);
					cout << "잘못된 입력입니다.";
					gotoxy(39, 15);
					cout << "다시 입력하세요.";
					gotoxy(36, 17);
					cout << "(아무 키나 누르세요.)";

					_getch();
				}
			}

			com->setCard(user->getCard(menu));

			gotoxy(3, 24);
			cout << "플레이어 [" << com->getName() << "] 에게 [" << user->getCard(menu) << "] 카드를 공개했습니다.";
		}
		else {
			gotoxy(3, 24);
			cout << "플레이어 [" << com2->getName() << "] 가 플레이어 [" << com->getName() << "] 에게 카드 한 장을 공개했습니다.";
		}

		gotoxy(3, 26);
		cout << "(아무 키나 누르면 메뉴로 돌아갑니다..)";
	}

	_getch();

	return result;
}