#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct  node
{
	int v;
	double	dis;
	node(int _v,double _dis):v(_v),dis(_dis){}
};
const double INF = 0x3fffffff;
const int maxn = 1011;
vector<node> adj[maxn];
bool vis[maxn] = { false };
int n,m;
double d[maxn];
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
	for (int i = 1; i <= n+m; i++)
	{
		int u = -1;
		double min = INF;
		for (int j = 1; j <= n+m; j++)
		{
			if (vis[j]==false&&d[j]<min)
			{
				min = d[j];
				u = j;
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
			double dis = adj[u][j].dis;
			if (vis[v] == false&&d[u]+dis<d[v])
			{
				d[v] = d[u] + dis;
			}
		}
	}
}
int D;
double avg[maxn];
double findmin(int g) {
	double total = 0;
	double min = INF;
	for (int i = 1; i <= n; i++)
	{
		if (d[i]>D)
		{
			return -1;
		}
		total += d[i];
		if (d[i]<min)
		{
			min = d[i];
		}
	}
	avg[g] = total / n;
	return min;
}
int strtoint(string &str) {
	int index=0;
	if (*str.begin()=='G')
	{
		str.erase(str.begin());
		index = n + strtoint(str);
	}
	else
	{
		while (str.length()>0)
		{
			index = index * 10 + *str.begin() - '0';
			str.erase(str.begin());
		}
	}
	return index;
}
void init() {
	for (int i = 1; i < n+m+1; i++)
	{
		vis[i] = false;
	}
}
int main() {
	int k;
	cin >> n >> m >> k >> D;
	for (int i = 0; i < k; i++)
	{
		string a, b;
		int index1, index2;
		double dis;
		cin >> a >> b >> dis;
		index1 = strtoint(a);
		index2 = strtoint(b);
		adj[index1].push_back(node(index2, dis));
		adj[index2].push_back(node(index1, dis));
	}
	int ans=-1;
	double min = -1;
	for (int i = n+1; i < n+m+1; i++)
	{
		Dijkstra(i);
		double temp = findmin(i);
		if (temp!=-1)
		{
			if (temp>min)
			{
				min = temp;
				ans = i;
			}
			else if (temp==min)
			{
				if (avg[i] < avg[ans])ans = i;
			}
		}
		init();
	}
	if (ans==-1)
	{
		cout << "No Solution\n";
	}
	else
	{
		printf("G%d\n", ans - n);
		printf("%.1lf %.1lf", min, avg[ans]);
	}
	return 0;
}