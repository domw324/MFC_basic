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
//	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd(); /// ������ ������ ������
//	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0); /// Ȱ��ȭ�� ���� ������
// 
// 	CDC* p = pView->GetWindowDC();
//
// 	p->MoveTo(pntStart.x, pntStart.y);
// 	p->LineTo(pntEnd.x, pntEnd.y);
// 	
// 	pView->ReleaseDC(p);
//}