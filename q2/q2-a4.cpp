#include <iostream>
#include <string>

using namespace std;

static int hashTable[26]={0};

void printHashTable()
{
	for (int i=0;i<26;i++)
	{
		cout<<hashTable[i]<<" ";
	}
	cout<<endl;
}

int alphebatHashTable(string& input)
{
	int index = 0;
	int count = 0;
	for (int i=0;i<input.length();i++)
	{
		index = input[i]-'a';
		if (hashTable[index]==0)
		{
			hashTable[index]=1;
			count++;
		}
	}
	cout<<"count:"<<count<<endl;
	printHashTable();
	return count;
}

bool scanHashTable(string& input, int count)
{
	int index = 0;
	for (int i=0;i<input.length();i++)
	{
		index = input[i]-'a';
		if (hashTable[index]==1)
		{
			hashTable[index] = 0;
			count--;
		}
	}
	printHashTable();
	cout<<"count:"<<count<<endl;
	
	if (count==0)
	{
		return true;
	} else {
		return false;
	}
}

int main()
{
	string n="abcdedfghijk";
	string m="bcdstwv";
	int count=alphebatHashTable(m);
	cout<<scanHashTable(n,count)<<endl;
}