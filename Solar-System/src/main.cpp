/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 */


#include "main.h"
#include "engine.h"

int main(int argc, char **argv) {
	try {
		Engine *engine = new Engine();
		engine->Run();
		engine->Cleanup();
		delete engine;
		engine = nullptr;
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << "\n";
		return 1;
	}
	return 0;
}
