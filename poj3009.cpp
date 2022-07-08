/*
 * ��������������ֻ������һ������ǰ��(�Խ��߲���)������ֻ��ײǽ����ͣ������ͣ������ǽ�ͱ�������(��Ϊ���ߵ�·)��
 ���ڵ�ǰ��λ�Ա������block���ܷ�����������㵽�յ���̵Ļ��������Ҫ����10���������
 * �ύ״̬��  AC
 *
 * AC ����� MEMORY:256K TIME:172MS->157MS(��֦��)
 *
 * ���ⷽ��1������㿪ʼdfs���ĸ����򶼱���һ�Σ�ûײǽ��һֱ���Ǹ������ߣ���������յ㣬
 ��������������������أ���֦����û�еĻ��ͶԱ�best�����͵�ǰstep��С��ѡ��С��Ȼ�󷵻�
 �����ײǽ�Ͱ�ǽ��Ϊ�յأ�step++���ݹ�dfs�������������������������ǰ����
 *				
				
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������0
 *
 * ����ԭ�� ����ѡ����
					
 *
 * �ĵ���� ����ѡ����
 */

#include <iostream>
using namespace std;
int map[100][100];
int dir[][2] = { {0,-1},{-1,0},{0,1},{1,0} };//��������

int best=10000;
int w, h;//����
int gx, gy;//�������

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
		if (dx < 0 || dy < 0 || dx >= h || dy >= w)//����
		{
			continue;
		}
		if (map[dx][dy] == 0 || map[dx][dy] == 2 || map[dx][dy] == 3)
		{
			while (dx<h&&dx >= 0 &&dy>=0&& dy < w && map[dx][dy] != 1)
			{
				
				if (map[dx][dy] == 3)//�����յ�
				{
					if (step > best)
						return;
					best = min(best, step + 1);
					break;
				}
				dx = dx + dir[o][0];
				dy = dy + dir[o][1];
				if (map[dx][dy] == 1)//ײǽ
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