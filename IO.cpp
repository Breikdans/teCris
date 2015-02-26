#include <iostream>
#include "IO.h"

using namespace std;

const STR_Color IO::colores[MAX_COLORES - 1] =	{	
												{ 0x02, 0x4A, 0xD4 },	// AZUL
												{ 0x00, 0xB2, 0x8E },	// CIAN
												{ 0xF5, 0x06, 0x09 },	// ROJO
												{ 0x41, 0xB6, 0x0B },	// VERDE
												{ 0xF7, 0x98, 0x00 },	// NARANJA
												{ 0xD3, 0xBA, 0x06 },	// AMARILLO
												{ 0xE0, 0x00, 0xD7 },	// MORADO
												{ 0x55, 0x55, 0x55 },	// PIVOTE
												{ 0x00, 0x00, 0x00 },	// NEGRO
												{ 0xFF, 0xFF, 0xFF },	// BLANCO
												};

IO::IO()
{
	//Inicializamos SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		cerr << "No se ha podido inicializar SDL!! SDL_Error: " << SDL_GetError() << endl;
		exit(-1);
	}

	// Creamos la ventana
	mWindow = SDL_CreateWindow("TeCRIS", SCREEN_INIT_X, SCREEN_INIT_Y, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!mWindow)
	{
		cerr << "No se ha podido crear la ventana!! SDL_Error: " << SDL_GetError() << endl;
		exit(-1);
	}

	// Creamos el renderer
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	if (!mRenderer)
	{
		cerr << "No se ha podido crear el renderer!! SDL_Error: " << SDL_GetError() << endl;
		exit(-1);
	}

	// Establecemos el tamaño del renderer igual que el de la ventana
	if (SDL_RenderSetLogicalSize(mRenderer, SCREEN_WIDTH, SCREEN_HEIGHT) < 0)
	{
		cerr << "No se ha podido establecer el renderer!! SDL_Error: " << SDL_GetError() << endl;
		exit(-1);
	}

	// Recogemos el mapa de estado del teclado
	mKeys = SDL_GetKeyboardState(nullptr);
}

void IO::setFrameRateDelay(float franeRate) 
{ 
	mFrameRateDelay = 1000.0f / franeRate; 
}

void IO::WaitDelay(float delta)
{
	SDL_Delay(mFrameRateDelay - delta);
}

// Devuelve true si la tecla por la que preguntamos, esta pulsada
Uint8 IO::Key(int ScanKey) const
{
	return mKeys[ScanKey];
}


void IO::Clear() const
{
	// Color con el que pintaremos en el render
	SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);	// NEGRO

	// Limpiamos el render
	SDL_RenderClear(mRenderer);
}

void IO::DrawRectangle(int X, int Y, int W, int H, int C) const
{
	SDL_Rect rect;
	rect.x = X, rect.y = Y, rect.w = W, rect.h = H;

	C--;	// Para adaptarlo al indice del array

	// Color del rectangulo
	SDL_SetRenderDrawColor(mRenderer, colores[C].r, colores[C].g, colores[C].b, 0xFF);

	// Pintamos nuestro Cuadrado
	SDL_RenderFillRect(mRenderer, &rect);
}

void IO::RefreshScreen() const
{
	// Finalmente RENDERIZAMOS
	SDL_RenderPresent(mRenderer);
}

IO::~IO()
{
	//Destruimos el renderer
	SDL_DestroyRenderer(mRenderer);

	//Destruimos la ventana
	SDL_DestroyWindow(mWindow);

	//Salimos de SDL
	SDL_Quit();
}