/*
 * �����������������ַ��������ͳ��ȣ������ַ�������������ַ����б��ӡ�������ࡱ�����������١����������ٵ�Ϊ�����
 *
 * �ύ״̬�� AC 
 *
 * AC ����� Memory: 184K Time: 47MS
 *
 * ���ⷽ��1������һ���ṹ�����飬�����и��ַ�ָ���������ַ�������nun���洢��������������
 * �������ַ�������sort���������ǵ��ַ�������������С��������ð������ѽṹ��������ַ����������
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������1
 *
 * ����ԭ�� ����ѡ������strcmy�����ַ��������³���
 *
 * �ĵ���� ����ѡ�����������ַ�ָ�����洢�ַ�������sort�����б�����
 */



#include <iostream>
#include <algorithm>
using namespace std;
struct sortedDNA
{
	int num;
	char *line;//ָ�룬a[i]��ֵ��ֵ������
}a[101];

int bubble_sort(char a[], int n);
bool cmp(sortedDNA a, sortedDNA b);

int main() 
{
	int n, m, i, j;//nΪ���ȣ�mΪ����
	char DNA[101][52];
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> DNA[i];
		a[i].line = DNA[i];//�ַ�ָ��Ҳ����ָ��һ���ַ�������ʱ���ַ�ָ��ָ��һ���ַ����������׵�ַ��
		a[i].num = bubble_sort(DNA[i], n);//����������
	}
	sort(a, a + m, cmp);//��m��a[]���num����
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i].line[j];//���
		}
		cout << "\n";

	}
	return 0;
}
bool cmp(sortedDNA a, sortedDNA b)
{
	return a.num < b.num;

}
int bubble_sort(char a[], int n)
{
	int i, j, num = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				num++;
			}
		}
	}
	return num;
}
/*
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
*/