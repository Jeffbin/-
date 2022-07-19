/*
* 问题描述：输入两个四位数的素数，求从第一个素数转化成第二个素数所花费的时间，转换的过程中全程都只能是素数，如果不可以的话，输出impossible
* 提交状态： AC
 *
* 交流结果： 内存：1064K 时间：16ms
 *
* 解题方法1：从个位开始，从0到9变，如果新组成的数如果是素数且没有遍历过，就把这个数入队，费用加1。如此操作直到千位。
* 剪枝：个位数为0时不是素数，减去；千位数不能为0，减去
 *
* 解题方法2 （可选）：
 *
* 出错次数：2
 *
* 错误原因 （可选）：超时，判断素数时，从2开始遍历到自身，导致超时
* 判断素数的方法出错或超时
 *
* 心得体会 （可选）：判断一个素数时是不是素数时，可以用数学上总结的判断素数方法，节省时间的同时也正确
这样就可以节约时间
 */

#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#define maxn 100000
using namespace std;
int used[maxn];
int prime[maxn];
int flag = 0;
int pre[maxn];
struct point
{
	int x;
	int cost;
};


void init() {//线性筛法（O（n）） 
	for (int i = 2; i < maxn; i++) {
		prime[i] = true;
	}
	prime[0] = prime[1] = false;
	int total = 0;
	for (int i = 2; i < maxn; i++) {
		if (prime[i]) {
			pre[total++] = i;
		}
		for (int j = 0; j < total && i * pre[j] < maxn; j++) {
			prime[i * pre[j]] = false;
			if (i % pre[j] == 0) {
				break;
			}
		}
	}
}
void BFS(int n, int m)
{
	queue<point> r;
	point start;
	start.x = n;
	start.cost = 0;
	r.push(start);
	while (!r.empty())
	{
		int dx = r.front().x;
		if (dx == m)
		{
			flag = 1;
			cout << r.front().cost << endl;
			return;
		}
		for (int i = 1; i < 10; i=i+2)//个位
		{
			int kt = dx / 10 * 10 + i;
			if (prime[kt] && used[kt] == 0)
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
			if (prime[kt] && used[kt] == 0)
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
			if (prime[kt] && used[kt] == 0)
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
			if (prime[kt] && used[kt] == 0)
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
	init();
	cin >> a;
	for (int op = 0; op < a; op++)
	{
		memset(used, 0, sizeof(used));
		cin >> b >> c;
		used[b] = 1;
		if (prime[b] == 1 && prime[c] == 1)
		{
			BFS(b, c);
		}
		if (flag == 0)
		{
			cout << "Impossible" << endl;
		}
		flag = 0;
	}

}
/*
Sample Input

3
1033 8179
1373 8017
1033 1033

Sample Output

6
7
0
*/
/*

*/
