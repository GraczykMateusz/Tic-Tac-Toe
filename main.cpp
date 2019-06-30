#include <iostream>
#include <memory>
#include "GameManager.h"
#include "Map.h"

int main() {
	std::unique_ptr<GameManager> gameManager(new GameManager());
	std::unique_ptr<Map> map(new Map());
	map->setMapNumbers();

	map->drawMap();
	gameManager->inputControl();
	
	return 0;
}
