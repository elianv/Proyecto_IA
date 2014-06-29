#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <sstream>

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


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);
void show_matrix(int **&matrix, int size);

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

		myfile.close();
	}
	else
	{
		std::cout << "Unable to open file";
		return -1;
	}


	for (int i = 0; i < DIM; ++i)
		free(travel_times[i]);
	free(travel_times);
	free(cities);

	return 0;
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

void show_matrix(int **&matrix, int size)
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