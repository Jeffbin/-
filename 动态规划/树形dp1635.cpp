/*
 * 问题描述：给定两棵树，用一串0或1的序列表示，0表示生成一个子节点，1表示返回父节点。判断这样的两棵树是否同构。
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 892K Time:265 MS
 *
* 解题方法1：首先对于整棵树在开头加一个往下走的字符，在结尾加一个往上走的字符，用来处理边界问题，假设现在这颗树的根节点有若干个儿子，
	首先先把每个儿子都变成最小表示，每个最小表示都是一个01序列，那么当前根节点的最小表示
	就是所有儿子的最小表示按照字典序从小到大全部拼接在一起。
	因此对于每个非叶子节点，递归去求子节点的最小表示再按照字典序从小到大拼接起来。
	对于每个叶子节点，他的最小表示就是空字符串""。
 *
 * 解题方法2 （可选）
 *
 * 出错次数：5
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：见到树状的就要想到树形dp，dfs，树形dp一般是回溯时做出状态改变
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;



//seq 表示dfs序列
//u 表示dfs序列的指针
string dfs(string& seq, int& u)
{
	vector<string> seqs; //存储所有儿子节点的最小表示
	u++; //跳过当前走下来的字符
	while (seq[u] == '0') seqs.push_back(dfs(seq, u)); //只要指针指向的字符是0，往下递归
	u++; //跳过走上来的字符

	sort(seqs.begin(), seqs.end()); //将所有儿子节点的最小表示按照字典序排序
	string res = "0"; //记录当前节点为根节点的子树的最小表示，最开始有一个0表示从上面走下来
	for (int i = 0; i < seqs.size(); i++) res += seqs[i]; //将所有儿子节点的最小表示按照字典序从小到大拼接
	res += '1'; //再结尾拼接一个回去的字符
	return res; //将拼接的最小表示返回
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string a, b;
		cin >> a >> b;
		//对于整棵树在开头加一个往下走的字符，在结尾加一个往上走的字符，用来处理边界问题
		a = '0' + a + '1', b = '0' + b + '1';
		int ua = 0, ub = 0; //表示两个dfs序列的指针
		if (dfs(a, ua) == dfs(b, ub)) puts("same"); //如果两个dfs序列的树的最小表示相同，说明是同构的
		else puts("different"); //否则说明不是同构的
	}

	return 0;
}
