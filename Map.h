#include <string>

class Map {
	public:
	void setMapNumbers(); 
	void drawMap();
	std::string getArray() { return array[9][9]; }
	private:
	std::string array[9][9]; //[area][position] 
};
