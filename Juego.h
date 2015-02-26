#ifndef JUEGO_H
#define JUEGO_H

#include <SDL.h>
#include "tablero.h"
#include "IO.h"

class Juego
{
private:
	int mPosX;
	int mPosY;
	int mPieza;
	int mRotacion;

	int mNextPosX;
	int mNextPosY;
	int mNextPieza;

	unsigned long int mPuntos;
	bool mRunning = true;

	Tablero *mTablero;
	IO *mIO;
	Piezas *mPiezas;

	int mGameSpeed;
	void DrawBoard();
	void DrawPiece(int , int , int , int );

public:
	Juego();
	void Init(void);
	void Input(void);
	void Update(void);
	void Draw(void);

	void NewPiece(void);
	void setRunning(bool R) { mRunning = R; }
	bool IsRunning(){ return mRunning; }
	~Juego();
};

#endif