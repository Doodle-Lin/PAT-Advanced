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
			flag = true;//����ǰ�ȿ���������������ټ�����
		}
	}
	int dp[maxn],s[maxn];//dp[]����Ե�ǰλ�ý����������е�����,s[]����������������е����
	dp[0] = A[0];
	s[0] = 0;//ע���ʼ��
	if (!flag)
	{
		cout << 0 << " " << A[0] << " " << A[n-1];
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (dp[i - 1] + A[i] > A[i]) {//������������ۣ��������״̬ת�Ʒ���
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