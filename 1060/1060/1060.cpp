#include <iostream>
#include <string>

using namespace std;

int n;
string deal(string a, int &e) {
	while (a[0] == '0'&&a.length() > 0) {
		a.erase(a.begin());
	}//将前导零删除
	if (a[0]=='.')
	{
		a.erase(a.begin());
		while (a[0] == '0'&&a.length()>0)
		{
			a.erase(a.begin());
			e--;
		}
	}//如果是小数，删除小数点，继续删除小数点后的0直到第一位非零位，每删去一个0将指数减1
	else
	{
		for (string::iterator it = a.begin(); it!=a.end(); it++)
		{
			if (*it=='.')
			{
				a.erase(it);
				break;
			}
			e++;
		}
	}//如果大于0，小数点前有几位就代表指数自加几次，等价于将小数点调整到首位，并删除小数点
	if (a.length() == 0)
	{
		e = 0;
	}//若string长度归零，说明该字符串全为0
	int num = 0;
	int i = 0;
	string res;
	while (num<n)
	{
		if (i<a.length())
		{
			res += a[i];
		}
		else
		{
			res += '0';
		}
		
		i++;
		num++;
	}//取前n位,不够补零
	return res;
}
int main() {
	string s1, s2,s11,s22;
	int e1=0, e2=0;
	cin >> n >> s1 >> s2;
	s11 = deal(s1, e1);
	s22 = deal(s2, e2);
	if (s11 == s22&&e1 == e2)
		cout << "YES 0." << s11 << "*10^" << e1;
	else
		cout << "NO 0." << s11 << "*10^" << e1 << " 0." << s22 << "*10^" << e2;
	return 0;
}