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
	/// Tree Instance 추가 및 삭제
public:
	virtual void InsertTree(int nShapeType, int nId);
	/*virtual void DeleteTree(int nShapeType, int nId);*/
	virtual void DeleteTreeBack(int nShapeType);
	virtual void DeleteTreeAll();

private:
	HTREEITEM  hRoot_OBJECT;
	HTREEITEM  hChild_LINE;
	HTREEITEM  hChild_RECT;

	CString strInsertName;

	virtual void ExpandTree(int nShapeType);

	int nTreeLineNum;
	int NTreeRectNum;

// 	std::vector<int> m_nLineIndex;
// 	std::vector<int> m_nRectIndex;
};