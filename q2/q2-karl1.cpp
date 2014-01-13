#include <iostream>
#include <string>
#include <limits.h>        /* for CHAR_BIT */
#include "stdio.h"
#include "string.h"

#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)

using namespace std;

int findMappingIndex(char c)
{
	// a=97, z=122	-> 0..25
	// A=65, Z=90	-> 26..51
	// '0'=48, '9'=57	->52..61
	if (c>=97 && c<=122)
	{
		return c-97;
	} else if(c>=65 && c<=90)
	{
		return c-39;
	} else if(c>=48 && c<=57)
	{
		return c+4;
	} else {
		return -1;
	}
}

void printBitArray(char* ba, int n)
{
	for (int i=n-1;i>=0;i--)
	{
		cout<<(BITTEST(ba,i)!=0)<<" ";
	}
	cout<<endl;
}

bool findContain(char* a, char* b)
{
  
   char bitarray[BITNSLOTS(62)]="";  //26+26+10
   //cout<<strlen(a)<<endl;
   //cout<<strlen(b)<<endl;
   for (int i=0;i<strlen(a);i++)
   {
		int pos = findMappingIndex(*(a+i));
		cout<<pos<<" ";
		if (!BITTEST(bitarray,pos))
		{
			// if not set, set it to 1
			BITSET(bitarray,pos);
		}
   }
   
   cout<<endl;
   printBitArray(bitarray,62);
   bool found = true;
   
   for (int i=0;i<strlen(b);i++)
   {
		int posb=findMappingIndex(*(b+i));
		cout<<posb<<" ";
		if (!BITTEST(bitarray,posb))
		{
			found = false;
			break;
		}
   }
   
   return (found == true);

}

int main()
{
	char str1[]="abcdefghij";
	char str2[]="fgh";	
	bool rv = findContain(str1,str2);
	cout<<endl<<"find:"<<rv<<endl;
	return 0;
}