﻿// MyMaze.h: MyMaze 应用程序的主头文件
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号

// CMyMazeApp:
// 有关此类的实现，请参阅 MyMaze.cpp

class CMyMazeApp : public CWinApp
{
public:
	CMyMazeApp() noexcept;
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyMazeApp theApp;
