//#pragma once

#include <iostream>
#include <Windows.h>
#include "Snake.h"

// We will not be using the standard namespace because this way looks cooler

class Map
{
private:
	int width;
	int height;
	int startingPointX;
	int startingPointY;
	bool gameOver;
	int score;
	char barrier;

public:

	// Default (and only) constructor
	Map() {
		// Let's setup this bad boy
		height = 30; // Set the height to 30
		width = 30; // Set the width to 30 

		// Let's make the starting point be in the middle of the board
		startingPointX = width / 2;
		startingPointY = height / 2;

		// And obviusly you can't loose before you even start playing... or can you?
		gameOver = false;

		// Also let's set the character of the barrier, although this can be changed in the menu... hopefully
		barrier = 178;

	}

	Snake sk;

	//Setters and getters
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
	void setStartingPointX(int startingPointX) {
		this->startingPointX = startingPointX;
	}
	int getStartingPointX() {
		return startingPointX;
	}
	void setStartingPointY(int startingPointY) {
		this->startingPointY = startingPointY;
	}
	int getStartingPointY() {
		return startingPointY;
	}
	void setGameOver(bool gameOver) {
		this->gameOver = gameOver;
	}
	bool getGameOver() {
		return gameOver;
	}
	void setScore(int score) {
		this->score = score;
	}
	int getScore() {
		return score;
	}
	void setBarrier(char barrier) {
		this->barrier = barrier;
	}
	char getBarrier() {
		return barrier;
	}

	// Other methods

	// Let's print the bloody map
	void drawMap() {
		system("cls"); // Clear the screen... but it's not linux :(
		// Print the top frontier
		for (int i = 0; i < width + 2; i++)  // We use the "+ 2" to fill a gap in the process of drawing the board
			std::cout << barrier;


		std::cout << std::endl;


		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0) // If its the begining of the map print a barrier
					std::cout << barrier;
				if (i == sk.getHeadPositionY() && j == sk.getHeadPositionX()) // If the head of the snake is in the coordinate being printed print the damn head
					std::cout << sk.getHeadValue();
				else if (i == sk.apples.getPositionY() && j == sk.apples.getPositionX()) // If theres an apple on the coordinate being printed put a damn apple
					std::cout << sk.apples.getSymbol();
				/*else if (i == sk.pears.getPositionY() && j == sk.pears.getPositionX()) // If theres a pear... Well you get the idea... :/
					std::cout << sk.pears.getSymbol();*/

				else { // Print the tail of the snake
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
					std::cout << barrier;
			}
			std::cout << std::endl;
		}

		for (int i = 0; i < width + 2; i++)
			std::cout << barrier;

		std::cout << std::endl;
		std::cout << "Score: " << sk.getLength() << std::endl;

	}



};
