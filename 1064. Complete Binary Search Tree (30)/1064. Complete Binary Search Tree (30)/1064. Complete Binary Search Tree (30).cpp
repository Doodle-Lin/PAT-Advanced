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
		Node[i].rchild = 2 * i + 1;//完全二叉树使用数组存储，左孩子下标为2i，右孩子下标为2i+1
	}
	it = s.begin();//初始化迭代器，否则报错
	inorder(1);
	for (int i = 1; i <=m; i++)
	{
		printf("%d", Node[i].data);//完全二叉树用数组存储本身满足层序遍历
		if (i < m) printf(" ");
	}
	return 0;
}
