// MyMazeView.cpp: CMyMazeView 类的实现
//
#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MyMaze.h"
#endif

#include "MyMazeDoc.h"
#include "MyMazeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyMazeView

IMPLEMENT_DYNCREATE(CMyMazeView, CView)

BEGIN_MESSAGE_MAP(CMyMazeView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()


BOOL CMyMazeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMyMazeView 绘图
#define Start 15 //开始绘图的坐标
#define CubeLong 12//每个小方块的边长
//#define CubeLong 130//每个小方块的边长

void CMyMazeView::OnDraw(CDC* pDC)
{
	CMyMazeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码

	//准备内存绘图缓冲区
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);//创建绘图设备
	CBitmap MemBitmap;
	MemBitmap.CreateCompatibleBitmap(pDC, 850, 650);//绘图区域大小，可以像这样中直接使用窗口大小，也可以自己计算需要多大的区域
	//创建绘图区
	CBitmap* pOldBit = MemDC.SelectObject(&MemBitmap);
	MemDC.FillSolidRect(0, 0, 850, 650, RGB(255, 255, 255));//初始化
	//读取文档
	char** p = pDoc->GetMaze();
	//定义画刷
	int Routec = RGB(0,0,0);//黑色是路
	CBrush RouteBrush(Routec);
	int Wallc = RGB(255,255,255);//白色是墙
	CBrush WallBrush(Wallc);
	CBrush* oldBrush;

	//在缓冲区绘图
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++)
			switch (p[j][i])
			{
			case ROUTE:
				oldBrush = MemDC.SelectObject(&RouteBrush);
				MemDC.Rectangle(Start + i * CubeLong, Start + j * CubeLong, Start + (i + 1) * CubeLong, Start + (j + 1) * CubeLong);
				MemDC.SelectObject(oldBrush);
				break;
			case WALL:
				oldBrush = MemDC.SelectObject(&WallBrush);
				MemDC.Rectangle(Start + i * CubeLong, Start + j * CubeLong, Start + (i + 1) * CubeLong, Start + (j + 1) * CubeLong);
				MemDC.SelectObject(oldBrush);
				break;
			}

	//将内存中的图拷贝到屏幕上进行显示 
	pDC->BitBlt(0, 0, 850, 650, &MemDC, 0, 0, SRCCOPY);
	//绘图完成后清理 
	MemBitmap.DeleteObject();
	MemDC.DeleteDC();
}


// CMyMazeView 打印

BOOL CMyMazeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMyMazeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMyMazeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMyMazeView 诊断

#ifdef _DEBUG
void CMyMazeView::AssertValid() const
{
	CView::AssertValid();
}

void CMyMazeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyMazeDoc* CMyMazeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyMazeDoc)));
	return (CMyMazeDoc*)m_pDocument;
}
#endif //_DEBUG

// CMyMazeView 消息处理程序
