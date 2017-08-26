#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
struct node
{
	int height;
	vector<int> child;
}Node[100010];
int m;
double price, r;
int minh=100010, num=0;
void BFS(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int fr = q.front();
		q.pop();
		if (Node[fr].height>minh)
		{
			break;
		}
		if (Node[fr].child.empty())
		{
			minh = Node[fr].height;
			num++;
		}
		else
		{
			if (Node[fr].height==minh)
			{
				continue;
			}
			for (int i = 0; i < Node[fr].child.size(); i++)
			{
				int child = Node[fr].child[i];
				Node[child].height = Node[fr].height + 1;
				q.push(child);
			}
		}
	}
}
int main() {
	scanf("%d%lf%lf", &m, &price, &r);
	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			int temp;
			scanf("%d", &temp);
			Node[i].child.push_back(temp);
		}
	}
	Node[0].height = 1;
	BFS(0);
	printf("%.4lf %d", price*pow(1 + r / 100, minh - 1), num);
	return 0;
}