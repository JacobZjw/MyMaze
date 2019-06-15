#pragma once

#include<cstdio>
#include<ctime>
#include<cmath>
#include<cstdlib>

//��ͼ����L���Թ�����40��ǽ��2��������Χ·��2
#define L 44

//ǽ��·���ı�ʶ
#define WALL   '0'
#define ROUTE  '1'


//�����Թ��ĸ��Ӷ�
static int Rank = 0;

class Maze
{
public:	
	Maze();
	virtual ~Maze();
	void CreateMaze();
	void SearchExit();
	char** GetMaze();
	void BeforeNew();
protected:
	char** maze;
	int tx, ty;
};
