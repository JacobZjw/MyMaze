// MazeDoc.h: CMazeDoc 类的接口
#pragma once

class CMyMazeDoc : public CDocument, public Maze
{
public:
	virtual ~CMyMazeDoc() {};
	virtual BOOL OnNewDocument();//新建文档
	virtual void Serialize(CArchive& ar);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected: // 仅从序列化创建
	CMyMazeDoc() :Maze() {};
	DECLARE_DYNCREATE(CMyMazeDoc)
	DECLARE_MESSAGE_MAP()// 生成的消息映射函数
};
