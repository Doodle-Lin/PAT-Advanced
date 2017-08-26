#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
struct node
{
	int level;
	vector<int> child;
}Node[100];
int m, n;
int num= 0,nowlevel=0,maxlevel;
int population[100];
void BFS(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		if (Node[front].level>nowlevel)
		{
			nowlevel = Node[front].level;
			population[nowlevel - 1] = num;
			num = 1;
		}
		else if (Node[front].level==nowlevel)
		{
			num++;
		}
		if (!Node[front].child.empty())
		{
			for (vector<int>::iterator it = Node[front].child.begin(); it != Node[front].child.end(); it++) {
				int child = *it;
				Node[child].level = Node[front].level + 1;
				q.push(child);
			}
		}
	}
	population[nowlevel] = num;
	maxlevel = nowlevel;
	return;
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		int nownode, k,child;
		scanf("%d%d", &nownode, &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			Node[nownode].child.push_back(child);
		}
	}
	Node[1].level = 1;
	BFS(1);
	int maxp = 0,res;
	for (int i = 1; i <= maxlevel; i++)
	{
		if (population[i]>maxp)
		{
			maxp = population[i];
			res = i;
		}
	}
	printf("%d %d", maxp, res);
	return 0;
}