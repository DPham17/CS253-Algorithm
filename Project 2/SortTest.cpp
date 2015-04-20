//Dzu Pham and Anton Strickland
//SortTest.cpp
//This program is to run Insertion sort, Merge Sort, and Heap sort. It will
//  put the three sorts to the test with different arrays, with different sizes.

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <cassert>
#include <ratio>
#include <chrono>
#include <limits>
#include "SortTest.h"
using namespace std;
using namespace std::chrono;

//====================================================
int heapsize=0, length=0;

int main()
{
  int num = 10000; //Can change the size of array for larger check
  int p[num];
	
  for(int i=1; i<num; i++) //sets the array with numbers
  {
    p[i] = generateNum(100+i); //Random
    //p[i] = i;  		     //Sorted
    //p[i] = downNum(num);     //Backwards
  }
  //output(p,num);
  //cout << endl;
  length = num;
  cout << "Array of size " << num << endl;
	
	//run time--------
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	//===sorts===
	//insert(p, num);
  //mergeSort(p, 1, num);
  heapSort(p);
  //output(p,num);

  //end run time -------
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	std::cout << "It took me ----------------" << time_span.count() << " seconds.";
  std::cout << std::endl;
 
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
	static int check=num-1;
	return check--;
}

void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
}
//--------------------------------------------------------------
void insert (int p[], int num)
{
  //pre-condition: array exist
	//output(A,num);
  	
	int STime, ETime, TTime;
  int key=0, j=0;
  
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
    //invariant: Key will hold the greates number in the array
		//assert(key >= p[j-1]);
		//assert(p[j-1] <= p[j]);

  }
  
  //post-condition: the array is sorted in order
  //output(p, num);
  return;
}
//--------------------------------------------------------------
void mergeSort(int A[], int p, int r)
{
	int q;
	//pre-condition: array exist
	//output(A,length);
	
	if(p<r)
	{
		q = (p+r)/2;
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,q,r);
		
	}

	//post-condition: the array is not sorted
	//output(A,length);
	return;
}

void merge(int A[], int p, int q, int r)
{
	int n1, n2, i, j, *L, *R;
  n1 = q-p+1;
  n2 = r-q;
  L = new int [n1+1];  
  R = new int [n2+1];
  for (int i=1; i<=n1; i++)
  {
    L[i] = A[p+i-1]; 
  }
  for (int j=1; j<=n2; j++)
  {
    R[j] = A[q+j];
  }
  L[n1+1] = std::numeric_limits<int>::max();
  R[n2+1] = std::numeric_limits<int>::max();
  i = 1;
  j = 1;
  for (int k=p; k<=r; k++)
  {
    if (L[i] <= R[j])
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
    //invariant: the right array conatins the correct numbers
    //output(R,n2);
    //assert(L[i-1] <= A[k] && R[j-1] <= A[k]);
  }
}
//--------------------------------------------------------------
void heapSort(int A[])
{
  //pre-condition: array exist
	//output(A,length);
	//the pre and post is taken care in this function as it is the
	//   one that calls the other two funcions.
	
	buildHeap(A);
  for (int i=length; i>=2; i--)
  {
    swap(A[1],A[i]);
    heapsize--;
    maxHeapify(A, 1);
		//invariant: check as the array gets sorted from least to greatest
    //output(A,length);
    //assert(A[i-1] <= A[i]);
    //assert(A[i] > A[i*2]);
	}
  
	//post-condition: The array is now sorted
	//cout << length << endl;
	//output(A,length);
}

void buildHeap(int A[])
{
	heapsize = length;
	
	for(int j = (length/2); j>=1; j--)
	{
		maxHeapify(A,j);
	}
}

void maxHeapify(int A[], int i)
{
  int l, r, largest=0;
  l = i*2;
	r = (i*2)+1;
  if (l <= heapsize && A[l] > A[i])
    largest = l;
  else
    largest = i;
  if (r <= heapsize && A[r] > A[largest])
  {
    largest = r;
  }
  if(largest != i)
	{
		swap(A[i],A[largest]);
    maxHeapify(A, largest);
  }
}
//--------------------------------------------------------------
void output(int p[], int num)
{
  for(int k=1; k<num; k++) //lets you see the array before it is sorted
  {
    cout << p[k] << " ";
  }
  cout << endl;
}
