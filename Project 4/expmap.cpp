//Dzu Pham
//expmap.cpp
//This programs uses an Adjacency Matrix to store the connections of
//  what each city can connect to. Then uses Prim's Algorithm to 
//  see if it can find the MST from Washington to some hand pick 
//  city.

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <cassert>
#include <ratio>
#include <math.h>
#include <fstream>
#include <string>
#include "map.h"
//#include <chrono>
//#include <limits>
using namespace std;
//using namespace std::chrono;

/*----==MAIN==----*/
int main ()
{
	int size=2000;
	//creat 2 arrays, one string and one 2d array
	//2d array, top row is long and bottom is lat
	string city[size];
	float point[size][2]; //top row is Longitude and bottom is Latitude
	float degree1, degree2, min1, min2, dis; //dis = distane of between 2 points
	string direction, state, cityName;
	int times, loc, places=0; //places = total number of cities
	string **cityCon; //stores what this city is connected to
	float **map; //stores the distance between the city
	cityCon = new string* [size];
	map = new float* [size];
	for(int i=0; i<size; i++)
	{
		cityCon[i] = new string[size];
		map[i] = new float[size];
	}

  //Pre condition: City[], point[][], cityCon[][] and map[][] are valid arrays

	ifstream fin; //Stream class to read from file
	fin.open ("Major C.txt");

	times = 4;
	
	do
	{
		fin >> state;
		//cout << state << endl;
		fin >> loc;
	  //cout << "loc " << loc << endl << endl;
	  
		for(int i=0; i<loc; i++)
		{
			fin >> cityName;
			//cout << cityName << endl;
			//puts city into array
			city[places+i] = cityName;
			//cout << "--------" << city[places+i] << endl;
			
			//location of each city
	    fin >> degree1;
	    fin >> min1;
	    fin >> direction;
	    //cout << "degree :" << degree1 << " min :" << min1 << " direction :" << direction << endl;
      //the Latitude, y axis
			point[places+i][0] = convert(degree1,min1); //convert degree and min into point
			fin >> degree2;
	    fin >> min2;
	    fin >> direction;
	    //cout << "degree :" << degree2 << " min :" << min2 << " direction :" << direction << endl;
      //the Longitude, x axis
			point[places+i][1] = convert(degree2,min2); //convert degree and min into point
			//cout << "  " << point[places+i][0] << " " << point[places+i][1] << endl;
	    //Invariant: point[][] is updated with the coordinates and mataches with the city stores in city[]
		}
		places = places + (loc);
		times--;
	}while(times > 0);
	
	/*for (int i=0; i<places; i++)
	{
		cout  << "point is " << i << "  " << point[i][0] << " " << point[i][1] << endl;
	}*/
	
	//Post Condition: point[][] and city[] contains all of the input of the file
	
	//Graph* citites = new Graph[places];
	for(int i=0; i<places; i++) //this loop is to start the MST 
	{
    
		//citites[i].name(city[i]);
		cityCon[i][0] = city[i]; //puts the frist row with the city name
		//cout << "   " << cityCon[i][0] << "-------------- #" << i << endl;
		for(int k=0; k<places; k++) //compares it to each one to see if it can connect
		{ 
		  // distance (x1, y1, x2, y2) and use distnace formula
			//cout << point[i][1] << " " << point[i][0] << " " << point[k][1] << " " << point[k][0] << endl;
			dis = distance(point[i][1],point[i][0],point[k][1],point[k][0]);
			if (dis <= 10) //SIZE OF THE HIGHWAY!!! you set it here
			{
			  cityCon[i][k] = city[k]; //stores what this city is connected to
				map[i][k] = dis; //stores the distance between the city
				//cout << " to " << cityCon[i][k] << " is " << map[i][k] << endl;
			}
			else 
			{
				cityCon[i][k] = "null";
				map[i][k] = 0;
				//cout << " Not Connected to " << city[k] << " distance is " << dis << endl;
			}
		}
	}
	
	//Pre condition: map[][] contains the weighted connection
	//Invariant: minKey() returns the vertext that is the min value
	primMST(map, places, city, point);
	//post condition: PrintMST() is called to display the MST
			
	
	//delete [] citites;
	for (int k=0; k<size; k++) //De-allocating
  {
    delete[] cityCon[k];
    delete[] map[k];
  }
  delete[] cityCon;
  delete[] map;
  cityCon = NULL;
  map = NULL;
	
	fin.close();
	return 0;
}

float convert(float degree, float min)
{
	min = min/60;
	return (degree + min);
}

float distance (float& x1, float& y1, float& x2, float& y2)
{
	float x, y;
	x = pow((x1-x2),2);
	y = pow((y1-y2),2);
	return pow((x+y),0.5);
}

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
	output.open("Y:\\KMLTest.txt");

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

