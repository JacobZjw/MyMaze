#include"MakeMaze.h"
#include "pch.h"

Maze::Maze()
{
	srand((unsigned)time(NULL));
	//生成二维数组
	maze = (int**)malloc(L * sizeof(int*));
	for (int i = 0; i < L; i++)
	{
		maze[i] = (int*)calloc(L, sizeof(int));
	}

	//将最外层设置成路
	for (int i = 0; i < L; i++)
	{
		maze[0][i] = ROUTE;
		maze[i][0] = ROUTE;
		maze[L - 1][i] = ROUTE;
		maze[i][L - 1] = ROUTE;
	}

	//设置入口
	maze[2][1] = ROUTE;
}

Maze::~Maze()
{
	//释放内存
	for (int i = 0; i < L; i++)
		free(maze[i]);
	free(maze);
}

//生成迷宫
void Maze::CreateMaze(int** maze, int x, int y)
{
	maze[x][y] = ROUTE;
	//方向设置
	int direction[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
	//随机设置方向
	for (int i = 0; i < 4; i++)
	{
		int r = rand() % 4;
		int temp = direction[0][0];
		direction[0][0] = direction[r][0];
		direction[r][0] = temp;

		temp = direction[0][1];
		direction[0][1] = direction[r][1];
		direction[r][1] = temp;
	}

	//循环控制方向
	for (int i = 0; i < 4; i++)
	{
		int dx = x;
		int dy = y;

		//设置前进距离
		int range = 1 + (Rank <= 0 ? 0 : rand() % Rank);

		//判断是否符合适合路径
		while (range > 0)
		{
			dx += direction[i][0];
			dy += direction[i][1];

			if (maze[dx][dy] == ROUTE)//排除回头路
				break;

			//判断是否挖穿路径
			int Judge = 0;
			for (int j = dx - 1; j < dx + 2; j++)
				for (int k = dy - 1; k < dy + 2; k++)
				{
					//abs(j - dx) + abs(k - dy) == 1 确保只判断九宫格的四个特定位置
					if (abs(j - dx) + abs(k - dy) == 1 && maze[j][k] == ROUTE)
						Judge++;
				}

			if (Judge > 1)
				break;

			--range;
			maze[dx][dy] = ROUTE;
		}
		if (range <= 0)
			CreateMaze(maze, dx, dy);
	}
}

void Maze::SearchExit(int** maze)
{
	//寻找出口
	for (int i = L - 3; i > 0; i--)
	{
		if (abs(maze[i][L - 3]) + abs(maze[i][L - 1]) == 2)
		{
			maze[i][L - 2] = ROUTE;
			break;
		}
	}
}
int** Maze::GetMaze()
{
	return maze;
}