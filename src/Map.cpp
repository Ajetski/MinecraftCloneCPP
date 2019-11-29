#include "Map.hpp"

Map::Map() {
	chunkSize = 32;
	for (unsigned int x = 0; x < chunkSize; x++) {
		for (unsigned int y = 0; y < chunkSize; y++) {
			for (unsigned int z = 0; z < chunkSize; z++) {
				if (y >= chunkSize / 2)
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

const unsigned int& Map::size() const {
	return chunkSize;
}