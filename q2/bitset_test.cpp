#include <bitset>
#include <iostream>

using std::bitset;
using std::cout;
using std::endl;

int main()
{
	bitset<32> mybs;
	cout<<mybs<<endl;
	mybs.set(11);
	cout<<mybs<<endl;
	cout<<mybs.test(11)<<endl;
	cout<<mybs.to_ulong()<<endl;
	mybs.reset(11);
	cout<<mybs.test(11)<<endl;
	
}