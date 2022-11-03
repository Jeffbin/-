/*
* 问题描述：陪审团终极削弱版，给定骨牌上下数，通过是否翻转来达到骨牌上下的差最小
* 提交状态： AC
 *
* 交流结果： 内存：47800K 时间：454MS
 *
* 解题方法1：通过背包dp的思想，dp[i][j]表示前i个骨牌的差值为j的最小翻转次数，因为有差值，数组不能为负，也要加上偏差
* 
*    当前骨牌翻转的状态方程为dp[i-1][j-(a[i]-b[i])]+1,不翻转的状态方程为dp[i-1][j+[(a[i]-b[i])]]
* 所以状态转移方程为dp[i][j]=min(dp[i-1][j-(a[i]-b[i])]+1,dp[i-1][j+[(a[i]-b[i])]])
 *
 *
* 解题方法2 （可选）：
 *
* 出错次数：1
 *
* 错误原因 （可选）：初始化dp数组后忘记让偏置归零
 *
* 心得体会 （可选）：
 */

#include<algorithm>
#include <iostream>
using namespace std;

int dp[1010][12010];
int a[1010];
int b[1010];
int n;
int base = 6000;//偏差
void init()
{
	memset(dp, 0xf, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]>>b[i];
	}
	dp[0][6000] = 0;
}
void guihua()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 12010; j++)
		{
			int cha = a[i] - b[i];
			dp[i][j] = min(dp[i - 1][j- cha], dp[i - 1][j + cha] + 1);
		}
	}
	for (int i = 0; i <= 6000; i++)
		 {
		        int ans = min(dp[n][i + 6000], dp[n][6000 - i]);
		       if (ans <= 1000)
		       {
		           cout << ans;
				   break;
		        }
	    }
}
int main()
{
	
	cin >> n;
	init();
	guihua();
}