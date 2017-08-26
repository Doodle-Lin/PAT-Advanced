#include <cstdio>
#include <set>
using namespace std;
const int maxn = 1001;
struct node
{
	int add;
	int data;
	int lchild;
	int rchild;
}Node[maxn];
int m;
set<int> s;
set<int>::iterator it;
void inorder(int root) {
	if (root>m)
	{
		return;
	}
	inorder(Node[root].lchild);
	Node[root].data = *it;
	it++;
	inorder(Node[root].rchild);
}
int main() {
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int temp;
		scanf("%d", &temp);
		s.insert(temp);
		Node[i].add = i;
		Node[i].lchild = 2 * i;
		Node[i].rchild = 2 * i + 1;//��ȫ������ʹ������洢�������±�Ϊ2i���Һ����±�Ϊ2i+1
	}
	it = s.begin();//��ʼ�������������򱨴�
	inorder(1);
	for (int i = 1; i <=m; i++)
	{
		printf("%d", Node[i].data);//��ȫ������������洢��������������
		if (i < m) printf(" ");
	}
	return 0;
}
