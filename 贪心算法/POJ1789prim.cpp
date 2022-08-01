/*
* 问题描述：根据给出的点数，边数，权值给出最小生成树
 *
* 提交状态： AC
 *
* 交流结果： 内存： 16500K 时间：500ms
 *
* 解题方法1：使用普利姆算法，随机选择第一个点，找出最小边标记，更新。继续寻找下一个点直到找到n-1个点，
* 判断字符串与原始字符串有多少个不同，有多少个就加上多少个t,检测完一行之后，这就是它的权值
 *
* 解题方法2 （可选）：
*
* 出错次数：1
 *
* 错误原因 （可选）：没按格式输出
 *
* 心得体会 （可选）：
 */

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int map[2010][2010], vis[2010], dis[2020];
char c[2010][10];
int n, m, t;//n个点，m条边
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
示例输入

4
aaaaaaa
baaaaaa
abaaaaa
aabaaaa
0
示例输出

The highest possible quality is 1/3.

*/