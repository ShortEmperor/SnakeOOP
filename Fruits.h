//#pragma once
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Map.h"
class Fruits
{
private:
	int positionX;
	int positionY;
	int grow;
	char symbol;
	Map mp;

public:
	void setPositionX(int x) {
		this->positionX = x;
	}
	int getPositionX() {
		return positionX;
	}
	void setPositionY(int y) {
		this->positionY = y;
	}
	int getPositionY() {
		return positionY;
	}

	void setGrow(int grow) {
		this->grow = grow;
	}
	int getGrow() {
		return grow;
	}
	void setSymbol(char symbol) {
		this->symbol = symbol;
	}
	char getSymbol() {
		return symbol;
	}

	virtual void valueOfFruit() = 0;
	virtual void valueOfSymbol() = 0;

	Fruits() {
		this->positionX = rand() % mp.getWidth();
		this->positionY = rand() % mp.getHeight();
	}
};


class Apple : public Fruits {
public:
	void valueOfFruit() {
		this->setGrow(1);
	}
	void valueOfSymbol() {
		this->setSymbol(227);
	}
};

class Pear : public Fruits {
public:
	void valueOfFruit() {
		this->setGrow(2);
	}
	void valueOfSymbol() {
		this->setSymbol(234);
	}
};
