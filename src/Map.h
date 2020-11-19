class Map {
public:
	Map();
	void set(unsigned int value, size_t x, size_t y, size_t z);

	const unsigned int& get(size_t x, size_t y, size_t z) const;
	const unsigned int& size() const;

	//to do:
	//implement map loading from files
	//change to chunk based map loading for infinite world
	
private:
	unsigned int chunkSize;
	unsigned int map[32][32][32] = {};

	/*
	// nested classes for multiple subscripting access
	class MapWall {
	public:

	private:
		class MapWallRow {

		};
	};*/
};