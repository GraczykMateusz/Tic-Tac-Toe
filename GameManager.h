#include <string>

class Map;

class GameManager {
	public:
	GameManager() = default;
	~GameManager() = default;
	void inputControl();
	void setIntoMap(std::shared_ptr<Map> map);	
    	bool checkWin();
	private:
	void setX(std::shared_ptr<Map> map);
	void setO(std::shared_ptr<Map> map);
	std::string checkTour();
	short area;
	unsigned short tour = 0;
};
