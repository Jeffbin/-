/*
* ��������������������λ������������ӵ�һ������ת���ɵڶ������������ѵ�ʱ�䣬ת���Ĺ�����ȫ�̶�ֻ������������������ԵĻ������impossible
* �ύ״̬�� AC
 *
* ��������� �ڴ棺 ʱ�䣺
 *
* ���ⷽ��1���Ӹ�λ��ʼ����0��9�䣬�������ɵ��������������û�б��������Ͱ��������ӣ����ü�1����˲���ֱ��ǧλ��
* ��֦����λ��Ϊ0ʱ������������ȥ��ǧλ������Ϊ0����ȥ
 *
* ���ⷽ��2 ����ѡ����
 *
* ���������1
 *
* ����ԭ�� ����ѡ������ʱ���ж�����ʱ����2��ʼ�������������³�ʱ
 *
* �ĵ���� ����ѡ�����ж�һ������ʱ�ǲ�������ʱ����ʵ����x�������ֳ����󲿷֣�
һ������С��x��ƽ����������һ���ִ���x��ƽ������С��ƽ�����ʹ���ƽ�����Ĳ�����һһ��Ӧ�ģ�
�������ֻ�жϴ�2��ƽ�����������Ƿ��ܱ��������ɡ�
�����Ϳ��Խ�Լʱ��
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
		for (int i = 1; i < 10; i++)//��λ
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
		for (int i = 0; i < 10; i++)//ʮλ
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
		for (int i = 0; i < 10; i++)//��λ
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
		for (int i = 1; i < 10; i++)//ǧλ
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