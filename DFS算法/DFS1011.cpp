/*
 * ����������ƴ�Ӹ�����ľ����ƴ����ͬ���ȵ�ľ������������̵�ľ������
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory:216k  Time: 16ms
 *
 * ���ⷽ��1����һ��״̬�����ж�ľ�����ޱ�ʹ�ã������ľ�����ȵ��ܳ���ö�ٳ����ܵ�ľ�����ȣ�Ȼ�󰴴�С��ľ�����������ƴ�ӳ�ľ�����򷵻أ��������ö�١�
 * ֱ������
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������3
 *
 * ����ԭ�� ����ѡ����ʱ�䳬ʱ
 * ���������һ����������֦����������ܳ��Ȳ�������ö��ľ�����ȣ���������֦�����������һ��ƴ�ӾͲ��ɹ������������ö�ٵ�ľ�����ȣ��г���һ�����
 *
 * �ĵ���� ����ѡ����1.��֦�����ܼ�������ʱ�䡣2.�ǵ�ͼ������Ҳ���������㷨3.����1Сʱ�벻��������ֱ�������Ͽ������˵Ľ���˼·���ⷨ
 */


#include<iostream>
#include<cstring>
using namespace std;
const int N = 55;
int a[N];//�ж�ľ�����ޱ�ʹ��

int sum, mx, len;

bool dfs(int cnt, int now, int mxx, int len)
{
    if (cnt == 0) return true;//���cnt == 0, ��Ŀ��ľ����ƴ�����

    if (now == len)
    {
        //ƴ�ӳɹ�, ��ʼƴ����һ��
        if (dfs(cnt - 1, 0, mx, len)) return true;
    }

    for (int i = mxx; i > 0; i--)
    {
        if (a[i] && i + now <= len)
        {
            a[i]--;
            if (dfs(cnt, now + i, i, len)) return true;

            a[i]++;//��ԭ
            if (now == 0 ) return false;//��һ��ʧ��ֱ�Ӽ�֦��˵�����ľ������ƴ��ľ��
        }

    }
    return false;
}

int main()
{
    int n, t;
    cin >> n;
    while (n!=0)
    {
        
        memset(a, 0, sizeof(a));
        sum = len = mx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            a[t]++;
            sum += t;
            mx = max(mx, t);
        }
        
        for (int i = mx; i <= sum; i++)
        {
            
            if (sum % i != 0)
            {
                continue;
            }
          
            
            if (dfs(sum / i, 0, mx, i))
            {
                cout << i << endl;
                break;
            }
        }

        cin >> n;
    }

    return 0;
}
/*
9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
0

*/