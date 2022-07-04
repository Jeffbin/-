/*
 * 问题描述：拼接给出的木棍来拼出相同长度的木棒，输出尽量短的木棒长度
 *
 * 提交状态： AC
 *
 * AC 结果： Memory:216k  Time: 16ms
 *
 * 解题方法1：用一个状态数组判断木棒有无被使用，从最大木棍长度到总长度枚举出可能的木棒长度，然后按大到小给木棍排序，如果能拼接出木棍，则返回，否则继续枚举‘
 * 直到列完
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：3
 *
 * 错误原因 （可选）：时间超时
 * 解决方法：一、给出个剪枝函数，如果总长度不能整除枚举木棒长度，则跳过剪枝。二、如果第一次拼接就不成功，则跳过这个枚举的木棒长度，列出下一个情况
 *
 * 心得体会 （可选）：1.剪枝函数能减大量的时间。2.非地图类问题也能用搜素算法3.超过1小时想不出来，就直接在网上看看他人的解题思路，解法
 */


#include<iostream>
#include<cstring>
using namespace std;
const int N = 55;
int a[N];//判断木棒有无被使用

int sum, mx, len;

bool dfs(int cnt, int now, int mxx, int len)
{
    if (cnt == 0) return true;//如果cnt == 0, 则目标木棒已拼接完成

    if (now == len)
    {
        //拼接成功, 开始拼接下一根
        if (dfs(cnt - 1, 0, mx, len)) return true;
    }

    for (int i = mxx; i > 0; i--)
    {
        if (a[i] && i + now <= len)
        {
            a[i]--;
            if (dfs(cnt, now + i, i, len)) return true;

            a[i]++;//还原
            if (now == 0 ) return false;//第一次失败直接剪枝，说明这个木棍不能拼成木棒
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