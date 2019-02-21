#include "stdafx.h"
#include "Rect.h"
#include "define.h"
#include "MainFrm.h"
#include "maptoolView.h"

CRectg::CRectg()
{
	this->nShapeType = SHAPE::S_RECT;
}

CRectg::~CRectg()
{
}

//void CRectg::DrawShape()
//{
//	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd(); /// 프레임 윈도우 포인터
//	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0); /// 활성화된 뷰의 포인터
//
//	CDC* p = pView->GetWindowDC();
//	   
//	p->Rectangle(pntStart.x, pntStart.y, pntEnd.x, pntEnd.y);
//	
//	pView->ReleaseDC(p);
//}
