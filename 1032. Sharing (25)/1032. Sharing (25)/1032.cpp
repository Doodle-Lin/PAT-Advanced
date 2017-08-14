#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 100010;
struct Node
{
	char data;
	int next;
	bool flag = false;
}node[maxn];

int main() {
	int ad1, ad2,n,temp,p;
	scanf("%d%d%d", &ad1, &ad2, &n);
	while (n--)
	{
		scanf("%d ", &temp);
		scanf("%c %d", &node[temp].data, &node[temp].next);
	}
	for (p=ad1; p!=-1; p=node[p].next)
	{
		node[p].flag = true;
	}
	for (p = ad2; p != -1; p = node[p].next)
	{
		if (node[p].flag == true)
		{
			break;
		}
	}
	if (p==-1)
	{
		printf("-1\n");
	}
	else
	{
		printf("%05d\n", p);
	}
	return 0;
}