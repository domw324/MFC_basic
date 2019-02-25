
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
#include "Line.h"
#include "Shape.h"
#include "Rect.h"
#include "BufferDC.h"
#include <WinUser.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmaptoolView

IMPLEMENT_DYNCREATE(CmaptoolView, CView)

BEGIN_MESSAGE_MAP(CmaptoolView, CView) /// 사용할 메시지를 미리 등록해놔야 사용 가능하다!!
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmaptoolView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
 	ON_WM_KEYDOWN()
// 	ON_WM_KEYUP()
// 	ON_WM_CHAR()
END_MESSAGE_MAP()

// CmaptoolView 생성/소멸

CmaptoolView::CmaptoolView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

	this->m_nDrawMode = MODE::NONE;
	this->m_bDragFlag = FALSE;
	this->m_bCtrlKey = FALSE;

	m_pShapeHandler = CShapeHandler::GetInstance();
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

void CmaptoolView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDragFlag = true;
	CheckPoint(point);

	m_StartMouse = point;
	
 	SetCapture(); /// 활성 영역 외의 메세지 받는 함수이다. 활성화 되면 다른 컨트롤 사용 불가.

	CView::OnLButtonDown(nFlags, point);
}

void CmaptoolView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_bDragFlag = false;
	m_CurrentMouse = point;

	switch (m_nDrawMode)
	{
	case MODE::DRAW_LINE:
	{
		m_pShapeHandler->CreateShape(SHAPE::S_LINE, m_StartMouse, m_CurrentMouse);
	}
	break;

	case MODE::DRAW_RECT:
	{
		m_pShapeHandler->CreateShape(SHAPE::S_RECT, m_StartMouse, m_CurrentMouse);
	}
	break;

	case MODE::NONE:
	{
	}
	break;

	default:
		break;
	}

	ReleaseCapture(); /// 포커싱 해제

	RedrawWindow();
	OnPaint();

	CView::OnLButtonUp(nFlags, point);
}

void CmaptoolView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (m_bDragFlag)
	{
		m_CurrentMouse = point;

		RedrawWindow();
		OnPaint();

 		switch (m_nDrawMode)
 		{
 		case MODE::DRAW_LINE:
 		{
 			DrawLine(m_StartMouse, m_CurrentMouse);
 		}
 		break;
 
 		case MODE::DRAW_RECT:
 		{
 			DrawRect(m_StartMouse, m_CurrentMouse);
 		}
 		break;
 
		case MODE::NONE:
			break;
 
 		default:
			break;
 		}
	}
}

 void CmaptoolView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
 {
 	//TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
 
	 if ((::GetAsyncKeyState(VK_CONTROL) & 0x8001) && nChar == _T('Z'))
	 {
		 DeleteBack();
	 }
	 /// Ctrl+Z 가 아니라 Ctral+다른키+Z를 입력해야 된다.. 이걸 바꿔야한다..
	 CView::OnKeyDown(nChar, nRepCnt, nFlags);
 }
// 
// void CmaptoolView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
// {
// 	//TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
// 
// 	if (GetKeyState(VK_CONTROL) & 0x8000)
// 	{
// 		m_bCtrlKey = FALSE;
// 	}
// 
// 	CView::OnKeyUp(nChar, nRepCnt, nFlags);
// }
// 
// void CmaptoolView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
// {
// 	//TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
// 
// 	if (m_bCtrlKey && (nChar == 'z' || nChar == 'Z'))
// 	{
// 		DeleteBack();
// 	}
// 
// 	CView::OnChar(nChar, nRepCnt, nFlags);
// }

void CmaptoolView::SetDrawMode(int nDrawMode)
{
	this->m_nDrawMode = nDrawMode;
}

void CmaptoolView::DeleteBack()
{
	m_pShapeHandler->DeleteBack();

	RedrawWindow();
	OnPaint();
}

void CmaptoolView::DeleteAll()
{
	m_pShapeHandler->DeleteAll();

	RedrawWindow();
}

inline void CmaptoolView::OnPaint()
{

	for (int i=0 ; i<m_pShapeHandler->GetSize() ; i++)
	{
		CShape* pTempShape = m_pShapeHandler->GetObject(i);
		int nTempType = pTempShape->GetType();

		switch (nTempType)
		{
		case SHAPE::S_LINE:
		{
			CLine* pTempLine = dynamic_cast<CLine*>(pTempShape);
			DrawLine(pTempLine->GetStartPoint(), pTempLine->GetEndPoint());
		}
		break;

		case SHAPE::S_RECT:
		{
			CRectg* pTempRect = dynamic_cast<CRectg*>(pTempShape);
			DrawRect(pTempRect->GetStartPoint(), pTempRect->GetEndPoint());
		}
		break;

		default:
			break;
		}
	}
}

void CmaptoolView::DrawLine(CPoint &pntStart, CPoint &pntEnd)
{
	CDC* p = this->GetWindowDC();

	p->MoveTo(pntStart.x, pntStart.y);
 	p->LineTo(pntEnd.x, pntEnd.y);

	this->ReleaseDC(p);
}

void CmaptoolView::DrawRect(CPoint &pntStart, CPoint &pntEnd)
{
	CDC* p = this->GetWindowDC();

	p->Rectangle(pntStart.x, pntStart.y, pntEnd.x, pntEnd.y);

	this->ReleaseDC(p);
}

void CmaptoolView::DrawPoint(CPoint & point)
{
	/// 필요시 코딩
}

void CmaptoolView::CheckPoint(CPoint & point)
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
