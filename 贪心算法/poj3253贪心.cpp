/*
* ��������������n��С��ľ�������㽫��ƴ��Ϊһ��ľ����ÿ��ƴ��ʹ�õĻ���Ϊ��
������ľ��a����Ϊaa��ľ��b����Ϊbb��aa+bb���ʽ���Щ��ľ�����������Ҫ����С���ѡ�
 *
* �ύ״̬�� AC
 *
* ��������� �ڴ棺 37.6K ʱ�䣺 79MS
 *
* ���ⷽ��1�������ȵ�����СԪ�ص����ȶ�����ƴ����С������ľ�壬ֱ�����ֻʣ��һ��ľ��ʱֹͣ
 *
* ���ⷽ��2 ����ѡ�����������ľ�峤�����������и�����ľ�壬ֱ��ľ������������Ҫ������ʱֹͣ
 *
* ���������0
 *
* ����ԭ�� ����ѡ����
 *
* �ĵ���� ����ѡ����������Ԫ�ش���10000ʱ������Ӧ���ó����ͱ������洢
 */


#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    int temp;
    while (cin >> N)
    {

        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            q.push(temp);
        }
        long long  sum = 0;

        if (q.size() == 1)
        {
            int a = q.top();
            sum += a;
            q.pop();
        }
        for (int i = 0; i < N - 1; i++)
        {

            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            int t = a + b;
            sum += t;
            q.push(t);
        }


        cout << sum << endl;
    }


    return 0;
}

