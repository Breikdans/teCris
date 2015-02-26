#include <iostream>
#include <SDL.h>
#include "Juego.h"
#include "tablero.h"

//#undef main

// El main para SDL SIEMPRE tiene que tener parametros
int main(int argc, char* argv[])
{
	// INICIALIZACION
	Juego TeCris;

	TeCris.Init();

	float deltaTime = 0.0;
	int thisTime = 0;
	int lastTime = 0;

	// BUCLE DEL JUEGO
	do{
		// GESTION EVENTO DE ENTRADA
		TeCris.Input();

		// ACTUALIZAR ESTADOS
		TeCris.Update();

		// DIBUJAR / RENDERIZAR
		TeCris.Draw();

		SDL_Delay(16);	// 1000 ms / 60 frames por segundo = 16
	} while (TeCris.IsRunning());

	atexit(SDL_Quit);

	return 0;
}