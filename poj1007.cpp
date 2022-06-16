
#include <iostream>


using namespace std;

char str[200][200];   //二维数组写入字符串每一个字符的值
int num[200];     //逆序数的值
char ls[100];


int main()
{
	int m, n;
	
	cin >> n;//长度
	cin >> m;//个数

	
	for (int i = 0; i < m; i++)
	{
		cin >> str[i];//直接定义第几行的数，直接输入几列的字符
		cout << "\t" << endl;
		
		for (int j = 0; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (str[i][j] > str[i][k])
				{
					num[i]++;
				}
			}
		}

	}
	
	
	int um;
	int sz;
	
	for (int i = 0; i <m-1; i++)
	{
		for (int j = 0; j <m - i-1; j++)
		{
			if (num[j] > num[j + 1])
			{
				um = num[j + 1];
				num[j + 1] = num[j];
				num[j] = um;
				memcpy(ls, str[j+1], n);
				memcpy(str[j + 1], str[j], n);
 				memcpy(str[j], ls, n);

			}
		}
	}
	for (sz = 0; sz < n; sz++)
	{
		cout << str[sz];
		cout << "\t" << endl;
	}
	return 0;

}
/*
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
 
*/
