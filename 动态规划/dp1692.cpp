
/*
 * ������������Ŀ�Ǹ����������飬Ҫ���ҳ����ƥ��������
		ƥ������ǣ�

				a[i] ==b[j]��������Ҫ�������棬����ÿ����ֻ��ƥ��һ�Ρ�
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory: 316K Time:16 MS
 *
* ���ⷽ��1����������dp[i][j]��ʾ��һ��ȡi�������ڶ���ȡj�����ֵ����ƥ����
	����ĳ��dp[i][j]:
	1.��ƥ���һ��i������ƥ��ڶ��е�j����dp[i][j]=Max(dp[i-1][j],dp[i][j-1])
	2.���a[i]==b[j],��������ƥ�䣬ƥ����Ϊ1��ֵ
	3.��a[i]!=b[j]:
	a.���һ�д�i��ǰ��ɨ��ֱ��ɨ����һ��a[k1]==b[j](k1 b.ͬ���ڶ��д�j��ǰɨ��
	ֱ��ɨ����һ��b[k2]==a[i](k2 ���Ҳ���������k1,k2���ܲŲ�����ƥ�䣬����
	������������k1,k2,��ʱƥ�䣨a[i],b[k2]����(a[k1],b[j])ƥ�䣬
	�����µ�ƥ������,ƥ������Ϊ��dp[k1-1][k2-1]+2.
*
 *
 * ���ⷽ��2 ����ѡ��
 *
 * ���������1
 *
 * ����ԭ�� ����ѡ����������ʲô�������жϽ���
 *
 * �ĵ���� ����ѡ����
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
					dp[i][j] = max(dp[i][j],dp[k2-1][k1-1] + 2);////�� dp[k1-1][k2-1]֮���ֲ����������µ�ƥ��
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
		init(N1,N2);//��ʼ��
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