#ifndef MAP_H
#define MAP_H

#include <string>

using namespace std;
class Map{
	public:
		int numVertex;
		double** coordinate;
		Map(string file);
		double getDistance(int,int);
		string file;
		void free();
};

#endif
