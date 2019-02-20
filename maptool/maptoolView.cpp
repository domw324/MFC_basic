
// maptoolView.cpp: CmaptoolView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "maptool.h"
#endif

#include "maptoolDoc.h"
#include "maptoolView.h"
#include "define.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmaptoolView

IMPLEMENT_DYNCREATE(CmaptoolView, CView)

BEGIN_MESSAGE_MAP(CmaptoolView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmaptoolView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CmaptoolView 생성/소멸

CmaptoolView::CmaptoolView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

	this->m_nDrawMode = MODE::NONE;
}

CmaptoolView::~CmaptoolView()
{
}

BOOL CmaptoolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CmaptoolView 그리기

void CmaptoolView::OnDraw(CDC* /*pDC*/)
{
	CmaptoolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CmaptoolView 인쇄


void CmaptoolView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmaptoolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CmaptoolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CmaptoolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CmaptoolView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmaptoolView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

void CmaptoolView::DrawLine()
{
	/// 이제 생성은 된다.
	CDC* p = this->GetWindowDC();

	int nStartX, nStartY, nEndX, nEndY;
	nStartX = nStartY = 10;
	nEndX = nEndY = 200;
	p->MoveTo(nStartX, nStartY);
 	p->LineTo(nEndX, nEndY);

	this->ReleaseDC(p);
}

void CmaptoolView::DrawRect()
{
	/// 이제 생성은 된다.
	CDC* p = this->GetWindowDC();

	int nStartX, nStartY, nEndX, nEndY;
	nStartX = nStartY = 10;
	nEndX = nEndY = 200;
	p->Rectangle(nStartX, nStartY, nEndX, nEndY);

	this->ReleaseDC(p);
}

void CmaptoolView::SetDrawMode(int nDrawMode)
{
	this->m_nDrawMode = nDrawMode;
}

void CmaptoolView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDragFlag = true;
	PointCheck(point);

	m_StartMouse = point;
	
// 	RedrawWindow();
// 	SetCapture();

	CView::OnLButtonDown(nFlags, point);
}

void CmaptoolView::OnLButtonUp(UINT nFlags, CPoint point)
{
}

void CmaptoolView::PointCheck(CPoint & point)
{
	if (point.x < 0)
	{
		point.x = 0;
	}
	if (point.x > 768)
	{
		point.x = 768;
	}
	if (point.y < 0)
	{
		point.y = 0;
	}
	if (point.y > 768)
	{
		point.y = 768;
	}
}


// CmaptoolView 진단

#ifdef _DEBUG
void CmaptoolView::AssertValid() const
{
	CView::AssertValid();
}

void CmaptoolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmaptoolDoc* CmaptoolView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmaptoolDoc)));
	return (CmaptoolDoc*)m_pDocument;
}
#endif //_DEBUG


// CmaptoolView 메시지 처리기
