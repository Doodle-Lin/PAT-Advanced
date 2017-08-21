#include <cstdio>
#include <queue>
using namespace std;
struct node
{
	int x, y, z;
}Node;
int m, n, slices, t;
queue<node> q;
int pixel[61][1300][130];
bool inq[61][1300][130] = { false };
int X[6] = { 0,0,0,0,1,-1 };
int Y[6] = { 0,0,1,-1,0,0 };
int Z[6] = { 1,-1,0,0,0,0 };
bool judge(int z, int x, int y) {
	if (x>=m||y>=n||z>=slices||x<0||y<0||z<0)
	{
		return false;
	}
	if (pixel[z][x][y]==0||inq[z][x][y]==true)
	{
		return false;
	}
	else return true;
}
int BFS(int z,int x,int y){
	int tot = 0;
	Node.x = x;
	Node.y = y;
	Node.z = z;
	q.push(Node);
	inq[z][x][y] = true;
	tot++;
	while (!q.empty())
	{
		node top = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int newx = top.x + X[i];
			int newy = top.y + Y[i];
			int newz = top.z + Z[i];
			if (judge(newz,newx,newy))
			{
				Node.x = newx;
				Node.y = newy;
				Node.z = newz;
				q.push(Node);
				inq[newz][newx][newy] = true;
				tot++;
			}
		}
	}
	if (tot>=t)
	{
		return tot;
	}
	else
	{
		return 0;
	}
}
int main() {
	scanf("%d%d%d%d", &m, &n, &slices, &t);
	for (int z = 0; z < slices; z++)
	{
		for (int x = 0; x < m; x++)
		{
			for (int y = 0; y < n; y++)
			{
				scanf("%d", &pixel[z][x][y]);
			}
		}
	}
	int ans = 0;
	for (int z = 0; z < slices; z++)
	{
		for (int x = 0; x < m; x++)
		{
			for (int y = 0; y < n; y++)
			{
				if (judge(z,x,y))
				{
					ans += BFS(z, x, y);
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}