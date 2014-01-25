#include <iostream>
#include <bitset>
#include <cmath>
#define MAX 1000

using namespace std;

static bitset<MAX> mybs;
bool is_primer2(int num) { 
  int i; 
  int upper = sqrt(num); 
  if (num<2)
	return false;
  
  for(i = 2; i <= upper; i++) { 
    if(num % i == 0) { 
      return false; 
    } 
  } 
  return true; 
}

void printArray()
{
	for (int i=0;i<MAX;i++)
	{
		if (mybs.test(i))
		{
			cout<<(i+1)<<" ";
		}
	}
	cout<<endl;
}

void load_primer_table2() {
 
  int i, j;
 
  for(i = 1; i <= MAX; i++) {
 
    if( i % 2) {
		mybs.set(i-1);
		//cout<<i<<" is prime"<<endl;
    } else { 
      mybs.reset(i-1); 
    } 
  } 

  //leave only odd value
  //but 1 should be removed
  // and 2 should be set
  mybs.reset(0);
  mybs.set(1);
  cout<<mybs<<endl;
  
  int upper = sqrt(MAX);
 
  for(i = 2; i <= upper; i++) {
    if(mybs.test(i-1)) { 
      for(j = i + i; j < MAX; j += i) 
        mybs.reset(j-1); 
    } 
  }
  
  cout<<mybs<<endl;
 }
 

 
 int main()
 {
	//cout<<is_primer2(1)<<endl;
	load_primer_table2();
	printArray();
 }