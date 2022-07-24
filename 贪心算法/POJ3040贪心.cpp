/*
* 问题描述：有n种硬币，每种硬币有mi个，然后让你给奶牛发工资，每周发至少c元（就是不找零钱的意思）
最多能发几周？（硬币之间都是倍数关系）
 *
* 提交状态： AC
 *
* 交流结果： 内存： 22K 时间：16ms
 *
* 解题方法1：首先先把大于c的钱全部给了，得到N1周的钱；第二，把钱从价值大到小来付款，计算付一周需要多少张面值，如果还有钱没付完，那就从面额
* 小的开始付，直到付完钱。计算最小要用多少张多少面额的钱，然后减去。重复此过程直到不够付钱
 *
* 解题方法2 （可选）：
* 
* 出错次数：1
 *
* 错误原因 （可选）：不懂如何实现组合付钱的逻辑
 *
* 心得体会 （可选）：
 */
#include<string.h>
#include<math.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n, c;
struct coin
{
	int money, num;
}a[25];
bool cmp(coin x, coin y)
{
	return x.money > y.money;
}
int use[25];
void pay()
{
	int sum = 0;
	int i;
	for (i = 0; i < n; i++)//把大于的直接发出去
	{
		if (a[i].money >= c)
		{
			sum += a[i].num;
			a[i].num = 0;
		}
	}
	while (1)//每次的循环，相当于凑出一个方案来。
	{
		int flag = 0;
		int temp = c;
		memset(use, 0, sizeof(use));//每次循环重新记录这回花了多少钱
		for (i = 0; i < n; i++)//因为前面把单个大于C的都取出去了，所以这一步每一个的钱肯定都不会大于C
			if (a[i].num)
			{
				int k = temp / a[i].money;//算出在这种情况下，需要多少个a[i]，记为k
 				int mi = min(a[i].num, k);//对比a[i]里的钱的个数和k谁小。如果k小，那么这个循环继续，继续找可以凑成的//钱的数量够不够
				temp -= mi * a[i].money;  //如果k大的话，那么说明a[i]可以直接凑出C，这时候能跳出循环，处理这一项。
				use[i] = mi;
				if (temp <= 0)
				{
					flag = 1;//符合条件标记
					break;
				}
			}
		if (temp > 0)//题解最后一步。
		{
			for (i = n - 1; i >= 0; i--)
				if (a[i].num > use[i])//如果现有的钱大于他已经花出去的钱，那么再继续。小于等于的话，说明已经花完这部分了
				{
					while (use[i] < a[i].num)
					{
						temp -= a[i].money;//从小面额一点一点减去，能少超过C就少超过
						use[i]++;
						if (temp <= 0)
						{
							flag = 1;//得到符合条件，标记
							break;
						}
					}
					if (temp <= 0) break;
				}
		}
		if (!flag) break;//如果这一轮小于C（凑不够钱），直接跳出。
		int mx = 1000000000;
		for (i = 0; i < n; i++)
			if (use[i])
				mx = min(mx, a[i].num / use[i]);//寻找每一回里面最小的钱币数
		sum += mx;
		for (i = 0; i < n; i++)
			if (use[i])
				a[i].num -= mx * use[i];//删掉已经发出去的钱币
	}
	cout << sum << endl;

}
int main()
{
	int i;
	cin >> n >> c;
	for (i = 0; i < n; i++)
	{
		cin >> a[i].money >> a[i].num;
	}
	sort(a, a + n, cmp);
	pay();
	
		
		
		
	
	
	
}
/*
示例输入

3 6
10 1
1 100
5 120
示例输出

111
*/