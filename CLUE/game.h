#include "common.h"

const string CHARACTER[6] = { "그린", "머스터드", "스칼렛", "플럼", "피콕", "화이트" };
const int CHARACTER_COUNT = sizeof(CHARACTER) / sizeof(CHARACTER[0]);
const string PLACE[9] = { "주방", "무도회장", "온실", "식당", "당구장", "서재", "라운지", "홀", "공부방" };
const int PLACE_COUNT = sizeof(PLACE) / sizeof(PLACE[0]);
const string WEAPON[6] = { "나이프", "렌치", "로프", "리볼버", "촛대", "파이프" };
const int WEAPON_COUNT = sizeof(WEAPON) / sizeof(WEAPON[0]);
const int PLACE_POS[10][2] = { {5, 5}, {2, 9}, {5, 8}, {8, 9}, {2, 6}, {7, 6}, {9, 4}, {1, 3}, {4, 2}, {8, 1} };
const int CARDS_COUNT = CHARACTER_COUNT + PLACE_COUNT + WEAPON_COUNT;

class DICE {
protected:
	int x;
	int y;
	int dice;
	int place;

public:
	DICE();
	DICE(int, int);
	DICE(const int[]);

	void operator>>(DICE*);
	void setDice(int);
	int getDice();
	void showXY();
	int getXY();
	int getPlace();
	void setPlace(int);
};

class PLAYER :public DICE {
	char* name;
	string cards[18]; // 플레이어가 소지하고 있는 카드(알리바이)
	int count; // 소지하고 있는 카드 갯수

public:
	PLAYER(char*);
	~PLAYER();

	void getCards(bool, int, int);
	void getCards(int, int, int);
	void initCards(string);
	bool checkCards(char*, char*, char*, int, int);
	void setInstance();
	char* getName();
	int getCount();
	string getCard(int);
	void setCard(string);
};

int gameSetting();
int gameStart();

void selectCriminal();
int checkCriminal(bool flag);
void cardShuffle();

int myRand(int);

DICE* moving();

void randMove(PLAYER*);
int randCard(PLAYER*, PLAYER*, PLAYER*);