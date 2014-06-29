#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <sstream>
#include <math.h> 

using namespace std;

int **travel_times;
class City{
public:
 int demand;
 int x_coord;
 int y_coord;
};
City *cities;
int DIM,CAP,NUMV;

//declaraciones de funciones
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);
void show_distance_matrix(int **&matrix, int size);
void calculate_distances();

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
		for (int i = 0; i < DIM; ++i)
			free(travel_times[i]);
		free(travel_times);
		free(cities);

	}
	else
	{
		std::cout << "Unable to open file";
		return -1;
	}

	return 0;
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
				tmp_dist_x=abs(cities[i].x_coord-cities[j].x_coord);
				tmp_dist_y=abs(cities[i].y_coord-cities[j].y_coord);
				tmp_dist=tmp_dist_x+tmp_dist_y;
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

void show_distance_matrix(int **&matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}