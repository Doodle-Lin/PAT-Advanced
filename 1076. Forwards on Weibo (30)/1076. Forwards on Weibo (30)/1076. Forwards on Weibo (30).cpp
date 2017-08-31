#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1010;
struct node
{
	int level;
	vector<int> fo;
}Node[maxn];
bool inq[maxn] = {false};
int n, maxlevel;
void BFS(int user) {
	queue<int> q;
	q.push(user);
	int num = 0;
	inq[user] = true;
	Node[user].level = 0;
	while (!q.empty())
	{
		int fr = q.front();
		q.pop();
		for (int i = 0; i < Node[fr].fo.size(); i++)
		{
			int fo = Node[fr].fo[i];
			if (inq[fo]==false)//先进行判断，以防多次入队或者多次增加层次
			{
				Node[fo].level = Node[fr].level + 1;
				if (Node[fo].level <= maxlevel)
				{
					inq[fo] = true;
					q.push(fo);
					num++;
				}
			}
		}
	}
	printf("%d\n", num);
}
void init() {
	for (int i = 1; i <=n ; i++)
	{
		inq[i] = false;
		Node[i].level = 0;
	}
}
int main() {
	scanf("%d%d", &n, &maxlevel);
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		while (k--)
		{
			int temp;
			scanf("%d", &temp);
			Node[temp].fo.push_back(i);
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int temp;
		scanf("%d", &temp);
		init();
		BFS(temp);
	}
	return 0;
}