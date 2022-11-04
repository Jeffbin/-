/*
 * ��������������һ�����֣��������ϲ����������õ�������ֵT
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory: 808K Time:40 MS
 *
* ���ⷽ��1��dp[i][j]��ʾǰi�����ĺ�Ϊj�ĵ�i����������ֵ��ͨ������õ�dp��������Ƶõ�����ֵ��Ȼ��+����-����С���Ŵ���
* ���Ҽ��Ϻϲ��������ϲ���һ�����ͺ����С����
*
 *
 * ���ⷽ��2 ����ѡ��
 *
 * ���������3
 *
 * ����ԭ�� ����ѡ����
 *
 * �ĵ���� ����ѡ����
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
	for (int i = N; i >= 2; i--)//������·��,ȷ��+,-��
	{
		ans[i] = dp[i][s];
		if (ans[i] == 1)
			s -= a[i];
		else if (ans[i] == -1)
			s += a[i];
	}
	int cnt = 0;
	for (int i = 2; i <= N; i++)//+�ż���С������������
		if (ans[i] == 1)//�� i ���������ģ�ִ�� cut(i - 1)��ǰ��ϲ��� cnt �Σ�����������λ��Ӧ���� i - 1 - cnt
		{
			cout << i - cnt - 1 << endl;
			cnt++;
		}
	for (int i = 2; i <= N; i++)
		if (ans[i] == -1)//�Ѿ��ϲ� cnt �Σ�����Ҫ�ϲ� n - 1 - cnt �Σ���ִ�� cut(1) ��������
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