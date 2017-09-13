#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = 10001;
int father[maxn];
bool isfather[maxn] = { false };
int n;
int findf(int a) {
	if (father[a]==a)
	{
		return a;
	}
	int F = findf(father[a]);
	father[a] = F;
	return F;
}
void Union(int a, int b) {
	int fa = findf(a);
	int fb = findf(b);
	if (fa != fb)
	{
		father[fa] = fb;
	}
}
int cou=0;
bool istree() {
	for (int i = 1; i <=n ; i++)
	{
		int F=findf(i);
		isfather[F] = true;
	}
	for (int i = 1; i <=n; i++)
	{
		if (isfather[i])cou++;
	}
	if (cou!=1)
	{
		return false;
	}
	return true;
}
int depth;
set<int> ans;
bool vis[maxn] = {false};
vector<int> adj[maxn];
void DFS(int s, int d, bool flag) {
	for (vector<int>::iterator it = adj[s].begin(); it !=adj[s].end() ; it++)
	{
		flag *= vis[*it];
	}
	if (flag||adj[s].size()==0)
	{
		if (d>depth)
		{
			depth = d;
			ans.clear();
			ans.insert(s);
		}
		else if (depth==d)
		{
			ans.insert(s);
		}
	}
	for (int i = 0; i < adj[s].size(); i++)
	{
		int next = adj[s][i];
		if (vis[next]==true)
		{
			continue;
		}
		vis[next] = true;
		DFS(next, d + 1, true);
		vis[next] = false;
	}
}
bool init() {
	for (int i = 1; i <= n; i++)
	{
		vis[i] = false;
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		Union(a, b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (istree())
	{
		vis[1] = true;
		DFS(1, 1, true);
		set<int> tmp = ans;
		init();
		vis[*ans.begin()] = true;
		DFS(*ans.begin(), 1, true);
		for (set<int>::iterator it = ans.begin(); it !=ans.end() ; it++)
		{
			tmp.insert(*it);
		}
		for (set<int>::iterator it = tmp.begin(); it !=tmp.end() ; it++)
		{
			cout << *it << endl;
		}
	}
	else
	{
		cout << "Error: " << cou << " components" << endl;
	}
	return 0;
}