class GameManager {
	public:
	GameManager() = default;
	~GameManager() = default;
	void inputControl();
	void setIntoMap();
	bool checkWin();
	private:
	short area;
	unsigned short tour = 0;
};
