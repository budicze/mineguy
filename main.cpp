#include <iostream>
#include <cstdlib>
#include <SDL2/SDL.h>

#include "Renderer.h"
#include "Texture.h"

int main(int argc, char* argv[]){
	using namespace std;
	
	Renderer renderer;
	if(!renderer.isOk()){
		cout << "Ending program" << endl;
		return EXIT_FAILURE;
	}

	Texture tex("images/test.png", renderer);

	tex.render(0, 0);
	
	renderer.update();

	

	while(1){
		SDL_Event e;
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT){
				return EXIT_SUCCESS;
			}
		}
		SDL_Delay(1);
	}

	return EXIT_SUCCESS;

}