class Map {
public:
	Map();
	unsigned int get(size_t x, size_t y, size_t z) const;
	void set(unsigned int value, size_t x, size_t y, size_t z);
	//to do:
	//implement map loading from files
	//change to chunk based map loading for infinite world
	
private:
	unsigned int map[32][32][32] = {};
	/*
	class MapWall {
	public:

	private:
		class MapWallRow {

		};
	};*/
};