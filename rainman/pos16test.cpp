#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

float rootn(unsigned long long num, unsigned int n)
{
	double r = 1.0/n;
	return pow(num,r);
}

int main()
{
	unsigned long long pos16min=1000000000000000ULL;
	unsigned long long pos16max=9999999999999999ULL;
	unsigned int root = 14;
	cout<<rootn(pos16min,root)<<endl;
	cout<<rootn(pos16max,root)<<endl;
}