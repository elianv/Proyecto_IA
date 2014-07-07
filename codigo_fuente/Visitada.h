
#ifndef VISITADA_H
#define VISITADA_H

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

class Visitada{
	public:
	 Visitada(int,int,int);
	 void setDatos(int,int,int);
	 int getNumero() const;
	 int getX() const;
	 int getY() const;
	
	private:
	 int numero;
	 int x;
	 int y;
};

#endif
