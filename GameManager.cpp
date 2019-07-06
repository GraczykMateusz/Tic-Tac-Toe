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

	//Sets whose round it is 
	if(round == 0) { //First round is always 0
		srand(time(NULL));
		round = rand() % 2;
	} 
	if(round % 2 != 0) {
		cout << "Player X: ";
	}
	else {
		cout << "Player O: ";
	}
	
	//Protection against wrong input
	do {
		cin >> selectedField;
		if(checkFieldAvailability(selectedField, map)) {
			field = selectedField;
		}
		else {
			field = -1;
			cout << "Wrong field, select again: ";
		}
	}while((selectedField < 0 && selectedField > 8) || field == -1);
}

void GameManager::setX(std::shared_ptr<Map> map) {
	auto* ptrToMap = map->getMap();
	for(int i = 0; i < 9; i += 2) {
		(*ptrToMap)[field][i] = "#";
	}		
}

void GameManager::setO(std::shared_ptr<Map> map) {
	auto* ptrToMap = map->getMap();
	for(int i = 0; i < 9; i++) {
		if(i != 4) {
			(*ptrToMap)[field][i] = "#";
		}
		else {
			(*ptrToMap)[field][i] = " ";
		}	
	}
}

std::string GameManager::checkRound() {
	if(round % 2 != 0) {
		return "X";
	}
	else {
		return "O";	
	}
}

bool GameManager::checkFieldAvailability(int selectedField, std::shared_ptr<Map> map) {	
	auto* ptrToMap = map->getMap();
	if((*ptrToMap)[selectedField][0] == "#") { //Position '0' is common for X and O
		return false;
	}
	else {
		return true;
	}
}

void GameManager::setIntoMap(std::shared_ptr<Map> map) {
	if(checkRound() == "X") {
		setX(map);
	}
	else {
		setO(map);
	}
	round++;
}

bool GameManager::checkWin(std::shared_ptr<Map> map) {
	auto* ptrToMap = map->getMap();
	//Check horizontal lines
	for(int i = 0; i < 9; i += 3) {
		//For X
		if((*ptrToMap)[i][4] == "#" && (*ptrToMap)[i + 1][4] == "#" && (*ptrToMap)[i + 2][4] == "#") {
			winner = 'X';
			return false;
		}
		//For O
		if((*ptrToMap)[i][4] == " " && (*ptrToMap)[i + 1][4] == " " && (*ptrToMap)[i + 2][4] == " ") {
			winner = 'O';
			return false;
		}
	}
	//Check vertical lines
	for(int i = 0; i < 3; i++) {
		//For X
		if((*ptrToMap)[i][4] == "#" && (*ptrToMap)[i + 3][4] == "#" && (*ptrToMap)[i + 6][4] == "#") {
	        	winner = 'X';
                        return false;
                }
                //For O
                if((*ptrToMap)[i][4] == " " && (*ptrToMap)[i + 3][4] == " " && (*ptrToMap)[i + 6][4] == " ") {
                        winner = 'O';
                        return false;
                }
	}
	//Check diagonal lines
	//For X
        if((*ptrToMap)[0][4] == "#" && (*ptrToMap)[4][4] == "#" && (*ptrToMap)[8][4] == "#") {
        	winner = 'X';
                return false;
        }
        if((*ptrToMap)[2][4] == "#" && (*ptrToMap)[4][4] == "#" && (*ptrToMap)[6][4] == "#") {
                winner = 'X';
                return false;	
	}
	//For O
	if((*ptrToMap)[0][4] == " " && (*ptrToMap)[4][4] == " " && (*ptrToMap)[8][4] == " ") {
                winner = 'O';
                return false;
        }
        if((*ptrToMap)[2][4] == " " && (*ptrToMap)[4][4] == " " && (*ptrToMap)[6][4] == " ") {
                winner = 'O';
                return false;
        }
	//No winner
	return true;
}

void GameManager::showWinner() {
	cout << "Congratulations! " <<  winner << " is the winner" << std::endl;
}

bool GameManager::playAgain() {
	do {
		cout << "Do you want play again? (y/n):";
		cin >> playAgain;
		cout << std::endl;
	} while(playAgain != 'y' || playAgain != 'Y' || playAgain != 'n' || playAgain != 'N');
	if(playAgain == 'y' || playAgain == 'Y') {
		return true;
	}
	else {
		return false;
	}
}
