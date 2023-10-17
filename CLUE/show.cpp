#include "show.h"

void showDisplay() {
	showSquare(0,0);
	showBoard(28,0);
	showSquare(68, 0);
	showCards(16, 23);
}

void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void showMenu(int x, int y) {
	showMenuSquare(28, 11);

	gotoxy(x, y++);
	cout << "������������������  ���Ӹ޴� ����������������";
	gotoxy(x, y++);
	cout << "�� �� ���ӽ��� (1)          ��";
	gotoxy(x, y++);
	cout << "�� �� ���ӹ�� (2)          ��";
	gotoxy(x, y++);
	cout << "�� �� �������� (3)          ��";
	gotoxy(x, y++);
	cout << "��������������������������������������������������������";
	gotoxy(x, y++);
	cout << "�� ";
}

void showGameMenu(bool flag, int x, int y) {
	showMenuSquare(28, 11);

	gotoxy(x, y++);
	cout << "����������������������������������������������������" << endl;
	gotoxy(x, y++);
	cout << "���� �ֻ��� ������ (1)      ��" << endl;
	if (flag) {
		gotoxy(x, y++);
		cout << "���� �߸��ϱ� (2)           ��" << endl;
	}
	gotoxy(x, y++);
	cout << "���� Ȩ���� ���ư��� (3)    ��" << endl;
	gotoxy(x, y++);
	cout << "����������������������������������������������������" << endl;
	gotoxy(x, y++);
	cout << "�� ";
}

void showBoard(int x, int y) {
	gotoxy(x, y++);
	cout << "����������������������������������������������������������������������������" << endl;
	gotoxy(x, y++);
	cout << "�� �ֹ�   ��     ����ȸ��    ��   �½�  ��" << endl;
	gotoxy(x, y++);
	cout << "��        ��                 ��         ��" << endl;
	gotoxy(x, y++);
	cout << "����������������������������������������������������������������������������" << endl;
	gotoxy(x, y++);
	cout << "��        ��                ��  �籸��  ��" << endl;
	gotoxy(x, y++);
	cout << "�� �Ĵ�   ��       CLUE     ��          ��" << endl;
	gotoxy(x, y++);
	cout << "��        ��                ������������������������" << endl;
	gotoxy(x, y++);
	cout << "����������������������                ��   ����  ��" << endl;
	gotoxy(x, y++);
	cout << "��         ��������������������������������������������������������" << endl;
	gotoxy(x, y++);
	cout << "�� �����  ��      Ȧ       ��   ���ι� ��" << endl;
	gotoxy(x, y++);
	cout << "����������������������������������������������������������������������������" << endl;
}

void showCards(int x, int y) {
	showCardsSquare(0, 21);

	gotoxy(x, y++);
	cout << "�� ������ ��" << endl;
	gotoxy(x, y++);
	cout << "�� ȭ��Ʈ, �÷�, �ӽ��͵�, ����, �׸�, ��Į��" << endl;
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "�� ������� ��" << endl;
	gotoxy(x, y++);
	cout << "�� �����, Ȧ, �籸��, ����ȸ��, �Ĵ�, �ֹ�, �½�, ����, ���ι�" << endl;
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "�� ���൵�� ��" << endl;
	gotoxy(x, y++);
	cout << "�� �д�, ������, ����, ������, ������, ��ġ" << endl;
	gotoxy(x, y++);
}

void showPlace(int x, int y) {
	showMenuSquare(28, 11);

	gotoxy(x, y++);
	cout << "�������������̵��ϱ⦡��������";
	gotoxy(x, y++);
	cout << "����                        ��";
	gotoxy(x, y++);
	cout << "������������������������������";
	gotoxy(x - 3, y++);
	cout << "(�̵��� ��Ҹ� �Է��ϼ���)";

	/*gotoxy(x, y++);
	cout << "�������������̵��ϱ⦡��������";
	gotoxy(x, y++);
	cout << "���� CLUE (0)               ��";
	gotoxy(x, y++);
	cout << "���� �ֹ� (1)               ��";
	gotoxy(x, y++);
	cout << "���� ����ȸ�� (2)           ��";
	gotoxy(x, y++);
	cout << "������������������������������";
	gotoxy(x-3, y++);
	cout << "(�ƹ� Ű�� ���� ���� �������� �̵�)";

	_getch();

	showMenuSquare(28, 11);
	y -= 6;

	gotoxy(x, y++);
	cout << "�������������̵��ϱ⦡��������";
	gotoxy(x, y++);
	cout << "���� �½� (3)               ��";
	gotoxy(x, y++);
	cout << "���� �Ĵ� (4)               ��";
	gotoxy(x, y++);
	cout << "���� �籸�� (5)             ��";
	gotoxy(x, y++);
	cout << "������������������������������";
	gotoxy(x-3, y++);
	cout << "(�ƹ� Ű�� ���� ���� �������� �̵�)";

	_getch();

	showMenuSquare(28, 11);
	y -= 6;

	gotoxy(x, y++);
	cout << "�������������̵��ϱ⦡��������";
	gotoxy(x, y++);
	cout << "���� ���� (6)               ��";
	gotoxy(x, y++);
	cout << "���� ����� (7)             ��";
	gotoxy(x, y++);
	cout << "���� Ȧ (8)                 ��";
	gotoxy(x, y++);
	cout << "������������������������������";
	gotoxy(x-3, y++);
	cout << "(�ƹ� Ű�� ���� ���� �������� �̵�)";

	_getch();

	showMenuSquare(28, 11);
	y -= 6;

	gotoxy(x, y++);
	cout << "�������������̵��ϱ⦡��������";
	gotoxy(x, y++);
	cout << "���� ���ι� (9)             ��";
	gotoxy(x, y++);
	cout << "������������������������������";
	gotoxy(x, y++);
	cout << "�� ";*/
}

void showHowToPlay(int x, int y) {
	showCardsSquare(0, 21);

	gotoxy(x, y++);
	cout << "== ���Ӽ��� ==";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "����� �ǹ��� �︸���ڿ��� �ʴ�Ǿ����ϴ�.";
	gotoxy(x, y++);
	cout << "��Ǭ ������ ���� ���� ������ �湮������, �������� �︸���ڴ� ��� ���صǾ����ϴ�.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "�����ڴ� ����� ������ �� 6��, �ǽɵǴ� ���൵���� �� 6��, �ǽɵǴ� ������Ҵ� �� 9��.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "����� �߸��� ���� ���� �����̰�, � ������ ����Ͽ� ��� �����ߴ��� �˾Ƴ��� �մϴ�.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "(�ƹ� Ű�� ������ ���� �������� �Ѿ�ϴ�...)";

	y -= 10;

	_getch();

	showCardsSquare(0, 21);

	gotoxy(x, y++);
	cout << "== �ι��Ұ� ==";
	gotoxy(x, y++);
	cout << "[�̽� ��Į��], [�ӽ��͵� ���], [ȭ��Ʈ ����], [�׸� �ź�], [���� ����], [�÷� ����]";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "== ���൵�� ==";
	gotoxy(x, y++);
	cout << "[����], [�д�], [������], [������], [������], [��ġ]";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "== ������� ==";
	gotoxy(x, y++);
	cout << "[�����], [Ȧ], [���ι�], [����], [�籸��], [�½�], [����ȸ��], [�ֹ�], [�Ĵ�]";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "(�ƹ� Ű�� ������ ���� �������� �Ѿ�ϴ�...)";

	y -= 10;

	_getch();

	showCardsSquare(0, 21);

	gotoxy(x, y++);
	cout << "== ���ӹ�� ==";
	gotoxy(x, y++);
	cout << "������ �����ϸ� �������� ���ΰ� ���൵��, ������Ұ� ���õ˴ϴ�.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "������ ���� �� 6���� ī�带 �޽��ϴ�.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "������ ������ �ִ� ī�峪 ������ ī��� ����ī�尡 �� �� �����Ƿ�";
	gotoxy(x, y++);
	cout << "������ �ڽ��� ������ ���� ���� ī��� �߸��ذ��� �մϴ�.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "(�ƹ� Ű�� ������ ���� ���������� �Ѿ�ϴ�...)";
	
	y -= 9;

	_getch();

	showCardsSquare(0, 21);

	gotoxy(x, y++);
	cout << "== ���ӹ�� ==";
	gotoxy(x, y++);
	cout << "�ֻ����� ���� ��ҿ� �����ϸ� �߸��� ������ �� �ֽ��ϴ�.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "�����ڸ� ��ȯ�Ͽ� ���൵���� ������Ҹ� �߸��� ���,";
	gotoxy(x, y++);
	cout << "������ �����ʿ� �ִ� �÷��̾�� ������ �߸��� ī�尡 �ִٸ� �� ���� �����մϴ�.";
	gotoxy(x, y++);
	cout << "���� ī�尡 ���� ��� �� �����ʿ� �ִ� �÷��̾ ī�� �� ���� �����մϴ�.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "(�ƹ� Ű�� ������ Ȩ���� ���ư��ϴ�...)";

	_getch();

	showCardsSquare(0, 21);
	showCards(16, 23);
}

void showMenuSquare(int x, int y) {
	drawLine(x, y, 36, 8);
}

void showCardsSquare(int x, int y) {
	drawLine(x, y, 92, 11);
}

void showSquare(int x, int y) {
	drawLine(x, y, 24, 19);
}

void drawLine(int x, int y, int width, int line) {
	gotoxy(x, y++);
	cout << "��";
	for (int i = 0; i < width; i++) cout << "��";
	cout << "��" << endl;

	for (int l = 0; l < line; l++) {
		gotoxy(x, y++);
		cout << "��";
		for (int i = 0; i < width; i++) cout << " ";
		cout << "��" << endl;
	}

	gotoxy(x, y++);
	cout << "��";
	for (int i = 0; i < width; i++) cout << "��";
	cout << "��" << endl;
}