/*
* �������������ݸ����ĵ�����������Ȩֵ������С������
 *
* �ύ״̬�� AC
 *
* ��������� �ڴ棺 24.8K ʱ�䣺79ms
 *
* ���ⷽ��1��ʹ�ÿ�³˹�����㷨�����ȳ�ʼ�����Ϻţ�ÿ���㶼�а��������ļ��Ϻţ�Ȼ���С�������򣬴�ȨֵС����ı߼��������ߣ����������
* ����������ĸ���һ������˵��������Ѿ��ɻ��������������ߣ����ѭ����ֱ������n-1����Ϊֹ��
 *
* ���ⷽ��2 ����ѡ����
*
* ���������0
 *
* ����ԭ�� ����ѡ����
 *
* �ĵ���� ����ѡ��������ͼһ��ѡ�� Kruskal ,�����ڽӱ���д洢��֮��Ĺ�ϵ(������ýṹ��ķ�ʽ)���ҿ�³˹�����ķ����򵥣�ֻ��ӱ�
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
    return x.w < y.w;//��С��������
}

void Init(int n) {//��ʼ�����Ϻ�Ϊ���� 
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int Find(int x) {//������ 
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
    for (int i = 0; i < m-1; i++)//ѡ��n-1����ʱ����
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
ʾ�����

0
17
16
26

*/