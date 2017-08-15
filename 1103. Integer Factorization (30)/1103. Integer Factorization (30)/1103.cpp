#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> temp, ans;
int  n, k, p,maxSum=0;
void DFS(int index,int nowk,int nowSum,int squ) {
	if (squ==n&&nowk==k)
	{
		if (nowSum > maxSum) {
			maxSum = nowSum;
			ans = temp;
		}
		return;
	}
	if (squ>n||nowk>k||index==0)
	{
		return;
	}
	temp.push_back(index);
	DFS(index, nowk + 1, nowSum + index, squ + pow(index, p));
	temp.pop_back();
	DFS(index - 1, nowk, nowSum, squ);
}
int main() {
	scanf("%d%d%d", &n, &k, &p);
	DFS(pow((double)n,1.0/p), 0, 0, 0);
	if (!ans.size())
	{
		printf("Impossible");
	}
	else
	{
		printf("%d =",n);
		for (int i = 0; i < k; i++)
		{
			if (i==k-1)
			{
				printf(" %d^%d", ans[i], p);
			}
			else
			{
					printf(" %d^%d +", ans[i], p);
			}
		}
	}
	return 0;
}
