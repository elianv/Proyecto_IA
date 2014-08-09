#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <list>
#include <algorithm>
#include "Dato.h"
#include "Visitada.h"

using namespace std;

int **travel_times;

class City{
public:
 int demand;
 int x_coord;
 int y_coord;
};

City *cities;


int DIM,CAP,NUMV,VEH,Q;
vector<Visitada> Visitadas;
vector<Dato> ruta; //vector solucion
vector<Dato> BestSol;

//declaraciones de funciones
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);
void show_distance_matrix(int **&matrix, int size);
void imprimir_ruta();
void calculate_distances();
void MFC(int **&matrix,int size,int vehiculos);
void imprimir_visitadas();
int visited_city(vector<Visitada> &vector, int numero);
void copiar_vector();


int main()
{
	std::string filename = "archivo.vrp";
	std::string line;
	std::ifstream myfile(filename.c_str());
	if (myfile.is_open())
	{
		getline(myfile,line); // Name
		getline(myfile,line); // Type
		getline(myfile,line); // Comment
		getline(myfile,line); // Dimension
		DIM = ::atof(split(line,' ')[1].c_str());
		cities = new City[DIM];
		travel_times = new int*[DIM];
		for (int i = 0; i < DIM; ++i)
			travel_times[i] = new int[DIM];
		getline(myfile,line); // Capacity
		CAP = ::atof(split(line,' ')[1].c_str());
		getline(myfile,line); // No Vehicles
		NUMV = ::atof(split(line,' ')[1].c_str());
		getline(myfile,line); // EdgeType
		getline(myfile,line); // EdgeWeight
		getline(myfile,line); // NodeCoordT
		getline(myfile,line); // NodeCordSect
		for (int i = 1; i < DIM; ++i) // el nodo 0 será el galpón
		{
			getline(myfile,line);// línea de coordenadas
			cities[i].x_coord=::atof(split(line,' ')[1].c_str());
			cities[i].y_coord=::atof(split(line,' ')[2].c_str());
		}
		getline(myfile,line); // DEMAND SECTION
		for (int i = 1; i < DIM; ++i) // el nodo 0 será el galpón
		{
			getline(myfile,line);// línea de coordenadas
			cities[i].demand=::atof(split(line,' ')[1].c_str());
		}
		getline(myfile,line); // DEPO SECTION
		getline(myfile,line); // COORDS
		cities[0].x_coord=::atof(split(line,' ')[0].c_str());
		cities[0].y_coord=::atof(split(line,' ')[1].c_str());
		cities[0].demand=-1;

		calculate_distances();
		show_distance_matrix(travel_times,DIM);

		myfile.close();
		//for (int i = 0; i < DIM; ++i)
			//free(travel_times[i]);
		//free(travel_times);
		//free(cities);

	}
	else
	{
		std::cout << "Unable to open file";
		return -1;
	}
    
	Visitada Cliente(0,0,0);
	Visitadas.push_back(Cliente);
	
	Dato newDato(0,0,0,CAP);//Creo deposito 
	ruta.push_back(newDato);//agrego deposito a la solucion
	VEH = NUMV;
	Q = 0;
	MFC(travel_times,DIM,NUMV); 
	cout << "Mejor Solucion:";
		for(unsigned int i = 0; i < BestSol.size() ; i++)
			cout << BestSol[i].getNumero() <<"-";
	cout <<endl;		

	return 0;
}

void imprimir_ruta(){
	
	int distancia_total = 0;
	cout << "ruta :";
	for (unsigned int i = 0 ; i < ruta.size(); i++){
		cout << ruta[i].getNumero() << "-";
		distancia_total = ruta[i].getDistancia() + distancia_total;
	}
	cout << endl;
	//cout << "distancia total recorrida :" << distancia_total <<endl;
	

}

void calculate_distances()//rellena la matriz de distancias entre ciudades y el depot
{
	int tmp_dist,tmp_dist_x,tmp_dist_y;
	for (int i = 0; i < DIM; ++i)
	{
		for (int j = i; j < DIM; ++j)
		{
			if(i==j){
				travel_times[i][j]=0;
			}
			else{
				tmp_dist_x=abs(cities[i].x_coord-cities[j].x_coord)*abs(cities[i].x_coord-cities[j].x_coord);
				tmp_dist_y=abs(cities[i].y_coord-cities[j].y_coord)*abs(cities[i].y_coord-cities[j].y_coord);
				tmp_dist=ceil(sqrt(tmp_dist_x+tmp_dist_y));
				travel_times[i][j]=tmp_dist;
				travel_times[j][i]=tmp_dist;
			}
		}
	}
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        if(item.empty()) continue;
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

void show_distance_matrix(int **&matrix, int size )
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            //std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        //std::cout << std::endl;
    }
}

int visited_city(int numero)
{
	
	int j = 1;
	
	for (unsigned int i = 0 ; i < Visitadas.size(); i++){
		if (Visitadas[i].getNumero() == numero){
			j = 0;
		}	
	
	}
	return j;
}

void imprimir_visitadas(){
	
	
	cout << "visitadas :";
	for (unsigned int i = 0 ; i < Visitadas.size(); i++){
		cout << Visitadas[i].getNumero() << "-";
		//distancia_total = ruta[i].getDistancia() + distancia_total;
	}
	cout << endl;
	//cout << "distancia total recorrida :" << distancia_total <<endl;
}

void copiar_vector(){

	BestSol.clear();
	for (unsigned int i = 0; i < ruta.size() ;i++){
		int Distancia = ruta[i].getDistancia();
		int Numero = ruta[i].getNumero();
		int Anterior = ruta[i].getAnterior();
		int Capacidad = ruta[i].getCapacidad();
		Dato newDato(Distancia,Numero,Anterior,Capacidad);
		BestSol.push_back(newDato);
	}
	

}

void MFC(int **&matrix,int size,int vehiculos)
{
	
	for(int i = 0; i < size ; i++){
	
		//veo si esta visitada
		if( visited_city(i) ){
						
			//veo si tiene capacidad para entregar
			if( (ruta[ruta.size()-1].getCapacidad() - cities[i].demand) >= 0 ) {
				//cout << "dentro MFC" << endl;
				//creo el cliente a guardar
				int distancia_recorrida = matrix[ruta[ruta.size()-1].getNumero()][i] + ruta[ruta.size()-1].getDistancia();
				int capacidad = ruta[ruta.size()-1].getCapacidad() - cities[i].demand;
				
				Dato NewDato2(distancia_recorrida,i,ruta[ruta.size()-1].getNumero(),capacidad);
				ruta.push_back(NewDato2);
				
				Visitada Cliente(i,ruta[ruta.size()-1].getNumero(),i);
				Visitadas.push_back(Cliente);
				
				MFC(matrix,size,vehiculos);
				
				Visitadas.pop_back();
				ruta.pop_back();
				
				if(ruta[ruta.size()-1].getAnterior() == 0 && ruta.size() > 2){
					
					ruta.pop_back();
					VEH = VEH + 1;
					//imprimir_ruta();
					
				}
				
			}
			else{
					if (VEH > 0){
							int distancia_recorrida = matrix[ruta[ruta.size()-1].getNumero()][0] + ruta[ruta.size()-1].getDistancia();
							int numero = ruta[ruta.size()-1].getNumero();
							int CAPACIDAD = CAP;
							Dato Volver(distancia_recorrida,0,numero,CAPACIDAD);//Creo deposito 
	
							ruta.push_back(Volver);//agrego deposito a la solucion
							VEH = VEH -1; //que otro camion continue con la ruta
					}
					else{
							
							imprimir_ruta();
							if (Q == 0){
								copiar_vector();
								Q++;
							}
							if(ruta[ruta.size()-1].getDistancia() < BestSol[BestSol.size()-1].getDistancia())
							{
								copiar_vector();
							}
							

					}
			}

			
		}
		
		//cout << "vehiculos :"<< VEH<<endl;
		//cout << "capacidad :" << ruta[ruta.size()-1].getCapacidad() << endl;
	    //Visitadas.pop_back();
	    //ruta.pop_back();
	}
	
}
