/*
 * 问题描述：在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。
 要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 244K Time: 47MS
 *
 * 解题方法1：设定一个检测列的数组，遍历一行查看是否有地方放棋子，一旦有就标记那一列，并跳到下一行检测是否能放棋子
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：1
 *
 * 错误原因 （可选）：用函数返回值出错，发现检测行res+=dfs(s,u+1)时会再次返回一次res
 * 错误解决方法：用一个全局变量res来返回方案的值
 *
 * 心得体会 （可选）：可以用字符指针来存储字符串，用sort来把列表排序
 */
#include <iostream>
using namespace std;
char map[100][100];
bool lie[100];
int n, k,res;
void  dfs(int s, int u)
{
	
	if (s == k)//棋子够了，就返回
	{
		res++;
		return;
	}
	if (u == n)//棋子不够，行检测完了
	{
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (map[u][i] == '#' && lie[i] == false)
		{
			lie[i] = true;
			 dfs(s + 1, u + 1);
			lie[i] = false;
		}
	}
	dfs(s,u+1);
	
	
}
int main()
{
	int result;
	
	k = n = 0;
	while (k != -1 || n != -1)
	{
		res = 0;
		cin >> n >> k;
		if (k == -1 || n == -1)
		{
			break;
		}
		for (int j = 0; j < n; j++)
		{
			cin >> map[j];
		}
		dfs(0, 0);
		cout << res<<endl;
	}
}
/*
2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1
*/