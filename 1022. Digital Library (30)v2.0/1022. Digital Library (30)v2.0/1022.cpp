#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

map<string, set<int> > mpTitle;
map<string, set<int> > mpAuthor;
map<string, set<int> > mpKey;
map<string, set<int> > mpPub;
map<string, set<int> > mpYear;

void query(map<string, set<int> > &mp, string &str) {
	if (mp.find(str)==mp.end())
	{
		printf("Not Found\n");
	}
	else
	{
		for (set<int>::iterator it = mp[str].begin(); it !=mp[str].end(); it++)
		{
			printf("%07d\n", *it);
		}
	}
}

int main() {
	int n,m,id,temp;
	char c='\0';
	string title, author, key, pub, year,str;
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		scanf("%d", &id);
		getchar();
		getline(cin, title);
		mpTitle[title].insert(id);
		getline(cin, author);
		mpAuthor[author].insert(id);
	/*	while (cin >> key) {
			mpKey[key].insert(id);
			c = getchar();
			if (c=='\n')
			{
				break;
			}
		}*/
		while (c!='\n')
		{
			cin >> key;
			mpKey[key].insert(id);
			c = getchar();
		}
		c = '\0';
		getline(cin, pub);
		mpPub[pub].insert(id);
		getline(cin, year);
		mpYear[year].insert(id);
	}
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d: ", &temp);
		getline(cin, str);
		cout << temp << ": " << str<<endl;
		if (temp==1)
		{
			query(mpTitle, str);
		}
		else if (temp==2)
		{
			query(mpAuthor, str);
		}
		else if (temp==3)
		{
			query(mpKey, str);
		}
		else if (temp==4)
		{
			query(mpPub, str);
		}
		else if (temp==5)
		{
			query(mpYear, str);
		}
		else
		{
			printf("Not Found\n");
		}
	}
}