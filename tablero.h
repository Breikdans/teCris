#ifndef TABLERO_H
#define TABLERO_H

#include "piezas.h"

// ==== Medido en PIXELS
#define TABLERO_POSICION_X_PX		320		// Posicion en X del centro del tablero
#define TABLERO_POSICION_Y_PX		240		// Posicion en Y del centro del tablero

#define TABLERO_ANCHO_LINEA_PX		8		// Ancho de la linea lateral del tablero
#define TAMANO_BLOQUE_PX			16		// Tamaño de bloque en pixels

// ==== Medido en BLOQUES
#define TABLERO_ANCHO				10		// Ancho del tablero en bloques
#define TABLERO_ALTO				20		// Alto del tablero en bloques

enum EN_BLOQUE
{
	VACIO = 0
	, AZUL
	, CIAN
	, ROJO
	, VERDE
	, NARANJA
	, AMARILLO
	, MORADO
	, PIVOTE		// 8. para ver el giro de las piezas
	, NEGRO
	, BLANCO
	, MAX_COLORES
};

enum EN_PIEZAS
{
	CUADRADO = 0
	, PALO
	, L
	, L_INV
	, N
	, N_INV
	, T
};

class Tablero
{
private:
	char mTablero[TABLERO_ANCHO][TABLERO_ALTO] = {};	// Con = {} Se inicializa a 0, que es el valor que queremos darle (VACIO = 0)
	Piezas *mPiezas;									// Las piezas que se van a usar en el tablero

	void BorraFila(int iY);
public:
	Tablero();
	void InitTablero(void){ mTablero[TABLERO_ANCHO][TABLERO_ALTO] = {}; }
	int X_EnPixels(int iX);
	int Y_EnPixels(int iY);
	void GuardaPieza(int iX, int iY, int iPieza, int iRotacion);
	const char DameTipoBloque(int iX, int iY) const;
	bool MovimientoPosible(int iX, int iY, int iPieza, int iRotacion);
	int CompruebaFilaCompleta(void);
	bool GameOver();
	~Tablero();
};
#endif