// CCControlView.cpp: 구현 파일
//

#include "stdafx.h"
#include "maptool.h"
#include "ControlView.h"
#include "define.h"

#define SAFE_DELETE(p) {if(p) {delete(p); (p)=NULL;} }

// CControlView

IMPLEMENT_DYNCREATE(CControlView, CFormView)

CControlView::CControlView() : CFormView(CControlView::IDD)
{
	m_pDialog1 = NULL;
	m_pDialog2 = NULL;
}

CControlView::~CControlView()
{
	SAFE_DELETE(m_pDialog1);
	SAFE_DELETE(m_pDialog2);
}

void CControlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_ctlTab);
}

BEGIN_MESSAGE_MAP(CControlView, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CControlView::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CControlView 그리기

void CControlView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
}


// CControlView 진단

#ifdef _DEBUG
void CControlView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CControlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CControlView 메시지 처리기



void CControlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_ctlTab.DeleteAllItems();
	m_ctlTab.InsertItem(0, L"Object"); /// cstring type로 사용하기 위해 L을 붙인다
	m_ctlTab.InsertItem(1, L"Drawing");

	CRect rect;

	m_pDialog1 = new CDlgTab1;
	m_pDialog1->Create(IDD_DIALOG1, &m_ctlTab);
	m_pDialog1->GetWindowRect(&rect);
	m_pDialog1->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pDialog1->ShowWindow(SW_SHOW);

	m_pDialog2 = new CDlgTab2;
	m_pDialog2->Create(IDD_DIALOG2, &m_ctlTab);
	m_pDialog2->GetWindowRect(&rect);
	m_pDialog2->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pDialog2->ShowWindow(SW_HIDE);

	UpdateData(FALSE);
}


void CControlView::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	int select = m_ctlTab.GetCurSel();

	switch (select)
	{
	case 0:
		m_pDialog1->ShowWindow(SW_SHOW);
		m_pDialog2->ShowWindow(SW_HIDE);
		break;
	case 1:
		m_pDialog1->ShowWindow(SW_HIDE);
		m_pDialog2->ShowWindow(SW_SHOW);
		break;
	}
	*pResult = 0;
}

void CControlView::InsertTree(int nShapeType, int nId)
{
	m_pDialog1->InsertTree(nShapeType, nId);
}

void CControlView::DeleteTreeBack(int nShapeType)
{
	m_pDialog1->DeleteTreeBack(nShapeType);
}

void CControlView::DeleteTreeAll()
{
	m_pDialog1->DeleteTreeAll();
}