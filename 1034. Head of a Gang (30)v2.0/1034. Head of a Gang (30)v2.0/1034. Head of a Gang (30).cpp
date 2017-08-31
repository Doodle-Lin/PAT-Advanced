#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct node
{
	bool vis=false;
	int value;
	vector<string> adj;
};
map<string, node> mp;
vector<pair<string,int> > ans;
int num = 0, total = 0, maxv = 0,n,threthold;
string head;
void DFS(string name) {
	mp[name].vis = true;
	num++;
	total += mp[name].value/2;
	if (mp[name].value>maxv)
	{
		maxv = mp[name].value;
		head = name;
	}
	for (int i = 0; i < mp[name].adj.size(); i++)
	{
		string temp = mp[name].adj[i];
		if (mp[temp].vis==false)
		{
			DFS(temp);
		}
	}
}
void DFSTrade() {
	for (map<string,node>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		if (it->second.vis == false) {
			DFS(it->first);
			if (num>2&&total>threthold)
			{
				ans.push_back(make_pair(head,num));
			}
			num = 0;
			maxv = 0;
			total = 0;
		}
	}
}
void addvalue(string a,int v) {
	if (mp.find(a)!=mp.end())
	{
		mp[a].value += v;
	}
	else
	{
		mp[a].value = v;
	}
}
int main() {
	cin >> n >> threthold;
	for (int i = 0; i < n; i++)
	{
		string A, B;
		int temp;
		cin >> A >> B >> temp;
		mp[A].adj.push_back(B);
		mp[B].adj.push_back(A);
		addvalue(A, temp);
		addvalue(B, temp);
	}
	DFSTrade();
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}