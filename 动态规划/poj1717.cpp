/*
* �����������������ռ������棬����������������ͨ���Ƿ�ת���ﵽ�������µĲ���С
* �ύ״̬�� AC
 *
* ��������� �ڴ棺47800K ʱ�䣺454MS
 *
* ���ⷽ��1��ͨ������dp��˼�룬dp[i][j]��ʾǰi�����ƵĲ�ֵΪj����С��ת��������Ϊ�в�ֵ�����鲻��Ϊ����ҲҪ����ƫ��
* 
*    ��ǰ���Ʒ�ת��״̬����Ϊdp[i-1][j-(a[i]-b[i])]+1,����ת��״̬����Ϊdp[i-1][j+[(a[i]-b[i])]]
* ����״̬ת�Ʒ���Ϊdp[i][j]=min(dp[i-1][j-(a[i]-b[i])]+1,dp[i-1][j+[(a[i]-b[i])]])
 *
 *
* ���ⷽ��2 ����ѡ����
 *
* ���������1
 *
* ����ԭ�� ����ѡ������ʼ��dp�����������ƫ�ù���
 *
* �ĵ���� ����ѡ����
 */

#include<algorithm>
#include <iostream>
using namespace std;

int dp[1010][12010];
int a[1010];
int b[1010];
int n;
int base = 6000;//ƫ��
void init()
{
	memset(dp, 0xf, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]>>b[i];
	}
	dp[0][6000] = 0;
}
void guihua()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 12010; j++)
		{
			int cha = a[i] - b[i];
			dp[i][j] = min(dp[i - 1][j- cha], dp[i - 1][j + cha] + 1);
		}
	}
	for (int i = 0; i <= 6000; i++)
		 {
		        int ans = min(dp[n][i + 6000], dp[n][6000 - i]);
		       if (ans <= 1000)
		       {
		           cout << ans;
				   break;
		        }
	    }
}
int main()
{
	
	cin >> n;
	init();
	guihua();
}