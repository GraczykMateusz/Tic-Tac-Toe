#include <iostream>
#include "GameManager.h"
#include <time.h>
#include <stdlib.h>

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
		cout << "Player Y: ";
	}
	cin >> area;
	tour++;
}
void GameManager::setIntoMap() {
	
}
bool GameManager::checkWin() {

}
