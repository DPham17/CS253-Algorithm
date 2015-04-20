//Dzu Pham
//InsertionSort.cpp
//Test Insertion Sort for how long it takes to run

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
using namespace std;

int generateNum(int num);

int downNum(int num);

void insert(int p[], int num);

void output(int p[], int num); //outputs the array

//====================================================

int main()
{
	int num = 110000; //Can change the size of array for larger check
	//1 million is the largest we can go...
	int p[num];
	int bigBaby [num]; 
	
	for(int i=0; i<num; i++) //sets the array with numbers
	{
		p[i] = generateNum(100+i); //Random
		//p[i] = i;  								 //Sorted
		//p[i] = downNum(num);         //Backwards
	}
	//output(p,num);
	cout << endl;
	insert(p, num);

	return 0;
}

//=====================================================

int generateNum(int num) //makes a random number
{
  int secret;
  
  srand(time(NULL));

  secret = rand() % num +1;

  return secret;
}

int downNum(int num) //backwards
{
	static int check=num;
	return check--;
}

void insert (int p[], int num)
{
	int STime, ETime, TTime;
	int key=0, j=0;
	
	STime = time(0); //Start the time
	for(int i=1; i<num; i++)
	{
		key = p[i];
		j = i - 1;
		while ((j>=0) && (p[j]>key))
		{
			p[j+1] = p[j];
			j--;
		}
		p[j+1] = key;
	}
	ETime = time(0);
	
	TTime = ETime - STime;
	//output(p, num);
	cout << "Start Time " << STime << ", End Time " << ETime << endl;
	cout << "Run Time " << TTime << " seconds." << endl;
	
	return;
}

void output(int p[], int num)
{
	for(int k=0; k<num; k++) //lets you see the array before it is sorted
	{
		cout << p[k] << " ";
	}
	cout << endl;
}


