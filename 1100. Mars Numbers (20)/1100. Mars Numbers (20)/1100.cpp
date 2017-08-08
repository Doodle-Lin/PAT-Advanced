#include <map>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 100;
string str[maxn];
map<string, int> mp;
map<string, int> mp2;

int main() {
	int nl;
	cin >> nl;
	cin.ignore();//注意，不使用ignore()无法循环进行输入
	mp["tret"] = 0;mp["jan"] = 1; mp["feb"] = 2; mp["mar"] = 3; mp["apr"] = 4; mp["may"] = 5; mp["jun"] = 6; mp["jly"] = 7; mp["aug"] = 8; mp["sep"] = 9; mp["oct"] = 10; mp["nov"] = 11; mp["dec"] = 12;
	mp2["tam"] = 1; mp2["hel"] = 2; mp2["maa"] = 3; mp2["huh"] = 4; mp2["tou"] = 5; mp2["kes"] = 6; mp2["hei"] = 7; mp2["elo"] = 8; mp2["syy"] = 9; mp2["lok"] = 10; mp2["mer"] = 11; mp2["jou"] = 12;//使用map进行映射，不如双向映射直接查表
	while(nl--)
	{
		int num=0,m,n;
		string mstr,str;
		getline(cin, str);
		if (str[0]>='0'&&str[0]<='9')//如果是数字就转化为int
		{
			for (int j = 0; j < str.length(); j++)
			{
				num = num * 10 + str[j] - '0';
			}
			m = num / 13;
			n = num % 13;
			if (m!=0)
			{
				for (map<string, int>::iterator it = mp2.begin(); it != mp2.end(); it++) {
					if (it->second==m)
					{
						cout << it->first ;
						break;
					}
				}
				if (n==0)
				{
					cout << endl;
				}
				else
				{
					for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
					{
						if (it->second == n)
						{
							cout << " "<<it->first << endl;
							break;
						}
					}
				}
			}
			else
			{
				for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
				{
					if (it->second == n)
					{
						cout << it->first << endl;
						break;
					}
				}
			}
		}
		else
		{
			if (str.length()>4)
			{
				mstr.replace(mstr.begin(),mstr.end(),str.substr(0,3));
				str.erase(str.begin(), str.begin() + 4);
				num = mp2.find(mstr)->second * 13;
				mstr.clear();
				mstr += str;
				num += mp.find(mstr)->second;
				cout << num << endl;
			}
			else
			{
				for (map<string,int>::iterator it = mp2.begin(); it !=mp2.end(); it++)
				{
					if (it->first == str) {
						cout << it->second*13 << endl;
						break;
					}
				}
				for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
				{
					if (it->first == str) {
						cout << it->second << endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}