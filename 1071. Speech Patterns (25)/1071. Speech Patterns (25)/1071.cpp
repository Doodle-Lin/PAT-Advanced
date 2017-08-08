#include <iostream>
#include <string>
#include <map>

using namespace std;

bool ischar(char a) {
	if ((a<='9'&&a>='0')||(a<='z'&&a>='a')||(a<='Z'&&a>='A'))
	{
		return true;
	}
	return false;
}//判断是否为合法输入

int main() {
	string str;
	map<string, int> mp;
	getline(cin, str);
	for (int i = 0; i < str.length();i++ )
	{
		string word;
		while (ischar(str[i]))
		{
			if (str[i]<='Z'&&str[i]>='A')
			{
				str[i] += 32;//将大写字母统一转化为小写
				word += str[i];
			}
			else
			{
				word += str[i];
			}
			i++;
		}
		if (word.length()!=0)
		{
			if (mp.find(word)==mp.end())
			{
				mp[word] = 1;
			}
			else
			{
				mp[word]++;
			}
		}
	}
	int max = 0;
	string res;
	for (map<string,int>::iterator it = mp.begin(); it !=mp.end(); it++)
	{
		if (it->second>max)
		{
			max = it->second;
			res = it->first;
		}
	}
	cout << res << " " << max;
	return 0;
}