/*
 * ������������һ����ά�Թ����ҵ����ڣ�SΪ��㣬EΪ�յ㣬#Ϊǽ��.Ϊ�յ�
 * �ύ״̬��  AC
 *
 * AC ����� MEMORY:316K	 TIME:47MS
 *
 * ���ⷽ��1����һ����ά����洢��ά���飬a*b��ʾ�����X������c��ʾ���������Y�������������һ�����飬������ x+b����������һ������
 * ������ x-b��Ȼ�����ÿһ���߷����������������û���߹��ĵ����ӣ�ֱ�������յ���ߺ�������
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������1
 *
 * ����ԭ�� ����ѡ����ʹ�ö�ά�������ʱ�д��󣬻ᵼ��������һά���鵼�´���
 *
 * �ĵ���� ����ѡ����������Ŀ���˼�ά�ü�ά
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