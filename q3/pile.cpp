#include "pile.h"

void swap (int &n, int &m)
{
	int temp;
	temp = n;
	n = m;
	m = temp;
}

//insert fix
//It means everything above index i is minimum heap
void MinHeapInsertFix(int a[], int i)
{
	int j=(i-1)/2; // j is i's father node
	
	while (j>=0 && i>0)
	{
		if (a[j]>a[i])
		{
			swap(a[i],a[j]);
		}
		i=j;
		j= (j-1)/2;		
	}
}

//delete fix 
//It is minimum heap, so suspect element shall go down from a[0]
//It means everything below index i is min heap
void MinHeapFixDown(int a[], int i, int n)
{
	int temp;		// swap temporary element
	int j=2*i+1; // j is i's child left node
	//cout<<"Input i="<<i<<" j="<<j<<" n="<<n<<endl;
	while (j<n)
	{
		// find min value between left and right nodes
		//cout<<" while j="<<j<<endl;
		
		if ((j+1)<n && (a[j]>a[j+1]))
		{
			j=j+1;   //find index of less value node
		}
		//cout<<"a[i]="<<a[i]<< " a[j]="<<a[j]<<" a[j+1]="<<a[j+1]<<endl;
		if (a[i]>a[j])
		{
			//father is bigger than child, swap
			swap(a[i],a[j]);
			i=j;
			j= 2*i+1;
		} else {
			//father is less than all nodes
			break;
		}				
	}
}

// Heap always delete a[0];
void MinHeapDeleteIdxZero(int a[],int n)
{
	swap(a[0],a[n-1]);
	MinHeapFixDown(a,0,n-1);
}


void printIntArray(int intArray[], int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<intArray[i]<<" ";
	}
	cout<<endl;
}

void BuildMinPile(int a[],int n)
{
	for (int i=(n-1)/2; i>=0;i--)	// leaf node is already in correct position
	{		
		// only need to adjust the the node has its children
		//cout<<"-------sink "<<a[i]<<"-------"<<endl;
		MinHeapFixDown(a,i,n);
		//printIntArray(a,n);
	}
}

/*
int main()
{
    int testArray1[] = {6,8,10,11,19,15,20,21,17,7};
	int testArray2[] = {9,12,17,30,50,20,60,65,4,49,5};
	//MinPileFixUp(testArray1,9);   //fix value 7
	//BuildMinPile(testArray2,sizeof(testArray2)/sizeof(int));
	//printIntArray(testArray2, sizeof(testArray2)/sizeof(int));
	BuildMinPile(testArray2,10);   // heap is build till a[9]=49
	printIntArray(testArray2, 10);	//size==10
	MinHeapInsertFix(testArray2,10);   // insert value 40 to array[10]
	printIntArray(testArray2, 11);	//size == 11
	MinHeapDeleteIdxZero(testArray2,11);
	printIntArray(testArray2, 10);	//size==10
}
*/