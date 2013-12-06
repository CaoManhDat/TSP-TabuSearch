#ifndef TSP_TABU_SOLVER_H
#define TSP_TABU_SOLVER_H

#include "map.h"
#include "solution.h"
class TSPTabuSolver{
	public:
		TSPTabuSolver(string filePath);
		void solve(int);
		Solution* getBestNearbySolution(int);
		void resetTabuList();
	private:
		double bestSolverScore;
		int** tabu_list;
		int** tabu_f_list;
		Map* map;
		Solution* s;
};

#endif
