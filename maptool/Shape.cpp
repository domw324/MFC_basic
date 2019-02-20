#include "stdafx.h"
#include "Shape.h"

CShape::CShape()
{
	this->nShapeType = NULL;
	this->pntStart->nX = this->pntStart->nY = 0;
	this->pntEnd->nX = this->pntEnd->nY = 0;
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
	this->pntStart->nX = nStartX;
	this->pntStart->nY = nStartY;
	this->pntEnd->nX = nEndX;
	this->pntEnd->nY = nEndY;
}

void CShape::SetStartPoint(int nStartX, int nStartY)
{
	this->pntStart->nX = nStartX;
	this->pntStart->nY = nStartY;
}

void CShape::SetEndPoint(int nEndX, int nEndY)
{
	this->pntEnd->nX = nEndX;
	this->pntEnd->nY = nEndY;
}
