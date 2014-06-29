#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

int *demand;
int **travel_times;


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
		int DIM = ::atof(split(line,' ')[1].c_str());
		getline(myfile,line); // Capacity
		int CAP = ::atof(split(line,' ')[1].c_str());
		getline(myfile,line); // No Vehicles
		int NUMV = ::atof(split(line,' ')[1].c_str());
		getline(myfile,line); // EdgeType
		getline(myfile,line); // EdgeWeight
		getline(myfile,line); // NodeCoordT
		getline(myfile,line); // NodeCordSect
		for (int i = 0; i < DIM-1; ++i)
		{
			


		}
		while (!myfile.eof())
		{
			//std::cout << "line: ";
			getline(myfile,line);
			if (line.empty()) continue;
			std::vector<std::string> x = split(line, ' ');
			std::cout << line + '\n';

			//aux_coord.x = ::atof(x[0].c_str());
			//aux_coord.y = ::atof(x[1].c_str());
			//result.push_back(aux_coord);
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open file";
		return -1;
	}
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