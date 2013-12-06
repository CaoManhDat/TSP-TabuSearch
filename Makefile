all: tsp_tabu

tsp_tabu: solution.o map.o tsptabusolver.o main.o
			g++ solution.o main.o map.o tsptabusolver.o  -g -o tsp_tabu
			

solution.o: solution.cpp solution.h
			g++ -Wall -g -c solution.cpp

map.o : map.cpp map.h
		g++ -Wall -g -c map.cpp

tsptabusolver.o : tsptabusolver.cpp tsptabusolver.h
					g++ -Wall -g -c tsptabusolver.cpp

main.o: main.cpp
		  g++ -Wall -g -c main.cpp



