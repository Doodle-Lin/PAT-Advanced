#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10001;
int main() {
	int n,m;
	int dp[maxn], A[maxn],priority[maxn];
	cin >> n >> m;
	fill(priority, priority + maxn, -1);
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		priority[temp] = i;
	}
	int L;
	cin >> L;
	int s[maxn];
	for (int i = 0; i < L; i++)
	{
		cin >> A[i];
	}
	if (priority[A[0]]!=-1)
	{
		dp[0] = 1;
		s[0] = 0;
	}
	else
	{
		dp[0] = 0;
		s[0] = -1;
	}
	int ans = -1;
	for (int i = 1; i < L; i++)
	{
		if (priority[A[i]]==-1)
		{
			dp[i] = dp[i - 1];
			s[i] = s[i - 1];
		}
		else
		{
			dp[i] = 1;
			s[i] = i;
			for (int j = 0; j < i; j++)
			{
				if (s[j]==-1)
				{
					continue;
				}
				if (priority[A[i]]>=priority[A[s[j]]]&&dp[j]+1>dp[i])//Âß¼­·±Ëö£¬·ÅÆú
				{
					dp[i] = dp[j] + 1;
				}
				else if (priority[A[i]]<priority[A[s[j]]]&&dp[j]>dp[i])
				{
					dp[i] = dp[j];
					s[i] = s[j];
				}
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
