//Dzu Pham
//LCS.h
//header file to LCSTest.cpp

#include <iostream>
#include <string>
#ifndef LCS_H
#define LCS_H

class LCS
{
		
		int DNA1, DNA2, w, h;
		string LCS1 [DNA1][DNA2];
		int LCS2 [DNA1][DNA2];
		char Str1[DNA1]; //Fragment of the DNA
		char Str2[DNA2]; //Long Piece
	 
  public:
  	
  	LCS() //Deafult constructor
  	{
  	  DNA1 = 10;
			DNA2 = 15;
			w = DNA1;
  		h = DNA2;
  	  GenOrder(Str1); //Makes fragment DNA
  	  GenOrder(Str2); //Makes main DNA
  	}
  	
  	~LCS(string LCS1 [], int LCS2 []) //Destructor
  	{
  	  for (int k=0; k<w; k++) //De-allocating
      {
        delete[] LCS1[k];
      }
      delete[] LCS1;
      LCS1 = NULL;
      for (int k=0; k<w; k++) //De-allocating
      {
        delete[] LCS2[k];
      }
      delete[] LCS2;
      LCS2 = NULL;
  	}
  	
  	/*void MakeLCS() //makes a 2d array
  	{
			LCS1 = new string* [w]; //creating a 2d array
      for (int k=0; k<w; k++)  //Allocating
      {
        LCS1[k] = new string[h];
      }
			
			LCS2 = new int* [w]; //creating a 2d array
      for (int k=0; k<w; k++)  //Allocating
      {
        LCS2[k] = new int[h];
      }
  	}*/
  	
  	void GenOrder ()//makes an order DNA strand
  	{
  		for (int i=0; i<=DNA1; i+5) //creates and ordered DNA string
  		{
				Str1 [i] = "A";
				if((i+1) <= w)
  			  Str1 [i+1] = "C";
		    if((i+2) <= w)
  			  Str1 [i+2] = "G";
  			if((i+3) <= w)
				  Str1 [i+3] = "T";
  		}
  		
  		for (int i=0; i<=DNA2; i+5) //creates and ordered DNA string
  		{
				Str2 [i] = "A";
				if((i+1) <= w)
  			  Str2 [i+1] = "C";
		    if((i+2) <= w)
  			  Str2 [i+2] = "G";
  			if((i+3) <= w)
				  Str2 [i+3] = "T";
  		}
  	}
  	
  	/*void RandOrder() //makes an DNA in Random order
		{	
  		for (int i=0; i<=DNA1; i++) //random generated DNA
  		{
  			int k;
				k = rand()%4 + 1;
  			if (k == 1)
  			  Str1 [i] = "A";
				if (k == 2)
  			  Str1 [i] = "C";
		    if (k == 3)
  			  Str1 [i] = "G";
  			if (k == 4)
				  Str1 [i] = "T";
  		}
  		for (int i=0; i<=DNA2; i++) //random generated DNA
  		{
  			int k;
				k = rand()%4 + 1;
  			if (k == 1)
  			  Str2 [i] = "A";
				if (k == 2)
  			  Str2 [i] = "C";
		    if (k == 3)
  			  Str2 [i] = "G";
  			if (k == 4)
				  Str2 [i] = "T";
  		}
  	}*/
  	
  	/* LCS Operations */
  	
  	void LCSLength(char& Str1 [], char& Str2 [], string LCS1 [], int LCS2 [])
  	{
			//idk make a new array or what??
			//MakeLCS();
			for (int i = 1; i<=w; i++)
  		{
  			LCS2[i,0] = 0;
  		}
  		for (int j=0; j<=h; j++)
  		{
  			LCS2[0,j] = 0;
  		}
  		for(int k=1; k<=w; k++)
  		{
  		  for(int p=1; p<=h; p++)
  		  {
  		    if (Str1[k] == Str2[k])
  		    {
  		      LCS2[k,p] = LCS2[k-1,p-1]+1;
  		      LCS1[k,p] = "bt"; //bu = back top
  		    }
  		    else if (LCS2[k-1,p] >= LCS2[k,p-1])
  		    {
  		      LCS2[k,p] = LCS2[k-1,p];
  		      LCS1[k,p] = "up";
  		    }
  		    else 
  		    {
  		      LCS2[k,p] = LCS2[k,p-1];
  		      LCS1[k,p] = "back";
  		    }
  		  }
  		}
  	}
  	
  	int getWidth()
  	{
  		return w;
  	}
  	
  	int getHeight()
  	{
  		return h;
  	}
  	
  	void output(int w, int h, string LCS1 []) //output the LCS
  	{
  		if (w==0 || h==0)
  		  return;
  		if (LCS1[w,h] == "bt")
  		{
  			output(w-1, h-1);
  			cout << Str1[w] << endl;
  		}
  		else if (LCS1[w,h] == "up")
  		  output(w-1,h, LCS1);
		  else
		    output(w,h-1), LCS1;
  	}
  	
  	
  	
  	
}

#endif
