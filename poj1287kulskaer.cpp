/*
* 问题描述：根据给出的点数，边数，权值给出最小生成树
 *
* 提交状态： AC
 *
* 交流结果： 内存： 24.8K 时间：79ms
 *
* 解题方法1：使用库鲁斯卡尔算法，首先初始化集合号，每个点都有包含这个点的集合号，然后从小到大排序，从权值小到大的边加入这条边，如果这条边
* 的两个顶点的父点一样，则说明这个边已经成环，不考虑这条边，如此循环，直到加入n-1条边为止。
 *
* 解题方法2 （可选）：
*
* 出错次数：0
 *
* 错误原因 （可选）：
 *
* 心得体会 （可选）：稠密图一般选择 Kruskal ,采用邻接表进行存储边之间的关系(更多采用结构体的方式)，且克鲁斯卡尔的方法简单，只需加边
 */

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 55;
int fa[N];
int n, m;

struct Edge {  
    int u, v, w;
}e[3000];

bool cmp(Edge x, Edge y) {
    return x.w < y.w;//从小到大排序
}

void Init(int n) {//初始化集合号为自身 
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int Find(int x) {//找祖宗 
    if (x != fa[x])
        fa[x] = Find(fa[x]);
    return fa[x];
}

bool Merge(int a, int b) {
    int p = Find(a);
    int q = Find(b);
    if (p == q) return 0;
    fa[q] = p;
    return 1;
}

int Kruskal(int n) {
    int ans = 0;
    sort(e, e + m, cmp);
    for (int i = 0; i < m-1; i++)//选择n-1条边时结束
        if (Merge(e[i].u, e[i].v)) {
            ans += e[i].w;
            n--;
            if (n == 1)
                return ans;
        }
    return 0;
}

int main() {
    while (cin >> n && n)
    {
        cin >>m;
        Init(n);
       
        for (int i = 0; i < m; i++)
            cin >> e[i].u >> e[i].v >> e[i].w;
        cout<< Kruskal(n) << endl;
    }
    return 0;
}
/*
1 0

2 3
1 2 37
2 1 17
1 2 68

3 7
1 2 19
2 3 11
3 1 7
1 3 5
2 3 89
3 1 91
1 2 32

5 7
1 2 5
2 3 7
2 4 8
4 5 11
3 5 10
1 5 6
4 2 12

0
示例输出

0
17
16
26

*/