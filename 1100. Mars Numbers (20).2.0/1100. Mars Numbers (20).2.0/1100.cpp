#include <map>
#include <string>
#include <iostream>

using namespace std;
const int maxn = 169;
string low[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string high[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
map<string, int> m2e;//map存放火星语翻译字典
string e2m[maxn] = {};//string数组存放地球语翻译字典
void init() {//初始化两个字典，将每一个数字双向映射，耗时耗空间但使用方便
	for (int i = 0; i < maxn; i++)
	{
		if (i<13)
		{
			e2m[i] = low[i];//小于13仅输出低位
		}
		else if(i%13==0)
		{
			e2m[i] = high[i / 13 - 1];//13的整数倍仅输出高位
		}
		else
		{
			e2m[i] = high[i / 13 - 1] + " " + low[i % 13];//一般情况下按格式输出高位低位
		}
		m2e[e2m[i]] = i;//将i也存入key为对应字符串的map中
	}
}
int main() {
	init();
	int n,num;
	string temp;
	cin >> n;
	getchar();//吃掉回车,否则getline无法进入循环
	for (int i = 0; i < n; i++)
	{
		num = 0;
		getline(cin, temp);
		if (temp[0] <= '9'&&temp[0] >= '0') {//根据首位判断是否数字
			for (int j = 0; j < temp.length(); j++)
			{
				num = num * 10 + temp[j] - '0';//数字转化为整型
			}
			cout << e2m[num] << endl;//查表
		}
		else
		{
			cout << m2e[temp]<<endl;//字符串直接查表
		}
		temp.clear();
	}
	return 0;
}