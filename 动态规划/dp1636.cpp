/*
* 问题描述：两个人数一样的监狱，有一些囚犯不能在一起，两个监狱要等数量（ < m/2）交换一些囚犯，问最多可以交换多少个囚犯；
* 提交状态： AC
 *
* 交流结果： 内存：44K 时间：329MS
 *
* 解题方法1：首先先用并查集的方法把危险对都联系起来，形成一个连通分量，再用一个结构体分别记录这个连通分量的两边人数，
* 然后用背包dp的思想，dp[j][k]在前i个连通分量中，用A监狱里的j人和B监狱里的k人交换是否可行。最后在m/2逐渐减小，寻找最多能交换多少人
 *
 *
* 解题方法2 （可选）：
 *
* 出错次数：
 *
* 错误原因 （可选）：数组开小了，还是没有很好掌握dp的思想
 *
* 心得体会 （可选）：
 */
#include<iostream>
#include<string.h>
using namespace std;

#define MAX 410

int cnt1[MAX];
int cnt2[MAX];
int f[MAX];
int dp[MAX / 2][MAX / 2];
int m, r;
int cnt; //记录连通集个数

struct P
{
	int a;
	int b;
}p[MAX];

//并查集，记录每个连通集两个监狱中有关系的人数
void init() {
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	memset(dp, 0, sizeof(dp));
	cnt = 0;
	for (int i = 0; i < MAX; i++)
		f[i] = i;
}


int find(int x) {//找祖宗 
	if (x != f[x])
		f[x] = find(f[x]);
	return f[x];
}

void merge(int a, int b) {//连边
	int fa = find(a);
	int fb = find(b);
	if (fa != fb)
	{
		f[fa] = fb;
	}
}
int main() {
	int n;
	int a, b;   //记录有关系的犯人
	cin >> n;
	while (n--) {
		cin >> m >> r;
		init();
		for (int i = 0; i < r; i++) 
		{
			cin >> a >> b;
			merge(a, b + m);//连边
		}
		for (int i = 1; i <= m; i++)
			cnt1[find(i)]++;
		for (int i = m + 1; i <= m * 2; i++)
			cnt2[find(i)]++;
		for (int i = 1; i <= m * 2; i++)
		{
			if (cnt1[i] || cnt2[i]) 
			{
				p[cnt].a = cnt1[i];
				p[cnt].b = cnt2[i];
				cnt++;
			}
		}
		//动态规划 /*dp[i][j] 表示从a监狱出去i个人和从b监狱出去j个人的情况下是否可行*/
		dp[0][0] = 1;
		for (int i = 0; i < cnt; i++)//连通集个数cnt
			for (int j = m / 2; j >= p[i].a; j--)
				for (int k = m / 2; k >= p[i].b; k--)
					if (dp[j - p[i].a][k - p[i].b])
						dp[j][k] = 1;   //状态转移方程
		int i = m / 2;
		while (!dp[i][i])i--;
		cout << i << endl;
	}
	return 0;
}

/*
示例输入

3
101 0
3 3
1 2
1 3
1 1
8 12
1 1
1 2
1 3
1 4
2 5
3 5
4 5
5 5
6 6
7 6
8 7
8 8
示例输出

50
0
3
*/