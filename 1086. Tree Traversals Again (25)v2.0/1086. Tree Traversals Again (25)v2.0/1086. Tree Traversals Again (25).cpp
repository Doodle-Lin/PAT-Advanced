#include <cstdio>
#include <cstring>
#include <stack>
//#include <vector>
using namespace std;
struct node
{
	int data;
	node* lchild;
	node* rchild;
}*root;
int pre[31],in[31],n;
stack<int> st;
//vector<int> vt;
node* create(int prel, int prer, int inl, int inr) {
	if (prel>prer)
	{
		return NULL;
	}
	node* root=new node;
	root->data = pre[prel];
	int temp = pre[prel];
	int k;
	for (k = inl; k <	inr; k++)
	{
		if (in[k]==temp)
		{
			break;
		}
	}
	int llen = k - inl;
	root->lchild = create(prel + 1, prel + llen, inl, k - 1);
	root->rchild = create(prel + llen + 1, prer, k + 1, inr);
	return root;
}
int num =0;
void post(node* root) {
	if (root==NULL)
	{
		return;
	};
	post(root->lchild);
	post(root->rchild);
	printf("%d", root->data);
	num++;
	if (num!=n)
	{
		printf(" ");
	}
	//vt.push_back(root->data);
};
int main() {
	int countpre=0,countin=0,temp;
	char str[5];
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < 2*n; i++)
	{
		scanf("%s", str);
		if (strcmp(str,"Push")==0)//strcmpÅÐ¶ÏÊÇ·ñÎªpush
		{
			scanf("%d", &temp);
			getchar();
			pre[countpre] = temp;
			countpre++;
			st.push(temp);
		}
		else
		{
			temp = st.top();
			st.pop();
			in[countin] = temp;
			countin++;
		}
	}
	root=create(0, n - 1, 0, n - 1);
	post(root);
	/*for (vector<int>::iterator it = vt.begin(); it != vt.end(); it++)
	{
		if (it == vt.end() - 1) printf("%d\n", *it);
		else printf("%d ", *it);
	}*/
	return 0;
}