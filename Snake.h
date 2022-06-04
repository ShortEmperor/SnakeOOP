#pragma once

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Map.h"



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

public:
	Map mp();
	enum sDirection { STOP = 0, LEFT, UP, DOWN, RIGHT };
	sDirection direction;


	//Setters and getters
	void setLength(int length) {
		this->length = length;
	}
	int getLength() {
		return length;
	}
	void setHeadPositionX(int x) {
		this->headPositionX = x;
	}
	int getHeadPositionX() {
		return headPositionX;
	}
	void setHeadPositionY(int y) {
		this->headPositionY = y;
	}
	int getHeadPositionY() {
		return headPositionY;
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
	int getTailX(int n) {
		return tailX[n];
	}
	int getTailY(int n) {
		return tailY[n];
	}

	// Constructor

	Snake() {
		headPositionX = mp.getStartingPointX();
		headPositionY = mp.getStartingPointY();
		speed = 10;
		headValue = 153;
		tailValue = 111;

	}

	//Other methods
	void getMove() {

		if (_kbhit) {
			switch (_getch())
			{
			case 'a':
				direction = LEFT;
				break;
			case 'w':
				direction = UP;
				break;
			case 's':
				direction = DOWN;
				break;
			case 'd':
				direction = RIGHT;
				break;
			case 'x':
				mp.setGameOver(true);
				break;
			default:
				break;
			}
		}

	}

	void applyMovement() {

		/*
		We are going to use some place-holder variables to handle snake growth
		this are not attributes nor are they going to be used anywhere else in the code.
		This will be from line 126 to line 142
		*/

		// Handle the growth of the snake

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
		case Snake::LEFT:
			this->headPositionX--;
			break;
		case Snake::UP:
			this->headPositionY--;
			break;
		case Snake::DOWN:
			this->headPositionY++;
			break;
		case Snake::RIGHT:
			this->headPositionX++;
			break;
		default:
			break;
		}

		// Let's check for collisitions with the map
		if (headPositionX >= mp.getWidth() || headPositionX < 0 || headPositionY > mp.getHeight() || headPositionY < 0)
			mp.setGameOver(true);

		// And now for collisitions with itself
		for (int i = 0; i < length; i++)
			if (tailX[i] == headPositionX && tailY[i] == headPositionY)
				mp.setGameOver(true);

		// Check for collitions with the fruits

		// Let's do apples first
		if (headPositionX == mp.apples.getPositionX() && headPositionY == mp.apples.getPositionY()) {
			mp.addToScore(mp.apples.getGrow());
			mp.apples.setPositionX(rand() % mp.getWidth());
			mp.apples.setPositionY(rand() % mp.getHeight());
			length += mp.apples.getGrow();
		}

		// Now let's do pears
		if (headPositionX == mp.pears.getPositionX() && headPositionY == mp.apples.getPositionY()) {
			mp.addToScore(mp.pears.getGrow());
			mp.pears.setPositionX(rand() % mp.getWidth());
			mp.pears.setPositionY(rand() % mp.getHeight());
			length += mp.pears.getGrow();
		}
	}
};
