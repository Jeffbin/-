#include <iostream>
#include <algorithm>
using namespace std;
struct sortedDNA
{
	int num;
	char *line;//指针，a[i]的值赋值到这里
}a[101];

int bubble_sort(char a[], int n);
bool cmp(sortedDNA a, sortedDNA b);

int main() 
{
	int n, m, i, j;//n为长度，m为个数
	char DNA[101][52];
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> DNA[i];
		a[i].line = DNA[i];//字符指针也可以指向一个字符串，此时，字符指针指向一个字符串常量的首地址。
		a[i].num = bubble_sort(DNA[i], n);
	}
	sort(a, a + m, cmp);//对m个a[]里的num排序
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i].line[j];//输出
		}
		cout << "\n";

	}
	return 0;
}
bool cmp(sortedDNA a, sortedDNA b)
{
	return a.num < b.num;

}
int bubble_sort(char a[], int n)
{
	int i, j, num = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				num++;
			}
		}
	}
	return num;
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
