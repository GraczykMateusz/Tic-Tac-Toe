#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <string>

class Map;

class GameManager {
public:
	GameManager() = default;
	~GameManager() = default;

	/*SETUP*/
	void inputControl(std::shared_ptr<Map> map);
	void setIntoMap(std::shared_ptr<Map> map);
	bool playAgain();

	/*WIN*/
	void showWinner();
	bool checkWin(std::shared_ptr<Map> map);
	bool winX();
	bool winO();

private:

	/*Methods*/
	void setX(std::shared_ptr<Map> map);
	void setO(std::shared_ptr<Map> map);
	std::string checkPlayerTurn();
	bool checkFieldAvailability(int selectedField, std::shared_ptr<Map> map);

	/*Variables*/
	char varPlayAgain;
	std::string winner;
	short field;
	unsigned short playerTurn = 0;
	unsigned short round = 0;
};

#endif
