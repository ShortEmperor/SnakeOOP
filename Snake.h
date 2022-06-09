//#pragma once
#include <iostream>
// We'll use cstd* instead of std* because the latter are deprecated
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include "Fruits.h"


class Snake
{
private:
	int length;
	int headPositionX;
	int headPositionY;
	int tailX[150];
	int tailY[150];
	double speed;
	bool movement;
	char headValue;
	char tailValue;
	int mWidth;
	int mHeight;
	bool mGO;

public:
	Apple apples;
	Pear pears;
	enum sDirection {STOP = 0, LEFT, RIGHT, UP, DOWN}; // an enumerator is a distinct type whose value is restricted to a range of values wich may include several explicitly named constants
	sDirection direction;

	// Constructor

	Snake() {
		headPositionX = 15;
		headPositionY = 15;
		speed = 50;
		headValue = 153;
		tailValue = 111;
		mWidth = 30;
		mHeight = 30;
		mGO = false;
		length = 0;
		direction = STOP;
	}

	Snake(int sPX, int sPY, double sp, int mW, int mH) {
		headPositionX = sPX;
		headPositionY = sPY;
		speed = sp;
		headValue = 153;
		tailValue = 111;
		mWidth = mW;
		mHeight = mH;
		mGO = false;
		length = 0;
	}
	
	//Setters and getters
	void setLength(int length) {
		this->length = length;
	}
	int getLength() {
		return length;
	}
	void setHeadPositionX(int headPositionX) {
		this->headPositionX = headPositionX;
	}
	int getHeadPositionX() {
		return headPositionX;
	}
	void setHeadPositionY(int headPositionY) {
		this->headPositionY = headPositionY;
	}
	int getHeadPositionY() {
		return headPositionY;
	}
	int getTailX(int n) {
		return tailX[n];
	}
	int getTailY(int n) {
		return tailY[n];
	}
	void setSpeed(double speed) {
		this->speed = speed;
	}
	double getSpeed() {
		return speed;
	}
	void setMovement(bool movement) {
		this->movement = movement;
	}
	bool getMovement() {
		return movement;
	}
	void setHeadValue(char headValue) {
		this->headValue = headValue;
	}
	char getHeadValue() {
		return headValue;
	}
	void setTailValue(char tailValue) {
		this->tailValue = tailValue;
	}
	char getTailValue() {
		return tailValue;
	}
	void setMWidth(int mWidth) {
		this->mWidth = mWidth;
	}
	int getMWidth() {
		return mWidth;
	}
	void setMHeight(int mHeight) {
		this->mHeight = mHeight;
	}
	int getMHeight() {
		return mHeight;
	}
	void setMGO(bool mGO) {
		this->mGO = mGO;
	}
	bool getMGO() {
		return mGO;
	}

	// Other methods

	// Get user input
	void getMove() {
		if (_kbhit) {
			switch (_getch())
			{
			case 'w':
				direction = UP;
				break;
			case 'a':
				direction = LEFT;
				break;
			case 's':
				direction = DOWN;
				break;
			case 'd':
				direction = RIGHT;
			case 'x':
				mGO = true;
				break;
			default:
				break;
			}

		}
	}

	// Let's use the captured input to actually move the snake
	void applyMovement(){
		/*
		We are goin to use some place-holder varibales to handle the snake's growth
		this are not atributes nor are they going to be used anywhere else in the code.
		*/

		// Handle snake's growth
		int pX = tailX[0];
		int pY = tailY[0];
		int pv2X, pv2Y;

		tailX[0] = headPositionX;
		tailY[0] = headPositionY;

		for (int i = 1; i < length; i++) {
			pv2X = tailX[i];
			pv2Y = tailY[i];
			tailX[i] = pX;
			tailY[i] = pY;
			pX = pv2X;
			pY = pv2Y;
		}

		switch (direction)
		{
		case LEFT:
			headPositionX--;
			break;
		case RIGHT:
			headPositionX++;
			break;
		case UP:
			headPositionY--;
			break;
		case DOWN:
			headPositionY++;
			break;
		default:
			break;
		}

		// Check collisions with frontiers
		if (headPositionX > mWidth || headPositionX < 0 || headPositionY > mHeight || headPositionY < 0)
			mGO = true;

		// Check collisions with itself
		for (int i = 0; i < length; i++)
			if (tailX[i] == headPositionX && tailY[i] == headPositionY)
				mGO = true;

		// Check collisions with fruits

		// Let's do apples first
		if (headPositionX == apples.getPositionX() && headPositionY == apples.getPositionY()) {
			
			apples.setPositionX(rand() % mWidth);
			apples.setPositionY(rand() % mHeight);
			length += apples.getGrowth();
		}

		// Now let's do pears
		if (headPositionX == pears.getPositionX() && headPositionY == pears.getPositionY()) {
			
			pears.setPositionX(rand() % mWidth);
			pears.setPositionY(rand() % mHeight);
			length += pears.getGrowth();
		}


	}


};

