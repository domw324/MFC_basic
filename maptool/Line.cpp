#include "stdafx.h"
#include "Line.h"
#include "define.h"
#include "MainFrm.h"
#include "maptoolView.h"

CLine::CLine()
{
	this->nShapeType = SHAPE::S_LINE;
	this->pntStart->nX = this->pntStart->nY = 0;
	this->pntEnd->nX = this->pntEnd->nY = 0;
}


CLine::~CLine()
{
	delete(this->pntStart);
	delete(this->pntEnd);
}

//void CLine::DrawShape()
//{
//	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd(); /// ������ ������ ������
//	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0); /// Ȱ��ȭ�� ���� ������
// 
// 	CDC* p = pView->GetWindowDC();
//
// 	p->MoveTo(pntStart->nX, pntStart->nY);
// 	p->LineTo(pntEnd->nX, pntEnd->nY);
// 	
// 	pView->ReleaseDC(p);
//}