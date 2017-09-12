#include <cstdio>
#include <vector>
#define INF 0x3fffffff
using namespace std;
const int maxn = 501;
struct  node
{
	int v, dis;
	node(int _v,int _dis):v (_v),dis(_dis){}
};
vector<node> adj[maxn];
int n;
int d[maxn];
int weight[maxn];
int w[maxn];
int num[maxn];
bool vis[maxn] = { false };
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for (int i = 0; i < n; i++)
	{
		int u = -1, min = INF;
		for (int j = 0; j < n; j++)
		{
			if (d[j]<min&&vis[j]==false)
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
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}
				else if (d[u]+adj[u][j].dis==d[v])
				{
					num[v] += num[u];//只要长度最小，累加的是中间结点的路径数目而不是+1
					if (w[u] + weight[v]>w[v]){
						w[v] = w[u] + weight[v];//更新最大资源数
					}
				}
			}
		}
	}
}
int main() {
	int m, s, t;
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
	Dijkstra(s);
	printf("%d %d", num[t], w[t]);
	return 0;
}
