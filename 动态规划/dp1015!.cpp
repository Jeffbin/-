#include <iostream>
#include <algorithm>
using namespace std;
const int N = 210;
const int M = 810;
const int base = 400;
int f[N][21][M],p[N],d[N],ans[N],n,m;


int main()
{
	int T = 1;
	while (cin >> n >> m, n, m)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i] >> d[i];
		}
		memset(f, -0x3f, sizeof(f));
		f[0][0][base] = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				for (int k = 0; k < M; k++)
				{
					f[i][j][k] = f[i - 1][j][k];//不选这个人
					int t = k - (p[i] - d[i]);
					if (t<0 || t>M)
					{
						continue;
					}
					if (j < 1)
					{
						continue;
					}
					f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][t] + p[i] + d[i]);//选第i个人
				}
			}
		}

		int v = 0;
		while (f[n][m][v + base] < 0 && f[n][m][base - v] < 0)
		{
			v++;
		}
		if (f[n][m][v + base] > f[n][m][base - v])
		{
			v = v + base;
		}
		else
		{
			v = base - v;
		}

		//回溯找人
		int i = n, j = m, k = v;
		while (j)
		{
			if (f[i][j][k] == f[i - 1][j][k])
			{

				i--;
			}
			else
			{
				ans[cnt++] = i;//选了第i个人
				 k= k - (p[i] - d[i]);  //差值减小
				 j--;
				 i--;
			}
		}
		int a = 0, b = 0;
		for (int i = 0; i < cnt; i++) a += p[ans[i]], b += d[ans[i]];
		cout << "Jury #" << T << endl;
		T++;
		cout << "Best jury has value " << a << " for prosecution and value " << b << " for defence:" << endl;
		for (int i = cnt - 1; i >= 0; i--)
		{
			cout << ans[i]<<" ";
		}
		cout << endl;
		cout << endl;
	}
}
/*
示例输入
4 2
1 2
2 3
4 1
6 2
0 0
示例输出
Jury #1
Best jury has value 6 for prosecution and value 4 for defence:
 2 3 
 */