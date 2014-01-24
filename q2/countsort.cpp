#include "countersort.h"

void countSort(string in, string& out)
{
	// Let's limit string in a-z characters
	int counter[26] = {0};
	int total_count = 0;
	
	//counter every char times, record in counter. c[0] counts 'a', c[1] counts 'b'...
	for (int i=0;i<in.length();i++)
	{
		counter[in[i]-'a']++;
	}

	//determine every char start position
	for (int i=1;i<26;i++)
	{
		counter[i]+=counter[i-1];
	}
	
	for (int i=in.length()-1;i>=0;i--)
	{
		// char index in counter bucket
		int index = in[i] - 'a';
		// counter bucket recorded start position, from high pos
		int pos = counter[index] - 1;
		// put char to out array
		out[pos]=in[i];
		// used one char, counter decrease
		counter[index]--;
	}	
}