#include "piezas.h"
// Tabla con esquema de piezas:
// 7 Piezas, 4 Rotaciones, 5 BloquesHorizontal, 5 BloquesVertical
const char Piezas::tPiezas[TIPOS_PIEZAS][ROTACIONES][BLOQUES_HORIZONTAL][BLOQUES_VERTICAL] =
{
	// Cuadrado (AZUL)
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 8, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 8, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 8, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 8, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
	},
	// I o Palo (ROJO)
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 3, 8, 3, 3 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 3, 0, 0 },
			{ 0, 0, 8, 0, 0 },
			{ 0, 0, 3, 0, 0 },
			{ 0, 0, 3, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 3, 3, 8, 3, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 3, 0, 0 },
			{ 0, 0, 3, 0, 0 },
			{ 0, 0, 8, 0, 0 },
			{ 0, 0, 3, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
	},
	// L (MORADO)
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 7, 0, 0 },
			{ 0, 0, 8, 0, 0 },
			{ 0, 0, 7, 7, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 7, 8, 7, 0 },
			{ 0, 7, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 7, 7, 0, 0 },
			{ 0, 0, 8, 0, 0 },
			{ 0, 0, 7, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 7, 0 },
			{ 0, 7, 8, 7, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
	},
	// L Invertida "_|" (AMARILLO)
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 6, 0, 0 },
			{ 0, 0, 8, 0, 0 },
			{ 0, 6, 6, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 6, 0, 0, 0 },
			{ 0, 6, 8, 6, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 6, 6, 0 },
			{ 0, 0, 8, 0, 0 },
			{ 0, 0, 6, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 6, 8, 6, 0 },
			{ 0, 0, 0, 6, 0 },
			{ 0, 0, 0, 0, 0 }
		},
	},
	// N (NARANJA)
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 5, 0 },
			{ 0, 0, 8, 5, 0 },
			{ 0, 0, 5, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 5, 8, 0, 0 },
			{ 0, 0, 5, 5, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 5, 0, 0 },
			{ 0, 5, 8, 0, 0 },
			{ 0, 5, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 5, 5, 0, 0 },
			{ 0, 0, 8, 5, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
	},
	// N Invertida (CIAN)
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 8, 2, 0 },
			{ 0, 0, 0, 2, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 8, 2, 0 },
			{ 0, 2, 2, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0 },
			{ 0, 2, 8, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 2, 2, 0 },
			{ 0, 2, 8, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
	},
	// T (VERDE)
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 4, 0, 0 },
			{ 0, 0, 8, 4, 0 },
			{ 0, 0, 4, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 4, 8, 4, 0 },
			{ 0, 0, 4, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 4, 0, 0 },
			{ 0, 4, 8, 0, 0 },
			{ 0, 0, 4, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 4, 0, 0 },
			{ 0, 4, 8, 4, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
	}
};

// Para colocar la pieza NUEVA correctamente en el centro del area de juego
// Partiendo del centro del area de juego, indicamos la posicion donde iria la casilla 0,0 de la pieza
// Nota: En el centro de la pantalla tiene que quedar el bloque PIVOTE (8) no el inicio de la figura
const char Piezas::tPiezasPosicionInicial[TIPOS_PIEZAS][DESPLAZAMIENTO_XY_INICIAL] =
{
	// Cuadrado
	{ -2, -3 },
	// I o palo
	{ -2, -2 },
	// L
	{ -2, -3 },
	// L Invertida "_|"
	{ -2, -3 },
	// N
	{ -2, -3 },
	// N Invertida
	{ -2, -3 },
	// T
	{ -2, -3 }
};

// Nos da el tipo de bloque
const char Piezas::getTipoBloque(int iPieza, int iRotacion, int iX, int iY) const
{
	return tPiezas[iPieza][iRotacion][iX][iY];
}

// Nos da la posicion X inicial donde empezaremos a dibujar la pieza
const char Piezas::getXPosicionInicial(int iPieza) const
{
	return tPiezasPosicionInicial[iPieza][0];
}

// Nos da la posicion Y inicial donde empezaremos a dibujar la pieza
const char Piezas::getYPosicionInicial(int iPieza) const
{
	return tPiezasPosicionInicial[iPieza][1];
}

