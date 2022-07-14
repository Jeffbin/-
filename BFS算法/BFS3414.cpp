/*
* ����������

���õ����������ֱ����A��B�������������ִ�����²�����

FILL��i�� ��ˮ��ͷ���� i ��1 �� i �� 2��;
DROP��i�� ���� i �������ˮ��;
POUR��i��j�� �ӹ� i ������ j;�ڴ˲���֮��Ҫô��j���������ҹ�i�п��ܻ�ʣ��һЩˮ����Ҫô��i�ǿյģ����������������ﶼ��������j����
��дһ���������ҵ���Щ������������У���Щ������������һ�����в���ǡ��C����ˮ��



* �ύ״̬�� AC
 *
* ��������� �ڴ棺 ʱ�䣺
 *
* ���ⷽ��1����һ���ṹ�壬������aͰ�ĵ�ǰˮ����AL��bͰ��ǰˮ����BL�����ã��������飬Ȼ�����㿪ʼFILL��A����FILL��B����DROP��A����DROP��B����pour(a,b)
* pour(b,a)ÿ�����������һ�飬��ӣ�ֱ������������������� IMPOSSIBEL��
* ��֦��ˮ�ղ��õ�ˮ��ˮ������װˮ��ˮ�ղ��ð�ˮ������һ��Ͱ���Ѿ��������ĵ㲻���ظ�������
 *
* ���ⷽ��2 ����ѡ����
 *
* ���������1
 *
* ����ԭ�� ����ѡ�������ڴ棬û�м�֦�����ظ�����ͬһ���㣬���е���������һ��
 *
* �ĵ���� ����ѡ����ѡ������ַ���ʱ����һ����ά�ַ����飬���Ը���һ������������ѡ������Ƕ��ַ���
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
		//ע��A
			
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
			//ע��b
			
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
			//����a
			
				//point temp;
				temp = r.front();
				if (temp.AL != 0)//��֦
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
			
				
				
				//����b
				temp = r.front();
				if (temp.BL != 0)//��֦
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


			
				//��a����b
				temp = r.front();
				if (temp.AL != 0)//��֦
				{
					if (temp.BL < x)//û����
					{
						temp.BL = temp.BL + temp.AL;
						temp.AL = 0;
						if (temp.BL > x)//������
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
			
				//��b����a
				temp = r.front();
				if (temp.BL != 0)//��֦
				{
					if (temp.AL < z)//û����
					{
						temp.AL = temp.AL + temp.BL;
						temp.BL = 0;
						if (temp.AL > z)//������
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
ʾ������

3 5 4
ʾ�����

6
FILL(2)
POUR(2,1)
DROP(1)
POUR(2,1)
FILL(2)
POUR(2,1)

*/