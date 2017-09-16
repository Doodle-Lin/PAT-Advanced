#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10001;
const int INF = 0x3fffffff;
int main() {
	int n,m;
	int dp[maxn], A[maxn],priority[maxn];
	cin >> n >> m;
	fill(priority, priority + n + 1, INF);
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		priority[temp] = i;
	}
	int L;
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> A[i];
		dp[i] = 0;
	}
	if (priority[A[0]]!=INF)
	{
		dp[0] = 1;
	}
	else
	{
		dp[0] = 0;
	}
	int ans = -1;
	for (int i = 1; i < L; i++)
	{
		if (priority[A[i]]==INF)
		{
			dp[i] = dp[i - 1];
		}
		else
		{
			for (int j = 0; j < i; j++)
			{
				if (priority[A[i]]>=priority[A[j]]&&dp[j]+1>dp[i])
				{
					dp[i] = dp[j] + 1;
				}
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
