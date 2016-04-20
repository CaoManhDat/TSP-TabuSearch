#include "map.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include <stdlib.h>

using namespace std;

std::string DIMESION_PROPERTY = "DIMENSION";
std::string BEST_PROPERTY = "BEST";
std::string START_VERTEX_PAGE = "NODE_COORD_SECTION";

double sqr(double x){
	return x*x;
}

double Map::getDistance(int vertexA, int vertexB){
	double distance = sqrt(
								sqr( this->coordinate[vertexA][0] - this->coordinate[vertexB][0] )
								+ sqr( this->coordinate[vertexA][1] - this->coordinate[vertexB][1] )
							);
	return distance;
}

Map::Map(string filePath){
	string line;
	cout << endl;
	cout << "Giai bai toan " << filePath << endl;
	ifstream dataFile;
	dataFile.open(filePath.c_str());
	if(dataFile.is_open()){
		bool vertexDataRegion = false;
		while(dataFile.good()){
			getline(dataFile,line);

			if(vertexDataRegion){
				int vertexId;
				double posX;
				double posY;
				sscanf(line.c_str(), "%d %lf %lf", &vertexId,&posX,&posY);
				vertexId--; // we store vertex from 0

				this->coordinate[vertexId][0] = posX;
				this->coordinate[vertexId][1] = posY;
			}

			if(line.find(DIMESION_PROPERTY) == 0){
				unsigned int index = 0;
				for(; index < line.size(); index++){
					if ( line[index] >= '0' && line[index] <= '9') break;
				}
				this->numVertex = atoi(line.substr(index,100).c_str());
				cout << "So dinh : " << this->numVertex << endl;

				this->coordinate = new double*[this->numVertex];
				for(int i = 0; i < this->numVertex; i++){
					this->coordinate[i] = new double[2];
				}
			}

			if(line.find(BEST_PROPERTY) == 0){
				int bestValue;
				unsigned int index = 0;
				for(; index < line.size(); index++){
					if ( line[index] >= '0' && line[index] <= '9') break;
				}
				bestValue = atoi(line.substr(index,100).c_str());
				cout << "Loi giai toi uu : " << bestValue << endl;
			}

			if(line.find(START_VERTEX_PAGE) == 0){
				vertexDataRegion = true;
			}
		}
		dataFile.close();
	}
}

void Map::free(){
	for(int i = 0; i < this->numVertex; i++){
		delete [] this->coordinate[i];
	}
	delete [] this->coordinate;
}
