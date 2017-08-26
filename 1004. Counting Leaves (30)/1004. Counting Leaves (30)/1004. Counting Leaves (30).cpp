#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int m, n,num[100],maxd;
struct node
{
	int depth;
	vector<int> child;
}Node[100];
void BFS(int root) {
	queue<int> q;
	q.push(root);
	int nowd=1,temp=0;
	while (!q.empty())
	{
		int fr = q.front();
		q.pop();
		if (Node[fr].depth>nowd)
		{
			num[nowd] = temp;
			nowd = Node[fr].depth;
			temp = 0;
		}
		if (!Node[fr].child.empty())
		{
			for (int i = 0; i < Node[fr].child.size(); i++) {
				int child = Node[fr].child[i];
				Node[child].depth = Node[fr].depth + 1;
				q.push(child);
			}
		}
		else
		{
			temp++;
		}
	}
	num[nowd] = temp;
	maxd = nowd;
	return;
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		int nownode,k,temp;
		scanf("%d%d", &nownode,&k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &temp);
			Node[nownode].child.push_back(temp);
		}
	}
	Node[1].depth = 1;
	BFS(1);
	for (int i = 1; i <=maxd ; i++)
	{
		printf("%d", num[i]);
		if (i<maxd)
		{
			printf(" ");
		}
	}
	return 0;
}
