#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct node
{
	int data;
	node* lchild;
	node* rchild;
}*root;
vector<pair<string, int> > order;//将指令存储
node* create(int v) {
	node* root = new node;
	root->data = v;
	root->lchild = NULL;
	root->rchild = NULL;
	return root;
}
void build(node* &root, vector<pair<string, int> >::iterator &it) {
	if (it == order.end())
	{
		return;
	}
	if (it->first == "Push")
	{
		root = create(it->second);
		build(root->lchild, ++it);
		build(root->rchild, ++it);//先序遍历建树
	}
	else if (it->first == "Pop")
	{
		return;
	}
}
int cou = 0, n;
void postorder(node* root) {
	if (root == NULL)
	{
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	cout << root->data;
	cou++;
	if (cou<n)
	{
		cout << " ";
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
	{
		string str;
		int num = 0;
		cin >> str;
		if (str == "Push")
		{
			cin >> num;
		}
		order.push_back(make_pair(str, num));
	}
	vector<pair<string, int> >::iterator it = order.begin();
	build(root, it);
	postorder(root);
	return 0;
}