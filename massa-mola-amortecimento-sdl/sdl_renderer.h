#ifndef __SDL_RENDERER_H__
#define __SDL_RENDERER_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <iomanip>

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400
#define BLOCK_X 200

class SDL_System_Renderer{
	private:
		SDL_Window *window;
		SDL_Renderer* renderer;
		SDL_Event event;
		SDL_Rect block_view;
	public:
		SDL_System_Renderer();
		~SDL_System_Renderer();
		void InstanceBlock(int block_height, int block_width);
		int DrawFinal(int pixel_pos);
};


#endif
