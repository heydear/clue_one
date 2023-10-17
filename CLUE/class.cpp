#include "game.h"
#include "show.h"

DICE::DICE() {
	x = 0;
	y = 0;
	dice = 0;
}

DICE::DICE(int x, int y) {
	this->x = x;
	this->y = y;
	dice = 0;
}

DICE::DICE(const int pos[]) {
	this->x = pos[0];
	this->y = pos[1];
	dice = 0;
}

void DICE::setDice(int dice) {
	this->dice = dice;
}

int DICE::getDice() {
	return dice;
}

void DICE::operator>>(DICE* point) {
	if (this->dice <= 0) {
		this->dice = abs(this->x - point->x) + abs(this->y - point->y);
		this->x = point->x;
		this->y = point->y;
	}

	this->dice -= point->dice;

	if (this->dice < 0)
		this->dice = 0;
}

void DICE::showXY() {
	gotoxy(72, 11);
	cout << "                    ";

	gotoxy(72, 11);
	cout << "현재 위치 ";
	if (dice == 0) {
		if (place == 0)
			cout << "[CLUE]";
		else 
			cout << "[" << PLACE[place - 1] << "]";
	}
	else
		cout << "[이동 중]";
}

int DICE::getXY() {
	return x + y;
}

int DICE::getPlace() {
	return place;
}

void DICE::setPlace(int place) {
	this->place = place;
}


PLAYER::PLAYER(char* name) {
	if (!(this->name))
		this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	count = 0;
	x = 5;
	y = 5;
	dice = -1;
}

PLAYER::~PLAYER() {
	if (name)
		delete name;
}

void PLAYER::setInstance() {
	count = 0;

	for (int i = 0; i < 18; i++) {
		cards[i] = "";
	}
}

void PLAYER::initCards(string card) {
	cards[this->count] = card;
	this->count++;
}

void PLAYER::getCards(bool flag, int x, int y) {
	gotoxy(x + 6, y + 1);
	cout << "===== " << name << " =====";

	for (int i = 0; i < count; i++) {
		gotoxy(x + 4, i + y + 3);
		if (flag)
			cout << cards[i];
		else
			cout << "???";
	}

}

void PLAYER::getCards(int index, int x, int y) {
	gotoxy(x + 4, index + y + 3);
	cout << "           ";

	gotoxy(x + 4, index + y + 3);
	cout << cards[index];
}

bool PLAYER::checkCards(char* character, char* place, char* weapon, int x, int y) {
	int i;

	for (i = 0; i < count; i++) {
		if (!cards[i].compare(character) || !cards[i].compare(place) || !cards[i].compare(weapon)) {
			getCards(i, x, y);

			return true;
		}
	}

	return false;
	/*if (i == count)
		return false;
	else
		return true;*/
}

char* PLAYER::getName() {
	return name;
}

int PLAYER::getCount() {
	return count;
}

string PLAYER::getCard(int i) {
	return cards[i];
}

void PLAYER::setCard(string card) {
	cards[count] = card;
	count++;
}