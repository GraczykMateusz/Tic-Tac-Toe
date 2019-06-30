#include <iostream>
#include "Map.h"

using std::cout;
using std::cin;

void GameManager::inputControl() {
	if(tour % 2 != 0) {
		cout << "Player X: ";
	}
	else {
		cout << "Player Y: ";
	}
	cin >> area;
}
void GameManager::setIntoMap() {
	
}
bool GameManager::checkWin() {

}
