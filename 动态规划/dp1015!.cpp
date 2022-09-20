/*
 * 问题描述：在n个候选人中选出m个成员，每个候选人都有d[i]和p[i]
 * 两个值，D和P为选出m个成员他们的d[i]的和和p[i]的和，必须保证|D-P|
 * 最小，如果一样小，则选择D+P最大的方案
 * 提交状态：  AC
 *
 * AC 结果： MEMORY:14264K TIME:360MS
 *
 * 解题方法1：这题属于背包dp，DP[i][j][k]表示前i个人中选j个人偏差为k时D+P的总和。由于有最多200个候选人,D-P的范围在-400-400
 * 中波动，由于数组没有负数，所以我们加上base=400的偏差
 * 先用转移方程得到D+P的最大值，再慢慢增大偏差来得到正值，从而满足题目给出得条件。
  当不选第i个人时, DP[i][j][k]=DP[i-1][j][k].选择第i个人时DP[i][j][k]=DP[i-1][j-1][k-D[i]+P[i]]+D[i]+P[i]
  我们想要最大的总和值，转移方程为DP[i][j][k]=max(DP[i][j][k], DP[i - 1][j - 1][t] + P[i] + D[i])
  然后我们回溯找人，如果f[i][j][k] == f[i - 1][j][k]，则说明第i个人没有被选择，i--。否则i--,j--,k再减去被选人得偏差，用一个
  数组来储存这个被选的人。
 * 
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：6
 *
 * 错误原因 （可选）：不懂怎么设转移方程
 *
 * 心得体会 （可选）：做动态规划要先分清楚它是哪一类dp，背包dp，区间dp，最长子序列，一般根据它的最大值或最小值来设定转移方程
 * 转移方程可以带几个显而易见有影响的参数，如花费，装入物品已装入数量等。然后动态规划完之后要回溯找选择的物品，输出。
 * memset函数可以用0x3f来表示负无穷
 */

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