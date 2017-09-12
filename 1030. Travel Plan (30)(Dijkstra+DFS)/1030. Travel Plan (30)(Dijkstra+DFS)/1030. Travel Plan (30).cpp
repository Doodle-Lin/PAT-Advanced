#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
	int v, dis;
	node(int _v,int _dis):v(_v),dis(_dis){}
};
const int maxn = 501;
const int INF = 0x3fffffff;
int n, m, s, t, d[maxn],mincost=INF;
int cost[maxn][maxn];
vector<node> adj[maxn];
vector<int> pre[maxn];
vector<int> path, temppath;
bool vis[maxn] = { false };
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
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
		if (u==-1)
		{
			return;
		}
		vis[u] = true;
		for (int j = 0; j < adj[u].size(); j++)
		{
			int v = adj[u][j].v;
			if (vis[v]==false)
			{
				if (d[u] + adj[u][j].dis<d[v])
				{
					d[v] = d[u] + adj[u][j].dis;
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u]+adj[u][j].dis==d[v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int v) {
	if (v==s)
	{
		temppath.push_back(v);
		int tempcost = 0;
		for (int i = temppath.size()-1; i > 0 ; i--)
		{
			int id = temppath[i];
			int idnext = temppath[i - 1];
			tempcost += cost[id][idnext];
		}
		if (tempcost<mincost)
		{
			path = temppath;
			mincost = tempcost;
		}
		temppath.pop_back();
		return;
	}
	temppath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
	{
		DFS(pre[v][i]);
	}
	temppath.pop_back();
}
int main() {
	fill(cost[0], cost[0] + maxn*maxn, INF);
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++)
	{
		int u, v, dis, c;
		scanf("%d%d%d%d", &u, &v, &dis, &c);
		adj[u].push_back(node(v, dis));
		adj[v].push_back(node(u, dis));
		cost[u][v] = c;
		cost[v][u] = c;
	}
	Dijkstra(s);
	DFS(t);
	for (int i = path.size()-1; i >=0 ; i--)
	{
		printf("%d ", path[i]);
	}
	printf("%d %d", d[t], mincost);
	return 0;
}