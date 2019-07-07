#include <iostream>
#include <memory>
#include "Map.h"
#include "GameManager.h"

int main() {
	bool x;
	do {
		std::unique_ptr<GameManager> gameManager(new GameManager());
		std::shared_ptr<Map> map(new Map());	
		do {
			map->drawMap();
			gameManager->inputControl(map);
			gameManager->setIntoMap(map);	
		} while(gameManager->checkWin(map));
		map->drawMap();
		gameManager->showWinner();
		x = gameManager->playAgain();
	} while(x);
	return 0;
}
