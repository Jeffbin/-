/*
* 问题描述：输入两个四位数的素数，求从第一个素数转化成第二个素数所花费的时间，转换的过程中全程都只能是素数，如果不可以的话，输出impossible
* 提交状态： AC
 *
* 交流结果： 内存： 时间：
 *
* 解题方法1：从个位开始，从0到9变，如果新组成的数如果是素数且没有遍历过，就把这个数入队，费用加1。如此操作直到千位。
* 剪枝：个位数为0时不是素数，减去；千位数不能为0，减去
 *
* 解题方法2 （可选）：
 *
* 出错次数：1
 *
* 错误原因 （可选）：超时，判断素数时，从2开始遍历到自身，导致超时
 *
* 心得体会 （可选）：判断一个素数时是不是素数时，其实数字x的因数分成两大部分，
一部分是小于x的平方根，另外一部分大于x的平方根，小于平方根和大于平方根的部分是一一对应的，
因而可以只判断从2到平方根的数字是否都能被整除即可。
这样就可以节约时间
 */

#include <iostream>
#include <queue>
using namespace std;
int used[10000];
int prime[10000];
struct point
{
	int x;
	int cost;
};
queue<point> r;
bool sushu(int n)
{
	for (int j = 2; j < sqrt(n); j++)
	{
		if (n % j == 0)
		{
			prime[n] = 0;
			return false;
		}

	}
	prime[n] = 1;
	return true;

}
void BFS(int n, int m)
{
	point start;
	start.x = n;
	start.cost = 0;
	r.push(start);
	while (!r.empty())
	{
		int dx = r.front().x;
		if (dx == m)
		{
			cout << r.front().cost << endl;
			return;
		}
		for (int i = 1; i < 10; i++)//个位
		{
			int kt = dx / 10 * 10 + i;
			if (sushu(kt) && used[kt] == 0)
			{
				point temp;
				temp.x = kt;
				temp.cost = r.front().cost + 1;
				used[kt] = 1;
				r.push(temp);
			}
		}
		for (int i = 0; i < 10; i++)//十位
		{
			int kt = dx -dx%100/10*10 + i*10;
			if (sushu(kt) && used[kt] == 0)
			{
				point temp;
				temp.x = kt;
				temp.cost = r.front().cost + 1;
				used[kt] = 1;
				r.push(temp);
			}
		}
		for (int i = 0; i < 10; i++)//百位
		{
			int kt = dx-dx % 1000/100*100 + i*100;
			if (sushu(kt) && used[kt] == 0)
			{
				point temp;
				temp.x = kt;
				temp.cost = r.front().cost + 1;
				used[kt] = 1;
				r.push(temp);
			}
		}
		for (int i = 1; i < 10; i++)//千位
		{
			int kt =dx- dx / 1000 * 1000 + i*1000;
			if (sushu(kt) && used[kt] == 0)
			{
				point temp;
				temp.x = kt;
				temp.cost = r.front().cost + 1;
				used[kt] = 1;
				r.push(temp);
			}
		}
		r.pop();
	}
}
int main()
{
	int a,b,c;
	cin >> a;
	for (int op = 0; op < a; op++)
	{
		memset(used, 0, sizeof(used));
		cin >> b >> c;
		BFS(b, c);
		if (prime[b]==0 || prime[c]==0)
		{
			cout << "Impossible" << endl;
		}
	}

}
/*
Sample Input

4
1033 8179
1373 8017
1033 1033

Sample Output

6
7
0
*/