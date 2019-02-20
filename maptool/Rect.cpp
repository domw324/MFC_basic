#include "stdafx.h"
#include "Rect.h"
#include "define.h"
#include "MainFrm.h"
#include "maptoolView.h"

CRectg::CRectg()
{
	this->nShapeType = SHAPE::S_RECT;
	this->pntStart->nX = this->pntStart->nY = 0;
	this->pntEnd->nX = this->pntEnd->nY = 0;
}

CRectg::~CRectg()
{
	delete(this->pntStart);
	delete(this->pntEnd);
}

//void CRectg::DrawShape()
//{
//	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd(); /// 프레임 윈도우 포인터
//	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0); /// 활성화된 뷰의 포인터
//
//	CDC* p = pView->GetWindowDC();
//	   
//	p->Rectangle(pntStart->nX, pntStart->nY, pntEnd->nX, pntEnd->nY);
//	
//	pView->ReleaseDC(p);
//}
