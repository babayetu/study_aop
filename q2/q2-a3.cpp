#include "stdio.h"
#include <string>
#include <iostream>
#include "countersort.h"
#include "string.h"
using namespace std;

bool compareContain(string& s1, string& s2)
{
	int posOne = 0;
	int posTwo = 0;
	
	while(posOne<s1.length() && posTwo<s2.length())
	{
		while(s1[posOne]<s2[posTwo] && posOne<s1.length())
		{
			posOne++;
		}
		
		if (s1[posOne]!=s2[posTwo])
			break;
		posTwo++;
	}
	if(posTwo!=s2.length())
		return false;
	else
		return true;
}

int main()
{
	string strOne = "adgisbdfg";
	string strTwo = "atbd";
	string a=strOne;
	string b=strTwo;
	countSort(strOne,a);  	//O(n+m)
	countSort(strTwo,b);	//O(n+m)
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<compareContain(a,b)<<endl;
	return 0;
}