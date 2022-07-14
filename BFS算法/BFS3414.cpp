/*
* 问题描述：

你会得到两个锅，分别具有A和B升的体积。可以执行以下操作：

FILL（i） 从水龙头填充锅 i （1 ≤ i ≤ 2）;
DROP（i） 将锅 i 清空至下水道;
POUR（i，j） 从锅 i 倒到锅 j;在此操作之后，要么锅j已满（并且锅i中可能还剩下一些水），要么锅i是空的（并且其所有内容物都已移至锅j）。
编写一个程序以找到这些操作的最短序列，这些操作将在其中一个罐中产生恰好C升的水。



* 提交状态： AC
 *
* 交流结果： 内存： 时间：
 *
* 解题方法1：设一个结构体，里面有a桶的当前水容量AL和b桶当前水容量BL，费用，整型数组，然后从起点开始FILL（A），FILL（B），DROP（A），DROP（B），pour(a,b)
* pour(b,a)每种情况都遍历一遍，入队，直到输出结果或函数结束输出 IMPOSSIBEL。
* 剪枝：水空不用倒水；水满不用装水；水空不用把水倒进另一个桶；已经遍历过的点不用重复遍历。
 *
* 解题方法2 （可选）：
 *
* 出错次数：1
 *
* 错误原因 （可选）：爆内存，没有剪枝导致重复遍历同一个点，所有的流程又走一遍
 *
* 心得体会 （可选）：选择输出字符串时，设一个二维字符数组，可以给定一个整型数组来选定输出那段字符串
 */


#include <iostream>
#include<queue>
using namespace std;
int used[1000][1000];
int flag = 0;

char str[6][16] =
{
	
	"FILL(1)",
	"FILL(2)",
	"DROP(1)",
	"DROP(2)",
	"POUR(1,2)",
	"POUR(2,1)"
};
struct point
{
	int AL;
	int BL;
	int cost;
	int line[100];
};
queue<point> r;
void BFS(int z,int x,int c)
{
	point start;
	start.AL = 0;
	start.BL = 0;
	start.cost = 0;
	start.line[1] = 0;
	r.push(start);
	used[0][0] = 1;
	
	while (!r.empty())
	{
		int ac = r.front().AL;
		int bc = r.front().BL;
		int costc = r.front().cost;
		//int zifucuan = r.front().line[costc];
		if (ac == c|| bc==c)
		{
			flag = 1;
			cout << costc << endl;
			for (int ui =0 ; ui < costc; ui++)
			{
				cout << str[r.front().line[ui]]<< endl;
			}
			return;
		}
		//注满A
			
				point temp;
				temp = r.front();
				if (temp.AL != z)
				{
					temp.AL = z;
					temp.cost++;
					if (used[temp.AL][temp.BL] != 1)
					{
						temp.line[costc] = 0;
						r.push(temp);
						used[temp.AL][temp.BL] = 1;
					}
				}
			//注满b
			
				//point temp;
				temp = r.front();
				if (temp.BL != x)
				{
					temp.BL = x;
					temp.cost++;
					if (used[temp.AL][temp.BL] != 1)
					{
						temp.line[costc] = 1;
						r.push(temp);
						used[temp.AL][temp.BL] = 1;
					}
				}
			//倒掉a
			
				//point temp;
				temp = r.front();
				if (temp.AL != 0)//剪枝
				{
					temp.AL = 0;
					temp.cost++;
					if (used[temp.AL][temp.BL] != 1)
					{
						temp.line[costc] = 2;
						r.push(temp);
						used[temp.AL][temp.BL] = 1;
					}
				}
			
				
				
				//倒掉b
				temp = r.front();
				if (temp.BL != 0)//剪枝
				{
					temp.BL = 0;
					temp.cost++;
					if (used[temp.AL][temp.BL] != 1)
					{
						temp.line[costc] = 3;
						r.push(temp);
						used[temp.AL][temp.BL] = 1;
					}
				}


			
				//把a倒到b
				temp = r.front();
				if (temp.AL != 0)//剪枝
				{
					if (temp.BL < x)//没有满
					{
						temp.BL = temp.BL + temp.AL;
						temp.AL = 0;
						if (temp.BL > x)//超过了
						{
							
							temp.AL = temp.BL - x;
							temp.BL = x;
						}
					}
					temp.cost++;
					if (used[temp.AL][temp.BL] != 1)
					{
						temp.line[costc] = 4;
						r.push(temp);
						used[temp.AL][temp.BL] = 1;
					}
				}
			
				//把b倒到a
				temp = r.front();
				if (temp.BL != 0)//剪枝
				{
					if (temp.AL < z)//没有满
					{
						temp.AL = temp.AL + temp.BL;
						temp.BL = 0;
						if (temp.AL > z)//超过了
						{
 							
							temp.BL = temp.AL - z;
							temp.AL = z;
						}
					}
					temp.cost++;
					if (used[temp.AL][temp.BL] != 1)
					{
						temp.line[costc] = 5;
						r.push(temp);
						used[temp.AL][temp.BL] = 1;
					}
				}
				r.pop();
		
	}
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	BFS(a, b, c);
	if (flag == 0)
	{
		cout << "impossible" << endl;
	}
	return 0;
}
/*
示例输入

3 5 4
示例输出

6
FILL(2)
POUR(2,1)
DROP(1)
POUR(2,1)
FILL(2)
POUR(2,1)

*/