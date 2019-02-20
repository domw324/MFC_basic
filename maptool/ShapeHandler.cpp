#include "stdafx.h"
#include "ShapeHandler.h"
#include "define.h"
#include "Line.h"
#include "Rect.h"

CShapeHandler::CShapeHandler()
{
}

CShapeHandler::~CShapeHandler()
{
	delete(m_ShapeArr);
}

void CShapeHandler::CreateShape(int nShapeType, int nStartX, int nStartY, int nEndX, int nEndY)
{
	if (nShapeType == SHAPE::S_LINE)
	{
		CLine* pLine = new CLine();
		pLine->SetPoint(nStartX, nStartY, nEndX, nEndY);
		m_ShapeArr->push_back(pLine);
	}
	else
	{
		CRectg* pRectg = new CRectg();
		pRectg->SetPoint(nStartX, nStartY, nEndX, nEndY);
		m_ShapeArr->push_back(pRectg);
	}
}

void CShapeHandler::DeleteShape(int nIndex)
{
	m_ShapeArr->erase(m_ShapeArr->begin() + nIndex);
}
