#ifndef RENDERER_H_
#define RENDERER_H_

#include <SDL2/SDL.h>

class Renderer {
private:
	static bool initialized;
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool ok;
public:
	Renderer();
	~Renderer();
	void update();

	bool isOk(){return ok;}
	operator SDL_Renderer*() const {return renderer;}
};

#endif