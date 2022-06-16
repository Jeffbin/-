#include <iostream>
using namespace std;



void merge(int a[], int l, int mid, int r)
{
	int i = l;
	int j = mid + 1;
	int k = 0;
	int ls[10000];
	while (i <= mid && j <= r)
	{
		if (a[i] < a[j])
		{
			ls[k++] = a[i++];
		}
		else
		{
			ls[k++] = a[j++];
			

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
	for (int i = 0; i < r - l + 1; ++i)
	{
		a[l + i] = ls[i];
	}
}
void mergesort(int a[], int l, int r)
{
	int key = 0;
	if (l >= r)
	{
		return ;
	}
	int mid = (l + r) / 2;
	mergesort(a, l, mid);
	mergesort(a, mid + 1, r);
	merge(a, l,mid, r);
	
}


int main()
{
	int a[10000];
	int n;
	int um;
	int m;
	cin >> n;//数量
	memset(a, 0, sizeof(a));

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		a[i] = m;
	}
	/*for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i-1; j++)
		{
			if (a[j] > a[j+1])
			{
				um = a[j + 1];
				a[j + 1] = a[j];
				a[j] = um;
			}
		}
	}*/
	
	mergesort(a, 0, n - 1);
	cout << a[n/2];
	
}
