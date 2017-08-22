#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct node
{
	int data;
	node* lchild;
	node* rchild;
};
queue<node*> q;
vector<int> vt;
int post[31];
int in[31];
node* create(int postl, int postr, int inl, int inr)//建树
{
	if (inl>inr)
	{
		return NULL;
	}
	node* root = new node;
	root->data = post[postr];
	int k;
	for (k = inl; k <= inr; k++)
	{
		if (in[k] == root->data)
		{
			break;
		}
	}
	int llen = k - inl;
	int lpostl = postl;
	int lpostr = postl + llen - 1;
	int linl = inl;
	int linr = inl + llen - 1;
	int rpostl = lpostr + 1;
	int rpostr = postr - 1;
	int rinl = k + 1;
	int rinr = inr;//根据中序后序序列判断左右子树
	root->lchild = create(lpostl, lpostr, linl, linr);
	root->rchild = create(rpostl, rpostr, rinl, rinr);
	return root;
}
void layer(node* root) {
	q.push(root);
	while (!q.empty())//类似于BFS
	{
		node* top = q.front();
		vt.push_back(top->data);
		q.pop();
		if (top->lchild != NULL)
		{
			q.push(top->lchild);
		}
		if (top->rchild != NULL)
		{
			q.push(top->rchild);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}
	node* root = create(0, n - 1, 0, n - 1);
	layer(root);
	for (vector<int>::iterator it = vt.begin(); it !=vt.end(); it++)
	{
		if (it == vt.end() - 1) {
			printf("%d\n", *it);
		}
		else
		{
			printf("%d ", *it);
		}
	}
	return 0;
}