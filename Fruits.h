//#pragma once

#include <iostream>
#include <cstdlib>
#include <conio.h>


class Fruits
{
private:
	int positionX;
	int positionY;
	int growth;
	char symbol;


public:

	Fruits() {
		positionX = rand() % 30;
		positionY = rand() % 30;
		growth = 1;
		symbol = 70;
	}

	void setPositionX(int positionX) {
		this->positionX = positionX;
	}
	int getPositionX() {
		return positionX;
	}
	void setPositionY(int positionY) {
		this->positionY = positionY;
	}
	int getPositionY() {
		return positionY;
	}
	void setGrowth(int growth) {
		this->growth = growth;
	}
	int getGrowth() {
		return growth;
	}
	void setSymbol(char symbol) {
		this->symbol = symbol;
	}
	char getSymbol() {
		return symbol;
	}


	virtual void valueOfFruit() = 0;
	virtual void valueOfSymbol() = 0;
};

class Apple : public Fruits {
public:

	Apple() {


		setPositionX(rand() % 30);
		setPositionY(rand() % 30);
		setSymbol(227);
		setGrowth(1);
	}

	void valueOfFruit() {
		setGrowth(1);
	}
	void valueOfSymbol() {
		setSymbol(227);
	}

};

/*
class Pear : public Fruits {
public:

	Pear() {


		setPositionX(rand() % 30);
		setPositionY(rand() % 30);
		setSymbol(234);
		setGrowth(2);
	}

	void valueOfFruit() {
		setGrowth(2);
	}
	void valueOfSymbol() {
		setSymbol(234);
	}
};
*/

