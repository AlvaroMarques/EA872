#ifndef __KEYBOARD_HANDLER_H__
#define __KEYBOARD_HANDLER_H__

#include "sdl_renderer.h" 

#define KEYBOARD_FORCE 10

class SDL_Keyboard_Handler{
	private:
	       	const Uint8* state;
	public:
		SDL_Keyboard_Handler();
		float HandleForceResponse();
};

#endif 
