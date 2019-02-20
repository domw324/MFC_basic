// DlgTab1.cpp: 구현 파일
//

#include "stdafx.h"
#include "maptool.h"
#include "DlgTab1.h"
#include "afxdialogex.h"

// CDlgTab1 대화 상자

IMPLEMENT_DYNAMIC(CDlgTab1, CDialog)

CDlgTab1::CDlgTab1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CDlgTab1::~CDlgTab1()
{
}

void CDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_ctlTreeCtrl1);
}

BEGIN_MESSAGE_MAP(CDlgTab1, CDialog)
END_MESSAGE_MAP()


// CDlgTab1 메시지 처리기

BOOL CDlgTab1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	HTREEITEM  hRoot;
	hRoot = m_ctlTreeCtrl1.InsertItem(L"OBJECT", 0/* nImage */, 1/* nSelectedImage */, TVI_ROOT, TVI_LAST);
	HTREEITEM  hChild1;
	hChild1 = m_ctlTreeCtrl1.InsertItem(L"Line", 1/* nImage */, 1/* nSelectedImage */, hRoot, TVI_LAST);
	HTREEITEM  hChild2;
	hChild2 = m_ctlTreeCtrl1.InsertItem(L"Rect", 1/* nImage */, 1/* nSelectedImage */, hRoot, TVI_LAST);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}