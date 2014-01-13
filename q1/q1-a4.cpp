#include <iostream>
using namespace std;

int gcd (int m, int n)
{
    int c;
    while ( m != 0 ) 
    {
        c = m; 
        m = n % m;  
        n = c;
    }
    return n;
}

void rotate_6(string &str, int m)
{
    int lenOfStr = str.length();
    int numOfGroup = gcd(lenOfStr, m);
    int elemInSub = lenOfStr / numOfGroup;

    for(int j = 0; j < numOfGroup; j++)
        //��Ӧ�����������������ѭ������jΪѭ�����ĸ�������gcd(n, m)��ѭ����
    {
        char tmp = str[j];
        int i;
		cout<<"====circle "<<j<<"======="<<endl;
		// j+ i*m		
        for (i = 0; i < elemInSub - 1; i++)
		{
		    cout<<"str["<<(j + i * m)<<"]="<<str[j + i * m]<<" ";
            //��ѭ������iΪ��ÿ��ѭ�����ϵ�Ԫ�ظ�����n/gcd(m,n)��
            str[(j + i * m) % lenOfStr] = str[(j + (i + 1) * m) % lenOfStr];
		}
		cout<<endl;
        str[(j + i * m) % lenOfStr] = tmp;
    }
}

void rotate_7(char *begin, char *mid, char *end)
{
    int n = end - begin;
    int k = mid - begin;
    int d = gcd(n, k);
    int i, j;
    for (i = 0; i < d; i ++)
    {
		cout<<"circle "<<i<<" string="<<begin<<endl;
        int tmp = begin[i];
        int last = i;

        //i+kΪi����k��λ�ã�%n�ǵ�i+k>nʱ�������¿�ʼ��
        for (j = (i + k) % n; j != i; j = (j + k) % n)    //��лlaocppָ����
        {
            begin[last] = begin[j];
            last = j;
        }
        begin[last] = tmp;
    }
}

int main()
{
    char str1[] = "abcdefghi";
	int shift = 3;
	string s = "abcdefghi";
    cout << "testing rotate_7" << endl;
    //cout << "before shift: " << str1 << endl;
    //rotate_7(&str1[0], &str1[shift], &str1[9]);
	cout << "before shift: " << s << endl;
	rotate_6(s, shift);
    cout << "after  shift: " << s << endl << endl;
}