#include <iostream>
#include "GameEngine.h"

//#define STD_IMAGE_IMPLEMENTATION
//#include "libraries/std_image/stb_image.h"

int main(int argc, char* argv[]) {
	GameEngine engine;
	int ret = engine.init(&argc, argv);
	if (ret != 0) {
		return ret;
	}
	return 0;
}


