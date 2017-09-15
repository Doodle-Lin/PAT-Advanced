#include <iostream>
#include <string>
using namespace std;
const int maxn = 100000;
struct node
{
	int lchild = -1;
	int rchild = -1;
}Node[maxn];
int n;
int maxindex = 0,last;
void preorder(int root, int index) {
	if (root==-1)
	{
		return;
	}
	if (index>maxindex)
	{
		maxindex = index;
		last = root;
	}
	preorder(Node[root].lchild, 2 * index);
	preorder(Node[root].rchild, 2 * index + 1);
}
bool isroot[maxn] ;
int strtoint(string a) {
	if (a=="-")
	{
		return -1;
	}
	else
	{
		int res =0;
		while (a.length()>0)
		{
			res = res * 10 + *a.begin()-'0';
			a.erase(a.begin());
		}
		isroot[res] = false;
		return res;
	}
}
int main() {
	cin >> n;
	fill(isroot, isroot + maxn, true);//初始化数组只有第一位为true,善用fill()
	for (int i = 0; i < n; i++)
	{
		string l, r;//要考虑到编号位数不止一位
		cin >> l >> r;
		Node[i].lchild = strtoint(l);
		Node[i].rchild = strtoint(r);
	}
	int root;
	for (int i = 0; i < n; i++)
	{
		if (isroot[i])
		{
			root = i;
			break;
		}
	}
	preorder(root, 1);
	if (maxindex==n)
	{
		cout << "YES " << last;
	}
	else
	{
		cout << "NO " << root;
	}
	return 0;
}