#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "Renderer.h"

class Texture {
private:
	bool ok;
	SDL_Texture* texture;
	int w, h;
	const Renderer* renderer;
public:
	Texture(const char* name, const Renderer & renderer_);
	~Texture();
	void render(int x, int y);

	bool isOk(){return ok;}
	operator SDL_Texture*() {return texture;}
};

#endif