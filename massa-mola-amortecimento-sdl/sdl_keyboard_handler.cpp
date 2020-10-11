#include "sdl_keyboard_handler.h"

SDL_Keyboard_Handler::SDL_Keyboard_Handler(){
	state = SDL_GetKeyboardState(nullptr);
}

float SDL_Keyboard_Handler::HandleForceResponse(){
	SDL_PumpEvents();
	if (this->state[SDL_SCANCODE_DOWN]){
		return -KEYBOARD_FORCE;
	}
	if (this->state[SDL_SCANCODE_UP]){
		return KEYBOARD_FORCE;
	}
	return 0;
}
