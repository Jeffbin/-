/*
* 问题描述：给你n个小的木棍，让你将其拼接为一根木棍，每次拼接使用的花费为：
（比如木棍a长度为aa，木棍b长度为bb）aa+bb，问将这些个木棍组合起来需要的最小花费。
 *
* 提交状态： AC
 *
* 交流结果： 内存： 37.6K 时间： 79MS
 *
* 解题方法1：用优先弹出最小元素的优先队列先拼接最小的两条木板，直到最后只剩下一根木棍时停止
 *
* 解题方法2 （可选）：给输入的木板长度排序，依次切割最大的木板，直到木板数量等于需要的数量时停止
 *
* 出错次数：0
 *
* 错误原因 （可选）：
 *
* 心得体会 （可选）：见到有元素大于10000时变量都应该用长整型变量来存储
 */


#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    int temp;
    while (cin >> N)
    {

        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            q.push(temp);
        }
        long long  sum = 0;

        if (q.size() == 1)
        {
            int a = q.top();
            sum += a;
            q.pop();
        }
        for (int i = 0; i < N - 1; i++)
        {

            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            int t = a + b;
            sum += t;
            q.push(t);
        }


        cout << sum << endl;
    }


    return 0;
}

