// DlgTab1.cpp: 구현 파일
//

#include "stdafx.h"
#include "maptool.h"
#include "DlgTab1.h"
#include "afxdialogex.h"
#include "define.h"
#include <string>
#include "MainFrm.h"

// CDlgTab1 대화 상자

IMPLEMENT_DYNAMIC(CDlgTab1, CDialog)

CDlgTab1::CDlgTab1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{
	nTreeLineNum = NTreeRectNum = 0;
}

CDlgTab1::~CDlgTab1()
{
}

void CDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_ctlTreeCtrl);
}

BEGIN_MESSAGE_MAP(CDlgTab1, CDialog)
END_MESSAGE_MAP()


// CDlgTab1 메시지 처리기

BOOL CDlgTab1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	hRoot_OBJECT = m_ctlTreeCtrl.InsertItem(L"OBJECT", 0/* nImage */, 1/* nSelectedImage */, TVI_ROOT, TVI_LAST);
	
	hChild_LINE = m_ctlTreeCtrl.InsertItem(L"Line", 1/* nImage */, 1/* nSelectedImage */, hRoot_OBJECT, TVI_LAST);
	hChild_RECT = m_ctlTreeCtrl.InsertItem(L"Rect", 1/* nImage */, 1/* nSelectedImage */, hRoot_OBJECT, TVI_LAST);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgTab1::InsertTree(int nShapeType, int nId)
{
	switch (nShapeType)
	{
	case SHAPE::S_LINE:
	{
		strInsertName.Format(_T("line %d"), nId);
		m_ctlTreeCtrl.InsertItem(strInsertName, 1, 1, hChild_LINE, TVI_LAST);
		nTreeLineNum++;
	}
	break;

	case SHAPE::S_RECT:
	{
		strInsertName.Format(_T("rect %d"), nId);
		m_ctlTreeCtrl.InsertItem(strInsertName, 1, 1, hChild_RECT, TVI_LAST);
		NTreeRectNum++;
	}
	break;

	default:
		break;
	}
	
}

//  void CDlgTab1::DeleteTree(int nShapeType, int nId)
//  {
//  	switch (nShapeType)
//  	{
//  	case SHAPE::S_LINE:
//  	{
//  		strInsertName.Format(_T("line %d"), nLineNum);
//  		m_ctlTreeCtrl.InsertItem(strInsertName, 1, 1, hChild_LINE, TVI_LAST);
//  	}
//  	break;
//  
//  	case SHAPE::S_RECT:
//  	{
//  		strInsertName.Format(_T("rect %d"), nRectNum);
//  		m_ctlTreeCtrl.InsertItem(strInsertName, 1, 1, hChild_RECT, TVI_LAST);
//  	}
//  	break;
//  
//  	default:
//		break;
//  	}
// }

void CDlgTab1::DeleteTreeBack(int nShapeType)
{
	switch (nShapeType)
	{
	case SHAPE::S_LINE:
	{
		HTREEITEM hDeleteChild = m_ctlTreeCtrl.GetNextItem(hChild_LINE,TVGN_CHILD);

		int nTemp = nTreeLineNum;
		while (--nTemp > 0)
		{
			hDeleteChild = m_ctlTreeCtrl.GetNextItem(hDeleteChild, TVGN_NEXT);
		}
		m_ctlTreeCtrl.DeleteItem(hDeleteChild);
		nTreeLineNum--;
	}
	break;

	case SHAPE::S_RECT:
	{
		HTREEITEM hDeleteChild = m_ctlTreeCtrl.GetNextItem(hChild_RECT, TVGN_CHILD);

		int nTemp = NTreeRectNum;
		while (--nTemp > 0)
		{
			hDeleteChild = m_ctlTreeCtrl.GetNextItem(hDeleteChild, TVGN_NEXT);
		}
		m_ctlTreeCtrl.DeleteItem(hDeleteChild);
		
		NTreeRectNum--;
	}
	break;

	default:
		break;
	}
}

void CDlgTab1::DeleteTreeAll()
{
	HTREEITEM hDeleteChild;

	while (nTreeLineNum--)
	{
		hDeleteChild = m_ctlTreeCtrl.GetNextItem(hChild_LINE, TVGN_CHILD);
		m_ctlTreeCtrl.DeleteItem(hDeleteChild);
	}
	while (NTreeRectNum--)
	{
		hDeleteChild = m_ctlTreeCtrl.GetNextItem(hChild_RECT, TVGN_CHILD);
		m_ctlTreeCtrl.DeleteItem(hDeleteChild);
	}
}

