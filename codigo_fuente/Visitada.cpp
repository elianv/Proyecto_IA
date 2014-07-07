#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <list>
#include "Dato.h"
#include "Visitada.h"

Visitada::Visitada(int NewNumero,int NewX, int NewY)
{
	numero = NewNumero;
	x = NewX;
	y = NewY;
}

void Visitada::setDatos(int NewNumero, int NewX, int NewY)
{
	numero = NewNumero;
	x = NewX;
	y = NewY;
}

int Visitada::getNumero() const{
	return numero;
}

int Visitada::getX() const{
	return x;
}

int Visitada::getY() const{
	return y;
}
