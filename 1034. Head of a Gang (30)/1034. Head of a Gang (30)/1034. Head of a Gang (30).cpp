#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int n,threthold;
const int maxn = 1001;
map<string, bool> vis ;
map<string, int> value;
map<string, vector<string> > adj;
vector<pair<string,int> > ans;
int total=0,maxv=0,num=0;
string head;
void DFS(string name) {
	vis[name] = true;
	total += value[name] / 2;
	num++;
	if (value[name]>maxv)
	{
		maxv = value[name];
		head = name;
	}
	for (int i = 0; i < adj[name].size(); i++)
	{
		string temp = adj[name][i];
		if (vis[temp]==false)
		{
			DFS(temp);
		}
	}
}
void DFSTrave() {
	for (map<string,bool>::iterator it = vis.begin(); it !=vis.end() ; it++)
	{
		if (it->second == false) {
			DFS(it->first);
			if (total>threthold&&num>2)
			{
				ans.push_back(make_pair(head,num));
			}
			total = 0;
			maxv = 0;
			num = 0;
		}
	}
}
void add(string a, int v) {
	if (value.find(a)!=value.end())
	{
		value[a] += v;
	}
	else
	{
		value[a] = v;
	}
}
int main() {
	cin >> n >> threthold;
	for (int i = 0; i < n; i++)
	{
		int value;
		string A, B;
		cin >> A >>B>>value;
		add(A, value);
		add(B, value);
		vis[A] = false;
		vis[B] = false;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	DFSTrave();
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
