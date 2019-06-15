#include"MakeMaze.h"
#include "pch.h"

Maze::Maze()
{
	//���ɶ�ά����
	maze = (char**)malloc(L * sizeof(char*));
	for (int i = 0; i < L; i++)
		maze[i] = (char*)calloc(L , sizeof(char));

	/*maze = new char* [L];
	for (int i = 0; i < L; i++)
		maze[i] = new char[L];*/
}

Maze::~Maze()
{
	//�ͷ��ڴ�
	for (int i = 0; i < L; i++)
		free(maze[i]);
	free(maze);

	/*for (int i = 0; i < L; i++)
		delete[]maze[i];
	delete[]maze;*/
}

void Maze::BeforeNew()
{
	if (maze != NULL)
	{
		//Ĭ������λ����ǽ
		for (int i = 0; i < L; i++)
			for (int j = 0; j < L; j++)
				maze[i][j] = WALL;

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
		//��ǽ���
		tx = 2; ty = 2;
	}
}

//�����Թ�
void Maze::CreateMaze()
{
	maze[tx][ty] = ROUTE;
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
	int x = tx, y = ty;
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
		{
			tx = dx; ty = dy;
			CreateMaze();
		}
	}
}

void Maze::SearchExit()
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
char** Maze::GetMaze()
{
	return maze;
}
