//#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> hashTable[26 * 26 * 26*10 + 1];
//int hashFunc(string a) {
//	int id=0;
//	for (int i = 0; i < a.length()-1; i++)
//	{
//		id =id*26+a[i] - 'A';
//	}
//	int len = a.length() - 1;
//	id = id * 10 + a[len]-'0';
//	return id;
//}
//ʹ��string�ᵼ�����г�ʱ

int hashFunc(char a[]) {
	int id = 0;
	for (int i = 0; i < 3; i++)
	{
		id = id * 26 + a[i] - 'A';
	}
	id = id * 10 + a[3] - '0';
	return id;
}
int main() {
	int m, n,coun,stun,id;
	char temp[4];
	//vector<char*> stu;
	//̫�����ˣ�����ʹ��vector�洢ѧ������������һ�����һ�����ɣ�Ҳ����ȫ���������������scanf���Եȴ���������

	//cin >> m >> n;
	//�������룬scanf�ȽϽ�Լ��Դ
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		//cin >> coun >> stun;
		scanf("%d%d", &coun, &stun);
		for (int j = 0; j < stun; j++)
		{
			//cin>>temp;
			scanf("%s", temp);
			id = hashFunc(temp);
			hashTable[id].push_back(coun);
		}
	}
	for (int k = 0; k < m ;k++)
	{
		//cout << *it1 ;
		scanf("%s", temp);
		printf("%s", &temp);
		id = hashFunc(temp);
		sort(hashTable[id].begin(), hashTable[id].end());
		if (hashTable[id].size() == 0)
		{
			//cout << " 0";
			printf(" 0");
		}
		else
		{
			//cout << " " << hashTable[id].size();
			printf(" %d", hashTable[id].size());
		}
		for (vector<int>::iterator it2=hashTable[id].begin(); it2!=hashTable[id].end(); it2++)
		{
			//cout <<" "<< *it2;
			printf(" %d", *it2);
		}
		//cout << endl;
		printf("\n");
	}
	return 0;
}

