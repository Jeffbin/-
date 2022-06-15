
#include <iostream>


using namespace std;

char str[200][200];   //二维数组写入字符串每一个字符的值
int num[200];     //逆序数的值
char ls[100];
int cnt;
//int merge(int a[], int l, int mid, int r)
//{
//	int i = l;
//	int j = mid + 1;
//	int k = 0;
//	while (i <= mid && j <= r)
//	{
//		if (a[i] < a[j])
//		{
//			ls[k++] = a[i++];
//		}
//		else
//		{
//			ls[k++] = a[j++];
//			cnt = mid - i + 1;
//
//		}
//	}
//	while (i <= mid)
//	{
//		ls[k++] = a[i++];
//	}
//	while (j <= r)
//	{
//		ls[k++] = a[j++];
//	}
//	return cnt;
//}
//int mergesort(int a[], int l, int r)
//{
//	int key = 0;
//	if (l >= r)
//	{
//		return 0;
//	}
//	int mid = (l + r) / 2;
//	mergesort(a, l, mid);
//	mergesort(a, mid + 1, r);
//	key=(merge(a, l,mid, r));
//	return key;
//}

int main()
{
	int m, n;
	
	cin >> n;//长度
	cin >> m;//个数

	
	for (int i = 1; i <= m; i++)
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
	
	for (int i = 1; i <=m; i++)
	{
		for (int j = 1; j <=m - i; j++)
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
	for (sz = 1; sz <= n; sz++)
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