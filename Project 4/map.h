//Dzu Pham
//maps.h
//header file to expmap.cpp

#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <cassert>
#include <ratio>
#include <math.h>
#include <fstream>
#ifndef MAP_H
#define MAP_H

using namespace std;

//Convertes degrees and min into coordinates
//Pre: 
//Post:returns coordinates
float convert(float degree, float min);

//Takes 2 points (x1,y1) and (x2,y2) and uses the distance formula
//Pre:
//Post:returns distnce between two points
float distance(float& x1, float& y1, float& x2, float& y2);

// to find the vertex with minimum key value, from the set of vertices
//Pre: Key[] must be filled and mstSet contains the true false
//Post:returns the vertext with the min value
int minKey(int key[], bool mstSet[], int places);

//Prints out the MST to show correctness
//Pre:primMST must pass in the MST 
//Post:outputs the MST
int printMST(int parent[], int places, float **graph, string city[], float point[][2]);

//This calculates the MST
//Pre:The 2d graph that is passed in must be filled with the weighted 
//     connections.
//Post:this will call printMST to display the MST
void primMST(float **graph, int places, string city[], float point[][2]);

#endif
