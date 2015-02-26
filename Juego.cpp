#include <time.h>
#include "Juego.h"

using namespace std;

Juego::Juego()
{
	mIO			= new IO();
	mTablero	= new Tablero();
	mPiezas		= new Piezas();

	mGameSpeed = 500;
}

void Juego::Init()
{
	// Inicializamos los numeros aleatorios
	srand((unsigned int)time(NULL));

	// Creamos primera pieza
	mPieza		= rand() % TIPOS_PIEZAS;
	mPosX		= (TABLERO_ANCHO / 2) + mPiezas->getXPosicionInicial(mPieza);
	mPosY		= mPiezas->getYPosicionInicial(mPieza);
	mRotacion	= 0;

	// Creamos pieza Siguiente
	mNextPieza	= rand() % TIPOS_PIEZAS;
	mNextPosX	= TABLERO_ANCHO + 5;
	mNextPosY	= 2;
}


void Juego::DrawBoard()
{
	int iAnchoBarraAbajo = 0;
	// X de la primera barra que delimita el tablero
	int X1 = TABLERO_POSICION_X_PX - (TAMANO_BLOQUE_PX * (TABLERO_ANCHO / 2)) - TABLERO_ANCHO_LINEA_PX;
	
	// X de la segunda barra que delimita el tablero
	int X2 = TABLERO_POSICION_X_PX + (TAMANO_BLOQUE_PX * (TABLERO_ANCHO / 2));

	// Y
	int Y = TABLERO_POSICION_Y_PX - (TAMANO_BLOQUE_PX * (TABLERO_ALTO / 2));

	// Y Barra abajo
	int Yabajo = TABLERO_POSICION_Y_PX + (TAMANO_BLOQUE_PX * (TABLERO_ALTO / 2));

	// Barra Izquierda
	mIO->DrawRectangle(X1, Y, TABLERO_ANCHO_LINEA_PX, TAMANO_BLOQUE_PX * TABLERO_ALTO, BLANCO);
	// Barra Derecha
	mIO->DrawRectangle(X2, Y, TABLERO_ANCHO_LINEA_PX, TAMANO_BLOQUE_PX * TABLERO_ALTO, BLANCO);
	// Barra Abajo
	iAnchoBarraAbajo = TABLERO_ANCHO_LINEA_PX + (X2 - (X1 + TABLERO_ANCHO_LINEA_PX)) + TABLERO_ANCHO_LINEA_PX;
	mIO->DrawRectangle(X1, Yabajo, iAnchoBarraAbajo, TABLERO_ANCHO_LINEA_PX, BLANCO);


	char cBloque = 0;
	// Dibujamos los bloques que ya hay en el tablero
	for (int i = 0; i < TABLERO_ANCHO; i++)
	{
		for (int j = 0; j < TABLERO_ALTO; j++)
		{
			if ( (cBloque = mTablero->DameTipoBloque(i, j)) != VACIO )
				mIO->DrawRectangle( mTablero->X_EnPixels(i),
									mTablero->Y_EnPixels(j),
									TAMANO_BLOQUE_PX,
									TAMANO_BLOQUE_PX,
									cBloque);
		}
	}
}

/// Recibe en los parametros, donde esta la coordenada en bloques respecto del tablero, de la casilla (0,0) de la pieza y Pinta sus bloques NO VACIOS
void Juego::DrawPiece(int X_blqIniPieza,	///< Posicion X en bloques del tablero, donde esta la casilla INICIAL del array de la pieza
					  int Y_blqIniPieza,	///< Posicion Y en bloques del tablero, donde esta la casilla INICIAL del array de la pieza
					  int Pieza,			///< Pieza
					  int Rotacion			///< Rotacion
					  )
{
	char cBloque = 0;
	// Coordenada inicial en PIXELS del inicio del array de la pieza
	int PixelsX = mTablero->X_EnPixels(X_blqIniPieza);
	int PixelsY = mTablero->Y_EnPixels(Y_blqIniPieza);

	// recorremos el array de la pieza
	for (int i = 0; i < BLOQUES_VERTICAL; i++)
	{
		for (int j = 0; j < BLOQUES_HORIZONTAL; j++)
		{
			cBloque = mPiezas->getTipoBloque(Pieza, Rotacion, i, j);
			// Si es un bloque a PINTAR, lo pintamos
			if (cBloque != VACIO)
				mIO->DrawRectangle( PixelsX + (i * TAMANO_BLOQUE_PX), 
									PixelsY + (j * TAMANO_BLOQUE_PX), 
									TAMANO_BLOQUE_PX, 
									TAMANO_BLOQUE_PX, 
									cBloque);
		}
	}
}

void Juego::Input(void)
{
	// Para tratamiento de eventos
	SDL_Event mEvent;
	Uint8 ui_tecla = 0;

	// procesamos los eventos
	while (SDL_PollEvent(&mEvent))
	{
		switch (mEvent.type)
		{
			case SDL_QUIT:
				setRunning(false);
				break;
		}
	}


	if (mIO->Key(SDL_SCANCODE_RIGHT))
	{
		if (mTablero->MovimientoPosible(mPosX + 1, mPosY, mPieza, mRotacion))
			mPosX++;
	}

	if (mIO->Key(SDL_SCANCODE_LEFT))
	{
		if (mTablero->MovimientoPosible(mPosX - 1, mPosY, mPieza, mRotacion))
			mPosX--;
	}

	if (mIO->Key(SDL_SCANCODE_DOWN))
	{
		if (mTablero->MovimientoPosible(mPosX, mPosY + 1, mPieza, mRotacion))
			mPosY++;
	}

	if (mIO->Key(SDL_SCANCODE_SPACE) || mIO->Key(SDL_SCANCODE_UP))
	{
		if (mTablero->MovimientoPosible(mPosX, mPosY, mPieza, (mRotacion + 1) % ROTACIONES))
			mRotacion = (mRotacion + 1) % ROTACIONES;
	}

	if (mIO->Key(SDL_SCANCODE_ESCAPE))
		setRunning(false);

	SDL_Delay(50);
}

// Actualiza la posicion de las fichas del juego
void Juego::Update()
{
	static Uint32 ui_TimeIni = SDL_GetTicks();
	Uint32 ui_TimeNow = SDL_GetTicks();

	int iPuntos = 0;

	if ((ui_TimeNow - ui_TimeIni) > mGameSpeed)
	{
		if (mTablero->MovimientoPosible(mPosX, mPosY + 1, mPieza, mRotacion))
			mPosY++;
		else
		{
			mTablero->GuardaPieza(mPosX, mPosY, mPieza, mRotacion);
			if ((iPuntos = mTablero->CompruebaFilaCompleta()) > 0)
			{
				mPuntos += iPuntos;
				if ( (mGameSpeed >= 200) && (mPuntos % 5 == 0) )
					mGameSpeed -= 100;
			}

			if (mTablero->GameOver())
				setRunning(false);
			else
				NewPiece();
		}

		ui_TimeIni = SDL_GetTicks();
	}
}

void Juego::Draw()
{
	mIO->Clear();
	DrawBoard();
	DrawPiece(mPosX, mPosY, mPieza, mRotacion);
	DrawPiece(mNextPosX, mNextPosY, mNextPieza, 0);
	mIO->RefreshScreen();
}

void Juego::NewPiece()
{
	// Movemos pieza NEXT a pieza ACTUAL
	mPieza = mNextPieza;
	mPosX = (TABLERO_ANCHO / 2) + mPiezas->getXPosicionInicial(mPieza);
	mPosY = mPiezas->getYPosicionInicial(mPieza);
	mRotacion = 0;

	// Creamos pieza Siguiente
	mNextPieza = rand() % TIPOS_PIEZAS;
	mNextPosX = TABLERO_ANCHO + 5;
	mNextPosY = 2;
}

Juego::~Juego()
{
	delete mIO;
	delete mTablero;
	delete mPiezas;
}