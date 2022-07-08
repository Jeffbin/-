/*
 * 问题描述：冰壶只能沿着一个方向前进(对角线不行)，并且只有撞墙才能停下来，停下来后墙就被击碎了(变为能走的路)，
 对于当前点位旁边如果有block则不能发球。最后求从起点到终点最短的击球次数，要求在10次以内完成
 * 提交状态：  AC
 *
 * AC 结果： MEMORY:256K TIME:172MS->157MS(剪枝后)
 *
 * 解题方法1：从起点开始dfs，四个方向都遍历一次，没撞墙就一直往那个方向走，如果到达终点，
 但步数大于最大步数，返回（剪枝），没有的话就对比best步数和当前step大小，选择小的然后返回
 。如果撞墙就把墙变为空地，step++，递归dfs继续遍历，如果出界则跳过当前方向
 *				
				
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：0
 *
 * 错误原因 （可选）：
					
 *
 * 心得体会 （可选）：
 */

#include <iostream>
using namespace std;
int map[100][100];
int dir[][2] = { {0,-1},{-1,0},{0,1},{1,0} };//←↑→↓

int best=10000;
int w, h;//宽，高
int gx, gy;//起点坐标

void dfs(int x,int y,int step)
{

	if (step >= 10)
	{
		
		return;
	}
	int dx, dy;
	for (int o=0; o < 4; o++)
	{
		dx = x + dir[o][0];
		dy = y + dir[o][1];
		if (dx < 0 || dy < 0 || dx >= h || dy >= w)//出界
		{
			continue;
		}
		if (map[dx][dy] == 0 || map[dx][dy] == 2 || map[dx][dy] == 3)
		{
			while (dx<h&&dx >= 0 &&dy>=0&& dy < w && map[dx][dy] != 1)
			{
				
				if (map[dx][dy] == 3)//到达终点
				{
					if (step > best)
						return;
					best = min(best, step + 1);
					break;
				}
				dx = dx + dir[o][0];
				dy = dy + dir[o][1];
				if (map[dx][dy] == 1)//撞墙
				{
					map[dx][dy] = 0;
					
					dfs(dx - dir[o][0], dy - dir[o][1], step +1);
					map[dx][dy] = 1;
				}
			
			}
		}
		
		
		
	}

}


int main()
{
	
	int x, y,step=0;
	cin >> w >> h;
	
	while (w!=0 || h!=0)
	{
		memset(map, -1, sizeof(map));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 2)
				{
					gx = i; gy = j;
					
				}
			}
		}
		dfs(gx, gy, step);
		
		if(best>10||best==0)
		{ 
			best = -1;
		}
		cout << best << endl;
		best = 10000;
		
		cin >> w >> h;
	}
}
/*
2 1
3 2
6 6
1 0 0 2 1 0
1 1 0 0 0 0
0 0 0 0 0 3
0 0 0 0 0 0
1 0 0 0 0 1
0 1 1 1 1 1
6 1
1 1 2 1 1 3
6 1
1 0 2 1 1 3
12 1
2 0 1 1 1 1 1 1 1 1 1 3
13 1
2 0 1 1 1 1 1 1 1 1 1 1 3
0 0
*/
/*
1
4
-1
4
10
-1
*/