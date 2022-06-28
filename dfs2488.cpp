/*
 * ��������������һ����Χ�����������յķ�������ÿһ�����ж��Ƿ�������ÿ���㣬���Ծ�
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory: 252K Time: 0MS
 *
 * ���ⷽ��1�������ֵ���С��ֵ���������㷨��·��Ӧ����ô�ߣ�Ȼ�������ߣ�ֱ�����г���
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������4
 *
 * ����ԭ�� ����ѡ���������ֵ�����ʲô�������˽⵽�ֵ������㷨�����ֵ���С�����꣬���ߴ�ģ�
 * һ��ʼ��̫��Ϥ�㷨����֪�������㷨��ɵ�����Ӧ����ʲô������֪�������������ÿ�����Ӧ�ý���
 *
 * �ĵ���� ����ѡ����Ҫ��֪���㷨����������
 */


#include <iostream>
#include <stdio.h>
using namespace std;
int dx[] = { -1, 1, -2, 2, -2, 2, -1, 1 }, dy[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int path[30][30], used[30][30], p, q;
bool flag;

void DFS(int r, int c, int sp)
{
    //path[sp][0] = r;
    //path[sp][1] = c;
    if (sp == p * q)
    {
        flag = 1;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int x = r + dx[i];
        int y = c + dy[i];
        if (x >= 1 && x <= p && y >= 1 && y <= q && used[x][y]==0 && !flag)
        {
            used[x][y] = 1;
            DFS(x, y, sp + 1);
            used[x][y] = 0;//����
        }
    }
}

int main()
{
    int n, k;
    cin >> n;//����n����
    for (k = 1; k <= n; k++)
    {
        flag = 0;
        cin >> p >> q;//�������
        memset(used, 0, sizeof(used));
        used[1][1] = 1;//ÿ�δ�1��1��ʼ
        DFS(1, 1, 1);
        cout << "Scenario #" << k << ":" << endl;
        if (flag)
        {
            for (int i = 1; i <= p * q; i++)
            {
                printf("%c%d", path[i][1] - 1 + 'A', path[i][0]);
            }
        }
        else
        {
            cout << "impossible";
        }
        cout << endl;
        cout << "\n";
    }

    return 0;
}
/*
3
1 1
2 3
4 3
*/