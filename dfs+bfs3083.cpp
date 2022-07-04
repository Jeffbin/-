#include<iostream>
#include <queue>

using namespace std;
struct point
{
	int x;
	int y;
	int step;
};
queue<point>r;//申请队列
int dx[4] = { 0,1,0,-1 };//顺时针右 下左上 
int dy[4] = { 1,0,-1,0 };
char map[100][100];
int dyl[] = {-1,0,1,0};
int dxl[] = {0,-1,0,1};
int dxr[] = { 1,0,-1,0 };
int dyr[] = { 0,1,0,-1 };
int ans=1;
int cnt = 1;
bool used[100][100],flag=0;
int w, h,outl=1,outr=1;

void dfsleft(int c,int z)
{
	
	if (outl == 0)
	{

		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		int x = c + dxl[i];
		int y = z + dyl[i];
		
		if (used[x][y]==0&&map[x][y]=='.'|| used[x][y] == 0&&map[x][y]=='S')
		{
			used[x][y] = 1;
			ans++;
			dfsleft(x , y);
			
			used[x][y] = 0;
			if (outl == 0)
			{

				return;
			}
			ans++;
		}
		if (used[x][y] == 0 && map[x][y] == 'E')
		{
			outl = 0;
			ans++;
			break;
		}
		
	}
}
void dfsright(int c, int z)
{
	if (outr == 0)
	{

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int x = c + dxr[i];
		int y = z + dyr[i];

		if (used[x][y] == 0 && map[x][y] == '.' || used[x][y] == 0 && map[x][y] == 'S')
		{
			used[x][y] = 1;
			cnt++;
			dfsright(x, y);

			used[x][y] = 0;
			if (outr == 0)
			{

				return;
			}
			cnt++;
		}
		if (used[x][y] == 0 && map[x][y] == 'E')
		{
			outr = 0;
			cnt++;
			break;
		}

	}
}
void bfs(int g,int p)
{
	point start;
	start.x = g;
	start.y = p;
	start.step = 1;
	r.push(start);//入队
	used[g][p] = 1;
	int flag = 1;
	while (!r.empty())
	{
		int x = r.front().x;
		int y = r.front().y;
		if (map[x][y] == 'E')
		{
			flag = 1;
			cout << r.front().step;
		}
		for (int k = 0; k <= 3; k++)
		{
			int tx, ty;
			tx = x + dx[k];
			ty = y + dy[k];
			if (map[tx][ty] == '.' && used[tx][ty] == 0|| map[tx][ty] == 'E' && used[tx][ty] == 0)
			{
				//入队
				point temp;
				temp.x = tx;
				temp.y = ty;
				temp.step = r.front().step + 1;
				r.push(temp);
				used[tx][ty] = 1;
			}
		}
		r.pop();
	}

}

int main()
{
	int n;
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		memset(used, 0, sizeof(used));
		memset(map, 0, sizeof(map));
		cin >> w >> h;
		for (int k = 0; k < h; k++)
		{
			cin >> map[k];
		}
		int i, m,g,p;
		for (i = 0; i < h; i++)
		{
			for (m=0; m < w; m++)
			{
				if (map[i][m] == 'S')
				{
					g = i; p = m;
					break;
				}
			}
			
		}
		used[g][p] = 1;
		dfsleft(g, p);
		cout << ans << endl;
		
		
		ans = 1;//初始化
		outl = 1;//初始化
		memset(used, 0, sizeof(used));
		used[g][p] = 1;
		dfsright(g, p);
		
		cout << cnt << endl;
		cnt = 1;//初始化
		outr = 1;//初始化
		memset(used, 0, sizeof(used));
		bfs(g, p);
	}
}
/*
1
8 8
########
#......#
#.####.#
#.####.#
#.####.#
#.####.#
#...#..#
#S#E####

*/
/*
2
8 8
########
#......#
#.####.#
#.####.#
#.####.#
#.####.#
#...#..#
#S#E####
9 5
#########
#.#.#.#.#
S.......E
#.#.#.#.#
#########

*/