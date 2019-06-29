#include <string>

class Map {
	public:
	void setMapNumbers(); 
	void showMap();
	private:
	std::string array[9][9]; //[area][position] 
};
