#include "Player.hpp"
#include "Map.hpp"

class GameEngine {
public:
	GameEngine();
	int init(int *argcp, char** argv);

	void update();
	void draw();

	void reshape(int w, int h);
	void timer(int);

	void drawSquare();
	void drawCube();

	void clean();
private:
	Player* player;
	Map* map;
	
};