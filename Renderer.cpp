#include <iostream>
#include <SDL2/SDL_image.h>

#include "Renderer.h"

bool Renderer::initialized = false;

Renderer::Renderer(){
	using namespace std;

	if(initialized){
		ok = false;
		cerr << "You can't initialize Renderer two times!" << endl;
		return;
	}
	ok = initialized = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		ok = false;
		return;
	}

	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if(window == NULL){
		cerr << "SDL_Window could not initialize! SDL_Error: " << SDL_GetError() << endl;
		ok = false;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){
		cerr << "SDL_Renderer could not initialize! SDL_Error: " << SDL_GetError() << endl;
		ok = false;
		return;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
	SDL_RenderClear(renderer);

	SDL_RendererInfo info;
	if(SDL_GetRendererInfo(renderer, &info) == 0){
		cout << "Renderer: " << info.name << endl;
	}

	int flags = IMG_INIT_PNG;

	if((IMG_Init(flags) & flags) != flags){
		cerr << "SDL_Image could not initialize! IMG_Error: " << IMG_GetError() << endl;
		ok = false;
		return;
	}

	cout << "SDL has been successfully initialized!" << endl;
}

Renderer::~Renderer(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}


void Renderer::update(){
	SDL_RenderPresent(renderer);
}