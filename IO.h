#ifndef IO_H
#define IO_H

#include <SDL.h>
#include "tablero.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_INIT_X = 300;
const int SCREEN_INIT_Y = 200;

typedef struct
{
	Uint8	r;
	Uint8	g;
	Uint8	b;
}STR_Color;

class IO
{
private:
	SDL_Window* mWindow = NULL;			///< La ventana que vamos a crear
	SDL_Renderer* mRenderer = NULL;		///< Renderizador de nuestra ventana
	const Uint8* mKeys;					///< Puntero a tabla con teclas mapeadas
	float mFrameRateDelay;				///< De cuanto va a ser la pausa del bucle del juego

	static const STR_Color colores[MAX_COLORES - 1];
public:
	IO();
	void setFrameRateDelay(float franeRate);
	void WaitDelay(float delta);
	void Clear() const;
	Uint8 Key(int ScanKey) const;
	void DrawRectangle(int X, int Y,int W, int H, int C) const;
	void RefreshScreen() const;
	~IO();
};

#endif