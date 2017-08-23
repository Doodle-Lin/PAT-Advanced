#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n,temp[32],c=0;
vector<int> vt;
struct node
{
	int data;
	node* lchild;
	node* rchild;
}*root;
node* newnode(int v) {
	node* Node=new node;
	Node->data = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
}
void create(node* &root) {
	if (c==2*n)
	{
		return;
	}
	char str[5];
	int temp;
	scanf("%s", str);
	c++;
	if (strcmp(str,"Push")==0)
	{
		scanf("%d", &temp);
		getchar();
		root=newnode(temp);
		create(root->lchild);
		create(root->rchild);
	}
	else
	{
		getchar();
		root = NULL;
	}
}
void post(node* root){
	if (root==NULL)
	{
		return;
	}
	post(root->lchild);
	post(root->rchild);
	vt.push_back(root->data);
}
int main() {
	scanf("%d", &n);
	getchar();
	create(root);
	post(root);
	for (vector<int>::iterator it = vt.begin(); it != vt.end(); it++)
	{
		if (it == vt.end() - 1) printf("%d\n", *it);
		else printf("%d ", *it);
	}
	return 0;
}