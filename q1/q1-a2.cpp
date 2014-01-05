#include <iostream>

using namespace std;

void swap(char* p1, char* p2)
{
   if (p1==0 || p2==0)
   {
      return;
   }
   
   char temp = *p1;
   *p1 = *p2;
   *p2 = temp;
}

void doLeftShift(char* str, int n, int m)
{
	if ((str == 0) || (m >= n))
	{
		return;
	}	
	
	//step 1
	int p1 = 0;
	int p2 = m;
	
	int k = n / m - 1;  //three set only need two swap
	int r = n % m;
	
	cout<<"k:"<<k<<" r:"<<r<<endl;
	
	//step 2
	while (k-- > 0)
	{
		// not exceed the up limit			
		//step 3
		for (int i=0;i<m;i++)
		{
			cout<<"p1:"<<p1<<" p2:"<<p2<<endl;
			swap(&str[p1],&str[p2]);
			p1++;
			p2++;
		}
		cout<<"round:"<<k<<" str:"<<str<<endl;
	}
	
	cout<<"middle tier:"<<str<<endl;
	
	//step 4
	while (r-- > 0)
	{
	    int i=p2;
		while (i > p1)
		{
			swap(&str[i-1],&str[i]);
			i--;
		}
		p1++;
		p2++;		
	}
	
}


int main()
{
  char str[12] = "abcdefghijk";   
  cout<<"original string is:"<<str<<endl;
  
  doLeftShift(str, 11, 3);
  cout<<"after rotation string is:"<<str<<endl;
  return 0;
}