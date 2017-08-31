#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> heap, ins, seq;
int n,pos=1;
void insertsort(int index) {
	int temp = ins[index];
	int j = index;
	while (j>0&&temp<ins[j-1])
	{
		ins[j] = ins[j - 1];
		j--;
	}
	ins[j] = temp;
	return;
}
void downadjust(int low, int high) {
	if (2*low>high)
	{
		return;
	}
	int temp = 2 * low;
	if (temp+1<=high&=&heap[temp+1-1]>heap[temp-1])
	{
		temp += 1;
	}
	if (heap[temp-1]>heap[low-1])
	{
		swap(heap[temp-1], heap[low-1]);
	}
	downadjust(temp, high);
}
int main() {
	scanf("%d", &n);
	int temp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		ins.push_back(temp);
		heap.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		seq.push_back(temp);
	}
	int pos = 1;
	for (; pos <n; pos++)
	{
		insertsort(pos);
		if (ins==seq)
		{
			insertsort(pos + 1);
			printf("Insertion Sort\n");
			for (int i = 0; i < n; i++)
			{
				printf("%d", ins[i]);
				if (i<n-1)
				{
					printf(" ");
				}
			}
			break;
		}
	}
	for (int i = n/2; i >0; i--)
	{
		downadjust(i, n);
	}
	for (int i = 1; i < n; i++)
	{
		swap(heap[0], heap[n - i]);
		downadjust(1,n-i);
		if (heap==seq)
		{
			swap(heap[0], heap[n - i-1]);
			downadjust(1, n - i-1);
			printf("Heap Sort\n");
			for (int j = 0; j < n; j++)
			{
				printf("%d", heap[j]);
				if (j<n-1)
				{
					printf(" ");
				}
			}
		}
	}
	return 0;
}
