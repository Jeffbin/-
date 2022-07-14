/*
 * 问题描述：，输入字符串数量和长度，输入字符串。输出输入字符串列表，从“排序最多”到“排序最少”。逆序数少的为排序多
 *
 * 提交状态： AC 
 *
 * AC 结果： Memory: 184K Time: 47MS
 *
 * 解题方法1：设立一个结构体数组，里面有个字符指针用来存字符串，用nun来存储逆序数的数量，
 * 输入了字符串，用sort函数把他们的字符串按逆序数大小排序，再用冒泡排序把结构体数组的字符串输出出来
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：1
 *
 * 错误原因 （可选）：用strcmy复制字符串，导致出错
 *
 * 心得体会 （可选）：可以用字符指针来存储字符串，用sort来把列表排序
 */



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
		a[i].num = bubble_sort(DNA[i], n);//计算逆序数
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