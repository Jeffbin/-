/*
* 问题描述：给出最小生成树
 *
* 提交状态： AC
 *
* 交流结果： 内存： 22.4K 时间：32ms
 *
* 解题方法1：套用普利姆算法的最小生成树，类似迪杰斯特拉算法，先随机选择一个点，然后寻找这个点到其他点的最短距离，标记这个点，然后寻找这两个点
* 到其他点的最短距离，如此循环直到连通完所有点，得到最短距离的和
 *
* 解题方法2 （可选）：
*
* 出错次数：
 *
* 错误原因 （可选）：
 *
* 心得体会 （可选）：比另外一个最小生成树算法简单，不需要学并查集
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
示例输入

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
示例输出

216
30

*/