#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int index = 0, maxl = 0, length = 0, maxsum = -1, sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		length++;
		if (sum>maxsum)
		{
			maxsum = sum;
			index = i;
			maxl = length;
		}
		else if (sum<0)
		{
			sum = 0;
			length = 0;
		}
	}
	if (maxsum!=-1)
	{
		cout << maxsum << " " << arr[index - maxl + 1] << " " << arr[index];//输出的是元素而不是下标
	}
	else
	{
		cout << 0 << " " << arr[0] << " " << arr[n - 1];//注意全为负数的情况
	}
	return 0;
}