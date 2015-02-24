#ifndef PIEZAS_H
#define PIEZAS_H

#include <iostream>

#define TIPOS_PIEZAS				7
#define ROTACIONES					4
#define BLOQUES_HORIZONTAL			5
#define BLOQUES_VERTICAL			5

#define DESPLAZAMIENTO_XY_INICIAL	2

class Piezas
{
private:
	static const char tPiezasPosicionInicial[TIPOS_PIEZAS][DESPLAZAMIENTO_XY_INICIAL];			///< Tabla con Posiciones Iniciales de las Piezas
	static const char tPiezas[TIPOS_PIEZAS][ROTACIONES][BLOQUES_HORIZONTAL][BLOQUES_VERTICAL];	///< Tabla con las 7 Piezas y sus rotaciones
public:
	const char getTipoBloque(int iPieza, int iRotacion, int iX, int iY) const;					///< Devuelve el bloque indicado en los parametros
	const char getXPosicionInicial(int iPieza) const;											///< posicion X inicial de la figura a pintar, respecto al centro
	const char getYPosicionInicial(int iPieza) const;											///< posicion X inicial de la figura a pintar, respecto al centro
};

#endif