#include <iostream>
#include <string>

using namespace std;

int n;
string deal(string a, int &e) {
	while (a[0] == '0'&&a.length() > 0) {
		a.erase(a.begin());
	}//��ǰ����ɾ��
	if (a[0]=='.')
	{
		a.erase(a.begin());
		while (a[0] == '0'&&a.length()>0)
		{
			a.erase(a.begin());
			e--;
		}
	}//�����С����ɾ��С���㣬����ɾ��С������0ֱ����һλ����λ��ÿɾȥһ��0��ָ����1
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
	}//�������0��С����ǰ�м�λ�ʹ���ָ���ԼӼ��Σ��ȼ��ڽ�С�����������λ����ɾ��С����
	if (a.length() == 0)
	{
		e = 0;
	}//��string���ȹ��㣬˵�����ַ���ȫΪ0
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
	}//ȡǰnλ,��������
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