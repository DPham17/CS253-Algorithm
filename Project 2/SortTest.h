//Dzu Pham and Anton Strickland
//SortTest.h
//refer to SortTest.cpp for description

#include <iostream>
#include <string>
#ifndef SORTTEST
#define SORTTEST

using namespace std;

//This is to generate an array of numbers of random numbers.
int generateNum(int num);

//This is to generate an array of backwards sorted numbers
int downNum(int num);

//A simple function to swap two elements passed in
void swap(int &x,int &y);

//Insertion sort
//Pre:The array is not of size zero and is of size 1 or greater
//Post:The array is sorted from least to greatest
void insert(int p[], int num);

//Merge Sort
//Pre:The array exist and of size of the array is greater then 2
//Post:The array will be returned sorted
void mergeSort(int A[], int p, int r);

//This will break down the array into little chuncks for merge sort
//Pre:An array exist and is of size greater then 2
//Post:This will breake the array down in half for the merge sort, 
//     then it will combine the arrays back into one.  
void merge(int A[], int p, int q, int r);

//This is the function that takes the input array and builds it into a heap
//Pre:There must be a valid array passed into the function
//Post:this will return an array that maxHeapify can use to sort
void buildHeap(int A[]);

//The main function that is called, this is the driver function for heap.
//Pre:A valid array must be passed in for the heap to work
//Post:Will call heapSort and end up with a sorted array of numbers.
void maxHeapify(int A[], int i);

//The body of the heap algorithm, this is where the array gets sorted
//Pre:all conditions are met through the other 2 heap functions.
//Post:the root and childs are in the correct order and the array is sorted.
void heapSort(int A[]);

//A post condition that outputs the array for visual use
void output(int p[], int num); 

#endif
