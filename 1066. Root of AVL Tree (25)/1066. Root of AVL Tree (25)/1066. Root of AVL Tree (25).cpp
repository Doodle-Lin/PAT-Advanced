#include <algorithm>
#include <cstdio>
using namespace std;
struct node
{
	int data, height;
	node* lchild, *rchild;
}*root;
int m;
node* newnode(int v) {
	node* root = new node;
	root->data = v;
	root->height = 1;
	root->lchild = root->rchild = NULL;
	return root;
}
int getheight(node* root) {
	if (root==NULL)
	{
		return 0;
	}
	else
	{
		return root->height;
	}
}
void updateheight(node* root) {
	root->height = max(getheight(root->lchild), getheight(root->rchild)) + 1;
	return;
}
int getbalance(node* root) {
	return getheight(root->lchild) - getheight(root->rchild);
}
void R(node* &root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateheight(root);
	updateheight(temp);
	root = temp;
}
void L(node* &root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateheight(root);
	updateheight(temp);
	root = temp;
}
void insert(node* &root, int x) {
	if (root==NULL)
	{
		root = newnode(x);
		return;
	}
	if (x<root->data)
	{
		insert(root->lchild, x);
		updateheight(root);
		if (getbalance(root)==2)
		{
			if (getbalance(root->lchild) == 1)
				R(root);
			else if (getbalance(root->lchild)==-1)
			{
				L(root->lchild);
				R(root);
			}
		}
	}
	else
	{
		insert(root->rchild, x);
		updateheight(root);
		if (getbalance(root) == -2)
		{
			if (getbalance(root->rchild) == -1)
				L(root);
			else if (getbalance(root->rchild) == 1)
			{
				R(root->rchild);
				L(root);
			}
		}
	}
}
node* create(int data[]) {
	root = NULL;
	for (int i = 0; i < m; i++)
	{
		insert(root, data[i]);
	}
	return root;
}
int main() {
	scanf("%d", &m);
	int *data = new int[m];
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &data[i]);
	}
	node* res=create(data);
	printf("%d", res->data);
	return 0;
}
