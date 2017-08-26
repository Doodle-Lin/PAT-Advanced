#include <vector>
#include <cstdio>
using namespace std;
struct node
{
	int data;
	node* lchild;
	node* rchild;
};
vector<int> pre, prem, post;
void insert(node* &root, int x) {
	if (root==NULL)
	{
		root = new node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}
	else if (x<root->data)
	{
		insert(root->lchild,x);
	}
	else
	{
		insert(root->rchild, x);
	}
}
void preorder(node* root) {
	if (root==NULL)
	{
		return;
	}
	pre.push_back(root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void mirrorpreorder(node* root) {
	if (root==NULL)
	{
		return;
	}
	prem.push_back(root->data);
	mirrorpreorder(root->rchild);
	mirrorpreorder(root->lchild);
}
void postorder(node* root) {
	if (root==NULL)
	{
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	post.push_back(root->data);
}
void mirrorpostorder(node* root) {
	if (root == NULL)
	{
		return;
	}
	mirrorpostorder(root->rchild);
	mirrorpostorder(root->lchild);
	post.push_back(root->data);
}
int main() {
	int m;
	node* root = NULL;
	vector<int> seq;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int temp;
		scanf("%d", &temp);
		seq.push_back(temp);
		insert(root, temp);
	}
	preorder(root);
	mirrorpreorder(root);
	if (pre==seq)
	{
		printf("YES\n");
		postorder(root);
		for (int i = 0; i < post.size(); i++)
		{
			printf("%d", post[i]);
			if (i<post.size()-1)
			{
				printf(" ");
			}
		}
	}
	else if(prem == seq)
	{
		printf("YES\n");
		mirrorpostorder(root);
		for (int i = 0; i < post.size(); i++)
		{
			printf("%d", post[i]);

			if (i<post.size() - 1)
			{
				printf(" ");
			}
		}
	}
	else
	{
		printf("NO");
	}
	return 0;
}