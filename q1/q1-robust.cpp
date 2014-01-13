#include <iostream>
#include <string>

#define positiveMod(m, n) ((m) % (n) + (n)) % (n)
using namespace std;

int main()
{
   int m = 3;
   int n = 10;
   cout<<"positiveMod("<<m<<", " <<n<<") ="<<positiveMod(m, n)<<endl;
   m=-3;
   cout<<"positiveMod("<<m<<", " <<n<<") ="<<positiveMod(m, n)<<endl;
   m=53;
   cout<<"positiveMod("<<m<<", " <<n<<") ="<<positiveMod(m, n)<<endl;
}