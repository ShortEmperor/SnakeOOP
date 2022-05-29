#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Map.h"


#pragma once

class Snake
{
private:
	Map map;
	int length;
	int headPositionX;
	int headPositionY;
	int tailX[150];
	int tailY[150];
	double speed;
	bool movement;
	enum sDirection {STOP = 0, LEFT, UP, DOWN, RIGHT};
	char headValue;
	char tailValue;

public:
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
		headPositionX = map.getStartingPointX();
		headPositionY = map.getStartingPointY();
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
				map.setGameOver(true);
				break;
			default:
				break;
			}
		}

	} 

	void applyMovement() {
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
	}
};

