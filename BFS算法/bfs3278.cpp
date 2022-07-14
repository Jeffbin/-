/*
 * 问题描述：给出两个点X，N，和三种移动方法，分别为x+1,x-1,x*2，每次移动花费1分钟，用这三种移动方法使X点到N点的花费最少
 * 提交状态：  AC
 *
 * AC 结果： MEMORY: TIME:
 *
 * 解题方法1：设立一个点的结构体，里面有坐标和花费时间，将起点入队，再分别把其他点移动入队，再把已扩展完的第一个点出队，直到队列为空或者X到达N点
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
	r.push(start);//起点入队
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
		r.pop();//队首出列;
	}

}


int main()
{
	int N, K;
	cin >> N>> K;
	BFS(N, K);
}
