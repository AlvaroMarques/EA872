#include <iostream>
#include <iomanip>
#include "massa-mola-amortecimento.h"

#define STD_DIM 3

Block::Block(float m, float x, float v, float c){
	this->m = m;
	this->x = x;
	this->c = c;
	this->v = v;
	this->height = STD_DIM;
	this->width = STD_DIM;
};

void Block::changeBlockDim(int height, int width){
	this->height = height;
	this->width = width;
}

int Block::get_height(){
	return this->height;
}

int Block::get_width(){
	return this->width;
}

float Block::get_mass(){
	return this->m;
}
float Block::get_aceleration(){
	return this->a;
}
float Block::get_vel(){
	return this->v;
}
float Block::get_c(){
	return this->c;
}
float Block::get_x(){
	return this->x;
}

void Block::set_aceleration(float a){
	this->a = a;
}
void Block::set_vel(float v){
	this->v = v;
}
void Block::set_x(float x){
	this->x = x;
}


Spring::Spring(float k){
	this->k = k;
}

float Spring::get_k(){
	return this->k;
}

PixelCalculator::PixelCalculator(std::shared_ptr<Block> block, int amplitude): block(block), amplitude(amplitude){ 
}

int PixelCalculator::calculate_pixel(){
	return 400*(block->get_x() + this->amplitude)/(2*this->amplitude);
}

void Viewer::showPixel(int pixel){
	std::cout << pixel << std::endl;
}

System::System(std::shared_ptr<Block> b, std::shared_ptr<Spring> s, int amplitude){
	this->b = b;
	this->s = s;
	this->p = std::shared_ptr<PixelCalculator>(new PixelCalculator(this->b, amplitude));
	this->v = std::shared_ptr<Viewer>(new Viewer ());;
	this->sdl_renderer = std::unique_ptr<SDL_System_Renderer>(new SDL_System_Renderer());
	this->sdl_renderer->InstanceBlock(this->b->get_height(), this->b->get_width());
	this->sdl_keyboard_handler = std::unique_ptr<SDL_Keyboard_Handler>(new SDL_Keyboard_Handler());
}

void System::iterate(float t_size){
	float k  = s->get_k();
	float x = b->get_x();
	float c = b->get_c();
	float vel = b->get_vel();
	float m = b->get_mass();

	b->set_aceleration((-k*x - c*vel)/m + (this->sdl_keyboard_handler->HandleForceResponse()/m));

	b->set_vel(vel + b->get_aceleration() * t_size);
	b->set_x(x + b->get_vel() * t_size);
}

void System::simulate(int iter){
	int i;
	float k  = s->get_k();
	float x = b->get_x();
	float c = b->get_c();
	float vel = b->get_vel();
	float m = b->get_mass();
	float a = 0;
	while (1){
		this->iterate(.01);
		std::cout<<this->p->calculate_pixel()<<std::endl;
		
		if(this->sdl_renderer->DrawFinal(this->p->calculate_pixel()) == -1){ 
			break;
		}
		
	}
}



