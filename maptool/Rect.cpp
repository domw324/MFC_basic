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
//	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd(); /// ������ ������ ������
//	CmaptoolView* pView = (CmaptoolView*)pFrame->m_wndSplitter.GetPane(0, 0); /// Ȱ��ȭ�� ���� ������
//
//	CDC* p = pView->GetWindowDC();
//	   
//	p->Rectangle(pntStart.x, pntStart.y, pntEnd.x, pntEnd.y);
//	
//	pView->ReleaseDC(p);
//}
