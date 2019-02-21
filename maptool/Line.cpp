#include "stdafx.h"
#include "Line.h"
#include "define.h"
#include "MainFrm.h"
#include "maptoolView.h"

CLine::CLine()
{
	this->nShapeType = SHAPE::S_LINE;
}


CLine::~CLine()
{
}

//void CLine::DrawShape()
//{
//	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd(); /// 프레임 윈도우 포인터
//	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0); /// 활성화된 뷰의 포인터
// 
// 	CDC* p = pView->GetWindowDC();
//
// 	p->MoveTo(pntStart.x, pntStart.y);
// 	p->LineTo(pntEnd.x, pntEnd.y);
// 	
// 	pView->ReleaseDC(p);
//}