
#ifndef DATO_H
#define DATO_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <list>

using namespace std;

class Dato{
	public:
	 //Dato();
	 Dato(int,int,int,int);
	 int getDistancia() const;
	 int getNumero() const;
	 int getAnterior() const;
	 int getCapacidad() const;
	 void setDistancia(int);
	 void setNumero(int);
	 void setAnterior(int);
	 void setCapacidad(int);
	 
	private:
	 int distancia;
	 int numero;
	 int anterior;
	 int capacidad;
};

#endif
