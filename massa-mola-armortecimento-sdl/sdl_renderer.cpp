#include "sdl_renderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

SDL_System_Renderer::SDL_System_Renderer(){
	if (SDL_Init (SDL_INIT_VIDEO) < 0){
		std::cout << SDL_GetError();
		return;
	}
	window = nullptr;
	window = SDL_CreateWindow("Sistema massa-mola",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
			);
	if (window == nullptr){
		SDL_DestroyWindow(window);
		std::cout << SDL_GetError();
		SDL_Quit();
		return;
	}

	renderer = nullptr;
	renderer = SDL_CreateRenderer(
			window, 
			-1,
			SDL_RENDERER_ACCELERATED
			);
	if (renderer == nullptr){
		SDL_DestroyWindow(window);
		std::cout << SDL_GetError();
		SDL_Quit();
		return;
	}
}


void SDL_System_Renderer::InstanceBlock(int block_height, int block_width){
	this->block_view.h = block_height;
	this->block_view.w = block_width;
	this->block_view.x = BLOCK_X;
	return;
}

int SDL_System_Renderer::DrawFinal(int pixel_pos){
	SDL_PumpEvents();
	while (SDL_PollEvent(&(this->event))){
		if (this->event.type == SDL_QUIT){
			return -1;
		}	
	}
	this->block_view.y = pixel_pos;
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
	SDL_RenderClear(this->renderer);
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(this->renderer, &(this->block_view));
	SDL_RenderPresent(this->renderer);
	SDL_Delay(2);
	return 0;
}

SDL_System_Renderer::~SDL_System_Renderer(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}




