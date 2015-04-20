//Dzu Pham
//LCSTest.cpp
//Creating small fragment of DNA string to test the Longest common string to a 
//  large DNA string.

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <cassert>
#include <ratio>
#include <chrono>
#include <limits>
#include <string>

using namespace std;
using namespace std::chrono;

//Generates the 2 DNA arrays, It contains different ways to generate the arrays
//Pre:two characters must exist
//Post:fills the characters array with A C G T characters
void GenOrder (char Str1[], char Str2[], int DNA1, int DNA2);

//Pre test for LCSLength to show that there are two valid filled character array
//Pre:two character arrays must exist
//Post:Displays the two arrays
void output (char Str1[], char Str2[], int DNA1, int DNA2);

//The algorithm that generates two 2D arrays and finds the length of the LCS
//Pre:The two character arrays must exist and be filled with valid characters
//Post:The LCS length is found and the 2nd 2D array is passed on
void LCSLength(char Str1 [], char Str2 [], int DNA1, int DNA2);

//Post condition for the LCSLength, show that a valid LCS was found
//Pre:A 2D array of breadcrumbs is passed in with the smaller DNA fragment
//Post: Display the 2D array showing the LCS that it contains
void printLCS(int i, int j, int** LCS1, char Str1 []);

//Cleans up the 2D arrays so that no data is left in the system
//Pre:2D array is still alive!!!
//Post:Now its dead!! :(
void clear (int **LCS1, int **LCS2, int m, int n);

int main()
{
	int time = 0;
	int DNA1 = 10000, DNA2 = 10000;
	char Str1[DNA1]; //Fragment of the DNA
	char Str2[DNA2]; //Long Piece
	
	do
	{
		time++;	
		cout << time << ".) ";
		
		GenOrder(Str1, Str2, DNA1, DNA2);
		
		//run time--------
  	high_resolution_clock::time_point t1 = high_resolution_clock::now();
		
		//Pre: Str 1 and Str2 was valid char arrays with output 
		//     function at the end of genorder
	  LCSLength(Str1, Str2, DNA1, DNA2);	  
	  //Post: at the end of LCSLength, the LCS was output to show the correctness of 
    //      the program
    
    //end run time -------
	  high_resolution_clock::time_point t2 = high_resolution_clock::now();
	  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	  std::cout << "It took me ----------------" << time_span.count() << " seconds.";
    std::cout << std::endl;
	}while(time != 1);
	
	return 0;
}
//---------------------------------------------------------------------

void GenOrder (char Str1[], char Str2[], int DNA1, int DNA2)//makes an order DNA strand
{
  srand(time(NULL));
	for (int i=0; i<=DNA2; i++) 
  {
  	int k;
		k = rand()%4 + 1;
  	if (k == 1)
  	  Str2 [i] = 'C';
		if (k == 2)
  	  Str2 [i] = 'A';
		if (k == 3)
  	  Str2 [i] = 'T';
  	if (k == 4)
		  Str2 [i] = 'G';
 	}
 	
 	for (int i=0; i<=DNA1; i++) 
  {
    int k;
		k = rand()%4 + 1;
  	if (k == 1)
  	  Str1 [i] = 'A';
		if (k == 2)
  	  Str1 [i] = 'A';
		if (k == 3)
  	  Str1 [i] = 'A';
  	if (k == 4)
		  Str1 [i] = 'A';
  }
 	//output (Str1, Str2, DNA1, DNA2);
}


void LCSLength(char Str1 [], char Str2 [], int DNA1, int DNA2)
{

  int m = DNA1, n = DNA2;
	  
  int** LCS1 = new int* [m]; //creating a 2d array
  int** LCS2 = new int* [m];
  for (int k=0; k<=m; k++)  //Allocating
  {
    LCS1[k] = new int[n];
    LCS2[k] = new int[n];
  }
	//creating a 2d array
  for (int k=0; k<m; k++)  //Allocating
  {
    for(int p=0; p<n; p++)
    {
      LCS1[k][p] = 0;
    }
  }
	//-----------------------------
			
	for (int i = 1; i<=m; i++)
  {
    LCS2[i][0] = 0;
 	}
 	for (int j=0; j<=n; j++)
 	{
   	LCS2[0][j] = 0; 
  }
  for(int i=1; i<=m; i++)
  {
    for(int j=1; j<=n; j++)
    {
      if (Str1[i] == Str2[j])
      {
        LCS2[i][j] = LCS2[i-1][j-1]+1;
  	    LCS1[i][j] = 2; //2 = back top
  	    //assert(LCS2 [i][j]);
  	  }
  	  else if (LCS2[i-1][j] >= LCS2[i][j-1])
  	  {
  	    LCS2[i][j] = LCS2[i-1][j];
  		  LCS1[i][j] = 3; //3 = up
  		  //assert(LCS2 [i][j]);
  		}
  		else 
  		{
  		  LCS2[i][j] = LCS2[i][j-1];
  		  LCS1[i][j] = 1; //1 = back
  		  //assert(LCS2 [i][j]);
  		}
  	}
  	// Invariant: The LCS1 is up to date with the size of the LCS
  	//            while the LCS2 contains the points where the LCS
  	//            are to appear. 
  }
  cout << LCS2[m][n]; //this checks the LCS2 for the correctness of the length of the LCS
  //printLCS(m,n,LCS1,Str1); //Post: shows the LCS
  cout << endl;
  clear (LCS1, LCS2, DNA1, DNA2);
	return;
}
  	
//Displaying programs----------------------------------------
void	output (char Str1[], char Str2[], int DNA1, int DNA2)
{
  for (int i=0; i<=DNA1; i++)
  {
		cout << Str1[i];
	} 
	cout << endl;
	for(int k=0; k<=DNA2; k++)
	{
		cout << Str2[k];
	}
	cout << endl;
}
  	
void printLCS(int i, int j, int **LCS1, char Str1 []) 
{
  if (i==0 || j==0)
  	return;
  if (LCS1[i][j] == 2)
  {
  	printLCS(i-1, j-1,LCS1, Str1);
		cout << Str1[i] << " ";
  }
  else if (LCS1[i][j] == 3)
    printLCS(i-1,j, LCS1, Str1);
	else
	  printLCS(i,j-1, LCS1, Str1);	
}
  	
void clear (int **LCS1, int **LCS2, int m, int n)
{
	for (int i=0; i<m; i++) //De-allocating
  {
    delete[] LCS1[i];
    delete[] LCS2[i];
  }
  delete[] LCS1;
  delete[] LCS2;
  LCS1 = NULL;
  LCS2 = NULL;
}
