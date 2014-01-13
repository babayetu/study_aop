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

void rotate(char* str, int n, int m, int head, int tail, bool direction_flag)
{
	// direction_flag == true left shift
	// direction_flag == false right shift
	if (m <= 0 || head == tail)
	   return;
	   
	if (direction_flag)
	{
		//left shift
		int k =  n - m - n%m;    // do 6 six left shift abc def ghi jk -> def ghi abc jk
		int p1 = head;
		int p2 = head + m;
		
		for (int i=0; i<k; i++, p1++, p2++)
		{
			swap(str[p1],str[p2]);
		}
		
		rotate(str, n - k, n%m, p1, tail, false);
	} else {
		//right shift
		int k =  n - m - n%m;	// do right shift   abc jk -> a jk bc
		int p1 = tail;
		int p2 = tail - m;

		for (int i=k; i>0; i--, p1--, p2--)
		{
			swap(str[p1],str[p2]);
		}
		
		rotate(str, n - k, n%m, head, p1, true);
	}
	   
}


int main()
{
  char str[12] = "abcdefghijk";   
  cout<<"original string is:"<<str<<endl;
  
  rotate(str, 11, 3, 0, 10, true);
  cout<<"after rotation string is:"<<str<<endl;
  return 0;
}