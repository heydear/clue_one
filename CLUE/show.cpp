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
	cout << "┌────────  게임메뉴 ───────┐";
	gotoxy(x, y++);
	cout << "│ ▶ 게임시작 (1)          │";
	gotoxy(x, y++);
	cout << "│ ▶ 게임방법 (2)          │";
	gotoxy(x, y++);
	cout << "│ ▶ 게임종료 (3)          │";
	gotoxy(x, y++);
	cout << "└──────────────────────────┘";
	gotoxy(x, y++);
	cout << "▶ ";
}

void showGameMenu(bool flag, int x, int y) {
	showMenuSquare(28, 11);

	gotoxy(x, y++);
	cout << "┌────────────────────────┐" << endl;
	gotoxy(x, y++);
	cout << "│▶ 주사위 굴리기 (1)      │" << endl;
	if (flag) {
		gotoxy(x, y++);
		cout << "│▶ 추리하기 (2)           │" << endl;
	}
	gotoxy(x, y++);
	cout << "│▶ 홈으로 돌아가기 (3)    │" << endl;
	gotoxy(x, y++);
	cout << "└────────────────────────┘" << endl;
	gotoxy(x, y++);
	cout << "▶ ";
}

void showBoard(int x, int y) {
	gotoxy(x, y++);
	cout << "┌────────┬─────────────────┬─────────┐" << endl;
	gotoxy(x, y++);
	cout << "│ 주방   │     무도회장    │   온실  │" << endl;
	gotoxy(x, y++);
	cout << "│        │                 │         │" << endl;
	gotoxy(x, y++);
	cout << "├────────┼────────────────┬┴─────────┤" << endl;
	gotoxy(x, y++);
	cout << "│        │                │  당구장  │" << endl;
	gotoxy(x, y++);
	cout << "│ 식당   │       CLUE     │          │" << endl;
	gotoxy(x, y++);
	cout << "│        │                └┬─────────┤" << endl;
	gotoxy(x, y++);
	cout << "├────────┴┐                │   서재  │" << endl;
	gotoxy(x, y++);
	cout << "│         ├───────────────┬┴─────────┤" << endl;
	gotoxy(x, y++);
	cout << "│ 라운지  │      홀       │   공부방 │" << endl;
	gotoxy(x, y++);
	cout << "└─────────┴───────────────┴──────────┘" << endl;
}

void showCards(int x, int y) {
	showCardsSquare(0, 21);

	gotoxy(x, y++);
	cout << "※ 용의자 ※" << endl;
	gotoxy(x, y++);
	cout << "▶ 화이트, 플럼, 머스터드, 피콕, 그린, 스칼렛" << endl;
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "※ 범행장소 ※" << endl;
	gotoxy(x, y++);
	cout << "▶ 라운지, 홀, 당구장, 무도회장, 식당, 주방, 온실, 서재, 공부방" << endl;
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "※ 범행도구 ※" << endl;
	gotoxy(x, y++);
	cout << "▶ 촛대, 나이프, 로프, 리볼버, 파이프, 렌치" << endl;
	gotoxy(x, y++);
}

void showPlace(int x, int y) {
	showMenuSquare(28, 11);

	gotoxy(x, y++);
	cout << "┌─────이동하기────┐";
	gotoxy(x, y++);
	cout << "│▶                        │";
	gotoxy(x, y++);
	cout << "└─────────────┘";
	gotoxy(x - 3, y++);
	cout << "(이동할 장소를 입력하세요)";

	/*gotoxy(x, y++);
	cout << "┌─────이동하기────┐";
	gotoxy(x, y++);
	cout << "│▶ CLUE (0)               │";
	gotoxy(x, y++);
	cout << "│▶ 주방 (1)               │";
	gotoxy(x, y++);
	cout << "│▶ 무도회장 (2)           │";
	gotoxy(x, y++);
	cout << "└─────────────┘";
	gotoxy(x-3, y++);
	cout << "(아무 키나 눌러 다음 페이지로 이동)";

	_getch();

	showMenuSquare(28, 11);
	y -= 6;

	gotoxy(x, y++);
	cout << "┌─────이동하기────┐";
	gotoxy(x, y++);
	cout << "│▶ 온실 (3)               │";
	gotoxy(x, y++);
	cout << "│▶ 식당 (4)               │";
	gotoxy(x, y++);
	cout << "│▶ 당구장 (5)             │";
	gotoxy(x, y++);
	cout << "└─────────────┘";
	gotoxy(x-3, y++);
	cout << "(아무 키나 눌러 다음 페이지로 이동)";

	_getch();

	showMenuSquare(28, 11);
	y -= 6;

	gotoxy(x, y++);
	cout << "┌─────이동하기────┐";
	gotoxy(x, y++);
	cout << "│▶ 서재 (6)               │";
	gotoxy(x, y++);
	cout << "│▶ 라운지 (7)             │";
	gotoxy(x, y++);
	cout << "│▶ 홀 (8)                 │";
	gotoxy(x, y++);
	cout << "└─────────────┘";
	gotoxy(x-3, y++);
	cout << "(아무 키나 눌러 다음 페이지로 이동)";

	_getch();

	showMenuSquare(28, 11);
	y -= 6;

	gotoxy(x, y++);
	cout << "┌─────이동하기────┐";
	gotoxy(x, y++);
	cout << "│▶ 공부방 (9)             │";
	gotoxy(x, y++);
	cout << "└─────────────┘";
	gotoxy(x, y++);
	cout << "▶ ";*/
}

void showHowToPlay(int x, int y) {
	showCardsSquare(0, 21);

	gotoxy(x, y++);
	cout << "== 게임설명 ==";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "당신은 의문의 억만장자에게 초대되었습니다.";
	gotoxy(x, y++);
	cout << "부푼 마음을 갖고 그의 저택을 방문했지만, 불행히도 억만장자는 방금 살해되었습니다.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "용의자는 당신을 포함한 총 6명, 의심되는 범행도구는 총 6개, 의심되는 범행장소는 총 9곳.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "당신은 추리를 통해 누가 범인이고, 어떤 도구를 사용하여 어디서 살해했는지 알아내야 합니다.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "(아무 키나 누르면 다음 페이지로 넘어갑니다...)";

	y -= 10;

	_getch();

	showCardsSquare(0, 21);

	gotoxy(x, y++);
	cout << "== 인물소개 ==";
	gotoxy(x, y++);
	cout << "[미스 스칼렛], [머스터드 대령], [화이트 부인], [그린 신부], [피콕 부인], [플럼 교수]";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "== 범행도구 ==";
	gotoxy(x, y++);
	cout << "[로프], [촛대], [파이프], [리볼버], [나이프], [렌치]";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "== 범행장소 ==";
	gotoxy(x, y++);
	cout << "[라운지], [홀], [공부방], [서재], [당구장], [온실], [무도회장], [주방], [식당]";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "(아무 키나 누르면 다음 페이지로 넘어갑니다...)";

	y -= 10;

	_getch();

	showCardsSquare(0, 21);

	gotoxy(x, y++);
	cout << "== 게임방식 ==";
	gotoxy(x, y++);
	cout << "게임이 시작하면 무작위로 범인과 범행도구, 범행장소가 선택됩니다.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "유저는 시작 시 6장의 카드를 받습니다.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "유저가 가지고 있는 카드나 공개된 카드는 범행카드가 될 수 없으므로";
	gotoxy(x, y++);
	cout << "유저는 자신이 가지고 있지 않은 카드로 추리해가야 합니다.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "(아무 키나 누르면 다음 페이지으로 넘어갑니다...)";
	
	y -= 9;

	_getch();

	showCardsSquare(0, 21);

	gotoxy(x, y++);
	cout << "== 게임방식 ==";
	gotoxy(x, y++);
	cout << "주사위를 굴려 장소에 도착하면 추리를 시작할 수 있습니다.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "용의자를 소환하여 범행도구와 범행장소를 추리할 경우,";
	gotoxy(x, y++);
	cout << "유저의 오른쪽에 있는 플레이어에게 유저가 추리한 카드가 있다면 한 장을 공개합니다.";
	gotoxy(x, y++);
	cout << "만약 카드가 없을 경우 그 오른쪽에 있는 플레이어가 카드 한 장을 공개합니다.";
	gotoxy(x, y++);
	cout << endl;
	gotoxy(x, y++);
	cout << "(아무 키나 누르면 홈으로 돌아갑니다...)";

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
	cout << "┌";
	for (int i = 0; i < width; i++) cout << "─";
	cout << "┐" << endl;

	for (int l = 0; l < line; l++) {
		gotoxy(x, y++);
		cout << "│";
		for (int i = 0; i < width; i++) cout << " ";
		cout << "│" << endl;
	}

	gotoxy(x, y++);
	cout << "└";
	for (int i = 0; i < width; i++) cout << "─";
	cout << "┘" << endl;
}