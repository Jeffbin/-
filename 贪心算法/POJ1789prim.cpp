/*
* �������������ݸ����ĵ�����������Ȩֵ������С������
 *
* �ύ״̬�� AC
 *
* ��������� �ڴ棺 16500K ʱ�䣺500ms
 *
* ���ⷽ��1��ʹ������ķ�㷨�����ѡ���һ���㣬�ҳ���С�߱�ǣ����¡�����Ѱ����һ����ֱ���ҵ�n-1���㣬
* �ж��ַ�����ԭʼ�ַ����ж��ٸ���ͬ���ж��ٸ��ͼ��϶��ٸ�t,�����һ��֮�����������Ȩֵ
 *
* ���ⷽ��2 ����ѡ����
*
* ���������1
 *
* ����ԭ�� ����ѡ����û����ʽ���
 *
* �ĵ���� ����ѡ����
 */

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int map[2010][2010], vis[2010], dis[2020];
char c[2010][10];
int n, m, t;//n���㣬m����
const int inf = 0x3f3f3f;
int sum;

int prim()
{
	int u; sum = 0;

	for (int i = 1; i <= n; i++)
	{
		vis[i] = 0;
		dis[i] = map[1][i];
	}
	vis[1] = 1;
	dis[1] = 0;
	for (int i = 1; i < n; i++)
	{
		int minn = inf;
		for (int j = 1; j <= n; j++)
		{
			if (dis[j] < minn && vis[j] == 0)
			{
				u = j;
				minn = dis[j];
			}
		}
		vis[u] = 1;
		sum += dis[u];

		for (int v = 1; v <= n; v++)
		{
			if (!vis[v] && dis[v] > map[u][v])
				dis[v] = map[u][v];
		}
	}
	return sum;
}
int main()
{

	while (cin >> n&&n)
	{
		memset(map, inf, sizeof(map));

		for (int i = 1; i <= n; i++)
		{
			cin >> c[i];
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				t = 0;
				for (int k = 0; k < 7; k++)
				{
					if (c[i][k] != c[j][k])
					{
						t++;
					}
				}
				map[i][j] = map[j][i] = t;
			}
		}
		prim();
		cout << "The highest possible quality is 1/" << sum <<"."<< endl;

	}

	return 0;
}
/*
ʾ������

4
aaaaaaa
baaaaaa
abaaaaa
aabaaaa
0
ʾ�����

The highest possible quality is 1/3.

*/