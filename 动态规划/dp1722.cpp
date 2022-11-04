/*
 * 问题描述：给定一列数字，不断做合并操作，来得到给出的值T
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 808K Time:40 MS
 *
* 解题方法1：dp[i][j]表示前i个数的和为j的第i个数的正负值，通过打表，得到dp数组后，逆推得到正负值，然后+都用-加上小括号代替
* 并且记上合并数，最后合并第一个数和后面的小括号
*
 *
 * 解题方法2 （可选）
 *
 * 出错次数：3
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */
#include<iostream>
#include<algorithm>
using namespace std;
//8016k 32ms

int a[110];
int base = 10000;
int dp[110][20050];
int ans[110];
int N, T;
void solve()
{
	dp[1][a[1] + base] = 1;
	dp[2][a[1] - a[2] + base] = -1;
	for (int i = 3; i <= N; i++)
	{
		for (int j = 0; j < 20050; j++)
		{
			if (dp[i - 1][j])
			{
				dp[i][j + a[i]] = 1;//+
				dp[i][j - a[i]] = -1;//-
			}
		}
	}
}

void anss()
{
	int s = base + T;
	for (int i = N; i >= 2; i--)//回溯走路径,确定+,-号
	{
		ans[i] = dp[i][s];
		if (ans[i] == 1)
			s -= a[i];
		else if (ans[i] == -1)
			s += a[i];
	}
	int cnt = 0;
	for (int i = 2; i <= N; i++)//+号加上小括号做减操作
		if (ans[i] == 1)//第 i 个数是正的，执行 cut(i - 1)，前面合并了 cnt 次，真正操作的位置应该是 i - 1 - cnt
		{
			cout << i - cnt - 1 << endl;
			cnt++;
		}
	for (int i = 2; i <= N; i++)
		if (ans[i] == -1)//已经合并 cnt 次，还需要合并 n - 1 - cnt 次，都执行 cut(1) 操作即可
			cout << 1 << endl;



}




int main()
{
	
	cin >> N>>T;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}
	solve();
	anss();
}