/*
 * ��������������������X��N���������ƶ��������ֱ�Ϊx+1,x-1,x*2��ÿ���ƶ�����1���ӣ����������ƶ�����ʹX�㵽N��Ļ�������
 * �ύ״̬��  AC
 *
 * AC ����� MEMORY: TIME:
 *
 * ���ⷽ��1������һ����Ľṹ�壬����������ͻ���ʱ�䣬�������ӣ��ٷֱ���������ƶ���ӣ��ٰ�����չ��ĵ�һ������ӣ�ֱ������Ϊ�ջ���X����N��
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
#include <queue>
using namespace std;

int flag = 0;
int au[] = {1,-1,0};
struct point
{
	int x;
	int minute;
};
queue<point> r;

void BFS(int manstartx,int cowstartx)
{
	point start;
	start.x = manstartx;
	start.minute = 0;
	r.push(start);//������
	while (!r.empty())
	{
		int x = r.front().x;
		if (x == cowstartx)
		{
			flag = 1;
			cout << r.front().minute<<endl;
			return;
		}
		for (int i = 0; i < 3; i++)
		{
			int tx;
			tx = x + au[i];
			if (i == 2)
			{
				tx = tx * 2;
			}
			if (x < 0)
			{
				continue;
			}
			point temp;
			temp.x = tx;
			temp.minute = r.front().minute + 1;
			r.push(temp);
		}
		r.pop();//���׳���;
	}

}


int main()
{
	int N, K;
	cin >> N>> K;
	BFS(N, K);
}
