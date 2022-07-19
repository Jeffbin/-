/*
 * ��������������һ��������n����дһ���������ҳ�n�ķ��㱶��m����ʮ���Ʊ�ʾֻ��������0��1��
			�����Լ��� n ������ 200��������һ������������ 100 ��С��λ����Ӧ m
 * �ύ״̬��  AC
 *
 * AC ����� MEMORY:4746K TIME:438MS
 *
 * ���ⷽ��1����1��ʼ��ÿ��*10����*10+1��������֤����ô������֤�����m��ֻ��0��1����ӣ��ظ�������̣�ֱ��m�ܹ�����n
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������3
 *
 * ����ԭ�� ����ѡ����һ��ʼ�޷����������֧�޽編��ϵ���������˱������ۼӱ������³�ʱ��
 * 2.ʹ�ö����͵��������������
 * 3.ÿ��ʹ���꺯����û�г�ʼ�����е��´���
 *
 * �ĵ���� ����ѡ����1.BFS�޷Ǿ���һ�����⣬��·�����Ҿ��Բ�ֹ1��·����������
 * 2.����Ҫ�ó����ʹ洢
 * 
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