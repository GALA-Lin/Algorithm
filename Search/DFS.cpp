#include <iostream>
using namespace std;

/*
 * 由于这里使用数组的原因, 而数组的初始值是为0的,
 * 所以不能让 0 表示空地, 1 表示障碍物。
 * 这里用 1 表示空地, 2 表示障碍物。
 */

int start_x, start_y; //起点坐标：(start_x, start_y)
int end_x, end_y; //终点坐标：(endx, endy)

int min_step = 99999;//一开始给它一个很大的数

//地图,放100行100列
int map[100][100];//1表示空地,2表示障碍物
int visit[100][100];//1表示访问,0表示未访问

void dfs(int x,int y,int step)
{
	if (x== end_x && y== end_y)
	{
		//如果当前步数小于最小值，就更新
		if (step < min_step)
			min_step = step;
		return;//回溯
	}
	//顺时针试探
	//右
	//如果当前位置的右边为空地且没有访问过
	if (map[x][y + 1] == 1 && visit[x][y + 1] == 0)
	{
		//将右边的点设置为已访问
		visit[x][y + 1] = 1;
		dfs(x, y + 1, step + 1);
		visit[x][y + 1] = 0;
	}

	//下
	if (map[x+1][y] == 1 && visit[x+1][y] == 0)
	{
		//将下边的点设置为已访问
		visit[x+1][y] = 1;
		dfs(x + 1, y, step + 1);
		visit[x+1][y] = 0;
	}
	//左
	if (map[x][y - 1] == 1 && visit[x][y - 1] == 0)
	{
		//将左边的点设置为已访问
		visit[x][y - 1] = 1;
		dfs(x, y - 1, step + 1);
		visit[x][y - 1] = 0;
	}
	//上
	if (map[x-1][y] == 1 && visit[x-1][y] == 0)
	{
		//将上边的点设置为已访问
		visit[x-1][y] = 1;
		dfs(x-1, y, step + 1);
		visit[x-1][y] = 0;
	}
	return;
}

int main()
{
	int m, n;

	printf("请设置地图的行数和列数，以逗号分隔:\n");
	scanf("%d,%d",&m,&n);

	printf("请输入 %d 行 %d 列的地图:\n",m,n);
	for (int i=1;i<=m;i++)
	{ 
		for (int j = 1; j <= n; j++)
			scanf("%d",&map[i][j]);//0表示空地,1表示障碍物
	}
	
	printf("请输入起点坐标,以逗号分隔:\n");
	scanf("%d,%d", &start_x,&start_y);

	printf("请输入终点坐标,以逗号分隔:\n");
	scanf("%d,%d", &end_x, &end_y);

	visit[start_x][start_y] = 1;
	dfs(start_x, start_y,0);
	printf("最短步数为 %d 步.\n", min_step);
	
	system("pause");
	return 0;
}
