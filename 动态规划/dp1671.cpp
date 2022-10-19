/*
 * 问题描述：有n行诗，每行都有其韵律.求n行诗存在的韵律组合数。
 * 提交状态： AC
 *
 * AC 结果： Memory: 348K Time:0 MS
 *
* 解题方法1：第二类Stirling数是把n个元素放入k个等价类的方法数目(每个等价类都不能为空)。

    注意到此题的'行数'>='韵律数',可以把'行数'抽象为n个元素,'韵律数'抽象为k个等价类.

   所求即为：把n行放入k个‘韵律’中的方法数( 其中:1=< k <=n )。
 *
 * 解题方法2 （可选）
 *
 * 出错次数：5
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：像这种背包dp也可以联想到第二类stirling数，
 * 得到固定的状态转移方程
 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
double f[110][110];//[元素数量][分组数量]=方法数
int n;
void init() {
    int i, j;
    for (i = 1; i <= 100; i++)
    {
        f[1][i] = 0;//韵律数超过行数时，一定存在空韵律
        f[i][1] = 1;//只存在一种韵律，把i行放入这一个韵律中的方法数始终为1
    }
    for (i = 2; i <= 100; i++)
        for (j = 2; j <= i; j++) {
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j] * j;
        }
    return;
}
int main() {
    init();
    while (cin>>n && n) {
        double ans = 0;
        for (int i = 1; i <= n; i++)
            ans += f[n][i];
        printf("%d %.0f\n", n, ans);
    }
    return 0;
}
/*
示例输入

1
2
3
4
20
30
10
0
示例输出

1 1
2 2
3 5
4 15
20 51724158235372
30 846749014511809120000000
10 115975

*/