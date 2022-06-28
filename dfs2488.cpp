/*
 * 问题描述：给出一个范围，根据马走日的方法走完每一个点判断是否能走完每个点，可以就
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 252K Time: 0MS
 *
 * 解题方法1：根据字典序小的值设置搜索算法的路径应该怎么走，然后依次走，直到运行出来
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：4
 *
 * 错误原因 （可选）：不懂字典序是什么，后面了解到字典序并让算法先往字典序小的走完，再走大的；
 * 一开始不太熟悉算法，不知道搜索算法完成的条件应该是什么，后面知道了如果走完了每个点就应该结束
 *
 * 心得体会 （可选）：要先知道算法结束的条件
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
            used[x][y] = 0;//回溯
        }
    }
}

int main()
{
    int n, k;
    cin >> n;//输入n组数
    for (k = 1; k <= n; k++)
    {
        flag = 0;
        cin >> p >> q;//输入宽、高
        memset(used, 0, sizeof(used));
        used[1][1] = 1;//每次从1，1开始
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