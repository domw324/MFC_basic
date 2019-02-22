#include "stdafx.h"
#include "ShapeHandler.h"
#include "define.h"
#include "Line.h"
#include "Rect.h"
#include <iostream>
#include "MainFrm.h"
#include "DlgTab1.h"
#include "ControlView.h"

CShapeHandler::CShapeHandler()
{
	nLineNum = nRectNum = 0;
}

CShapeHandler::~CShapeHandler()
{
}

void CShapeHandler::CreateShape(int nShapeType, CPoint pntStart, CPoint pntEnd)
{
	CShape* pShape;
	switch (nShapeType)
	{
	case SHAPE::S_LINE:
	{
		nLineNum++;
		pShape = new CLine();
		pShape->SetShapeInfo(nLineNum, pntStart, pntEnd);
		m_ShapeArr.push_back(pShape);
	}
		break;
	case SHAPE::S_RECT:
	{
		nRectNum++;
		pShape = new CRectg();
		pShape->SetShapeInfo(nRectNum, pntStart, pntEnd);
		m_ShapeArr.push_back(pShape);
	}
		break;
	default:
		break;
	}

	/// 트리에 항목 추가
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CControlView* pView = (CControlView*)pFrame->m_wndSplitter.GetPane(0, 1);

	pView->InsertTree(nShapeType, pShape->GetId());
}

void CShapeHandler::DeleteShape(int nIndex)
{
	m_ShapeArr.erase(m_ShapeArr.begin() + nIndex);
}

void CShapeHandler::DeleteBack()
{
	int nSize = m_ShapeArr.size();
	
	if (nSize)
	{
		CShape *pTempShape = m_ShapeArr.back();

		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		CControlView* pView = (CControlView*)pFrame->m_wndSplitter.GetPane(0, 1);

		pView->DeleteTreeBack(pTempShape->GetType());

		m_ShapeArr.erase(m_ShapeArr.end() - 1);
	}
}

void CShapeHandler::DeleteAll()
{
	while (!m_ShapeArr.empty())
	{
		m_ShapeArr.erase(m_ShapeArr.begin());
	}

	/// 트리 인스턴스 모두 제거
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CControlView* pView = (CControlView*)pFrame->m_wndSplitter.GetPane(0, 1);

	pView->DeleteTreeAll();
}

CShape* CShapeHandler::GetObject(int nIndex)
{
	return m_ShapeArr.at(nIndex);
}

int CShapeHandler::GetSize()
{
	return m_ShapeArr.size();
}
