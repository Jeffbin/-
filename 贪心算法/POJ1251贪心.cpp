/*
* ����������������С������
 *
* �ύ״̬�� AC
 *
* ��������� �ڴ棺 22.4K ʱ�䣺32ms
 *
* ���ⷽ��1����������ķ�㷨����С�����������ƵϽ�˹�����㷨�������ѡ��һ���㣬Ȼ��Ѱ������㵽���������̾��룬�������㣬Ȼ��Ѱ����������
* �����������̾��룬���ѭ��ֱ����ͨ�����е㣬�õ���̾���ĺ�
 *
* ���ⷽ��2 ����ѡ����
*
* ���������
 *
* ����ԭ�� ����ѡ����
 *
* �ĵ���� ����ѡ����������һ����С�������㷨�򵥣�����Ҫѧ���鼯
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 30;
const int inf = 0x3f3f3f;
int mapp[maxn][maxn];
int dis[maxn];
int vis[maxn];
int n;
char x, h;
int m, ans, w;
void init()
{
    ans = 0;
    memset(vis, 0, sizeof(vis));
    memset(mapp, inf, sizeof(mapp));
}
void prim()
{
    for (int i = 0; i < n; i++)
    {
        dis[i] = mapp[0][i];
    }
    dis[0] = 0;
    vis[0] = 1;
    for (int v = 0; v < n - 1; v++)
    {
        int minx = inf;
        int p = -1;
        for (int i = 0; i < n; i++)
            if (!vis[i] && dis[i] < minx)
            {
                p = i;
                minx = dis[i];
            }
        ans += dis[p];
        vis[p] = 1;
        for (int i = 0; i < n; i++)
            if (!vis[i] && dis[i] > mapp[p][i])
                dis[i] = mapp[p][i];
    }
}
int main()
{
    while (cin>>n && n)
    {
        init();
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x >> m;
            for (int j = 0; j < m; j++)
            {
                
                cin >> h >> w;
                int from = x - 'A';
                int to = h - 'A';
                mapp[from][to] = mapp[to][from] = w;
            }
        }
        prim();
        cout << ans << endl;
    }
    return 0;
}
/*
ʾ������

9
A 2 B 12 I 25
B 3 C 10 H 40 I 8
C 2 D 18 G 55
D 1 E 44
E 2 F 60 G 38
F 0
G 1 H 35
H 1 I 35
3
A 2 B 10 C 40
B 1 C 20
0
ʾ�����

216
30

*/