#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
struct node
{
	string v;
	int cost;
	node(string _v,int _cost):v(_v),cost(_cost){}
};
const int maxn = 201;
const int INF = 0x3fffffff;
int n, m;
map<string, int> c;
map<string, vector<node> > adj;
map<string, vector<string> > pre;
map < string, bool > vis;
void Dijkstra(string start) {
	/*for ( map<string,int>::iterator it = c.begin(); it !=c.end() ; it++)
	{
		vis[it->first] = false;
		it->second = INF;
	}*/
	//并未初始化无法赋值
	//c[start] = 0;
	for (int i = 0; i < n; i++)
	{
		string u = "***";
		int minc = INF;
		for (map<string,int>::iterator it=c.begin(); it != c.end(); it++)
		{
			string next = it->first;
			int co = it->second;
			if (co<minc&&vis[next]==false)
			{
				u = next;
				minc = co;
			}
		}
		if (u=="***")
		{
			return;
		}
		vis[u] = true;
		for (int j = 0; j < adj[u].size(); j++)
		{
			string v = adj[u][j].v;
			if (!vis[v]) {
				if (c[u]+adj[u][j].cost<c[v])
				{
					c[v] = c[u] + adj[u][j].cost;
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (c[u]+adj[u][j].cost==c[v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}
map<string, int> hap;
vector<string> tmp, ans;
string s, t="ROM";
int totalhap = 0, avg = 0;
int cou = 0;
void DFS(string t,int num) {
	if (t==s)
	{
		cou++;
		int tmphap=0;
		tmp.push_back(s);
		for (int i = tmp.size()-1; i >= 0; i--)
		{
			tmphap += hap[tmp[i]];
		}
		if (tmphap>totalhap)
		{
			totalhap = tmphap;
			avg = totalhap / num;
			ans = tmp;
		}
		tmp.pop_back();
		return;
	}
	tmp.push_back(t);
	for  (vector<string>::iterator it=pre[t].begin();  it!= pre[t].end(); it++)
	{
		string p = *it;
		DFS(p, num + 1);
	}
	tmp.pop_back();
}
int main(){
	cin >> n >> m >> s;
	hap[s] = 0;
	c[s] = 0;
	vis[s] = false;
	for (int i = 0; i < n-1; i++)
	{
		string city;
		int tmp;
		cin >> city >> tmp;
		hap[city] = tmp;
		c[city] = INF;
		vis[city] = false;
	}
	for (int i = 0; i < m; i++)
	{
		string u, v;
		int co;
		cin >> u >> v >> co;
		adj[u].push_back(node(v, co));
		adj[v].push_back(node(u, co));
	}
	Dijkstra(s);
	DFS(t,0);
	cout << cou <<" "<<c[t] << " " << totalhap << " " << avg << endl;
	for (int i = ans.size()-1; i >=0 ; i--)
	{
		cout << ans[i];
		if (i>0)
		{
			cout << "->";
		}
	}
	return 0;
}