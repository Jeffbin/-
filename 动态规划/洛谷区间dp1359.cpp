/*
 * 问题描述：给定一个区间，中间可以停靠，求起点1到n的最少费用
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 808K Time:40 MS
 *
* 解题方法1：用区间dp的方法来做，区间长度从3递增到最大长度，多次比较中间停靠和不停靠所得的费用，最后得到1到n的最小费用
* 
 *
 * 解题方法2 （可选）
 *
 * 出错次数：1
 *
 * 错误原因 （可选）：一开始的起点i遍历到了终点，须改成遍历到（i+区间长度-1）
 *
 * 心得体会 （可选）：区间dp就用逐次递增区间长度来完成
 */


#include <iostream>
#include <algorithm>
using namespace std;

int dp[210][210];
int r[210][210];
int n;
int shuchu()
{
	
	for (int lenq = 3; lenq <= n; lenq++)//区间长度
	{
		for (int i = 1; i <= n-lenq+1; i++)//起点到起点加区间长度
		{
			int j = i + lenq - 1;//终点
			for (int k = i+1; k < j; k++)//中间停留点
			{
				if (r[i][k] + r[k][j] < r[i][j])
				{
					r[i][j] = r[i][k] + r[k][j];
				}
			}
		}
	}
	return r[1][n];


}

int main()
{
	
	cin >> n;
	for (int i = 1; i <= n; i++)//输入
	{
		for (int j = i + 1; j <= n; j++)
		{
			cin >> r[i][j];
		}
	}
	cout<<shuchu()<<endl;
}