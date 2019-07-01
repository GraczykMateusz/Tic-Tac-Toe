#include <iostream>
#include <memory>
#include <time.h>
#include <stdlib.h>
#include "GameManager.h"
#include "Map.h"

using std::cout;
using std::cin;

void GameManager::inputControl() {
	if(tour == 0) {
		srand(time(NULL));
		tour = rand() % 2;
	} 
	if(tour % 2 != 0) {
		cout << "Player X: ";
	}
	else {
		cout << "Player O: ";
	}
	cin >> area;
	tour++;
}
void GameManager::setX(std::shared_ptr<Map> map) {
	for(int i = 0; i < 9; i += 2) {
		
	}		
}
void GameManager::setO(std::shared_ptr<Map> map) {
	for(int i = 0; i < 9; i++) {
		if(i != 4) {
			
		}	
	}
}
std::string GameManager::checkTour() {
	if(tour % 2 != 0) {
		return "X";
	}
	else {
		return "O";	
	}
}
void GameManager::setIntoMap(std::shared_ptr<Map> map) {
	if(checkTour() == "X") {
		setX(map);
	}
	else {
		setO(map);
	}
}
bool GameManager::checkWin() {
	return true;
}
