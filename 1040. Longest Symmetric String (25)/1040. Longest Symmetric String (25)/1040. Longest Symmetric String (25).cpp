#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 1001;
int dp[maxn][maxn];
int main() {
	string s;
	getline(cin, s);
	fill(dp[0], dp[0] + s.length()*s.length(), 0);
	//char* arr = new char[s.length()];
	char arr[maxn];
	strcpy(arr, s.c_str());
	int ans = 1;
	//for (int i = 0; i < s.length()-1; i++)
	//ע���ʼ������
	/*{
		dp[i][i] = 1;
		if (arr[i]==arr[i+1])
		{
			dp[i][i + 1] = 1;
			ans = 2;
		}
	}*/
	for (int i = 0; i < s.length(); i++)
	{
		dp[i][i] = 1;
		if (i<s.length()-1)
		{
			if (arr[i]==arr[i+1])
			{
				dp[i][i + 1] = 1;
				ans = 2;
			}
		}
	}
	for (int l = 3; l <= s.length(); l++)//LΪ���Ĵ����ȣ�����Ե���s.length(),ע��<=��
	{
		for (int i = 0; i + l - 1 < s.length();i++) {
			int j = i + l - 1;
			/*if (arr[i]==arr[j])
			{
				dp[i][j] = dp[i + 1][j - 1];
				if (dp[i][j]==1)
				{
					ans = l;
				}
			}*/
			if (arr[i]==arr[j]&&dp[i+1][j-1]==1)
			{
				dp[i][j] = 1;
				ans = l;
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}