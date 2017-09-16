#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxc = 210;
int hashtable[maxc];
int dp[maxn], A[maxn];
int main() {
	int n, m;
	cin >> n >> m;
	fill(hashtable, hashtable + maxc, -1);
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		hashtable[temp] = i;
	}
	int num = 0;
	int l;
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int temp;
		cin >> temp;
		if (hashtable[temp]!=-1)
		{
			A[num++] = hashtable[temp];
		}
	}
	int ans = -1;
	for (int i = 0; i < num; i++)
	{
		dp[i] = 1;//初始化，很重要，状态转移方程的一部分，如果不满足条件长度为1
		for (int j = 0; j < i; j++)
		{
			if (dp[i]<dp[j]+1&&A[i]>=A[j])
			{
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
