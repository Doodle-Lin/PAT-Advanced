#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
	int temp=0;
	string n;
	cin >> n;
	while (n.length()>0)
	{
		temp += *n.begin()-'0';
		n.erase(n.begin());
	}//��ĿҪ������ܹ�����10^100������ʹ��int���ͣ�������Χ���𰸴���
	vector<int> ans;
	if (temp==0)
	{
		cout<<"zero";
	}
	else
	{
		while (temp>0)
		{
			ans.push_back(temp % 10);
			temp /= 10;
		}
		reverse(ans.begin(), ans.end());
		string map[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
		for (int i = 0; i < ans.size(); i++)
		{
			cout << map[ans[i]];
			if (i<ans.size() - 1)
			{
				cout << " ";
			}
		}
	}
	return 0;
}