#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 40010;
const int maxc = 2510;

char stu[maxn][5];//此处必须为5，可能是因为需要多一位作为结束标志
vector<int> hashTable[maxc];
bool cmp(int a, int b) {
	return strcmp(stu[a], stu[b]) < 0;
}


int main() {
	int n, k,coun,couid;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d", stu[i], &coun);
		for (int j = 0; j < coun; j++)
		{
			scanf("%d", &couid);
			hashTable[couid].push_back(i);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		printf("%d %d\n", i, hashTable[i].size());
		sort(hashTable[i].begin(), hashTable[i].end(), cmp);
		/*for (vector<int>::iterator it = hashTable[i].begin(); it!=hashTable[i].end(); it++)
		{
			printf("%s\n", stu[*it]);
		}*/
		for (int j = 0; j < hashTable[i].size(); j++)
		{
			printf("%s\n", stu[hashTable[i][j]]);
		}
	}
	return 0;
}