#include <stack>
#include <string>
#include <cstdio>

using namespace std;

const int maxn = 1001;
int seq[maxn];
stack<int> st;
int main() {
	int m, n, k,temp=0;

	scanf("%d%d%d", &m, &n, &k);
	for (int i = 0; i < k; i++)
	{
		temp = 0;
		while(!st.empty())
		{
			st.pop();
		}//Çå¿Õ
		for (int j = 0; j < n; j++) {
			scanf("%d", &seq[j]);
		}
		for (int z = 1; z <= n; z++)
		{
			if (st.size()==m)
			{
				printf("NO\n");
				break;
			}
			st.push(z);
			while(!st.empty() && st.top() == seq[temp])
			{
				st.pop();
				temp++;
			}
			if (temp==n)
			{
				printf("YES\n");
				break;
			}
			if (z==n)
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}