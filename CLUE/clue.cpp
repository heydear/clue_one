#include "game.h"
#include "show.h"

int main() {
	int menu, result = 0;
	system("mode con lines=35 cols=100"); // ȭ�� ũ�� ����

	showDisplay(); // �ʱ� UI(ȭ�鱸��) ����

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
			cout << "������ �����մϴ�.";
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
			cout << "�߸��� �Է��Դϴ�.";
			gotoxy(39, 15);
			cout << "�ٽ� �Է��ϼ���.";
			gotoxy(36, 17);
			cout << "(�ƹ� Ű�� ��������.)";

			_getch();
		}
	}

	return 0;
}