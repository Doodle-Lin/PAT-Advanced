#include <unordered_set>
#include <vector>
#include <cstdio>

using namespace std;

const int maxn = 50;

unordered_set<int> sets[maxn];

double setCmp(int a, int b) {//ע�⣬��Ҫ��set������Ϊ�������룬����Ӱ�������ٶȣ��ᵼ�³�ʱ
	int n=0, m=sets[b].size();
	//unordered_set<int> c=b;
	for (unordered_set<int>::iterator it = sets[a].begin(); it != sets[a].end(); it++)
	{
		if (sets[b].find(*it) != sets[b].end()) 
		{
			n++;
		}
		else
		{
			m++;
		}
	}
	return (double)n / (double)m;
}
int main() {
	int n,m,temp,a,b;
	double res;
	//unordered_set<int> setTemp;
	bool ismin;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &temp);
			sets[i].insert(temp);
		}
		/*sets[i] = setTemp;
		setTemp.clear();*/
		//��δ�����һ��
	}
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		ismin = sets[a-1].size() < sets[b-1].size() ? true : false;
		if (ismin)
		{
			res=setCmp(a-1, b-1);
		}
		else
		{
			res=setCmp(b-1, a-1);
		}
		printf("%3.1f%\n", 100 * res);
	}
	return 0;
}