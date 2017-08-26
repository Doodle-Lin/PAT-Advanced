#include <cstdio>
#include <set>
#include <queue>
using namespace std;
const int maxn = 101;
struct node
{
	int data;
	int lchild;
	int rchild;
}Node[maxn];
set<int> s;
set<int>::iterator it;
void inorder(int root) {
	if (root==-1)
	{
		return;
	}
	inorder(Node[root].lchild);
	Node[root].data = *it;
	it++;
	inorder(Node[root].rchild);
}
int num=0,m;
void level(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int fr = q.front();
		q.pop();
		num++;
		printf("%d", Node[fr].data);
		if (num<m)
		{
			printf(" ");
		}
		if (Node[fr].lchild!=-1)
		{
			q.push(Node[fr].lchild);
		}
		if (Node[fr].rchild!=-1)
		{
			q.push(Node[fr].rchild);
		}
	}
}
int main() {
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int lc, rc;
		scanf("%d%d", &lc, &rc);
		Node[i].lchild = lc;
		Node[i].rchild = rc;
	}
	for (int i = 0; i < m; i++)
	{
		int temp;
		scanf("%d", &temp);
		s.insert(temp);
	}
	it = s.begin();
	inorder(0);
	level(0);
	return 0;
}