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
//	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd(); /// ������ ������ ������
//	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0); /// Ȱ��ȭ�� ���� ������
//
//	CDC* p = pView->GetWindowDC();
//	   
//	p->Rectangle(pntStart->nX, pntStart->nY, pntEnd->nX, pntEnd->nY);
//	
//	pView->ReleaseDC(p);
//}
