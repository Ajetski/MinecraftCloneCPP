#include "Map.hpp"

Map::Map() {
	for (int x = 0; x < 32; x++) {
		for (int y = 0; y < 32; y++) {
			for (int z = 0; z < 32; z++) {
				if (y >= 16)
					map[x][y][z] = 0;
				else
					map[x][y][z] = 1;
				
			}
		}
	}
}

const unsigned int& Map::get(size_t x, size_t y, size_t z) const {
	return map[x][y][z];
}

void Map::set(unsigned int value, size_t x, size_t y, size_t z) {
	map[x][y][z] = value;
}
