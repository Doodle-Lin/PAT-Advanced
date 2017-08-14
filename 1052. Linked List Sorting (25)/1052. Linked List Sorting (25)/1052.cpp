#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node
{
	int address;
	int data=100001;
	int next;
	bool flag=false;
}node[maxn];
bool cmp(Node &a, Node &b) {
	if (a.flag==false||b.flag==false)
	{
		return a.flag > b.flag;//����Ч��������������
	}
	return a.data < b.data;
}
int main() {
	int n, fadd,add,data,next;
	scanf("%d%d", &n, &fadd);
	for(int i=0;i<n;i++)
	{

		scanf("%d%d%d", &add, &data, &next);
		node[add].address = add;//��ΪҪ�ı�����˳�򣬲��ܵ����������±�Ϊ��ַ
		node[add].data = data;
		node[add].next = next;
	}
	int p = fadd,count=0;
	while (p!=-1)
	{
		node[p].flag = true;//����������Ч����־λ��Ϊtrue
		p = node[p].next;
		count++;
	}
	if (count==0)
	{
		printf("0 -1");//Ҫ���ǵ�������û��Ԫ�ص����
	}
	else
	{
		sort(node, node + maxn, cmp);//����
		printf("%d %05d\n", count, node[0].address);
		for (int i = 0; i < count; i++)
		{
			if (i == count - 1)
			{
				node[i].next = -1;
				printf("%05d %d %d\n", node[i].address, node[i].data, node[i].next);
			}
			else
			{
				node[i].next = node[i + 1].address;
				printf("%05d %d %05d\n", node[i].address, node[i].data, node[i].next);
			}
		}
	}
	return 0;
}