/*
 * ������������n����ѡ����ѡ��m����Ա��ÿ����ѡ�˶���d[i]��p[i]
 * ����ֵ��D��PΪѡ��m����Ա���ǵ�d[i]�ĺͺ�p[i]�ĺͣ����뱣֤|D-P|
 * ��С�����һ��С����ѡ��D+P���ķ���
 * �ύ״̬��  AC
 *
 * AC ����� MEMORY:14264K TIME:360MS
 *
 * ���ⷽ��1���������ڱ���dp��DP[i][j][k]��ʾǰi������ѡj����ƫ��ΪkʱD+P���ܺ͡����������200����ѡ��,D-P�ķ�Χ��-400-400
 * �в�������������û�и������������Ǽ���base=400��ƫ��
 * ����ת�Ʒ��̵õ�D+P�����ֵ������������ƫ�����õ���ֵ���Ӷ�������Ŀ������������
  ����ѡ��i����ʱ, DP[i][j][k]=DP[i-1][j][k].ѡ���i����ʱDP[i][j][k]=DP[i-1][j-1][k-D[i]+P[i]]+D[i]+P[i]
  ������Ҫ�����ܺ�ֵ��ת�Ʒ���ΪDP[i][j][k]=max(DP[i][j][k], DP[i - 1][j - 1][t] + P[i] + D[i])
  Ȼ�����ǻ������ˣ����f[i][j][k] == f[i - 1][j][k]����˵����i����û�б�ѡ��i--������i--,j--,k�ټ�ȥ��ѡ�˵�ƫ���һ��
  ���������������ѡ���ˡ�
 * 
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������6
 *
 * ����ԭ�� ����ѡ����������ô��ת�Ʒ���
 *
 * �ĵ���� ����ѡ��������̬�滮Ҫ�ȷ����������һ��dp������dp������dp��������У�һ������������ֵ����Сֵ���趨ת�Ʒ���
 * ת�Ʒ��̿��Դ������Զ��׼���Ӱ��Ĳ������绨�ѣ�װ����Ʒ��װ�������ȡ�Ȼ��̬�滮��֮��Ҫ������ѡ�����Ʒ�������
 * memset����������0x3f����ʾ������
 */

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 210;
const int M = 810;
const int base = 400;
int f[N][21][M],p[N],d[N],ans[N],n,m;


int main()
{
	int T = 1;
	while (cin >> n >> m, n, m)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i] >> d[i];
		}
		memset(f, -0x3f, sizeof(f));
		f[0][0][base] = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				for (int k = 0; k < M; k++)
				{
					f[i][j][k] = f[i - 1][j][k];//��ѡ�����
					int t = k - (p[i] - d[i]);
					if (t<0 || t>M)
					{
						continue;
					}
					if (j < 1)
					{
						continue;
					}
					f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][t] + p[i] + d[i]);//ѡ��i����
				}
			}
		}

		int v = 0;
		while (f[n][m][v + base] < 0 && f[n][m][base - v] < 0)
		{
			v++;
		}
		if (f[n][m][v + base] > f[n][m][base - v])
		{
			v = v + base;
		}
		else
		{
			v = base - v;
		}

		//��������
		int i = n, j = m, k = v;
		while (j)
		{
			if (f[i][j][k] == f[i - 1][j][k])
			{

				i--;
			}
			else
			{
				ans[cnt++] = i;//ѡ�˵�i����
				 k= k - (p[i] - d[i]);  //��ֵ��С
				 j--;
				 i--;
			}
		}
		int a = 0, b = 0;
		for (int i = 0; i < cnt; i++) a += p[ans[i]], b += d[ans[i]];
		cout << "Jury #" << T << endl;
		T++;
		cout << "Best jury has value " << a << " for prosecution and value " << b << " for defence:" << endl;
		for (int i = cnt - 1; i >= 0; i--)
		{
			cout << ans[i]<<" ";
		}
		cout << endl;
		cout << endl;
	}
}
/*
ʾ������
4 2
1 2
2 3
4 1
6 2
0 0
ʾ�����
Jury #1
Best jury has value 6 for prosecution and value 4 for defence:
 2 3 
 */