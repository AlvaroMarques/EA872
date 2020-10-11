LDFLAGS = -framework SDL2  -I 

all : main

main: main.o massa-mola-amortecimento.o sdl_renderer.o sdl_keyboard_handler.o
	g++ -o main main.o massa-mola-amortecimento.o  sdl_keyboard_handler.o sdl_renderer.o -I/usr/local/include  -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11
main.o: main.cpp
	g++ -c main.cpp -o main.o -std=c++11

massa-mola-amortecimento.o : massa-mola-amortecimento.cpp massa-mola-armortecimento.h
	g++ -c massa-mola-amortecimento.cpp -omassa-mola-amortecimento.o 

sdl_keyboard_handler.o : sdl_keyboard_handler.cpp sdl_keyboard_handler.h
	g++ -c sdl_keyboard_handler.cpp -osdl_keyboard_handler.o # -I/usr/local/include  -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11

sdl_renderer.o : sdl_renderer.cpp sdl_renderer.h
	g++ -c sdl_renderer.cpp -osdl_renderer.o # -I/usr/local/include  -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11
clean:
	rm *.o
