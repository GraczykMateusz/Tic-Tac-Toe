#include <string>

class Map {
	public:
	Map() = default;
  	~Map() = default;	
 	void setMapNumbers(); 
	void drawMap();
	std::string getArray(); 
	private:
	std::string array[9][9]; //[area][position] 
};
