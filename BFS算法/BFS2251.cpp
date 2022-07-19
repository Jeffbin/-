/*
 * 问题描述：从一个三维迷宫中找到出口，S为起点，E为终点，#为墙，.为空地
 * 提交状态：  AC
 *
 * AC 结果： MEMORY:316K	 TIME:47MS
 *
 * 解题方法1：用一个二维数组存储三维数组，a*b表示数组的X行数，c表示数组的列数Y，如果想跳到下一组数组，可以让 x+b，想跳回上一个数组
 * 可以让 x-b。然后遍历每一个走法，如果符合条件且没有走过的点就入队，直到到达终点或者函数结束
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：1
 *
 * 错误原因 （可选）：使用二维数组解题时有错误，会导致跳到下一维数组导致错误
 *
 * 心得体会 （可选）：能用题目给了几维用几维
 */
#include <iostream>
#include <queue>
using namespace std;
char map[30][30][30];
bool used[30][30][30];
int x, y, z;
int flag = 0;
int L[8] = { 0, 0, 0, 0, -1, 1 };
int R[8] = { 0, 0, -1, 1, 0, 0 };
int C[8] = { -1, 1, 0, 0, 0, 0 };
struct point
{
	int nx;
	int ny;
	int nz;
	int cost;
};
bool panduan(int gx,int gy,int gz)
{
	if (gx < 0 || gx == x || gy < 0 || gy == y || gz < 0 || gz == z||map[gx][gy][gz]=='#')
	{
		return false;
	}
	return true;
}
void BFS(int xx, int yy, int zz)
{
	queue<point> r;
	point start;
	start.cost = 0;
	start.nx = xx;
	start.ny = yy;
	start.nz = zz;
	r.push(start);
	while (!r.empty())
	{
		int endx = r.front().nx;
		int endy = r.front().ny;
		int endz = r.front().nz;
		int costc = r.front().cost;
		r.pop();
		if (map[endx][endy][endz] == 'E')
		{
			flag = 1;
			cout <<"Escaped in "<< costc <<" minute(s)." << endl;
			return;
		}
		for (int i = 0; i < 6; i++)
		{
			point temp;
			temp.nx = endx + L[i];
			temp.ny = endy + R[i];
			temp.nz = endz + C[i];
			temp.cost = costc + 1;
			if (used[temp.nx][temp.ny][temp.nz] == 0 && panduan(temp.nx, temp.ny, temp.nz))
			{
				used[temp.nx][temp.ny][temp.nz] = 1;
				r.push(temp);
			}
		}
		
	}
}
int main()
{
	cin >> x >> y >> z;
	int start_l, start_c, start_r;
	while (x != 0 || y != 0 || z != 0)
	{
		memset(used, 0, sizeof(used));
		memset(map, 0, sizeof(map));
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				for (int k = 0; k < z; k++) {
					
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S')
					{
						start_l = i;
						start_r = j;
						start_c = k;
					}
				}
			}
		}
		BFS(start_l, start_r, start_c);
		if (flag == 0)
		{
			cout << "Trapped!" << endl;
		}
		cin >> x >> y >> z;
		flag = 0;
	}
}

/*
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

1 30 30
.#############################
#...........................E#
#.############################
#.#..........................#
#.#.########################.#
#.#.#......................#.#
#.#.#.####################.#.#
#.#.#.#..................#.#.#
#.#.#.#.################.#.#.#
#.#.#.#.#..............#.#.#.#
#.#.#.#.#.############.#.#.#.#
#.#.#.#.#.#..........#.#.#.#.#
#.#.#.#.#.#.########.#.#.#.#.#
#.#.#.#.#.#.#......#.#.#.#.#.#
#.#.#.#.#.#.#.####.#.#.#.#.#.#
#.#.#.#.#.#.#.##S#.#.#.#.#.#.#
#.#.#.#.#.#.#....#.#.#.#.#.#.#
#.#.#.#.#.#.######.#.#.#.#.#.#
#.#.#.#.#.#........#.#.#.#.#.#
#.#.#.#.#.##########.#.#.#.#.#
#.#.#.#.#............#.#.#.#.#
#.#.#.#.##############.#.#.#.#
#.#.#.#................#.#.#.#
#.#.#.##################.#.#.#
#.#.#....................#.#.#
#.#.######################.#.#
#.#........................#.#
#.##########################.#
#............................#
.#############################
*/