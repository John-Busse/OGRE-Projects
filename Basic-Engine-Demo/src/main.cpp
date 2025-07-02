/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 */

#include "main.h"
#include "engine.h"

int main(int argc, char **argv) {
	try{
		Engine *engine = new Engine();
		engine->Init();
		engine->Run();
		engine->Cleanup();
	} catch (const std::exception& e) {
		std::cerr << "Error occured during execution: " << e.what() << '\n';
		return 1;
	}
	return 0;
}
