#include <cstdio>
#include <algorithm>
using namespace std;
int m;
struct node
{
	int data, height;
	node* lchild;
	node* rchild;
}*root;
int geth(node* root) {
	if (root==NULL)
	{
		return 0;
	}
	return root->height;
}
void updateh(node* root) {
	root->height = max(geth(root->lchild), geth(root->rchild))+1;
	return;
}
int getb(node* root){
	return geth(root->lchild) - geth(root->rchild);
}
node* newnode(int v) {
	node* root = new node;
	root->data = v;
	root->height = 1;
	root->lchild = root->rchild = NULL;
	return root;
}
void R(node* &root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateh(root);
	updateh(temp);
	root = temp;
	return;
}
void L(node* &root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateh(root);
	updateh(temp);
	root = temp;
	return;
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
		updateh(root);
		if (getb(root)==2)
		{
			if (getb(root->lchild)==1)
			{
				R(root);
			}
			else if (getb(root->lchild)==-1)
			{
				L(root->lchild);
				R(root);
			}
		}
	}
	else
	{
		insert(root->rchild, x);
		updateh(root);
		if (getb(root) == -2)
		{
			if (getb(root->rchild) == -1)
			{
				L(root);
			}
			else if (getb(root->rchild) == 1)
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
	node* root = create(data);
	printf("%d", root->data);
	return 0;
}