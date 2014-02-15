#include <iostream>
#include <string>
using namespace std;

int prime[]={2 ,3 ,5 ,7 ,11,13,17,19,23,29,
             31,37,41,43,47,53,59,61,67,71,
			 73,79,83,89,97,101};

bool findStrInStr(string host,string guest)
{
	unsigned long long host_value =1ULL;
	unsigned long long guest_value =1ULL;
	for (int i=0;i<host.length();i++)
	{
		host_value*=prime[(host[i]-'a')];
	}
	for (int i=0;i<guest.length();i++)
	{
		guest_value*=prime[(guest[i]-'a')];
	}
	
	return (host_value%guest_value == 0);
}

int main()
{
	string host="abcdefghijk";
	string guest="bdfgk";
	cout<<host<<" contains "<<guest<<" is "<<findStrInStr(host,guest)<<endl;
}