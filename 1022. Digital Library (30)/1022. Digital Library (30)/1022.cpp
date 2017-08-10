#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>//cout格式化输出

using namespace std;

map<int, vector<string> > lib;
vector<string> keyword;
map<int, vector<string> > keywords;
int main() {
	int n,id;
	string str;
	cin>>n;
	while (n--) {
		cin>>id;
		getchar();
		for (int i = 0; i < 5; i++)
		{
			getline(cin, str);
			lib[id].push_back(str);

			if (i == 2)
			{
				while (str.find(" ") != string::npos)
				{
					keyword.push_back(str.substr(0, str.find(" ")));
					str.erase(0, str.find(" ") + 1);
				}
				keyword.push_back(str);
				keywords[id] = keyword;
			}
			str.clear();
			keyword.clear();
		}
	}
	int m, temp, count = 0;
	vector<string> vi;
	cin >> m;
	getchar();
	while (m--)
	{
		getline(cin, str);
		cout << str << endl;
		temp = str[0] - '0';
		str.erase(0, 3);
		if (temp != 3)
		{
			for (map<int, vector<string> >::iterator it = lib.begin(); it != lib.end(); it++)
			{
				if ((it->second)[temp - 1] == str)
				{
					cout << setfill('0')<<setw(7)<<it->first << endl;//id必须为7位
					count++;
				}
			}
		}
		else
		{
			for (map<int, vector<string> >::iterator it = keywords.begin(); it != keywords.end(); it++)
			{
				vi = it->second;
				for (vector<string>::iterator it2 = vi.begin(); it2 != vi.end(); it2++)
				{
					if (*it2 == str) {
						cout << setfill('0') << setw(7) << it->first << endl;
						count++;
						break;
					}
				}
			}
			/*for (map<int, vector<string> >::iterator it = lib.begin(); it != lib.end(); it++)
			{
			if ((it->second)[temp - 1].find(str)!=string::npos)
			{
			cout << it->first << endl;
			count++;
			}
			}*/
			//这段代码逻辑错误，如果使用find(),则关键词不完全匹配也可以通过查询,例如"keyword"中就包含"word"

		}
		if (!count)
		{
			cout << "Not Found" << endl;
		}
		count = 0;
		str.clear();
	}
	return 0;
}