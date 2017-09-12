#include <cstdio>
#include <vector>
using namespace std;
#define INF 0x3fffffff
const int maxn = 501;
struct node
{
	int v, dis, cost;
	node(int _v, int _dis, int _cost) :v(_v), dis(_dis), cost(_cost) {}
};
vector<node> adj[maxn];
int n;
int d[maxn];
int pre[maxn];
int c[maxn];
bool vis[maxn];
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
	c[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1, min = INF;
		for (int j = 0; j < n; j++)
		{
			if (vis[j]==false&&d[j]<min)
			{
				u = j;
				min = d[j];
			}
		}
		if (u == -1)
		{
			return;
		}
		vis[u] = true;
		for (int j = 0; j < adj[u].size(); j++)
		{
			int v = adj[u][j].v;
			if (vis[v] == false)
			{
				if (d[u] + adj[u][j].dis<d[v])
				{
					d[v] = d[u] + adj[u][j].dis;
					c[v] = c[u] + adj[u][j].cost;
					pre[v] = u;
				}
				else if (d[u] + adj[u][j].dis == d[v] && c[u] + adj[u][j].cost<c[v])
				{
					c[v] = c[u] + adj[u][j].cost;
					pre[v] = u;
				}
			}
		}
	}
}
void DFS(int t) {
	if (pre[t] == t)
	{
		printf("%d ", t);
		return;
	}
	DFS(pre[t]);
	printf("%d ", t);
}
int main() {
	int m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < n; i++)
	{
		pre[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int u, v, dis, cost;
		scanf("%d%d%d%d", &u, &v, &dis, &cost);
		adj[u].push_back(node(v, dis, cost));
		adj[v].push_back(node(u, dis, cost));
	}
	Dijkstra(s);
	DFS(t);
	printf("%d %d", d[t], c[t]);
	return 0;
}