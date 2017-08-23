#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 11;
struct node {
	int lchild, rchild;
}Node[maxn];
int n;
bool notRoot[maxn] = { false };
int num = 0;
void level(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		printf("%d", now);
		num++;
		if (num != n)
		{
			printf(" ");
		}
		if (Node[now].lchild!=-1)
		{
			q.push(Node[now].lchild);
		}
		if (Node[now].rchild!=-1)
		{
			q.push(Node[now].rchild);
		}
	}
}
int num2 = 0;
void inOrder(int root) {
	if (root==-1)
	{
		return;
	}
	inOrder(Node[root].lchild);
	printf("%d", root);
	num2++;
	if (num2!=n)
	{
		printf(" ");
	}
	inOrder
	(Node[root].rchild);
}
void postOrder(int root) {
	if (root==-1)
	{
		return;
	}
	postOrder(Node[root].lchild);
	postOrder(Node[root].rchild);
	swap(Node[root].lchild, Node[root].rchild);
}
int charToInt(char a) {
	if (a=='-')
	{
		return -1;
	}
	else
	{
		notRoot[a - '0'] = true;
		return a - '0';
	}
}
int main() {
	char ltemp, rtemp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%*c%c %c", &ltemp, &rtemp);
		Node[i].lchild = charToInt(ltemp);
		Node[i].rchild = charToInt(rtemp);
	}
	int k;
	for (k = 0; k < n; k++)
	{
		if (notRoot[k]==false)
		{
			break;
		}
	}
	postOrder(k);
	level(k);
	printf("\n");
	inOrder(k);
	return 0;
}