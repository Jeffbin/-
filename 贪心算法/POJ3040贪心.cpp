/*
* ������������n��Ӳ�ң�ÿ��Ӳ����mi����Ȼ���������ţ�����ʣ�ÿ�ܷ�����cԪ�����ǲ�����Ǯ����˼��
����ܷ����ܣ���Ӳ��֮�䶼�Ǳ�����ϵ��
 *
* �ύ״̬�� AC
 *
* ��������� �ڴ棺 22K ʱ�䣺16ms
 *
* ���ⷽ��1�������ȰѴ���c��Ǯȫ�����ˣ��õ�N1�ܵ�Ǯ���ڶ�����Ǯ�Ӽ�ֵ��С��������㸶һ����Ҫ��������ֵ���������Ǯû���꣬�Ǿʹ����
* С�Ŀ�ʼ����ֱ������Ǯ��������СҪ�ö����Ŷ�������Ǯ��Ȼ���ȥ���ظ��˹���ֱ��������Ǯ
 *
* ���ⷽ��2 ����ѡ����
* 
* ���������1
 *
* ����ԭ�� ����ѡ�����������ʵ����ϸ�Ǯ���߼�
 *
* �ĵ���� ����ѡ����
 */
#include<string.h>
#include<math.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n, c;
struct coin
{
	int money, num;
}a[25];
bool cmp(coin x, coin y)
{
	return x.money > y.money;
}
int use[25];
void pay()
{
	int sum = 0;
	int i;
	for (i = 0; i < n; i++)//�Ѵ��ڵ�ֱ�ӷ���ȥ
	{
		if (a[i].money >= c)
		{
			sum += a[i].num;
			a[i].num = 0;
		}
	}
	while (1)//ÿ�ε�ѭ�����൱�ڴճ�һ����������
	{
		int flag = 0;
		int temp = c;
		memset(use, 0, sizeof(use));//ÿ��ѭ�����¼�¼��ػ��˶���Ǯ
		for (i = 0; i < n; i++)//��Ϊǰ��ѵ�������C�Ķ�ȡ��ȥ�ˣ�������һ��ÿһ����Ǯ�϶����������C
			if (a[i].num)
			{
				int k = temp / a[i].money;//�������������£���Ҫ���ٸ�a[i]����Ϊk
 				int mi = min(a[i].num, k);//�Ա�a[i]���Ǯ�ĸ�����k˭С�����kС����ô���ѭ�������������ҿ��Դճɵ�//Ǯ������������
				temp -= mi * a[i].money;  //���k��Ļ�����ô˵��a[i]����ֱ�Ӵճ�C����ʱ��������ѭ����������һ�
				use[i] = mi;
				if (temp <= 0)
				{
					flag = 1;//�����������
					break;
				}
			}
		if (temp > 0)//������һ����
		{
			for (i = n - 1; i >= 0; i--)
				if (a[i].num > use[i])//������е�Ǯ�������Ѿ�����ȥ��Ǯ����ô�ټ�����С�ڵ��ڵĻ���˵���Ѿ������ⲿ����
				{
					while (use[i] < a[i].num)
					{
						temp -= a[i].money;//��С���һ��һ���ȥ�����ٳ���C���ٳ���
						use[i]++;
						if (temp <= 0)
						{
							flag = 1;//�õ��������������
							break;
						}
					}
					if (temp <= 0) break;
				}
		}
		if (!flag) break;//�����һ��С��C���ղ���Ǯ����ֱ��������
		int mx = 1000000000;
		for (i = 0; i < n; i++)
			if (use[i])
				mx = min(mx, a[i].num / use[i]);//Ѱ��ÿһ��������С��Ǯ����
		sum += mx;
		for (i = 0; i < n; i++)
			if (use[i])
				a[i].num -= mx * use[i];//ɾ���Ѿ�����ȥ��Ǯ��
	}
	cout << sum << endl;

}
int main()
{
	int i;
	cin >> n >> c;
	for (i = 0; i < n; i++)
	{
		cin >> a[i].money >> a[i].num;
	}
	sort(a, a + n, cmp);
	pay();
	
		
		
		
	
	
	
}
/*
ʾ������

3 6
10 1
1 100
5 120
ʾ�����

111
*/