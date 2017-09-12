#include <cstdio>
#include <vector>
#include <set>
using namespace std;
struct node
{
	int v, dis;
	node(int _v,int _dis):v(_v),dis(_dis){}
};
const int INF = 0x3fffffff;
const int maxn = 501;
int n,m,s,t;
int d[maxn];
int weight[maxn];
vector<int> temppath;
set<int> pre[maxn];
vector<node> adj[maxn];
bool Bellman(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int u = 0; u < n; u++)
		{
			for (int j = 0; j < adj[u].size(); j++)
			{
				int v = adj[u][j].v;
				int dis = adj[u][j].dis;
				if (d[u]+dis<d[v])
				{
					d[v] = d[u] + dis;
					pre[v].clear();
					pre[v].insert(u);
				}
				else if (d[u]+dis==d[v])
				{
					pre[v].insert(u);
				}
			}
		}
	}
	for (int u = 0; u < n; u++)
	{
		for (int j = 0; j < adj[u].size(); j++)
		{
			int v = adj[u][j].v;
			int dis = adj[u][j].dis;
			if (d[u] + dis < d[v]) return false;
		}
	}
	return true;
}
int maxw = 0,cou=0;
void DFS(int now) {
	if (now==s)
	{
		temppath.push_back(now);
		int nowweight = 0;
		for (int i = temppath.size()-1; i >=0 ; i--)
		{
			int v = temppath[i];
			nowweight += weight[v];
		}
		if (nowweight>maxw)
		{
			maxw = nowweight;
		}
		cou++;
		temppath.pop_back();
		return;
	}
	temppath.push_back(now);
	for (set<int>::iterator it = pre[now].begin(); it !=pre[now].end() ; it++)
	{
		DFS(*it);
	}
	temppath.pop_back();
}
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int u, v, dis;
		scanf("%d%d%d", &u, &v, &dis);
		adj[u].push_back(node(v, dis));
		adj[v].push_back(node(u, dis));
	}
	if (Bellman(s))
	{
		DFS(t);
	}
	printf("%d %d", cou, maxw);
	return 0;
}