#include <map>
#include <cstdio>
#include <functional>

using namespace std;
map<int, double,greater<int> >  mp;
int main() {
	int n,ex;
	double co;
	for (int i = 0; i < 2; i++)
	{
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d %lf", &ex, &co);
			mp[ex] += co;
		}
	}
	for (map<int,double,greater<int> >::iterator it = mp.begin(); it!=mp.end(); it++)
	{
		if (it->second==0)
		{
			mp.erase(it->first);
		}
	}
	printf("%d", mp.size());
	for (map<int, double, greater<int> >::iterator it = mp.begin(); it != mp.end(); it++)
	{
			printf(" %d %.1lf", it->first, it->second);
	}
	return 0;
}