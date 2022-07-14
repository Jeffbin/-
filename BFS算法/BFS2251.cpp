/*
 * 问题描述：从一个三维迷宫中找到出口，S为起点，E为终点，#为墙，.为空地
 * 提交状态：  AC
 *
 * AC 结果： MEMORY:	 TIME:
 *
 * 解题方法1：用一个二维数组存储三维数组，a*b表示数组的X行数，c表示数组的列数Y，如果想跳到下一组数组，可以让 x+b，想跳回上一个数组
 * 可以让 x-b。然后遍历每一个走法，如果符合条件且没有走过的点就入队，直到到达终点或者函数结束
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：0
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：三维的东西可以用二维数组来存储
 */
#include <iostream>
#include <queue>
using namespace std;
char map[1000][1000];
int luxian[][2] = { {1,0}, {0,-1} ,{-1,0}, {0,1}, {0,0},{0,0} };//南，西，北，东，上，下
int flag = 0;
int a, b, c;
int used[1000][1000];
struct point
{
	int cost;
	int x;
	int y;
}; 
queue<point> r;
void BFS(int startx, int starty)
{
	point start;
	start.cost = 0;
	start.x = startx;
	start.y = starty;
	r.push(start);
	while (!r.empty())
	{
		int dx = r.front().x;
		int dy = r.front().y;
		int costc = r.front().cost;
		if (map[dx][dy] == 'E')
		{
			flag = 1;
			cout <<"Escaped in "<< costc << " minute(s)." << endl;
			return;
		}
		for (int i = 0; i < 6; i++)
		{
			point temp;
			temp.x = dx + luxian[i][0];
			temp.y = dy + luxian[i][1];
			temp.cost = costc + 1;
			if (i == 4)
			{
				temp.x = dx + b;
				temp.y = dy;
				
			}
			if (i == 5)
			{
				temp.x = dx - b;
				temp.y = dy;
			}
			if (used[temp.x][temp.y]==0&&map[temp.x][temp.y] == 'S' || used[temp.x][temp.y] == 0 && map[temp.x][temp.y] == '.' || used[temp.x][temp.y] == 0 && map[temp.x][temp.y] == 'E')
			{
				used[temp.x][temp.y] = 1;
				r.push(temp);
			}

		}
		r.pop();
	}
}







int main()
{
	
	cin >> a >> b >> c;
	while (a != 0 || b != 0 || c != 0)
	{
		int k=0;
		int g, p;
		memset(map, 0, sizeof(map));
		memset(used, 0, sizeof(used));
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				cin >> map[k++];
			}
		}
		for (int m = 0; m < a*b; m++)
		{
			for (int n = 0; n < c; n++)
			{
				if (map[m][n] == 'S')
				{
					g = m;
					p = n;
				}
			}
		}
		BFS(g, p);
		if (flag == 0)
		{
			cout << "Trapped!" << endl;
		}
		flag = 0;
		cin >> a >> b >> c;
	}
}
/*
示例输入

3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
示例输出

Escaped in 11 minute(s).
Trapped!
*/