#include <iostream>
#include <SDL2/SDL_image.h>

#include "Texture.h"

Texture::Texture(const char* filename, const Renderer& renderer_){
	using namespace std;

	ok = false;

	renderer = &renderer_;

	SDL_Surface* surface = IMG_Load(filename);

	if(surface == NULL){
		cerr << "Image cannot be loaded: " << IMG_GetError() << endl;
		return;
	}

	texture = SDL_CreateTextureFromSurface(*renderer, surface);
	if(texture == NULL){
		SDL_FreeSurface(surface);
		cerr << "Cannot create texture from " << filename << " SDL_Error: " << SDL_GetError() << endl;
		return;
	}

	SDL_FreeSurface(surface);


	if(SDL_QueryTexture(texture, NULL, NULL, &w, &h) != 0){
		SDL_DestroyTexture(texture);
		cerr << "Cannot query texture " << filename << " SDL_Error: " << SDL_GetError() << endl;
		return;
	}

	ok = true;
}

void Texture::render(int x, int y){
	static SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;

	SDL_RenderCopy(*renderer, texture, NULL, &dest);
}


Texture::~Texture(){
	SDL_DestroyTexture(texture);
}