#include <map>
#include <cstdio>

using namespace std;
map<int, int> mp;
int main() {
	int m, n,temp;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			scanf("%d", &temp);
			if (mp.find(temp)!=mp.end())
			{
				mp[temp]++;
			}
			else
			{
				mp[temp] = 1;
			}
		}
	}
	int max = 0;
	int res;
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		if (it->second > max) {
			max = it->second;
			res = it->first;
		}
	}
	printf("%d", res);
	return 0;
}