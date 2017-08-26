#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int m;
double price, r;
const int maxn = 100001;
struct node
{
	int height;
	vector<int> child;
}Node[maxn];
void BFS(int root) {
	queue<int> q;
	int num = 0,maxh=0;
	q.push(root);
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		if (Node[top].child.empty()&&Node[top].height>maxh)
		{
			num = 1;
			maxh = Node[top].height;
		}
		else if (Node[top].child.empty()&&Node[top].height==maxh)
		{
			num++;
		}
		else
		{
			int child;
			for (int i = 0; i < Node[top].child.size(); i++)
			{
				child = Node[top].child[i];
				q.push(child);
				Node[child].height = Node[top].height + 1;
			}
		}
	}
	printf("%.2lf %d", price*pow(1 + r / 100, maxh - 1), num);
}
int main() {
	int temp,root;
	scanf("%d%lf%lf", &m, &price, &r);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		if (temp!=-1)
		{
			Node[temp].child.push_back(i);
		}
		else
		{
			root = i;
		}
	}
	Node[root].height = 1;
	BFS(root);
	return 0;
}