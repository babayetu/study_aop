#include <iostream>
#include <string>
using namespace std;

bool aContainsB(string host, string guest)
{
	int index=0;
	unsigned long host_bit=0UL;
	unsigned long guest_bit=0UL;
	while (index<host.length())
	{
		host_bit |=1<<(host[index]-'a');
		index++;
	}
	
	index=0;
	while (index<guest.length())
	{
		if ((host_bit & 1<<(guest[index]-'a')) == 0)
		{
			return false;
		}
		index++;
	}
	return true;
}

int main()
{
	string host="abcdefghijk";
	string guest="bdfgkt";
	cout<<host<<" contains "<<guest<<" is "<<aContainsB(host,guest)<<endl;
}