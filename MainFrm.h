// MainFrm.h: CMainFrame 类的接口
#pragma once

class CMainFrame : public CFrameWnd
{	
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual ~CMainFrame() {};

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
	CMainFrame() {};
	DECLARE_DYNCREATE(CMainFrame)
};


