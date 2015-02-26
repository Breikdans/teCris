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
	unsigned long mTimeIni = 0;
	unsigned long mTimeNow = 0;
	
	TeCris.Init();
	
	// Tiempo Actual(SDL)
	mTimeIni = SDL_GetTicks();	

	// BUCLE DEL JUEGO
	do{
		// EVENTOS - GESTION EVENTO DE ENTRADA
		TeCris.Input();

		// LOGICA - ACTUALIZAR ESTADOS
		// TeCris.Update();
		
		// Si se ha cumplido el tiempo de bajar la pieza
		mTimeNow = SDL_GetTicks();
		if(mTimeNow - mTimeIni > mGameSpeed)
		{
			// LOGICA - ACTUALIZAR ESTADOS
			TeCris.Update();
			
			mTimeIni = SDL_GetTicks();
		}
		
		// RENDERIZAR - DIBUJAR
		TeCris.Draw();

//		SDL_Delay(50);
	} while (TeCris.IsRunning());

	atexit(SDL_Quit);

	return 0;
}
