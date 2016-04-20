#include "solution.h"
#include <iostream>
#include <time.h>
#include <stdlib.h> 

using namespace std;
Solution::Solution(Map* map){
	this->map = map;
	v = new int[map->numVertex];
	score = 0;
	initSolution();
}

void Solution::initSolution(){
	for(int i = 0; i < map->numVertex; i++){
		this->v[i] = i;
	}
	srand(time(NULL));
	for(int i = (map->numVertex - 1); i >= 0; i--){
		int j = rand() % map->numVertex;
		swap(this->v[i], this->v[j]);
	}
	computeScore();
}

void Solution::computeScore(){
	score = 0;
	for(int i = 0; i < (map->numVertex - 1); i++){
		score += map->getDistance(this->v[i], this->v[i+1]);
	}
	score += map->getDistance(this->v[map->numVertex-1], this->v[0]);
}

void Solution::printPath(){
	cout << "Duong di : ";
	for(int i = 0; i < map->numVertex; i++){
		cout << this->v[i] << " ";
	}
	cout << endl;
}

int Solution::getV(int key){
	return this->v[key];
}
void Solution::set(int key, int value){
	this->v[key] = value;
}

void Solution::swapSolve(int i, int j){
	swap(this->v[i],this->v[j]);
}

double Solution::getScore(){
	computeScore();
	return score;
}

void Solution::free(){
	delete [] this->v;
}
