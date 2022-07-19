/*
 * 问题描述：给定一个正整数n，编写一个程序来找出n的非零倍数m，其十进制表示只包含数字0和1。
			您可以假设 n 不大于 200，并且有一个包含不超过 100 个小数位的相应 m
 * 提交状态：  AC
 *
 * AC 结果： MEMORY:4746K TIME:438MS
 *
 * 解题方法1：从1开始，每次*10或者*10+1，这样保证了怎么样都保证了这个m中只有0和1，入队，重复这个过程，直到m能够整除n
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：3
 *
 * 错误原因 （可选）：一开始无法把问题与分支限界法联系起来，用了暴力法累加倍数导致超时。
 * 2.使用短整型导致溢出输出错误答案
 * 3.每次使用完函数后没有初始化队列导致错误
 *
 * 心得体会 （可选）：1.BFS无非就是一个问题，找路，而且绝对不止1条路（暴力法）
 * 2.大数要用长整型存储
 * 3.有时可以用g++来提交
 */


#include <queue>
#include <iostream>
using namespace std;
struct point
{
	long long x;
};


void BFS(int n)
{
	queue <point> r;
	point start;
	start.x = 1;
	r.push(start);
	while (!r.empty())
	{
		long long dx = r.front().x;
		r.pop();
		if (dx % n == 0)
		{
			cout << dx << endl;
			return;
		}
		
			point temp;
			
				temp.x = dx * 10;
				r.push(temp);
		
				temp.x = dx * 10 + 1;
				r.push(temp);
			
		
	}
}
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		BFS(n);
	}


	return 0;
}
