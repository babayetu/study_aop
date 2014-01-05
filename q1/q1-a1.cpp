#include <iostream>

using namespace std;

void leftShiftOne(char *str, int n)
{
   char first = str[0];
   for (int i=1;i<n;i++) {
      str[i-1] = str[i];	  
   }
   str[n-1]=first;
}

void leftShiftM(char *str, int n, int m)
{
   while (m--) {
     leftShiftOne(str,n);
   }
}

int main() {
   char str[12] = "abcdefghijk";
   
   cout<<"original string is:"<<str<<endl;
 //  for (int i=0;i<12;i++) {
//     cout<<i<<":"<<str[i]<<endl;
 //  }
   cout<<"size of str:"<<sizeof(str)<<endl;
   //the last one is \0 and can't be count
   leftShiftM(str,sizeof(str)-1,3);
   cout<<"after left shift 3 string is:"<<str<<endl;   
   
   return 0;
}
