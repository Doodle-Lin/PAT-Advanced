#include <map>
#include <string>
#include <iostream>

using namespace std;
const int maxn = 169;
string low[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string high[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
map<string, int> m2e;//map��Ż����﷭���ֵ�
string e2m[maxn] = {};//string�����ŵ����﷭���ֵ�
void init() {//��ʼ�������ֵ䣬��ÿһ������˫��ӳ�䣬��ʱ�Ŀռ䵫ʹ�÷���
	for (int i = 0; i < maxn; i++)
	{
		if (i<13)
		{
			e2m[i] = low[i];//С��13�������λ
		}
		else if(i%13==0)
		{
			e2m[i] = high[i / 13 - 1];//13���������������λ
		}
		else
		{
			e2m[i] = high[i / 13 - 1] + " " + low[i % 13];//һ������°���ʽ�����λ��λ
		}
		m2e[e2m[i]] = i;//��iҲ����keyΪ��Ӧ�ַ�����map��
	}
}
int main() {
	init();
	int n,num;
	string temp;
	cin >> n;
	getchar();//�Ե��س�,����getline�޷�����ѭ��
	for (int i = 0; i < n; i++)
	{
		num = 0;
		getline(cin, temp);
		if (temp[0] <= '9'&&temp[0] >= '0') {//������λ�ж��Ƿ�����
			for (int j = 0; j < temp.length(); j++)
			{
				num = num * 10 + temp[j] - '0';//����ת��Ϊ����
			}
			cout << e2m[num] << endl;//���
		}
		else
		{
			cout << m2e[temp]<<endl;//�ַ���ֱ�Ӳ��
		}
		temp.clear();
	}
	return 0;
}