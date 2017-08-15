#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
struct Node {
	int address;
	int data;
	int next;
}node[100010];
map<int, int> mp;
queue<Node> res, rem;
int main() {
	int fadd, n,add;
	scanf("%d%d", &fadd, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &add);
		node[add].address = add;
		scanf("%d%d", &node[add].data, &node[add].next);
	}
	int p = fadd;
	while (p!=-1)
	{
		if (mp[abs(node[p].data)]!=1)
		{
			res.push(node[p]);
			mp[abs(node[p].data)] = 1;
		}
		else
		{
			rem.push(node[p]);
		}
		p = node[p].next;
	}
	while (!res.empty())
	{
		Node temp = res.front();
		res.pop();
		if (res.empty())
		{
			temp.next = -1;
			printf("%05d %d %d\n", temp.address, temp.data, temp.next);
		}
		else
		{
			temp.next = res.front().address;
			printf("%05d %d %05d\n", temp.address, temp.data, temp.next);
		}
	}
	while (!rem.empty())
	{
		Node temp = rem.front();
		rem.pop();
		if (rem.empty())
		{
			temp.next = -1;
			printf("%05d %d %d\n", temp.address, temp.data, temp.next);
		}
		else
		{
			temp.next = rem.front().address;
			printf("%05d %d %05d\n", temp.address, temp.data, temp.next);
		}
	}
}