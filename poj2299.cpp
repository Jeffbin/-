#include <iostream>
using namespace std;
#define ll long long
ll n,i,j,k,ls[10000],cnt;
ll b[10000];

	

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
		
		cin >> n;
	}
}