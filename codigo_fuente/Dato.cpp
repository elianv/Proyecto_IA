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
/*
Dato::Dato(){
	distancia = 0;
	numero = 0;
	anterior = 0;
	capacidad = 0;
}
*/
Dato::Dato(int newDistancia, int newNumero ,int newAnterior, int newCapacidad){
	distancia = newDistancia;
	numero = newNumero;
	anterior = newAnterior;
	capacidad = newCapacidad;
}

int Dato::getDistancia() const{
	return distancia;
}

int Dato::getNumero() const{
	return numero;
}

int Dato::getAnterior() const{
	return anterior;
}

int Dato::getCapacidad() const{
	return capacidad;
}

void Dato::setDistancia(int newDistancia){
	distancia = newDistancia;
}

void Dato::setNumero(int newNumero){
	numero = newNumero;
}

void Dato::setAnterior(int newAnterior){
	anterior = newAnterior;
}

void Dato::setCapacidad(int newCapacidad){
	capacidad = newCapacidad;
}
