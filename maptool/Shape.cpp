#include "stdafx.h"
#include "Shape.h"

CShape::CShape()
{
	nShapeType = NULL;
	pntStart->SetPoint(0, 0);
	pntEnd->SetPoint(0, 0);
}

CShape::~CShape()
{
	delete(this->pntStart);
	delete(this->pntEnd);
}

int CShape::GetType()
{
	return this->nShapeType;
}

void CShape::SetPoint(int nStartX, int nStartY, int nEndX, int nEndY)
{
	pntStart->SetPoint(nStartX, nStartY);
	pntEnd->SetPoint(nEndX, nEndY);
}

CPoint* CShape::GetStartPoint()
{
	return pntStart;
}

CPoint* CShape::GetEndPoint()
{
	return pntEnd;
}