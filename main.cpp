#include <iostream>
#include <memory>
#include "Map.h"
#include "GameManager.h"

int main() {
	std::unique_ptr<GameManager> gameManager(new GameManager());
	std::shared_ptr<Map> map(new Map());
	map->setMapNumbers();
	
	do {
		map->drawMap();
		gameManager->inputControl();
		gameManager->setIntoMap(map);	
	} while(gameManager->checkWin());
	return 0;
}
