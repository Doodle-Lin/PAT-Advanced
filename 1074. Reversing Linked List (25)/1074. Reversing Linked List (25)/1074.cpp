#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node
{
	int address;
	int data;
	int next;
}node[maxn];
int main() {
	int fadd, n, k;
	scanf("%d%d%d", &fadd, &n, &k);
	int add;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &add);
		scanf("%d%d", &node[add].data, &node[add].next);
		node[add].address = add;
	}
	Node *sortNode=new Node[n];
	int p = fadd,count=0;
	for (int i = 0; i < n&&p!=-1; i++)
	{
		sortNode[i] = node[p];
		p = node[p].next;
		count++;
	}
	for (int i = 0; i < count/k; i++)
	{
		reverse(sortNode + i*k, sortNode + (i + 1)*k);//使用reverse()可以极大减少代码量
	}
	/*if (count%k)
	{
		reverse(sortNode + count / k*k, sortNode + count);
	}*/
	//不到k个不反转，注意审题
	for (int i = 0; i < count; i++)
	{
		if (i==count-1)
		{
			sortNode[i].next = -1;
			printf("%05d %d %d", sortNode[i].address, sortNode[i].data, sortNode[i].next);
		}
		else
		{
			sortNode[i].next = sortNode[i + 1].address;
			printf("%05d %d %05d\n", sortNode[i].address, sortNode[i].data, sortNode[i].next);
		}
	}
	delete[] sortNode;
	return 0;
}