
/*
 * 问题描述：确定 Ultra-QuickSort 需要执行多少交换操作才能对给定的输入序列进行排序。用一个排序算法确定
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 7240K Time: 1438MS
 *
 * 解题方法1：用归并排序把输入排序，当右边序列小于左边的第i位时，说明mid-i+1位将成为他的逆序数，用cnt+=mid-i+1来计算逆序数
 * 
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：3
 *
 * 错误原因 （可选）：运行时发生错误，原因是数组不够大
 *
 * 心得体会 （可选）：尽量少用全局变量
 */











#include <iostream>
using namespace std;
#define ll long long
ll n,i,j,k,ls[500000],cnt;
ll b[500000];

	

int mergesort(ll a[], ll l, ll r)
{
	
	if (l >= r)
	{
		return 0;
	}
	int mid = (l + r) / 2;
	mergesort(a, l, mid);
	mergesort(a, mid + 1, r);
	
	i = l;
	j = mid + 1;
	 k = 0;
	
	while (i <= mid && j <= r)
	{
		if (a[i] < a[j])
		{
			ls[k++] = a[i++];
		}
		else
		{
			ls[k++] = a[j++];
			cnt += mid - i + 1;
		}
	}
	while (i <= mid)
	{
		ls[k++] = a[i++];
	}
	while (j <= r)
	{
		ls[k++] = a[j++];
	}
	for (int o = 0; o < r - l + 1; o++)
	{
		a[l + o] = ls[o];
	}
}

int main()
{
	
	cin >> n;
	while (n != 0)
	{
		cnt = 0;
		for (int g = 0; g < n; g++)
		{
			cin >> b[g];
			
		}
		mergesort(b, 0, n - 1);
		cout << cnt;
		cout << "\n";
		cin >> n;
	}
}