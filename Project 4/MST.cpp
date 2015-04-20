//Dzu Pham
//MST.hpp
//This file contains the functions to create the Minimal spanning tree

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
#include "map.h"

using namespace std;


// to find the vertex with minimum key value, from the set of vertices
int minKey(int key[], bool mstSet[], int places)
{
  int V = places;
	// Initialize min value
  int min = 1000, min_index;
 
  for (int v = 0; v <= V; v++)
  {
    if (mstSet[v] == false && key[v] < min)
    {
      min = key[v];
		 min_index = v;
		}
	}
 
  return min_index;
}
 
//to print the constructed MST stored in parent[]
int printMST(int parent[], int places, float **graph, string city[], float point[][2])
{
  for (int i = 1; i < places; i++)
  {
   	cout << i << " - " << city [i] << " to " <<  parent[i] << " - " << city[parent[i]];
		cout << "  " << graph[i][parent[i]] << endl;
	}
	 
	/*ofstream output;
	output.open("C:\\KMLTest.txt");
	 
	for (int i = 1; i < places; i++)
  {
     //This prints out in KML format to be put into Google Map engine
		output << "  <Placemark>"  << endl;
		output << "    <name>" << city [i] << " to " <<  city[parent[i]] << "</name>" << endl;
		output << "    <LineString>" << endl;
		output << "      <extrude>1</extrude>" << endl;
		output << "      <tessellate>1</tessellate>" << endl;
		output << "      <coordinates>" << endl;
		output << "       -" << point[i][1] << "," << point[i][0] << ",0  -" << point[parent[i]][1] << "," << point[parent[i]][0] << ",0" << endl;
		output << "      </coordinates>" << endl;
		output << "    </LineString>" << endl;
		output << "  </Placemark>"  << endl;
	}
	output.close();*/
}

// construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(float **graph, int places, string city[], float point[][2])
{
  int V = places;
	int parent[V]; // Array to store constructed MST
  int key[V];   // Key values used to pick minimum weight edge in cut
  bool mstSet[V];  // To represent set of vertices not yet included in MST
 
  // Initialize all keys 
  for (int i = 0; i <= V; i++)
  {
    key[i] = 1000;
		mstSet[i] = false;
	}
 
  // Always include first 1st vertex in MST.
  key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
  parent[0] = -1; // First node is always root of MST 
 
  for (int count = 0; count <= V-1; count++)
  {
     int u = minKey(key, mstSet, places);
 
    // Add the picked vertex to the MST Set
    mstSet[u] = true;
 
    for (int v = 0; v <= V; v++)
    { 
      // graph[u][v] is non zero only for adjacent vertices of m
      // mstSet[v] is false for vertices not yet included in MST
      // Update the key only if graph[u][v] is smaller than key[v]
      if ((graph[u][v] && mstSet[v]) == false && (graph[u][v] <  key[v]) && (graph[u][v] > 0))
      {
        parent[v]  = u;
			   key[v] = graph[u][v];
      }
    }
  }
  // print the constructed MST
  printMST(parent, places, graph, city, point);
}
