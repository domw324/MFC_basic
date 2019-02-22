#pragma once
#include <afxstr.h>
#include <stack>
#include <vector>


// CDlgTab1 대화 상자

class CDlgTab1 : public CDialog
{
	DECLARE_DYNAMIC(CDlgTab1)

public:
	CDlgTab1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgTab1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_ctlTreeCtrl;
	virtual BOOL OnInitDialog();

//////////////////////////////////////////////////////////////////////////
	/// 구현하고 싶은 것! 카테고리 추가 및 삭제 가능하게
public:
	virtual void InsertTree(int nShapeType, int nId);
	/*virtual void DeleteTree(int nShapeType, int nId);*/
	virtual void DeleteTreeBack(int nTnShapeType);
	virtual void DeleteTreeAll();

private:
	HTREEITEM  hRoot_OBJECT;
	HTREEITEM  hChild_LINE;
	HTREEITEM  hChild_RECT;

	CString strInsertName;

	int nTreeLineNum;
	int NTreeRectNum;

// 	std::vector<int> m_nLineIndex;
// 	std::vector<int> m_nRectIndex;
};