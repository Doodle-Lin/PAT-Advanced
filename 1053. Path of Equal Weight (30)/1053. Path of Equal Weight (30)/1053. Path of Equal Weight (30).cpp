#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, s;
struct node
{
	int data;
	vector<int> child;
}Node[101];
bool cmp(int a, int b) {
	return Node[a].data > Node[b].data;
}
vector<int> temp;
void DFS(int root, int nows) {
	if (root==-1)
	{
		if (nows==s)
		{
			for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
			{
				if (it==temp.end()-1)
				{
					printf("%d\n", *it);
				}
				else
				{
					printf("%d ", *it);
				}
			}
			return;//记得返回
		}
		else
		{
			return;
		}
	}
	if (nows>s)
	{
		return;
	}
	sort(Node[root].child.begin(), Node[root].child.end(), cmp);
	for (int i = 0; i < Node[root].child.size(); i++)
	{
		temp.push_back(Node[root].data);//记录当前结点权值
		DFS(Node[root].child[i], nows + Node[root].data);
		temp.pop_back();
	}
}
int main() {
	int nownode,k,leaf;
	scanf("%d%d%d", &m, &n, &s);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &Node[i].data);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &nownode,&k);
		for (int i = 0; i < k; i++)
		{
			scanf("%d", &leaf);
			Node[nownode].child.push_back(leaf);
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (Node[i].child.size()==0)
		{
			Node[i].child.push_back(-1);//将所有叶子节点的孩子设为-1
		}
	}
	DFS(0, 0);
	return 0;
}

