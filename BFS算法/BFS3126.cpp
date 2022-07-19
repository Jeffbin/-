/*
* ��������������������λ������������ӵ�һ������ת���ɵڶ������������ѵ�ʱ�䣬ת���Ĺ�����ȫ�̶�ֻ������������������ԵĻ������impossible
* �ύ״̬�� AC
 *
* ��������� �ڴ棺1064K ʱ�䣺16ms
 *
* ���ⷽ��1���Ӹ�λ��ʼ����0��9�䣬�������ɵ��������������û�б��������Ͱ��������ӣ����ü�1����˲���ֱ��ǧλ��
* ��֦����λ��Ϊ0ʱ������������ȥ��ǧλ������Ϊ0����ȥ
 *
* ���ⷽ��2 ����ѡ����
 *
* ���������2
 *
* ����ԭ�� ����ѡ������ʱ���ж�����ʱ����2��ʼ�������������³�ʱ
* �ж������ķ��������ʱ
 *
* �ĵ���� ����ѡ�����ж�һ������ʱ�ǲ�������ʱ����������ѧ���ܽ���ж�������������ʡʱ���ͬʱҲ��ȷ
�����Ϳ��Խ�Լʱ��
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


void init() {//����ɸ����O��n���� 
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
		for (int i = 1; i < 10; i=i+2)//��λ
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
		for (int i = 0; i < 10; i++)//ʮλ
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
		for (int i = 0; i < 10; i++)//��λ
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
		for (int i = 1; i < 10; i++)//ǧλ
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
