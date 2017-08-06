#include <iostream>
#include <string>

using namespace std;

int n;
string deal(string a, int &e) {
	while (a[0] == '0'&&a.length() > 0) {
		a.erase(a.begin());
	}
	if (a[0]=='.')
	{
		a.erase(a.begin());
		while (a[0] == '0'&&a.length()>0)
		{
			a.erase(a.begin());
			e--;
		}
	}
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
	}
	if (a.length() == 0)
	{
		e = 0;
	}
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
	}
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