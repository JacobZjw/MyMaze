// MyMazeDoc.cpp: CMyMazeDoc 类的实现

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MyMaze.h"
#endif

#include "MyMazeDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMyMazeDoc

IMPLEMENT_DYNCREATE(CMyMazeDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyMazeDoc, CDocument)
END_MESSAGE_MAP()


BOOL CMyMazeDoc::OnNewDocument()
{
	/*if (!CDocument::OnNewDocument())
		return FALSE;*/
	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	CreateMaze(maze, 2, 2);//生成新迷宫
	SearchExit(maze);
	
	return TRUE;
}

// CMyMazeDoc 序列化

void CMyMazeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
		for (int i = 0; i <L; i++)//保存迷宫区域
		{
			for (int j = 0; j <L; j++)
			{
				ar << maze[i][j];
			}
		}
	}
	else
	{
		// TODO:  在此添加加载代码
		for (int i = 0; i < L; i++)//保存迷宫区域
		{
			for (int j = 0; j < L; j++)
			{
				ar >> maze[i][j];
			}
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMyMazeDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMyMazeDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMyMazeDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMyMazeDoc 诊断

#ifdef _DEBUG
void CMyMazeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyMazeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMyMazeDoc 命令
