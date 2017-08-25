#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;
int m;
const int maxn = 100001;
double price, r;
struct node
{
	int height;
	int amount;
	vector<int> child;
}Node[maxn];
double total=0;
void DFS(int root) {
	if (Node[root].child.size()==0)
	{
		total += price*pow(1 + r/100, Node[root].height - 1)*Node[root].amount;
		return;
	}
	for (int i = 0; i < Node[root].child.size(); i++)
	{
		int child = Node[root].child[i];
		Node[child].height = Node[root].height + 1;
		DFS(child);
	}
}
void BFS(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (Node[t].child.empty())
		{
			total+= price*pow(1 + r/100, Node[t].height - 1)*Node[t].amount;
		}
		else
		{
			for (int i = 0; i < Node[t].child.size(); i++)
			{
				int child = Node[t].child[i];
				q.push(child);
				int nowh = Node[t].height;
				Node[child].height = nowh+1;
			}
		}
	}
}
int main() {
	int temp,leaf;
	scanf("%d%lf%lf", &m, &price, &r);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		if (temp!=0)
		{
			for (int j = 0; j < temp; j++) {
				scanf("%d", &leaf);
				Node[i].child.push_back(leaf);
			}
		}
		else
		{
			scanf("%d", &Node[i].amount);
		}
	}
	Node[0].height = 1;
	DFS(0);
	printf("%.1lf", total);
	return 0;
}
