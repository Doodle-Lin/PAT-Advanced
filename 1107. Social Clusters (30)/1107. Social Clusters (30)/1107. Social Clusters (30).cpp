#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1010;
vector<int> ans;
int father[maxn];
int isRoot[maxn] = { 0};
int hobby[maxn] = { 0 };
bool cmp(int a, int b) {
	return a > b;
}
int findf(int x) {
	if (x == father[x])
	{
		return x;
	}
	else
	{
		int F = findf(father[x]);
		father[x] = F;
		return F;
	}
}
void Union(int a, int b) {
	int fa = findf(a);
	int fb = findf(b);
	if (fa!=fb)
	{
		father[fb] = fa;
	}
}
int main() {
	int m;
	scanf("%d", &m);
	for (int i = 1; i <=m; i++)
	{
		father[i] = i;
		int k;
		scanf("%d: ", &k);
		for (int j = 0; j < k; j++) {
			int temp;
			scanf("%d", &temp);
			if (hobby[temp]==0)
			{
				hobby[temp] = i;
			}
			else
			{
				Union(i, hobby[temp]);
			}
		}
	}
	for (int i = 1; i <=m; i++)
	{
		int F = findf(i);
		isRoot[F]++;
	}	
	for (int i = 1; i <=m; i++)
	{
		if (isRoot[i]!=0)
		{
			ans.push_back(isRoot[i]);
		}
	}
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end(),cmp);
	for (vector<int>::iterator it = ans.begin(); it !=ans.end(); it++)
	{
		printf("%d", *it);
		if (it<ans.end()-1)
		{
			printf(" ");
		}
	}
	return 0;
}

