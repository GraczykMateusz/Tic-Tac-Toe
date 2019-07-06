#include <string>

class Map;

class GameManager {
	public:
	GameManager() = default;
	~GameManager() = default;
	void inputControl(std::shared_ptr<Map> map);
	void setIntoMap(std::shared_ptr<Map> map);
	void showWinner();	
    	bool checkWin(std::shared_ptr<Map> map);
	bool playAgain();

	private:
	/*Methods*/
	void setX(std::shared_ptr<Map> map);
	void setO(std::shared_ptr<Map> map);
	std::string checkRound();
	bool checkFieldAvailability(int selectedField, std::shared_ptr<Map> map);
	/*Variables*/
	char playAgain;
	char winner;
	short field;
	unsigned short round = 0;
};
