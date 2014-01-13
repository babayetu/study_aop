#include "kqsort.h"
#include "string.h"
#include "stdio.h"

//using namespace std;

void printStr(char* str)
{
	int n = strlen(str);
	for (int i=0;i<n;i++)
	{
		printf("%c ",str[i]);		
	}
	printf("\n");
}

void quick_sort(char* s, int l, int r)
{
    if (l < r)
    {
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r;
		char x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;  
            if(i < j) 
				s[i++] = s[j];
			
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;  
            if(i < j) 
				s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用 
        quick_sort(s, i + 1, r);
    }
}

/*
int main()
{
	//char str[] = "dbcafegih";
	char str[] = "dbcafegihkjnlmt";
	printf("len=%d\n",strlen(str));

	printStr(str);
	quick_sort(str,0,strlen(str)-1);
	printStr(str);	
	return 0;
}
*/