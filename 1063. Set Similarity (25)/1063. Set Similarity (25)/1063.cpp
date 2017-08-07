#include <set>
#include <vector>
#include <cstdio>

using namespace std;

vector<set<int> > sets;

double setCmp(set<int> a, set<int> b) {
	int n=0, m=0;
	set<int> c=b;
	for (set<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		if (b.find(*it) != b.end())
			n++;
		c.insert(*it);
	}
	m = c.size();
	return (double)n / (double)m;
}
int main() {
	int n,m,temp,a,b;
	double res;
	set<int> setTemp;
	bool ismin;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &temp);
			setTemp.insert(temp);
		}
		sets.push_back(setTemp);
		setTemp.clear();
	}
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		ismin = sets[a-1].size() < sets[b-1].size() ? true : false;
		if (ismin)
		{
			res=setCmp(sets[a-1], sets[b-1]);
		}
		else
		{
			res=setCmp(sets[b-1], sets[a-1]);
		}
		printf("%3.1f%\n", 100 * res);
	}
	return 0;
}