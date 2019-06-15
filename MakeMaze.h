#pragma once

#include<cstdio>
#include<ctime>
#include<cmath>
#include<cstdlib>

//地图长度L，迷宫主体40，墙体2，最外侧包围路径2
#define L 44

//墙和路径的标识
#define WALL  0
#define ROUTE 1

//控制迷宫的复杂度
static int Rank = 0;

class Maze
{

public:	
	int** maze;
	Maze();
	virtual ~Maze();
	void CreateMaze(int** maze, int x, int y);
	void SearchExit(int** maze);
	int** GetMaze();
};
