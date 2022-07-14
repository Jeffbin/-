/*
 * ��������������һ��������n����дһ���������ҳ�n�ķ��㱶��m����ʮ���Ʊ�ʾֻ��������0��1��
			�����Լ��� n ������ 200��������һ������������ 100 ��С��λ����Ӧ m
 * �ύ״̬��  AC
 *
 * AC ����� MEMORY: TIME:
 *
 * ���ⷽ��1����1��ʼ��ÿ��*10����*10+1��������֤����ô������֤�����m��ֻ��0��1����ӣ��ظ�������̣�ֱ��m�ܹ�����n
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������1
 *
 * ����ԭ�� ����ѡ����һ��ʼ�޷����������֧�޽編��ϵ���������˱������ۼӱ������³�ʱ��

 *
 * �ĵ���� ����ѡ����BFS�޷Ǿ���һ�����⣬��·�����Ҿ��Բ�ֹ1��·����������
 */


#include <queue>
#include <iostream>
using namespace std;
struct point
{
	int x;
};
queue <point> r;

void BFS(int n)
{
	point start;
	start.x = 1;
	r.push(start);
	while (!r.empty())
	{
		int dx=r.front().x;
		if (r.front().x % n == 0)
		{
			cout << r.front().x << endl;
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			point temp;
			if (i == 0)
			{
				temp.x = dx * 10;
				r.push(temp);
			}
			if (i == 1)
			{
				temp.x = dx * 10 + 1;
				r.push(temp);
			}
		}
		r.pop();
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