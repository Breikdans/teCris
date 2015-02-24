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

	// BUCLE DEL JUEGO
	do{
		// DIBUJAR / RENDERIZAR
		TeCris.Draw();

		// GESTION EVENTO DE ENTRADA
		TeCris.Input();

		// ACTUALIZAR ESTADOS
		TeCris.Update();

		SDL_Delay(50);
	} while (TeCris.IsRunning());

	atexit(SDL_Quit);

	return 0;
}