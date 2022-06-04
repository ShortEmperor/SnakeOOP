#pragma once
#include "Barrier.h"
#include <iostream>
#include <Windows.h>
#include "Snake.h"
#include "Fruits.h"



class Map
{
private:
	int width;
	int height;
	double startingPointX;
	double startingPointY;
	bool gameOver;
	int score = 0;

public:
	Barrier bar;
	Snake sk;
	Apple apples;
	Pear pears;

	// Methods
	void setGameOver(bool gameOver) {
		this->gameOver = gameOver;
	}
	bool getGameOver() {
		return gameOver;
	}

	void setWidth(int width) {
		this->width = width;
	}
	int getWidth() {
		return width;
	}
	void setHeight(int height) {
		this->height = height;
	}
	int getHeight() {
		return height;
	}
	void setStartingPointX(double x) {
		this->startingPointX = x;
	}
	double getStartingPointX() {
		return startingPointX;
	}
	void setStartingPointY(double y) {
		this->startingPointY = y;
	}
	double getStartingPointY() {
		return startingPointY;
	}

	void setScore(int score) {
		this->score = score;
	}
	int getScore() {
		return score;
	}

	void addToScore(int points) {
		score += points;
	}


	Map() {
		width = 30;
		height = 30;
		startingPointX = width / 2;
		startingPointY = width / 2;
		gameOver = false;

	}

	void setup() {

	}


	// lets draw the damn map
	void drawMap() {

		system("cls");
		for (int i = 0; i < width + 2; i++)
			std::cout << bar.getValue();

		std::cout << std::endl;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0)
					std::cout << bar.getValue();
				if (i == sk.getHeadPositionY() && j == sk.getHeadPositionX())
					std::cout << sk.getHeadValue();
				else if (i == apples.getPositionY() && j == apples.getPositionX())
					std::cout << apples.getSymbol();
				else if (i == pears.getPositionY() && j == pears.getPositionX())
					std::cout << pears.getSymbol();
				else {
					bool print = false;
					for (int k = 0; k < sk.getLength(); k++) {
						if (sk.getTailY(k) == i && sk.getTailX(k) == j) {
							std::cout << sk.getTailValue();
							print = true;
						}
					}
					if (!print)
						std::cout << " ";
				}
				if (j == width - 1)
					std::cout << bar.getValue();
			}
			std::cout << std::endl;
		}

		for (int i = 0; i < width + 2; i++)
			std::cout << bar.getValue();


		Sleep(10);
	}
};

