#include "tablero.h"

Tablero::Tablero()
{
	mPiezas = new Piezas;
}

/*
============================================================================================================
Guardamos los bloques de la pieza en la tabla (sera un array de 2 x 2)

Parametros:
int iX			ENTRADA. Posicion X en bloques de la pieza, dentro de la tabla
int iY			ENTRADA. Posicion Y en bloques de la pieza, dentro de la tabla
int iPieza		ENTRADA. Identificador de pieza a guardar (hay 7)
int iRotacion	ENTRADA. Identificador de rotacion de pieza (hay 4)

Retorno:
Nada

Nota: Siempre nos llegarán casillas validas para guardar, es decir, no nos llegara una casilla que este en el borde o encima de otra
============================================================================================================
*/
void Tablero::GuardaPieza(int iX,int iY,int iPieza,int iRotacion)
{
	char c_tipoBloque = VACIO;

	// Recorremos a la vez los bloques del tablero y los de la pieza
	for (int iT = iX, iP = 0; iT < iX + BLOQUES_HORIZONTAL; iT++, iP++)
	{
		for (int jT = iY, jP = 0; jT < iY + BLOQUES_VERTICAL; jT++, jP++)
		{
			// Si el bloque de la pieza en el que estamos NO ESTA VACIO, LO GUARDAMOS
			if ((c_tipoBloque = mPiezas->getTipoBloque(iPieza, iRotacion, iP, jP)) != VACIO)
				mTablero[iT][jT] = c_tipoBloque;
		}
	}
}

/*
============================================================================================================
Comprueba si en la linea de arriba del tablero hay algun bloque

Parametros:
Nada

Retorno:
true	Si hay algun bloque
false	Si no hay ninguno
============================================================================================================
*/
bool Tablero::GameOver()
{
	for (int i = 0; i < TABLERO_ANCHO; i++)
	{
		if (mTablero[i][0] != VACIO)
			return true;
	}

	return false;
}

/*
============================================================================================================
Borra la linea recibida y mueve las demas hacia abajo en el tablero

Parametros:
int iY		ENTRADA. Linea a borrar

Retorno:
Nada
============================================================================================================
*/
void Tablero::BorraFila(int iY)
{
	// Nos ponemos en la linea recibida y recorremos hacia arriba
	for (int j = iY; j > 0; j--)
	{
		// Copiamos en la linea actual, la linea de arriba
		for (int i = 0; i < TABLERO_ANCHO; i++)
			mTablero[i][j] = mTablero[i][j - 1];
	}
}

/*
============================================================================================================
Recorre todas las filas del tablero comprobando si hay alguna completa para borrarla

Parametros:
Nada

Retorno:
Numero de filas completas encontradas y borradas
============================================================================================================
*/
int Tablero::CompruebaFilaCompleta()
{
	int iLineas = 0;

	for (int j = 0; j < TABLERO_ALTO; j++)
	{
		int i = 0;
		while (i < TABLERO_ANCHO)
		{
			if (mTablero[i][j] == VACIO) 
				break;
			i++;
		}
		if (i == TABLERO_ANCHO)
		{
			++iLineas;
			BorraFila(j);
		}
	}

	return iLineas;
}

/*
============================================================================================================
Devuelve el tipo de bloque del tablero indicado en las coordenadas X e Y recibidas

Parametros:
int iX		ENTRADA. Coordenada X del tablero
int iY		ENTRADA. Coordenada Y del tablero

Retorno:
Tipo de bloque (EN_BLOQUE)
============================================================================================================
*/
const char Tablero::DameTipoBloque(int iX, int iY) const
{ 
	return mTablero[iX][iY];
}


/*
============================================================================================================
Devuelve la coordenada X del bloque convertida en PIXELS

Parametros:
int iX		ENTRADA. Coordenada X del tablero

Retorno:
Posicion en pixels de X
============================================================================================================
*/
int Tablero::X_EnPixels(int iX)
{
	return (TABLERO_POSICION_X_PX - ((TABLERO_ANCHO / 2) * TAMANO_BLOQUE_PX)) + iX * TAMANO_BLOQUE_PX;
}

/*
============================================================================================================
Devuelve la coordenada Y del bloque convertida en PIXELS

Parametros:
int iY		ENTRADA. Coordenada Y del tablero

Retorno:
Posicion en pixels de Y
============================================================================================================
*/
int Tablero::Y_EnPixels(int iY)
{
	return (TABLERO_POSICION_Y_PX - ((TABLERO_ALTO / 2) * TAMANO_BLOQUE_PX)) + iY * TAMANO_BLOQUE_PX;
}

/*
============================================================================================================
Comprueba si se va a hacer un movimiento valido

Parametros:
int iX			ENTRADA. Coordenada X de la pieza en el tablero
int iY			ENTRADA. Coordenada Y de la pieza en el tablero
int iPieza		ENTRADA. Identificador de pieza a Mover (hay 7)
int iRotacion	ENTRADA. Identificador de rotacion de pieza (hay 4)

Retorno:
true		Movimiento VALIDO
false		Movimiento INVALIDO
============================================================================================================
*/
bool Tablero::MovimientoPosible(int iX, int iY, int iPieza, int iRotacion)
{
	// Recorremos a la vez los bloques del tablero y los de la pieza
	for (int iT = iX, iP = 0; iT < iX + BLOQUES_HORIZONTAL; iT++, iP++)
	{
		for (int jT = iY, jP = 0; jT < iY + BLOQUES_VERTICAL; jT++, jP++)
		{
			// Comprobamos si las cordenadas de la pieza estan fuera del tablero (pueden ser bloques VACIOS)
			if (iT < 0 ||
				iT > TABLERO_ANCHO - 1 ||
				jT > TABLERO_ALTO - 1)
			{
				// El tipo de bloque actual no es VACIO, movimiento NO POSIBLE.
				if (mPiezas->getTipoBloque(iPieza, iRotacion, iP, jP) != VACIO)
					return false;
			}

			// Comprobamos si hemos chocado con una pieza ya puesta
			if (jT >= 0)	// Si estamos en un bloque de dentro del tablero
			{
				// miramos si el bloque de la pieza NO ESTA VACIO y si esta encima de otro OCUPADO en el tablero
				if (mPiezas->getTipoBloque(iPieza, iRotacion, iP, jP) != VACIO && DameTipoBloque(iT, jT) != VACIO)
					return false;
			}
		}
	}

	return true;
}

Tablero::~Tablero()
{
	delete mPiezas;
}