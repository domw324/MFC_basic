#include "stdafx.h"
#include "Shape.h"

CShape::CShape()
{
	nShapeType = NULL;
	pntStart.SetPoint(0, 0);
	pntEnd.SetPoint(0, 0);
}

CShape::~CShape()
{
}

int CShape::GetType()
{
	return this->nShapeType;
}

CShape* CShape::GetInstance()
{
	return this;
}

int CShape::GetId()
{
	return this->nId;
}

void CShape::SetShapeInfo(int nId, CPoint pntStart, CPoint pntEnd)
{
	this->nId = nId;
	this->pntStart = pntStart;
	this->pntEnd = pntEnd;
}

CPoint CShape::GetStartPoint()
{
	return pntStart;
}

CPoint CShape::GetEndPoint()
{
	return pntEnd;
}