
/*
 * 问题描述：题目是给定两个数组，要求找出最大匹配数量。
		匹配规则是：

				a[i] ==b[j]，而且需要产生交叉，而且每对数只能匹配一次。
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 316K Time:16 MS
 *
* 解题方法1：分析：用dp[i][j]表示第一行取i个数，第二行取j个数字的最多匹配项
	对于某个dp[i][j]:
	1.不匹配第一行i个，或不匹配第二行第j个：dp[i][j]=Max(dp[i-1][j],dp[i][j-1])
	2.如果a[i]==b[j],不产生新匹配，匹配结果为1的值
	3.若a[i]!=b[j]:
	a.则第一行从i往前面扫，直到扫到第一个a[k1]==b[j](k1 b.同理，第二行从j往前扫，
	直到扫到第一个b[k2]==a[i](k2 若找不到这样的k1,k2则不能才产生新匹配，跳过
	若存在这样的k1,k2,此时匹配（a[i],b[k2]）、(a[k1],b[j])匹配，
	才生新的匹配情形,匹配数量为：dp[k1-1][k2-1]+2.
*
 *
 * 解题方法2 （可选）
 *
 * 出错次数：1
 *
 * 错误原因 （可选）：不懂用什么条件来判断交叉
 *
 * 心得体会 （可选）：
 */


#include <iostream>
#include <algorithm>
using namespace std;
int a[110];
int b[110];
int dp[110][110];

void init(int n,int m)
{
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int j = 1; j <= m; j++)
	{
		cin >> b[j];
	}
	memset(dp, 0, sizeof(dp));
}

void fun(int N1,int N2)
{
	for (int i = 2; i <= N1; i++)
	{
		for (int j = 2; j <= N2; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (a[i] != b[j])
			{
				int k1;
				for (k1 = j - 1; k1 > 0; k1--)
				{
					if (a[i] == b[k1])
					{
						break;
					}
				}
				int k2;
				for (k2 = i - 1; k2 > 0; k2--)
				{
					if (a[k2] == b[j])
					{
						break;
					}
				}
				if (k1 && k2)
				{
					dp[i][j] = max(dp[i][j],dp[k2-1][k1-1] + 2);////在 dp[k1-1][k2-1]之后又产生了两组新的匹配
				}
			}
		}
	}
	
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N1,N2;
		cin >> N1 >> N2;
		init(N1,N2);//初始化
		fun(N1, N2);
		cout << dp[N1][N2] << endl;
	/*	for (int i = 1; i <= N1; i++)
		{
			for (int j = 1; j <= N2; j++)
			{
				cout << dp[i][j];
			}
			cout  << endl;
		}*/
	}
}