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
		//Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
        int i = l, j = r;
		char x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
				j--;  
            if(i < j) 
				s[i++] = s[j];
			
            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
				i++;  
            if(i < j) 
				s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // �ݹ���� 
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