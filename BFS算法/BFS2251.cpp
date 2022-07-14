/*
 * ������������һ����ά�Թ����ҵ����ڣ�SΪ��㣬EΪ�յ㣬#Ϊǽ��.Ϊ�յ�
 * �ύ״̬��  AC
 *
 * AC ����� MEMORY:	 TIME:
 *
 * ���ⷽ��1����һ����ά����洢��ά���飬a*b��ʾ�����X������c��ʾ���������Y�������������һ�����飬������ x+b����������һ������
 * ������ x-b��Ȼ�����ÿһ���߷����������������û���߹��ĵ����ӣ�ֱ�������յ���ߺ�������
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������0
 *
 * ����ԭ�� ����ѡ����
 *
 * �ĵ���� ����ѡ������ά�Ķ��������ö�ά�������洢
 */
#include <iostream>
#include <queue>
using namespace std;
char map[1000][1000];
int luxian[][2] = { {1,0}, {0,-1} ,{-1,0}, {0,1}, {0,0},{0,0} };//�ϣ��������������ϣ���
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
ʾ������

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
ʾ�����

Escaped in 11 minute(s).
Trapped!
*/