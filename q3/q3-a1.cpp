#include "pile.h"
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <windows.h>
#include <stdio.h>

#define MAX 10000

void FindMaxTen(int a[], int maxTen[])
{

}

int main()
{
	int maxTen[10];
	int store[MAX];
	
	srand( (unsigned)time( NULL ) );
	int int_limit = numeric_limits<int>::max();
	cout<<"int limit is: "<<int_limit<<endl;
	for (int i=0;i<MAX;i++)
	{
		store[i] = rand() % int_limit;
	}
	
	/*
	for (int i=0;i<MAX;i++)
	{
		cout<< store[i] << " ";
	}
	*/
	
	//pick first 10 to build a minimize heap
   SYSTEMTIME sys, sys2; 
   GetLocalTime( &sys ); 
   printf("%4d/%02d/%02d %02d:%02d:%02d.%03d\n",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond,sys.wMilliseconds);
	
	for (int i=0;i<10;i++)
	{
		maxTen[i]=store[i];
	}
	BuildMinPile(maxTen,10);
	printIntArray(maxTen, 10);
	for (int i=10;i<MAX;i++)
	{
		if (store[i] > maxTen[0])
		{
			//if next query element is bigger than top value on min heap
			maxTen[0] = store[i];
			MinHeapFixDown(maxTen,0,10);
		}
	}
    GetLocalTime( &sys2 ); 
    printf("%4d/%02d/%02d %02d:%02d:%02d.%03d\n",sys2.wYear,sys2.wMonth,sys2.wDay,sys2.wHour,sys2.wMinute, sys2.wSecond,sys2.wMilliseconds);
	
	printIntArray(maxTen, 10);
	return 0;
}
