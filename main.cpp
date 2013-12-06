#include <iostream>
#include "tsptabusolver.h"
using namespace std;


int main(int argc, char* argv[]){

	TSPTabuSolver solver2("tsp0.txt");
	solver2.solve(6);	
	TSPTabuSolver solver1("tsp1.txt");
	solver1.solve(5);				

				

	TSPTabuSolver solver3("tsp2.txt");
	solver3.solve(7);				
	
	return 1;
}
