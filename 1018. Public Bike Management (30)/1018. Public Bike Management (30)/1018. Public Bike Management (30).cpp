#include <vector>
#include <iostream>
using namespace std;
struct node
{
	int v;
	int dis;
	node(int _v,int _dis):v(_v),dis(_dis){}
};
const int maxn = 501;
const int INF = 0x3fffffff;
int n, c, m, t;
vector<node> adj[maxn];
int bikes[maxn];
int d[maxn];
vector<int> pre[maxn];
bool vis[maxn] = { false };
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1;
		int min = INF;
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
			int dis = adj[u][j].dis;
			if (vis[v]==false)
			{
				if(d[u]+dis<d[v]){
					d[v] = d[u] + dis;
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u]+dis==d[v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}
vector<int> ans, tmp;
int minc=INF,mins=INF;
void DFS(int t) {
	if (t==0)
	{
		tmp.push_back(0);
		int collect = 0,send=0;
		for (int i =tmp.size()-2; i >= 0; i--)
		{
			if (collect+bikes[tmp[i]]-c/2>0)
			{
				collect=collect+bikes[tmp[i]]-c/2;
			}
			else
			{
				send += c / 2 - collect - bikes[tmp[i]];
				collect = 0;
			}
		}
		/*if (collect<minc)
		{
			minc = collect;
			ans = tmp;
			mins = send;
		}
		else if (collect==minc&&send<mins)
		{
			ans = tmp;
			minc = collect;
			mins = send;
		}*/
		if (send<mins)//优先级依次为路径最短，发送数目最小，回收数目最小
		{
			ans = tmp;
			minc = collect;
			mins = send;
		}
		else if (send==mins&&collect<minc)
		{
			ans = tmp;
			minc = collect;
			mins = send;
		}
		tmp.pop_back();
		return;
	}
	tmp.push_back(t);
	for (int i = 0; i < pre[t].size(); i++)
	{
		int p = pre[t][i];
		DFS(p);
	}
	tmp.pop_back();
}
int main() {
	cin >> c >> n >> t >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> bikes[i];
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, dis;
		cin >> a >> b >> dis;
		adj[a].push_back(node(b, dis));
		adj[b].push_back(node(a, dis));
	}
	Dijkstra(0);
	DFS(t);
	cout << mins<< " ";
	for (int i = ans.size()-1; i >= 0; i--)
	{
		cout << ans[i];
		if (i!=0)
		{
			cout << "->";
		}
	}
	cout << " " << minc;
	return 0;
}