#include <iostream>
#include <string>
#include <algorithm>    // std::reverse

using namespace std;

void reverseT(string& str)
{
   reverse(str.begin(),str.end());
}

void leftShift(string& str, int m)
{
	if (&str==0 || m<=0)
		return;
	int n = str.length();
	if (n==0)
		return;
	
	m = m % n;
	string x = str.substr(0,m);
	string y = str.substr(m);
	cout<<"x="<<x<<" y="<<y<<endl;
	reverseT(x);
	reverseT(y);
	x=x+y;
	reverseT(x);
	cout<<"str="<<x<<endl;
}

int main()
{
   string str = "abcdefghi";
   //reverseT(str);
   leftShift(str,3);
}