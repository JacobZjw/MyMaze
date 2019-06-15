// MyMazeView.h: CMyMazeView 类的接口

#pragma once

class CMyMazeView : public CView
{
// 特性
public:
	virtual ~CMyMazeView() {};
	CMyMazeDoc* GetDocument() const;
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 生成的消息映射函数
protected:
	CMyMazeView() {};
	DECLARE_DYNCREATE(CMyMazeView);
	DECLARE_MESSAGE_MAP()
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
};

#ifndef _DEBUG  // MyMazeView.cpp 中的调试版本
inline CMyMazeDoc* CMyMazeView::GetDocument() const
   { return reinterpret_cast<CMyMazeDoc*>(m_pDocument); }
#endif

