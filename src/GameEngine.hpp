#include "Player.hpp"
#include "Map.hpp"

class GameEngine {
public:
	GameEngine();
	void init();
	void update();
	void draw();
	void clean();
private:
	Player* player;
	Map* map;
};