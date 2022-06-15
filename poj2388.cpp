#include <iostream>
using namespace std;
int main()
{
	int a[10000];
	int n;
	int um;
	int m;
	cin >> n;//ÊýÁ¿
	memset(a, 0, sizeof(a));

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		a[i] = m;
	}
	for (int i = 0; i < n; i++)
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
	}
	
	
	cout << a[n/2];
	
}
