#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
const int maxn = 10001;
int n,cou;
bool isf[maxn] = { false };
int father[maxn];
void Union(int a, int b) {
	int fa = father[a];
	int fb = father[b];
	if (fa!=fb)
	{
		father[b] = fa;
	}
}
int findfather(int a) {
	if (father[a]==a)
	{
		return a;
	}
	int F = findfather(father[a]);
	father[a] = F;
	return F;
}
bool istree() {
	cou = 0;
	for (int i = 1; i <= n; i++)
	{
		int F = findfather(i);
		isf[F] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		if (isf[i])cou++;
	}
	if (cou!=1)
	{
		return false;
	}
	return true;
}
set<int> ans;
int depth = 0;
vector<int> adj[maxn];
bool vis[maxn] = { false };
void DFS(int s,int tempd,bool flag) {
	for (int i = 0; i < adj[s].size(); i++)
	{
		flag *= vis[adj[s][i]] ;
	}
	if (flag)
	{
		if (tempd>depth)
		{
			depth = tempd;
			ans.clear();
			ans.insert(s);
		}
		else if (tempd==depth)
		{
			ans.insert(s);
		}
		return;
	}
	for (int i = 0; i < adj[s].size(); i++)
	{
		int next = adj[s][i];
		if (vis[next])
		{
			continue;
		}
		vis[next] = true;
		DFS(next, tempd + 1,true);
		vis[next] = false;
	}
}
void init() {
	for (int i = 1; i <=n ; i++)
	{
		vis[i] = false;
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		father[i] = i;
	}
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		Union(a, b);
	}
	for (int i = 1; i <=n ; i++)
	{
		findfather(i);
	}
	if (istree())
	{
		/*for (int i = 1; i <= n; i++)
		{
			DFS(i,0,true);
			if (depth>maxd)
			{
				maxd = depth;
				ans.clear();
				ans.insert(i);
			}
			else if (depth==maxd)
			{
				ans.insert(i);
			}
			init();
		}*/
		vis[1] = true;
		DFS(1, 1, true);
		set<int> tmp=ans;
		init();
		DFS(*ans.begin(), 1, true);
		for (set<int>::iterator it = tmp.begin(); it !=tmp.end() ; it++)
		{
			ans.insert(*it);
		}
		int len = ans.size();
		for (set<int>::iterator it = ans.begin(); it != ans.end(); it++)
		{
			cout << *it;
			if (--len)
			{
				cout << endl;
			}
		}
	}
	else
	{
		cout << "Error: " << cou << " components"<<endl;
	}
}