#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main() {
	// Inicializando o subsistema de video do SDL
	if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
		std::cout << SDL_GetError();
		return 1;
	}

	// Criando uma janela
	SDL_Window* window = nullptr;
	window = SDL_CreateWindow("Demonstracao do SDL2",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
	if (window==nullptr) { // Em caso de erro...
		std::cout << SDL_GetError();
		SDL_Quit();
		return 1;
	}

	// Inicializando o renderizador
	SDL_Renderer* renderer = SDL_CreateRenderer(
			window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer==nullptr) { // Em caso de erro...
		SDL_DestroyWindow(window);
		std::cout << SDL_GetError();
		SDL_Quit();
		return 1;
	}

	// Carregando texturas
	// personagem
	SDL_Texture *texture = IMG_LoadTexture(renderer, "./capi.png");
	// fundo
	SDL_Texture *texture2 = IMG_LoadTexture(renderer, "./park.jpeg");
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.h = 5;
	rect.w = 5;

	// Quadrado onde a textura sera desenhada
	SDL_Rect target;
	target.x = 0;
	target.y = 0;
	SDL_QueryTexture(texture, nullptr, nullptr, &target.w, &target.h);

	// Controlador:
	bool rodando = true;

	// Variaveis para verificar eventos
	SDL_Event evento; // eventos discretos
	const Uint8* state = SDL_GetKeyboardState(nullptr); // estado do teclado

	// Laco principal do jogo
	while(rodando) {
		// Polling de eventos
		SDL_PumpEvents(); // atualiza estado do teclado
		if (state[SDL_SCANCODE_LEFT]) rect.x -= 1;
		if (state[SDL_SCANCODE_RIGHT]) rect.x += 1;
		if (state[SDL_SCANCODE_UP]) rect.y -= 1;
		if (state[SDL_SCANCODE_DOWN]) rect.y += 1;


		while (SDL_PollEvent(&evento)) {
			if (evento.type == SDL_QUIT) {
				rodando = false;
			}
			// Exemplos de outros eventos.
			// Que outros eventos poderiamos ter e que sao uteis?
			//if (evento.type == SDL_KEYDOWN) {
			//}
			//if (evento.type == SDL_MOUSEBUTTONDOWN) {
			//}
		}

		// Desenhar a cena
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);

		// Delay para diminuir o framerate
		SDL_Delay(10);
	}

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
