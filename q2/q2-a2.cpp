#include "stdio.h"
#include "kqsort.h"
#include "string.h"

bool compareContain(char* s1, char* s2)
{
	int posOne = 0;
	int posTwo = 0;
	
	while(posOne<strlen(s1) && posTwo<strlen(s2))
	{
		while(s1[posOne]<s2[posTwo] && posOne<strlen(s1))
		{
			posOne++;
		}
		
		if (s1[posOne]!=s2[posTwo])
			break;
		posTwo++;
	}
	if(posTwo!=strlen(s2))
		return false;
	else
		return true;
}

int main()
{
	char str1[]="dbcafegih";
	char str2[]="feih";
	char str3[]="acbws";
	
	quick_sort(str1,0,strlen(str1)-1);
	quick_sort(str2,0,strlen(str2)-1);
	quick_sort(str3,0,strlen(str3)-1);
	printStr(str1);
	printStr(str2);
	printStr(str3);
	
	printf("round1 =%d",compareContain(str1,str2));
	printf("round2 =%d",compareContain(str1,str3));
}