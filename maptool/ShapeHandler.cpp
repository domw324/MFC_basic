#include "stdafx.h"
#include "ShapeHandler.h"
#include "define.h"
#include "Line.h"
#include "Rect.h"
#include <iostream>

CShapeHandler::CShapeHandler()
{
}

CShapeHandler::~CShapeHandler()
{
}

void CShapeHandler::CreateShape(int nShapeType, CPoint pntStart, CPoint pntEnd)
{
	switch (nShapeType)
	{
	case SHAPE::S_LINE:
	{
		CShape* pLine = new CLine();
		pLine->SetPoint(pntStart, pntEnd);
		m_ShapeArr.push_back(pLine);
	}
		break;
	case SHAPE::S_RECT:
	{
		CShape* pRectg = new CRectg();
		pRectg->SetPoint(pntStart, pntEnd);
		m_ShapeArr.push_back(pRectg);
	}
		break;
	default:
		break;
	}
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
		m_ShapeArr.erase(m_ShapeArr.begin() + nSize - 1);
	}
}

void CShapeHandler::DeleteAll()
{
	while (!m_ShapeArr.empty())
	{
		m_ShapeArr.erase(m_ShapeArr.begin());
	}
}

CShape* CShapeHandler::GetObject(int nIndex)
{
	return m_ShapeArr.at(nIndex);
}

int CShapeHandler::GetSize()
{
	return m_ShapeArr.size();
}
