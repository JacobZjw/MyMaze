#include"MakeMaze.h"
#include "pch.h"

Maze::Maze()
{
	srand((unsigned)time(NULL));
	//���ɶ�ά����
	maze = (int**)malloc(L * sizeof(int*));
	for (int i = 0; i < L; i++)
	{
		maze[i] = (int*)calloc(L, sizeof(int));
	}

	//����������ó�·
	for (int i = 0; i < L; i++)
	{
		maze[0][i] = ROUTE;
		maze[i][0] = ROUTE;
		maze[L - 1][i] = ROUTE;
		maze[i][L - 1] = ROUTE;
	}

	//�������
	maze[2][1] = ROUTE;
}

Maze::~Maze()
{
	//�ͷ��ڴ�
	for (int i = 0; i < L; i++)
		free(maze[i]);
	free(maze);
}

//�����Թ�
void Maze::CreateMaze(int** maze, int x, int y)
{
	maze[x][y] = ROUTE;
	//��������
	int direction[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
	//������÷���
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

	//ѭ�����Ʒ���
	for (int i = 0; i < 4; i++)
	{
		int dx = x;
		int dy = y;

		//����ǰ������
		int range = 1 + (Rank <= 0 ? 0 : rand() % Rank);

		//�ж��Ƿ�����ʺ�·��
		while (range > 0)
		{
			dx += direction[i][0];
			dy += direction[i][1];

			if (maze[dx][dy] == ROUTE)//�ų���ͷ·
				break;

			//�ж��Ƿ��ڴ�·��
			int Judge = 0;
			for (int j = dx - 1; j < dx + 2; j++)
				for (int k = dy - 1; k < dy + 2; k++)
				{
					//abs(j - dx) + abs(k - dy) == 1 ȷ��ֻ�жϾŹ�����ĸ��ض�λ��
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
	//Ѱ�ҳ���
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