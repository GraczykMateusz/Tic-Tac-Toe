#include <iostream>
#include <memory>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "GameManager.h"
#include "Map.h"

using std::cout;
using std::cin;

void GameManager::inputControl(std::shared_ptr<Map> map) {
	int selectedField;

	//Sets whose player turn it is 
	if(round == 0) { //First round is always 0
		srand(time(NULL));
		playerTurn = rand() % 2;
	} 
	if(playerTurn % 2 != 0) {
		cout << "Player X: ";
	}
	else {
		cout << "Player O: ";
	}
	
	//Protection against wrong input
	do {
		cin >> selectedField;
	
		if(checkFieldAvailability(selectedField, map) && selectedField >= 0 && selectedField <= 8) {
			field = selectedField;
		}
		else {
			field = -1;
			cout << "Wrong field, select again: ";
		}
	}while((selectedField < 0 && selectedField > 8) || field == -1);
}

void GameManager::setX(std::shared_ptr<Map> map) {
	auto ptrToMap = map->getMap();
	
	for(int i = 0; i < 9; i += 2) {
		(*ptrToMap)[field][i] = "#";
	}		
}

void GameManager::setO(std::shared_ptr<Map> map) {
	auto ptrToMap = map->getMap();

	for(int i = 0; i < 9; ++i) {
		if(i != 4) {
			(*ptrToMap)[field][i] = "#";
		}
		else {
			(*ptrToMap)[field][i] = " ";
		}	
	}
}

std::string GameManager::checkPlayerTurn() {
	if(playerTurn % 2 != 0) {
		return "X";
	}
	else {
		return "O";	
	}
}

bool GameManager::checkFieldAvailability(int selectedField, std::shared_ptr<Map> map) {	
	auto ptrToMap =map->getMap();
	
	if(selectedField >= 0 && selectedField <= 8) {
		if((*ptrToMap)[selectedField][0] == "#") { //Position '0' is common for X and O
			return false;
		}
	}
	return true;
}

void GameManager::setIntoMap(std::shared_ptr<Map> map) {
	if(checkPlayerTurn() == "X") {
		setX(map);
	}
	else {
		setO(map);
	}
	++playerTurn;
	++round;
}

bool GameManager::checkWin(std::shared_ptr<Map> map) {
	auto ptrToMap = map->getMap();

	//Check horizontal lines
	for(int i = 0; i < 9; i += 3) {
		//For X
		if((*ptrToMap)[i][4] == "#" && (*ptrToMap)[i + 1][4] == "#" && (*ptrToMap)[i + 2][4] == "#") {
			return winX();
		}
		//For O
		if((*ptrToMap)[i][4] == " " && (*ptrToMap)[i + 1][4] == " " && (*ptrToMap)[i + 2][4] == " ") {
			return winO();
		}
	}
	//Check vertical lines
	for(int i = 0; i < 3; ++i) {
		//For X
		if((*ptrToMap)[i][4] == "#" && (*ptrToMap)[i + 3][4] == "#" && (*ptrToMap)[i + 6][4] == "#") {
	        	return winX();
                }
                //For O
                if((*ptrToMap)[i][4] == " " && (*ptrToMap)[i + 3][4] == " " && (*ptrToMap)[i + 6][4] == " ") {
                        return winO();
                }
	}
	//Check diagonal lines
	//For X
        if((*ptrToMap)[0][4] == "#" && (*ptrToMap)[4][4] == "#" && (*ptrToMap)[8][4] == "#") {
        	return winX();
        }
        if((*ptrToMap)[2][4] == "#" && (*ptrToMap)[4][4] == "#" && (*ptrToMap)[6][4] == "#") {
                return winX();	
	}
	//For O
	if((*ptrToMap)[0][4] == " " && (*ptrToMap)[4][4] == " " && (*ptrToMap)[8][4] == " ") {
                return winO();
        }
        if((*ptrToMap)[2][4] == " " && (*ptrToMap)[4][4] == " " && (*ptrToMap)[6][4] == " ") {
                return winO();
        }
	//Check if all fields are occupied
	if(round == 9) {
		winner = "Draw";
		return false;	
	}
	//No winner
	return true;
}

bool GameManager::winX() {
	winner = "X";
        return false;
}

bool GameManager::winO() {
	winner = "O";
        return false;
}

void GameManager::showWinner() {
	if(winner != "Draw") {
		cout << "Congratulations! " <<  this->winner << " is the winner" << std::endl;
	}
	else {
		cout << this->winner << std::endl;
	}
}

bool GameManager::playAgain() {
	do {
		cout << "Do you want to play again? (y/n):";
		cin >> varPlayAgain;
	} while(varPlayAgain != 'y' && varPlayAgain != 'Y' && varPlayAgain != 'n' && varPlayAgain != 'N');

	if(varPlayAgain == 'y' || varPlayAgain == 'Y') {
		return true;
	}
	else {
		return false;
	}
}
