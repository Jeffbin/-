/*
 * ��������������һ�����䣬�м����ͣ���������1��n�����ٷ���
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory: 808K Time:40 MS
 *
* ���ⷽ��1��������dp�ķ������������䳤�ȴ�3��������󳤶ȣ���αȽ��м�ͣ���Ͳ�ͣ�����õķ��ã����õ�1��n����С����
* 
 *
 * ���ⷽ��2 ����ѡ��
 *
 * ���������1
 *
 * ����ԭ�� ����ѡ����һ��ʼ�����i���������յ㣬��ĳɱ�������i+���䳤��-1��
 *
 * �ĵ���� ����ѡ��������dp������ε������䳤�������
 */


#include <iostream>
#include <algorithm>
using namespace std;

int dp[210][210];
int r[210][210];
int n;
int shuchu()
{
	
	for (int lenq = 3; lenq <= n; lenq++)//���䳤��
	{
		for (int i = 1; i <= n-lenq+1; i++)//��㵽�������䳤��
		{
			int j = i + lenq - 1;//�յ�
			for (int k = i+1; k < j; k++)//�м�ͣ����
			{
				if (r[i][k] + r[k][j] < r[i][j])
				{
					r[i][j] = r[i][k] + r[k][j];
				}
			}
		}
	}
	return r[1][n];


}

int main()
{
	
	cin >> n;
	for (int i = 1; i <= n; i++)//����
	{
		for (int j = i + 1; j <= n; j++)
		{
			cin >> r[i][j];
		}
	}
	cout<<shuchu()<<endl;
}