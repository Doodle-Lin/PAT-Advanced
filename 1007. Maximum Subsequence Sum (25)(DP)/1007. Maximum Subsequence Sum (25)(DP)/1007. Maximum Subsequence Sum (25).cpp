#include <iostream>
using namespace std;
const int maxn = 10001;
int main() {
	int n;
	cin >> n;
	int A[maxn];
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		if (A[i]>=0)
		{
			flag = true;//遍历前先考虑特殊情况，减少计算量
		}
	}
	int dp[maxn],s[maxn];//dp[]存放以当前位置结束的子序列的最大和,s[]存放最大和连续子序列的起点
	dp[0] = A[0];
	s[0] = 0;//注意初始化
	if (!flag)
	{
		cout << 0 << " " << A[0] << " " << A[n-1];
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (dp[i - 1] + A[i] > A[i]) {//分两种情况讨论，即问题的状态转移方程
				dp[i] = dp[i - 1] + A[i];
				s[i] = s[i - 1];
			}
			else
			{
				dp[i] = A[i];
				s[i] = i;
			}
		}
		int k=0;
		for (int i = 1; i < n; i++)
		{
			if (dp[i]>dp[k])
			{
				k = i;
			}
		}
		cout << dp[k] << " " << A[s[k]] << " " << A[k];
	}
	return 0;
}