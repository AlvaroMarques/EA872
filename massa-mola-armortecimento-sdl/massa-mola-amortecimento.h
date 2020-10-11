#ifndef MASSA_MOLA_ARMORTECIMENTO_H
#define MASSA_MOLA_ARMORTECIMENTO_H

#include <iostream>
#include <iomanip>
#include "sdl_renderer.h"
#include "sdl_keyboard_handler.h"


class Block {
	private:
		float m, x, v, c, a;
		int height, width;
	public:
		Block(float m, float x, float v, float c);
		float get_mass();
		float get_aceleration();
		float get_x();
		float get_vel();
		float get_c();
		int get_height();
		int get_width();
		void set_aceleration(float a);
		void set_vel(float v);
		void set_x(float x);
		void changeBlockDim(int height, int width);

};

class Spring{
	private:
		float k;
	public:
		Spring(float k);
		float get_k();	
};

class PixelCalculator{
	private:
		std::shared_ptr<Block> block;
		int amplitude;
	public:
		PixelCalculator(std::shared_ptr<Block> block, int amplitude);
		int calculate_pixel();
};

class Viewer{
	public:
		void showPixel(int pixel);
};

class System{
	private:
		std::shared_ptr<Block> b;
		std::shared_ptr<Spring> s;
		std::shared_ptr<PixelCalculator> p;
		std::shared_ptr<Viewer> v;
		std::unique_ptr<SDL_System_Renderer> sdl_renderer;
		std::unique_ptr<SDL_Keyboard_Handler> sdl_keyboard_handler;
	public:
		System(std::shared_ptr<Block> b, std::shared_ptr<Spring> s, int amplitude);
		void iterate(float t_size);
		void simulate(int iter);

};

#endif
