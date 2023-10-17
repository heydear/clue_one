#include "game.h"
#include "show.h"

int main() {
	int menu, result = 0;
	system("mode con lines=35 cols=100"); // 화면 크기 설정

	showDisplay(); // 초기 UI(화면구성) 설정

	while (true) {
		if (result != 1 && result != 3) {
			showMenu(33, 13);
			gotoxy(36, 18);
			menu = _getch() - '0';
		}

		if (menu == 3) {
			showMenu(33, 13);
			showCardsSquare(0, 21);
			gotoxy(3, 22);
			cout << "게임을 종료합니다.";
			gotoxy(3, 23);
			break;
		}

		switch (menu) {
		case 1:
			result = gameSetting();
			if (result == 1) menu = 1;
			else if (result == 3) menu = 3;
			break;
		case 2:
			showHowToPlay(3, 22); break;
		default:
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

	return 0;
}