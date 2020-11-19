#include "Player.hpp"
#include "Map.hpp"

class GameEngine {
public:
	GameEngine();
	int init(int *argcp, char** argv);

	const Player* player() const;
	const Map* map() const;

	void update();
	void handleKeyPress();

	void drawSquare();
	void drawCube();

	void clean();
private:
	Player* player_var;
	Map* map_var;
	
	//funciton pointers
	void (*reshape)(int, int);
	void (*draw)();
	void (*timer)(int);

	//keyboard bools
	bool w_key, a_key, s_key, d_key, shift_key, ctrl_key,
		left_key, right_key, up_key, down_key;
};